#include "Archive.h"
#include <archive.h>
#include <archive_entry.h>
#include <QMessageBox>
#include <QtCore/qdir.h>
#include <QFile>
#include <QFileInfo>
#include <QIODevice>

namespace dd::nixrar {
    Archive::Archive(const QString &path) {
        archiveDiskPath = path;
    }

    bool Archive::open() {
        archive_entry *entry;
        archive *a = archive_read_new();
        archive_read_support_filter_all(a);
        archive_read_support_format_all(a);
        int r = archive_read_open_filename(a, this->archiveDiskPath.toStdString().c_str(), 10240);

        if (r != ARCHIVE_OK) {
            QMessageBox::critical(nullptr, "Error", archive_error_string(a));
            return false;
        }

        while ((r = archive_read_next_header(a, &entry)) == ARCHIVE_OK) {
            if (r == ARCHIVE_EOF)
                break;

            this->files.append({
                QString::fromStdString(archive_entry_pathname(entry)),
                archive_entry_size(entry),
                QString::fromStdString(archive_entry_pathname(entry)).split('.').last(),
                QDateTime::fromSecsSinceEpoch(archive_entry_mtime(entry))
            });
        }

        archive_read_close(a);
        archive_read_free(a);

        this->opened = true;

        return true;
    }

    bool Archive::isOpen() const {
        return this->opened;
    }

    QString Archive::getFilename(const int idx) {
        if (idx < 0 || idx >= this->files.size())
            return "";
        return this->files[idx].filename;
    }

    QString Archive::getFileType(const int idx) {
        if (idx < 0 || idx >= this->files.size())
            return "";

        return this->files[idx].type;
    }

    qsizetype Archive::getFileSize(const int idx) {
        if (idx < 0 || idx >= this->files.size())
            return 0;
        return this->files[idx].size;
    }

    QDateTime Archive::getFileModifiedDate(const int idx) {
        if (idx < 0 || idx >= this->files.size())
            return {};
        return this->files[idx].modified;
    }

    QString Archive::getArchivePath() {
        return this->archiveDiskPath;
    }

    void Archive::encrypt(QString password) {

    }

    bool Archive::extractFile(const int idx, const QString &pathToExtractTo) const {
        if (const QDir dir(pathToExtractTo); !dir.exists())
            return false;

        if (idx < 0 || idx >= this->files.size())
            return false;

        archive *a = archive_read_new();
        archive *ext = archive_write_disk_new();
        archive_entry *entry;
        int r;

        archive_read_support_filter_all(a);
        archive_read_support_format_all(a);

        archive_write_disk_set_options(ext, ARCHIVE_EXTRACT_TIME | ARCHIVE_EXTRACT_PERM);
        archive_write_disk_set_standard_lookup(ext);

        if ((r = archive_read_open_filename(a, this->archiveDiskPath.toStdString().c_str(), 10240))) {
            QMessageBox::warning(nullptr, "Archive Read Error", archive_error_string(a));
            return false;
        }

        while ((r = archive_read_next_header(a, &entry)) == ARCHIVE_OK) {
            const char* currentFile = archive_entry_pathname(entry);
            auto outputFilePath = QDir::cleanPath(pathToExtractTo + "/" + currentFile);
            archive_entry_set_pathname(entry, outputFilePath.toStdString().c_str());

            r = archive_write_header(ext, entry);
            if (r != ARCHIVE_OK) {
                QMessageBox::warning(nullptr, "Disk Write Error",archive_error_string(ext));
            }
            else {
                Archive::copyData(a, ext);
                r = archive_write_finish_entry(ext);
                if (r != ARCHIVE_OK) {
                    QMessageBox::warning(nullptr, "Archive Close Error", archive_error_string(ext));
                }
            }
        }

        archive_read_close(a);
        archive_read_free(a);

        archive_write_close(ext);
        archive_write_free(ext);

        return true;
    }

    void Archive::decrypt(QString password) {

    }

    bool Archive::extractAll(const QString &pathToExtractTo) const {
        if (const QDir dir(pathToExtractTo); !dir.exists(pathToExtractTo))
            return false;

        for (int i = 0; i < this->files.size(); ++i) {
            if (!this->extractFile(i, pathToExtractTo))
                return false;
        }

        return true;
    }

    qsizetype Archive::getFileCount() const {
        return this->files.length();
    }

    int Archive::copyData(archive *ar, archive *aw) {
        int r;
        const void *buff;
        size_t size;
#if ARCHIVE_VERSION_NUMBER >= 3000000
        int64_t offset;
#else
            off_t offset;
#endif

        for (;;) {
            r = archive_read_data_block(ar, &buff, &size, &offset);
            if (r == ARCHIVE_EOF)
                return (ARCHIVE_OK);
            if (r != ARCHIVE_OK)
                return (r);
            r = static_cast<int>(archive_write_data_block(aw, buff, size, offset));
            if (r != ARCHIVE_OK) {
                QMessageBox::warning(nullptr, "archive_write_data_block()",archive_error_string(aw));
                return (r);
            }
        }
    }

    bool Archive::addFile(const QString &filePath, const QString &archivePath) {
        QStringList fileList;
        fileList << filePath;
        return addFiles(fileList, archivePath);
    }

    bool Archive::addFiles(const QStringList &filePaths, const QString &archivePath) {
        if (!this->opened) {
            return false;
        }

        archive *input = archive_read_new();
        archive *output = archive_write_new();
        archive_entry *entry;
        QString tempArchivePath = this->archiveDiskPath + ".tmp";

        archive_read_support_filter_all(input);
        archive_read_support_format_all(input);
        archive_write_set_format_pax_restricted(output);
        archive_write_set_compression_gzip(output);

        if (archive_write_open_filename(output, tempArchivePath.toStdString().c_str()) != ARCHIVE_OK) {
            archive_read_free(input);
            archive_write_free(output);
            return false;
        }

        if (archive_read_open_filename(input, this->archiveDiskPath.toStdString().c_str(), 10240) == ARCHIVE_OK) {
            while (archive_read_next_header(input, &entry) == ARCHIVE_OK) {
                if (archive_write_header(output, entry) == ARCHIVE_OK) {
                    Archive::copyData(input, output);
                    archive_write_finish_entry(output);
                }
            }
            archive_read_close(input);
        }
        archive_read_free(input);

        for (const QString &filePath : filePaths) {
            QFileInfo fileInfo(filePath);
            if (!fileInfo.exists() || !fileInfo.isFile()) {
                continue;
            }

            QFile file(filePath);
            if (!file.open(QIODevice::ReadOnly)) {
                continue;
            }

            entry = archive_entry_new();
            QString entryPath = archivePath.isEmpty() ? fileInfo.fileName() : archivePath + "/" + fileInfo.fileName();
            archive_entry_set_pathname(entry, entryPath.toStdString().c_str());
            archive_entry_set_size(entry, fileInfo.size());
            archive_entry_set_filetype(entry, AE_IFREG);
            archive_entry_set_perm(entry, 0644);
            archive_entry_set_mtime(entry, fileInfo.lastModified().toSecsSinceEpoch(), 0);

            if (archive_write_header(output, entry) == ARCHIVE_OK) {
                QByteArray data = file.readAll();
                archive_write_data(output, data.constData(), data.size());
                archive_write_finish_entry(output);

                File newFile;
                newFile.filename = entryPath;
                newFile.size = fileInfo.size();
                newFile.type = fileInfo.suffix();
                newFile.modified = fileInfo.lastModified();
                this->files.append(newFile);
            }

            archive_entry_free(entry);
            file.close();
        }

        archive_write_close(output);
        archive_write_free(output);

        QFile::remove(this->archiveDiskPath);
        QFile::rename(tempArchivePath, this->archiveDiskPath);

        return true;
    }

    bool Archive::createNewArchive(const QString &archivePath) {
        this->archiveDiskPath = archivePath;
        this->files.clear();
        
        archive *a = archive_write_new();
        archive_write_set_format_pax_restricted(a);
        archive_write_set_compression_gzip(a);
        
        if (archive_write_open_filename(a, archivePath.toStdString().c_str()) != ARCHIVE_OK) {
            archive_write_free(a);
            return false;
        }
        
        archive_write_close(a);
        archive_write_free(a);
        
        this->opened = true;
        return true;
    }
} // nixrar
// dd
