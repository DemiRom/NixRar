#!/bin/bash
set -e

# NixRar AppImage Build Script
# This script automates the creation of an AppImage for NixRar

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
BUILD_DIR="$PROJECT_ROOT/build"
APPDIR="$PROJECT_ROOT/AppDir"

echo "Building NixRar AppImage..."
echo "Project root: $PROJECT_ROOT"

# Clean previous builds
rm -rf "$BUILD_DIR" "$APPDIR"
mkdir -p "$BUILD_DIR"

# Configure and build
cd "$BUILD_DIR"
echo "Configuring CMake..."
cmake .. \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=/usr

echo "Building project..."
make -j$(nproc)

# Install to AppDir
echo "Installing to AppDir..."
DESTDIR="$APPDIR" make install

# Ensure desktop file and icon are in the right places
mkdir -p "$APPDIR/usr/share/applications"
mkdir -p "$APPDIR/usr/share/icons/hicolor/256x256/apps"

cp "$PROJECT_ROOT/resources/nixrar.desktop" "$APPDIR/usr/share/applications/"
cp "$PROJECT_ROOT/resources/nixrar.png" "$APPDIR/usr/share/icons/hicolor/256x256/apps/"

# Download linuxdeploy if not present
cd "$PROJECT_ROOT"
if [ ! -f "linuxdeploy-x86_64.AppImage" ]; then
    echo "Downloading linuxdeploy..."
    wget -q https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage
    chmod +x linuxdeploy-x86_64.AppImage
fi

if [ ! -f "linuxdeploy-plugin-qt-x86_64.AppImage" ]; then
    echo "Downloading linuxdeploy Qt plugin..."
    wget -q https://github.com/linuxdeploy/linuxdeploy-plugin-qt/releases/download/continuous/linuxdeploy-plugin-qt-x86_64.AppImage
    chmod +x linuxdeploy-plugin-qt-x86_64.AppImage
fi

# Create AppImage
echo "Creating AppImage..."
export QMAKE=$(which qmake6 || which qmake)
./linuxdeploy-x86_64.AppImage \
    --appdir "$APPDIR" \
    --executable "$APPDIR/usr/bin/NixRar" \
    --plugin qt \
    --output appimage \
    --desktop-file="$APPDIR/usr/share/applications/nixrar.desktop" \
    --icon-file="$APPDIR/usr/share/icons/hicolor/256x256/apps/nixrar.png"

# Find the created AppImage and rename it
APPIMAGE_FILE=$(find . -name "NixRar*.AppImage" | head -n1)
if [ -n "$APPIMAGE_FILE" ]; then
    VERSION=$(git describe --tags --always --dirty 2>/dev/null || echo "dev")
    NEW_NAME="NixRar-$VERSION-linux-x86_64.AppImage"
    mv "$APPIMAGE_FILE" "$NEW_NAME"
    echo "AppImage created: $NEW_NAME"
    
    # Make it executable
    chmod +x "$NEW_NAME"
    
    echo "Build complete! AppImage location: $PWD/$NEW_NAME"
else
    echo "Error: AppImage creation failed"
    exit 1
fi