#!/bin/bash
set -e

# NixRar macOS Icon Generator
# This script creates a .icns file from a 1024x1024 PNG source image

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
RESOURCES_DIR="$PROJECT_ROOT/resources"

# Check if source image is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <source-png-file>"
    echo ""
    echo "Creates nixrar.icns from a source PNG image (preferably 1024x1024)"
    echo "Example: $0 ~/Desktop/nixrar-logo.png"
    echo ""
    echo "Requirements:"
    echo "- macOS with sips and iconutil commands"
    echo "- Source PNG image (ideally 1024x1024 pixels)"
    exit 1
fi

SOURCE_PNG="$1"

# Check if source file exists
if [ ! -f "$SOURCE_PNG" ]; then
    echo "Error: Source PNG file '$SOURCE_PNG' not found"
    exit 1
fi

# Check for required tools
if ! command -v sips >/dev/null 2>&1; then
    echo "Error: 'sips' command not found (required on macOS)"
    exit 1
fi

if ! command -v iconutil >/dev/null 2>&1; then
    echo "Error: 'iconutil' command not found (required on macOS)"
    exit 1
fi

echo "Creating macOS icon from: $SOURCE_PNG"
echo "Project resources: $RESOURCES_DIR"

# Create temporary iconset directory
ICONSET_DIR="$SCRIPT_DIR/nixrar.iconset"
rm -rf "$ICONSET_DIR"
mkdir -p "$ICONSET_DIR"

# Generate all required icon sizes
echo "Generating icon sizes..."

# 16x16
sips -z 16 16 "$SOURCE_PNG" --out "$ICONSET_DIR/icon_16x16.png" >/dev/null
echo "✓ 16x16"

# 32x32 (16x16@2x)
sips -z 32 32 "$SOURCE_PNG" --out "$ICONSET_DIR/icon_16x16@2x.png" >/dev/null
sips -z 32 32 "$SOURCE_PNG" --out "$ICONSET_DIR/icon_32x32.png" >/dev/null
echo "✓ 32x32"

# 64x64 (32x32@2x)
sips -z 64 64 "$SOURCE_PNG" --out "$ICONSET_DIR/icon_32x32@2x.png" >/dev/null
echo "✓ 64x64"

# 128x128
sips -z 128 128 "$SOURCE_PNG" --out "$ICONSET_DIR/icon_128x128.png" >/dev/null
echo "✓ 128x128"

# 256x256 (128x128@2x and 256x256)
sips -z 256 256 "$SOURCE_PNG" --out "$ICONSET_DIR/icon_128x128@2x.png" >/dev/null
sips -z 256 256 "$SOURCE_PNG" --out "$ICONSET_DIR/icon_256x256.png" >/dev/null
echo "✓ 256x256"

# 512x512 (256x256@2x and 512x512)
sips -z 512 512 "$SOURCE_PNG" --out "$ICONSET_DIR/icon_256x256@2x.png" >/dev/null
sips -z 512 512 "$SOURCE_PNG" --out "$ICONSET_DIR/icon_512x512.png" >/dev/null
echo "✓ 512x512"

# 1024x1024 (512x512@2x)
sips -z 1024 1024 "$SOURCE_PNG" --out "$ICONSET_DIR/icon_512x512@2x.png" >/dev/null
echo "✓ 1024x1024"

# Create the .icns file
echo "Creating .icns file..."
iconutil -c icns "$ICONSET_DIR"

# Move the created .icns file to resources directory
if [ -f "$SCRIPT_DIR/nixrar.icns" ]; then
    mv "$SCRIPT_DIR/nixrar.icns" "$RESOURCES_DIR/nixrar.icns"
    echo "✓ nixrar.icns created successfully"
    
    # Clean up temporary iconset directory
    rm -rf "$ICONSET_DIR"
    
    echo ""
    echo "Success! Icon created at: $RESOURCES_DIR/nixrar.icns"
    echo "The icon is now ready for use in your macOS app bundle."
    echo ""
    echo "To test the icon, rebuild your project in Release mode:"
    echo "  cmake -B build -DCMAKE_BUILD_TYPE=Release"
    echo "  cmake --build build"
    echo "  cd build && make package_macos"
else
    echo "Error: Failed to create nixrar.icns"
    rm -rf "$ICONSET_DIR"
    exit 1
fi