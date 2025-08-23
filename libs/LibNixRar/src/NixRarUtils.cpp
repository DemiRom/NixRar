#include "libbarchive/archive_utils.h"
#include <QFileInfo>
#include <QRegularExpression>

namespace libbarchive {

QString ArchiveUtils::formatFileSize(qsizetype bytes) noexcept {
    const QStringList units = {"B", "KB", "MB", "GB", "TB"};
    double size = static_cast<double>(bytes);
    int unitIndex = 0;

    while (size >= 1024.0 && unitIndex < units.size() - 1) {
        size /= 1024.0;
        ++unitIndex;
    }

    if (unitIndex == 0) {
        return QString("%1 %2").arg(static_cast<qsizetype>(size)).arg(units[unitIndex]);
    } else {
        return QString("%1 %2").arg(size, 0, 'f', 1).arg(units[unitIndex]);
    }
}

QString ArchiveUtils::sanitizePath(const QString& path) noexcept {
    QString sanitized = path;
    
    // Remove any dangerous path components
    sanitized.replace("../", "");
    sanitized.replace("..\\", "");
    
    // Replace backslashes with forward slashes for consistency
    sanitized.replace("\\", "/");
    
    // Remove leading slashes to prevent absolute paths
    while (sanitized.startsWith("/")) {
        sanitized.remove(0, 1);
    }
    
    // Remove multiple consecutive slashes
    QRegularExpression multiSlash("/+");
    sanitized.replace(multiSlash, "/");
    
    return sanitized;
}

QString ArchiveUtils::getFileExtension(const QString& filename) noexcept {
    QFileInfo fileInfo(filename);
    return fileInfo.suffix().toLower();
}

bool ArchiveUtils::isArchiveExtension(const QString& extension) noexcept {
    const QStringList archiveExtensions = {
        "zip", "rar", "7z", "tar", "gz", "bz2", "xz", "cab", 
        "arj", "lzh", "ace", "uue", "z", "lz", "lzma"
    };
    
    return archiveExtensions.contains(extension.toLower());
}

QString ArchiveUtils::generateSafeFilename(const QString& originalName) noexcept {
    QString safeName = originalName;
    
    // Replace unsafe characters with underscores
    QRegularExpression unsafeChars("[<>:\"/\\\\|?*]");
    safeName.replace(unsafeChars, "_");
    
    // Remove control characters
    QRegularExpression controlChars("[\\x00-\\x1F\\x7F]");
    safeName.replace(controlChars, "");
    
    // Limit length to reasonable size
    if (safeName.length() > 255) {
        safeName = safeName.left(252) + "...";
    }
    
    // Ensure it's not empty
    if (safeName.isEmpty()) {
        safeName = "unnamed_file";
    }
    
    return safeName;
}

} // namespace dd::nixrar::barchive