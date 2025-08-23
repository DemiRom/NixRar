#ifndef LIBBARCHIVE_ARCHIVE_UTILS_H
#define LIBBARCHIVE_ARCHIVE_UTILS_H

#include <QString>
#include <QtCore/qtypes.h>
#include <type_traits>

namespace libbarchive {

// C++23: Concept for string-like types (simplified for better compatibility)
template<typename T>
concept StringLike = std::is_same_v<std::remove_cv_t<T>, QString> || 
                     std::is_convertible_v<T, QString>;

class ArchiveUtils {
public:
    // C++23: Format file size with noexcept for performance
    [[nodiscard]] static QString formatFileSize(qsizetype bytes) noexcept;

    // C++23: Use concepts for better template constraints  
    template<StringLike T>
    [[nodiscard]] static QString sanitizePath(const T& path) noexcept {
        QString sanitized = QString(path);
        return sanitizePath(sanitized);  // Delegate to the implementation
    }

    // C++23: Template-based file extension extraction
    template<StringLike T>
    [[nodiscard]] static QString getFileExtension(const T& filename) noexcept {
        QString fname = QString(filename);
        return getFileExtension(fname);  // Delegate to the implementation
    }

    // C++23: Concept-constrained archive format validation
    template<StringLike T>
    [[nodiscard]] static bool isArchiveExtension(const T& extension) noexcept {
        QString ext = QString(extension);
        return isArchiveExtension(ext);  // Delegate to the implementation
    }

    // C++23: Safe filename generation with templates
    template<StringLike T>
    [[nodiscard]] static QString generateSafeFilename(const T& originalName) noexcept {
        QString name = QString(originalName);
        return generateSafeFilename(name);  // Delegate to the implementation
    }

    // Non-template implementations
    [[nodiscard]] static QString sanitizePath(const QString& path) noexcept;
    [[nodiscard]] static QString getFileExtension(const QString& filename) noexcept;
    [[nodiscard]] static bool isArchiveExtension(const QString& extension) noexcept;
    [[nodiscard]] static QString generateSafeFilename(const QString& originalName) noexcept;

private:
    // C++23: Delete all constructors for pure static class
    ArchiveUtils() = delete;
    ~ArchiveUtils() = delete;
    ArchiveUtils(const ArchiveUtils&) = delete;
    ArchiveUtils& operator=(const ArchiveUtils&) = delete;
    ArchiveUtils(ArchiveUtils&&) = delete;
    ArchiveUtils& operator=(ArchiveUtils&&) = delete;
};

} // namespace dd::nixrar::barchive

#endif // LIBBARCHIVE_ARCHIVE_UTILS_H