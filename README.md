# NixRar 🗃️

A modern, cross-platform archive manager built with Qt and libarchive. NixRar provides a free, open-source alternative to WinRAR with a clean interface and powerful archive management capabilities.

## Features ✨

- **Multi-format Support**: Open and extract RAR, ZIP, TAR, GZIP, BZIP2, CAB, ARJ, LZH, ACE, UUE and more
- **Drag & Drop Interface**: Simply drag files into the application to add them to your archive
- **Cross-platform**: Works on Windows, macOS, and Linux
- **Modern Qt Interface**: Clean, intuitive user interface built with Qt
- **Progress Tracking**: Visual progress feedback for long operations
- **Archive Creation**: Create new archives in various formats
- **File Management**: Add, extract, and manage files within archives

## Screenshots 📸

*Coming soon - screenshots of the application in action*

## Installation 🛠️

### Prerequisites

- **Qt 6.x** or later
- **libarchive** development libraries
- **CMake 3.16** or later
- A C++17 compatible compiler

### Building from Source

1. **Clone the repository:**
   ```bash
   git clone https://github.com/demirom/NixRar.git
   cd NixRar
   ```

2. **Install dependencies:**

   **Ubuntu/Debian:**
   ```bash
   sudo apt-get install qt6-base-dev libarchive-dev cmake build-essential
   ```

   **macOS (with Homebrew):**
   ```bash
   brew install qt6 libarchive cmake
   ```

   **Windows:**
   - Install Qt6 from the official Qt installer
   - Install libarchive (e.g., via vcpkg)
   - Install CMake

3. **Build the project:**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

4. **Run NixRar:**
   ```bash
   ./NixRar
   ```

## Usage 🚀

1. **Opening Archives**: Use File → Open or drag an archive file into the window
2. **Adding Files**: 
   - Drag and drop files from your file manager into the archive view
   - Or use Commands → Add File to browse and select files
3. **Extracting Files**: Use Commands → Extract To and choose your destination folder
4. **Creating Archives**: Use File → New Archive (feature in development)

## Supported Formats 📁

| Format | Read | Write | Notes |
|--------|------|-------|-------|
| ZIP    | ✅   | ✅    | Full support |
| RAR    | ✅   | ❌    | Read-only (proprietary format) |
| TAR    | ✅   | ✅    | Including compressed variants |
| GZIP   | ✅   | ✅    | |
| BZIP2  | ✅   | ✅    | |
| 7Z     | ✅   | ⚠️    | Limited write support |
| CAB    | ✅   | ❌    | Read-only |

## Contributing 🤝

We welcome contributions! Here's how you can help:

1. **Fork the repository**
2. **Create a feature branch**: `git checkout -b feature-name`
3. **Make your changes** and add tests if applicable
4. **Follow the existing code style**
5. **Submit a pull request**

### Development Setup

- Follow the building instructions above
- Use Qt Creator or any C++ IDE of your choice
- Code style: Follow Qt/C++ conventions
- All new features should include appropriate error handling

## Roadmap 🗺️

- [ ] Support for creating RAR archives (if licensing permits)
- [ ] Archive encryption/decryption
- [ ] Batch operations
- [ ] Command-line interface
- [ ] Archive integrity verification
- [ ] Thumbnail previews for common file types
- [ ] Plugin system for additional formats

## License 📄

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Why NixRar? 🤔

- **Free & Open Source**: No licensing fees, no restrictions
- **Privacy Focused**: No telemetry or data collection
- **Cross-platform**: One application for all your devices
- **Modern Interface**: Built with contemporary UI frameworks
- **Community Driven**: Developed by users, for users

## Acknowledgments 🙏

- Built with [Qt](https://www.qt.io/) framework
- Archive handling powered by [libarchive](https://libarchive.org/)
- Icons from various open source icon packs
- Inspired by the need for a free, modern archive manager

## Support 💬

- **Issues**: Report bugs or request features on [GitHub Issues](https://github.com/demirom/NixRar/issues)
- **Discussions**: Join the community discussions
- **Wiki**: Check the wiki for detailed documentation

---

**NixRar** - Making archive management simple, fast, and free for everyone! 🚀