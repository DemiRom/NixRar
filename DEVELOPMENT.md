# NixRar Development Guide 🛠️

This document provides a comprehensive overview of unimplemented functions and development priorities for the NixRar project.

## Table of Contents
- [Unimplemented Functions Overview](#unimplemented-functions-overview)
- [Priority Categories](#priority-categories)
- [Function Specifications](#function-specifications)
- [Implementation Guidelines](#implementation-guidelines)
- [Development Workflow](#development-workflow)

## Unimplemented Functions Overview

### 📊 Status Summary
| Component | Total Functions | Implemented | Stub/Empty | Priority |
|-----------|----------------|-------------|------------|----------|
| Archive | 2 | 0 | 2 | Medium |
| MainWindow | 7 | 0 | 7 | High |
| FileExplorer | 1 | 0 | 1 | Medium |

## Priority Categories

### 🔴 **High Priority** (Core Functionality)
These functions are essential for basic archive management:

1. **testArchive()** - Validate archive integrity
2. **viewArchive()** - Preview file contents
3. **deleteFileFromArchive()** - Remove files from archives
4. **findInArchive()** - Search functionality
5. **showArchiveInfo()** - Display archive metadata

### 🟡 **Medium Priority** (Enhanced Features)
Important for user experience but not critical:

6. **startArchiveWizard()** - Guided archive creation
7. **repairArchive()** - Fix corrupted archives
8. **mouseDoubleClickEvent()** - File preview on double-click

### 🟢 **Low Priority** (Advanced Features)
Nice-to-have features for power users:

9. **encrypt()** - Archive encryption
10. **decrypt()** - Archive decryption

---

## Function Specifications

### 🏗️ Archive Class (`Archive.h/cpp`)

#### `void encrypt(QString password)`
**Location:** `Archive.cpp:80`  
**Status:** Empty implementation  
**Complexity:** 🔴 Hard  

**Specification:**
- Encrypt existing archive with password protection
- Support for AES-256 encryption standard
- Maintain archive format compatibility where possible
- Handle encryption for different archive formats (ZIP, 7Z)

**Dependencies:**
- Cryptographic library (OpenSSL/Qt Cryptography)
- Format-specific encryption support in libarchive

**Implementation Notes:**
```cpp
// Suggested approach:
// 1. Create new encrypted archive
// 2. Copy all files with encryption
// 3. Replace original archive
// 4. Update internal file list
```

---

#### `void decrypt(QString password)`
**Location:** `Archive.cpp:134`  
**Status:** Empty implementation  
**Complexity:** 🔴 Hard  

**Specification:**
- Decrypt password-protected archives
- Validate password before processing
- Support multiple encryption standards
- Graceful error handling for wrong passwords

**Dependencies:**
- Cryptographic library integration
- Password validation mechanisms

---

### 🖥️ MainWindow Class (`MainWindow.h/cpp`)

#### `void testArchive()`
**Location:** `MainWindow.cpp:175`  
**Status:** Empty stub  
**Complexity:** 🟡 Medium  
**Priority:** 🔴 High  

**Specification:**
- Verify archive integrity without extraction
- Check for corruption, missing files, or format errors
- Display results in a dialog with detailed report
- Support for different archive formats
- Progress indication for large archives

**UI Requirements:**
- Progress dialog during testing
- Results dialog showing:
  - Overall status (✅ Healthy / ⚠️ Issues / ❌ Corrupted)
  - File count and total size
  - List of any problematic files
  - Detailed error messages

**Implementation Approach:**
```cpp
void MainWindow::testArchive() {
    if (!archive || !archive->isOpen()) {
        showError("No archive open");
        return;
    }
    
    // Create progress dialog
    QProgressDialog progress("Testing archive...", "Cancel", 0, 100, this);
    
    // Test each file in archive
    // Display results in custom dialog
}
```

---

#### `void viewArchive()`
**Location:** `MainWindow.cpp:178`  
**Status:** Empty stub  
**Complexity:** 🟡 Medium  
**Priority:** 🔴 High  

**Specification:**
- Preview selected file content without extraction
- Support text files, images, and basic document formats
- Hex viewer for binary files
- External application integration for complex formats

**UI Requirements:**
- Tabbed preview dialog
- Syntax highlighting for code files
- Image viewer with zoom/pan
- Hex dump view for binary data
- File information panel (size, type, dates)

**Supported Preview Types:**
- Text files (.txt, .md, .log, .cfg)
- Code files (.cpp, .h, .js, .py, .html, .css)
- Images (.png, .jpg, .gif, .bmp)
- Basic documents (.xml, .json, .csv)

---

#### `void deleteFileFromArchive()`
**Location:** `MainWindow.cpp:181`  
**Status:** Empty stub  
**Complexity:** 🟡 Medium  
**Priority:** 🔴 High  

**Specification:**
- Remove selected files/folders from archive
- Multiple selection support
- Confirmation dialog with file list
- Undo functionality (temporary backup)
- Progress indication for large operations

**UI Requirements:**
- Confirmation dialog listing files to delete
- Progress dialog for deletion process
- Success/failure notifications
- Model refresh after deletion

**Implementation Considerations:**
- Create new archive without deleted files
- Handle directory deletion (recursive)
- Maintain archive format and compression
- Update internal file tracking

---

#### `void findInArchive()`
**Location:** `MainWindow.cpp:184`  
**Status:** Empty stub  
**Complexity:** 🟡 Medium  
**Priority:** 🔴 High  

**Specification:**
- Search files by name, content, or metadata
- Regular expression support
- Case-sensitive/insensitive options
- Filter by file type, size, or date
- Search within file contents (text files only)

**UI Requirements:**
- Search dialog with options:
  - Search term input
  - Search scope (filename/content/both)
  - File type filters
  - Size/date range filters
  - RegEx toggle
- Results dialog with:
  - Matched files list
  - Context snippets for content matches
  - Jump to file in main view

**Search Capabilities:**
- Filename patterns (wildcards, regex)
- File content search (text files)
- Metadata search (size, date, type)
- Advanced filters and combinations

---

#### `void startArchiveWizard()`
**Location:** `MainWindow.cpp:187`  
**Status:** Empty stub  
**Complexity:** 🟡 Medium  
**Priority:** 🟡 Medium  

**Specification:**
- Guided workflow for creating new archives
- Step-by-step process with validation
- Support multiple archive formats
- Compression level selection
- Batch operations support

**Wizard Steps:**
1. **Archive Type Selection**
   - Format selection (ZIP, TAR.GZ, 7Z, etc.)
   - Compression level options
   - Encryption options

2. **File Selection**
   - File/folder browser
   - Drag & drop support
   - Exclude patterns
   - Size estimation

3. **Archive Settings**
   - Output location
   - Archive name
   - Metadata options
   - Advanced settings

4. **Creation Process**
   - Progress indication
   - Cancel support
   - Error handling
   - Success confirmation

---

#### `void showArchiveInfo()`
**Location:** `MainWindow.cpp:190`  
**Status:** Empty stub  
**Complexity:** 🟢 Easy  
**Priority:** 🔴 High  

**Specification:**
- Display comprehensive archive information
- File statistics and metadata
- Format-specific details
- Export information to file

**Information Categories:**
- **General Info:**
  - Archive path and name
  - Format and version
  - Total size (compressed/uncompressed)
  - Compression ratio
  - File count and folder count

- **Security:**
  - Encryption status
  - Password protection
  - Digital signatures

- **Statistics:**
  - Largest/smallest files
  - File type distribution
  - Date range (oldest/newest)
  - Compression effectiveness by type

- **Technical:**
  - Archive format details
  - Compression algorithms used
  - CRC checksums
  - Archive comments

**UI Layout:**
- Tabbed dialog with categories
- Copy-to-clipboard functionality
- Export as text/JSON
- Rich formatting with icons

---

#### `void repairArchive()`
**Location:** `MainWindow.cpp:193`  
**Status:** Empty stub  
**Complexity:** 🔴 Hard  
**Priority:** 🟡 Medium  

**Specification:**
- Attempt to repair corrupted archives
- Recover partial data from damaged files
- Rebuild archive structure when possible
- Backup original before repair attempts

**Repair Capabilities:**
- Header reconstruction
- CRC error correction
- Partial file recovery
- Structural repairs
- Format conversion as fallback

**Process:**
1. **Analysis Phase:**
   - Scan for corruption types
   - Assess repairability
   - Estimate recovery success

2. **Backup Phase:**
   - Create backup of original
   - Prepare recovery workspace

3. **Repair Phase:**
   - Apply appropriate repair techniques
   - Progress indication
   - Detailed logging

4. **Verification Phase:**
   - Test repaired archive
   - Compare with original
   - Report recovery results

---

### 🖱️ FileExplorer Class (`FileExplorer.h/cpp`)

#### `void mouseDoubleClickEvent(QMouseEvent *event)`
**Location:** `FileExplorer.cpp:99`  
**Status:** Debug stub (only prints position)  
**Complexity:** 🟢 Easy  
**Priority:** 🟡 Medium  

**Current Implementation:**
```cpp
void FileExplorer::mouseDoubleClickEvent(QMouseEvent *event) {
    qDebug() << event->pos();
    QTreeView::mouseDoubleClickEvent(event);
}
```

**Specification:**
- Double-click to preview/open files
- Different actions based on file type
- Integration with system default applications
- Fallback to built-in viewer

**Behavior:**
- **Text files:** Open in built-in viewer
- **Images:** Open in image viewer
- **Archives:** Open as nested archive (future feature)
- **Executables:** Show properties instead of executing
- **Unknown types:** Hex viewer or save dialog

**Implementation:**
```cpp
void FileExplorer::mouseDoubleClickEvent(QMouseEvent *event) {
    QModelIndex index = indexAt(event->pos());
    if (index.isValid()) {
        // Get file info from model
        // Determine action based on file type
        // Emit signal to MainWindow for processing
        emit fileDoubleClicked(index);
    }
    QTreeView::mouseDoubleClickEvent(event);
}
```

---

## Implementation Guidelines

### 🔧 Development Standards

**Code Style:**
- Follow Qt coding conventions
- Use const correctness
- Implement proper error handling
- Add comprehensive logging
- Include unit tests for new functions

**Error Handling:**
- Use Qt's message system for user notifications
- Log errors to debug output
- Provide meaningful error messages
- Graceful degradation when possible

**UI Guidelines:**
- Maintain consistent styling with existing interface
- Use Qt's built-in dialogs when appropriate
- Implement proper keyboard shortcuts
- Support internationalization (tr() for all strings)

**Testing Requirements:**
- Unit tests for business logic
- Integration tests for UI components
- Performance testing for large archives
- Cross-platform testing

### 📋 Implementation Checklist

For each function implementation:

- [ ] Write function specification
- [ ] Design UI mockups (if applicable)
- [ ] Implement core functionality
- [ ] Add error handling
- [ ] Write unit tests
- [ ] Update documentation
- [ ] Test on multiple platforms
- [ ] Add internationalization strings
- [ ] Performance optimization
- [ ] Code review

---

## Development Workflow

### 🎯 Getting Started

1. **Choose a Function:**
   - Start with high-priority, low-complexity functions
   - Consider dependencies between functions
   - Review existing codebase patterns

2. **Design Phase:**
   - Create detailed specification
   - Design UI mockups if needed
   - Plan integration with existing code

3. **Implementation:**
   - Follow coding standards
   - Implement incrementally
   - Test frequently

4. **Testing:**
   - Unit tests
   - Manual testing
   - Edge case validation

5. **Integration:**
   - Code review
   - Documentation updates
   - Merge to main branch

### 🏆 Recommended Implementation Order

**Phase 1: Core Functionality**
1. `showArchiveInfo()` - Easy win, useful for debugging
2. `testArchive()` - Critical for reliability
3. `deleteFileFromArchive()` - Essential file management

**Phase 2: User Experience**
4. `viewArchive()` - Major UX improvement
5. `findInArchive()` - Essential for large archives
6. `mouseDoubleClickEvent()` - Natural interaction

**Phase 3: Advanced Features**
7. `startArchiveWizard()` - Guided creation workflow
8. `repairArchive()` - Advanced functionality
9. `encrypt()`/`decrypt()` - Security features

---

## Contributing

When implementing any of these functions:

1. **Create an issue** describing your implementation plan
2. **Fork the repository** and create a feature branch
3. **Follow the implementation checklist** above
4. **Write comprehensive tests**
5. **Update this document** with implementation details
6. **Submit a pull request** with detailed description

For questions or clarification on any function specification, please open an issue on GitHub.

---

**Last Updated:** [Current Date]  
**Contributors:** NixRar Development Team