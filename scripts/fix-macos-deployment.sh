#!/bin/bash
set -e

# NixRar macOS Deployment Fix Script
# This script manually fixes Qt framework deployment issues
# Use this if macdeployqt fails or has rpath resolution problems

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"

# Check if app bundle path is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <path-to-NixRar.app>"
    echo ""
    echo "This script manually fixes Qt framework deployment in a NixRar.app bundle"
    echo "Example: $0 /path/to/build/install/NixRar.app"
    exit 1
fi

APP_BUNDLE="$1"

# Validate app bundle
if [ ! -d "$APP_BUNDLE" ]; then
    echo "Error: App bundle not found: $APP_BUNDLE"
    exit 1
fi

if [ ! -f "$APP_BUNDLE/Contents/MacOS/NixRar" ]; then
    echo "Error: NixRar executable not found in app bundle"
    exit 1
fi

echo "Fixing Qt deployment for: $APP_BUNDLE"

# Detect Qt installation
echo "Detecting Qt installation..."
QT_LIB_PATH=""
if [ -d "/opt/homebrew/lib" ]; then
    QT_LIB_PATH="/opt/homebrew/lib"
    echo "Using Homebrew Qt at: $QT_LIB_PATH"
elif [ -d "/usr/local/lib" ]; then
    QT_LIB_PATH="/usr/local/lib"
    echo "Using system Qt at: $QT_LIB_PATH"
else
    echo "Error: Could not find Qt installation"
    exit 1
fi

# Create Frameworks directory
FRAMEWORKS_DIR="$APP_BUNDLE/Contents/Frameworks"
mkdir -p "$FRAMEWORKS_DIR"

# Get required Qt frameworks by analyzing the executable
echo "Analyzing required Qt frameworks..."
REQUIRED_FRAMEWORKS=$(otool -L "$APP_BUNDLE/Contents/MacOS/NixRar" | grep -E "@rpath/Qt.*framework" | sed 's/.*@rpath\/\([^\/]*\)\.framework.*/\1/' | sort -u)

echo "Required frameworks: $REQUIRED_FRAMEWORKS"

# Copy Qt frameworks
for framework in $REQUIRED_FRAMEWORKS; do
    FRAMEWORK_PATH="$QT_LIB_PATH/$framework.framework"
    TARGET_PATH="$FRAMEWORKS_DIR/$framework.framework"
    
    if [ -d "$FRAMEWORK_PATH" ]; then
        echo "Copying $framework.framework..."
        cp -R "$FRAMEWORK_PATH" "$FRAMEWORKS_DIR/"
        
        # Fix framework's internal references
        FRAMEWORK_BINARY="$TARGET_PATH/Versions/A/$framework"
        if [ -f "$FRAMEWORK_BINARY" ]; then
            # Change the framework's ID
            install_name_tool -id "@rpath/$framework.framework/Versions/A/$framework" "$FRAMEWORK_BINARY"
            
            # Fix references to other Qt frameworks within this framework
            otool -L "$FRAMEWORK_BINARY" | grep "@rpath/Qt" | while read -r line; do
                OLD_PATH=$(echo "$line" | awk '{print $1}')
                NEW_PATH=$(echo "$OLD_PATH" | sed 's|@rpath|@loader_path/..|')
                install_name_tool -change "$OLD_PATH" "$NEW_PATH" "$FRAMEWORK_BINARY" 2>/dev/null || true
            done
        fi
    else
        echo "Warning: Framework not found: $FRAMEWORK_PATH"
    fi
done

# Fix executable's framework references
echo "Fixing executable references..."
EXECUTABLE="$APP_BUNDLE/Contents/MacOS/NixRar"

# Update rpath in executable
install_name_tool -add_rpath "@executable_path/../Frameworks" "$EXECUTABLE" 2>/dev/null || true

# Change @rpath references to relative paths
otool -L "$EXECUTABLE" | grep "@rpath/Qt" | while read -r line; do
    OLD_PATH=$(echo "$line" | awk '{print $1}')
    NEW_PATH=$(echo "$OLD_PATH" | sed 's|@rpath|@executable_path/../Frameworks|')
    echo "Changing: $OLD_PATH -> $NEW_PATH"
    install_name_tool -change "$OLD_PATH" "$NEW_PATH" "$EXECUTABLE"
done

# Copy Qt plugins if they exist
PLUGINS_DIR="$APP_BUNDLE/Contents/PlugIns"
mkdir -p "$PLUGINS_DIR"

QT_PLUGINS_PATH="$QT_LIB_PATH/../plugins"
if [ -d "$QT_PLUGINS_PATH" ]; then
    echo "Copying Qt plugins..."
    
    # Copy essential plugins
    for plugin_type in platforms imageformats iconengines styles; do
        if [ -d "$QT_PLUGINS_PATH/$plugin_type" ]; then
            cp -R "$QT_PLUGINS_PATH/$plugin_type" "$PLUGINS_DIR/"
            
            # Fix plugin references
            find "$PLUGINS_DIR/$plugin_type" -name "*.dylib" -exec install_name_tool -add_rpath "@loader_path/../../Frameworks" {} \; 2>/dev/null || true
        fi
    done
fi

# Create qt.conf file
echo "Creating qt.conf..."
cat > "$APP_BUNDLE/Contents/Resources/qt.conf" << EOF
[Paths]
Plugins = PlugIns
EOF

# Apply codesigning
echo "Applying codesigning..."
codesign --force --deep --sign - "$APP_BUNDLE" 2>/dev/null || echo "Warning: Codesigning failed"

echo ""
echo "✅ Manual deployment fix completed!"
echo ""
echo "App bundle structure:"
ls -la "$APP_BUNDLE/Contents/"
echo ""
echo "Frameworks:"
ls -la "$FRAMEWORKS_DIR/" 2>/dev/null | head -10 || echo "No frameworks directory"
echo ""
echo "Test the app with: open \"$APP_BUNDLE\""