#!/bin/bash
set -e

# NixRar macOS Release Build Script
# This script builds a complete macOS distribution package

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
BUILD_DIR="$PROJECT_ROOT/build-release"

echo "Building NixRar for macOS Release..."
echo "Project root: $PROJECT_ROOT"

# Clean previous builds
rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"

# Detect Qt installation path
echo "Detecting Qt installation..."
QT_PATH=""
if [ -d "/opt/homebrew/lib/cmake/Qt6" ]; then
    QT_PATH="/opt/homebrew/lib/cmake/Qt6"
    echo "Found Homebrew Qt6 at: $QT_PATH"
elif [ -d "/usr/local/lib/cmake/Qt6" ]; then
    QT_PATH="/usr/local/lib/cmake/Qt6"
    echo "Found system Qt6 at: $QT_PATH"
elif command -v qmake6 >/dev/null 2>&1; then
    QMAKE_PATH=$(which qmake6)
    QT_BIN_DIR=$(dirname "$QMAKE_PATH")
    QT_PATH="$QT_BIN_DIR/../lib/cmake/Qt6"
    echo "Found Qt6 via qmake6 at: $QT_PATH"
else
    echo "Warning: Could not detect Qt6 installation path"
fi

# Configure for Release build
cd "$BUILD_DIR"
echo "Configuring CMake for Release..."
CMAKE_ARGS=(
    -DCMAKE_BUILD_TYPE=Release
    -DCMAKE_INSTALL_PREFIX="$BUILD_DIR/install"
)

if [ -n "$QT_PATH" ]; then
    CMAKE_ARGS+=(-DQt6_DIR="$QT_PATH")
    CMAKE_ARGS+=(-DCMAKE_PREFIX_PATH="$(dirname "$(dirname "$QT_PATH")")")
fi

cmake .. "${CMAKE_ARGS[@]}"

echo "Building project..."
make -j$(sysctl -n hw.ncpu)

echo "Creating macOS app bundle..."
make package_macos

# Check deployment results and apply fixes if needed
APP_BUNDLE="$BUILD_DIR/install/NixRar.app"
if [ -d "$APP_BUNDLE" ]; then
    echo "Checking app bundle structure..."
    
    # Check if Qt frameworks were deployed
    if [ ! -d "$APP_BUNDLE/Contents/Frameworks" ]; then
        echo "WARNING: No Qt frameworks found in app bundle"
        echo "This may indicate macdeployqt deployment issues"
    else
        echo "✓ Qt frameworks deployed to app bundle"
        ls -la "$APP_BUNDLE/Contents/Frameworks/" | head -10
    fi
    
    # Apply additional codesigning
    echo "Applying codesigning..."
    codesign --force --deep --sign - "$APP_BUNDLE" 2>/dev/null || echo "Warning: Codesigning failed, but app may still work"
    
    # Test if app can launch (basic check)
    echo "Testing app bundle..."
    if [ -x "$APP_BUNDLE/Contents/MacOS/NixRar" ]; then
        echo "✓ Executable is present and executable"
        # Quick library check
        otool -L "$APP_BUNDLE/Contents/MacOS/NixRar" | grep -E "(Qt|@rpath)" | head -5
    else
        echo "❌ Executable not found or not executable"
    fi
fi

# Check if DMG creation is available
if command -v hdiutil >/dev/null 2>&1; then
    echo "Creating DMG installer..."
    make create_dmg
    
    DMG_FILE=$(find "$BUILD_DIR" -name "NixRar-*-macOS.dmg" | head -n1)
    if [ -n "$DMG_FILE" ]; then
        echo "DMG created: $DMG_FILE"
        
        # Move to project root for easier access
        FINAL_DMG="$PROJECT_ROOT/$(basename "$DMG_FILE")"
        cp "$DMG_FILE" "$FINAL_DMG"
        echo "Final DMG location: $FINAL_DMG"
    fi
else
    echo "hdiutil not found - DMG creation skipped"
fi

# Show the app bundle location
APP_BUNDLE="$BUILD_DIR/install/NixRar.app"
if [ -d "$APP_BUNDLE" ]; then
    echo "App bundle created: $APP_BUNDLE"
    echo "You can run it with: open \"$APP_BUNDLE\""
else
    echo "Error: App bundle not found"
    exit 1
fi

echo "macOS release build complete!"
echo ""
echo "Distribution files:"
echo "- App Bundle: $APP_BUNDLE"
if [ -n "$FINAL_DMG" ]; then
    echo "- DMG Installer: $FINAL_DMG"
fi