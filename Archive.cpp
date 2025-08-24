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
        if (!QFile::exists(path)) {
            createNewEmptyArchive(path);
        }

        archiveDiskPath = path;
    }

    bool Archive::open() {
        this->files.clear();

        archive_entry *entry;
        archive *a = archive_read_new();
        archive_read_support_filter_all(a);
        archive_read_support_format_all(a);

        if (const int r = archive_read_open_filename(a, this->archiveDiskPath.toStdString().c_str(), 10240);
            r != ARCHIVE_OK) {
            QMessageBox::critical(nullptr, "Error", archive_error_string(a));
            return false;
        }

        while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
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

        if (archive_read_open_filename(a, this->archiveDiskPath.toStdString().c_str(), 10240)) {
            QMessageBox::warning(nullptr, "Archive Read Error", archive_error_string(a));
            return false;
        }

        while ((r = archive_read_next_header(a, &entry)) == ARCHIVE_OK) {
            const char *currentFile = archive_entry_pathname(entry);
            auto outputFilePath = QDir::cleanPath(pathToExtractTo + "/" + currentFile);
            archive_entry_set_pathname(entry, outputFilePath.toStdString().c_str());

            r = archive_write_header(ext, entry);
            if (r != ARCHIVE_OK) {
                QMessageBox::warning(nullptr, "Disk Write Error", archive_error_string(ext));
            } else {
                // Archive::copyData(a, ext); //FIXME
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

    bool Archive::addFile(const QString &filePath) {
        if (!QFile::exists(filePath)) {
            return false;
        }

        QFile file(filePath);
        if (!file.open(QFile::ReadOnly)) {
            return false;
        }
        File f;

        this->files.append({filePath, file.size(), });

        return true;
    }

    bool Archive::addFiles(const QStringList &filePaths, const QString &archivePath) {
        if (!this->opened) {
            return false;
        }

        // archive *input = archive_read_new();
        // archive *output = archive_write_new();
        // archive_entry *entry;
        // QString tempArchivePath = this->archiveDiskPath + ".tmp";
        //
        // archive_read_support_filter_all(input);
        // archive_read_support_format_all(input);
        // archive_write_set_format_pax_restricted(output);
        // // archive_write_set_compression_gzip(output);
        // archive_write_zip_set_compression_lzma(output);
        //
        // if (archive_write_open_filename(output, tempArchivePath.toStdString().c_str()) != ARCHIVE_OK) {
        //     archive_read_free(input);
        //     archive_write_free(output);
        //     return false;
        // }
        //
        // if (archive_read_open_filename(input, this->archiveDiskPath.toStdString().c_str(), 10240) == ARCHIVE_OK) {
        //     while (archive_read_next_header(input, &entry) == ARCHIVE_OK) {
        //         if (archive_write_header(output, entry) == ARCHIVE_OK) {
        //             copyData(input, output);
        //             archive_write_finish_entry(output);
        //         }
        //     }
        //     archive_read_close(input);
        // }
        // archive_read_free(input);
        //
        // for (const QString &filePath: filePaths) {
        //     QFileInfo fileInfo(filePath);
        //     if (!fileInfo.exists() || !fileInfo.isFile()) {
        //         continue;
        //     }
        //
        //     QFile file(filePath);
        //     if (!file.open(QIODevice::ReadOnly)) {
        //         continue;
        //     }
        //
        //     entry = archive_entry_new();
        //     QString entryPath = archivePath.isEmpty() ? fileInfo.fileName() : archivePath + "/" + fileInfo.fileName();
        //     archive_entry_set_pathname(entry, entryPath.toStdString().c_str());
        //     archive_entry_set_size(entry, fileInfo.size());
        //     archive_entry_set_filetype(entry, AE_IFREG);
        //     archive_entry_set_perm(entry, 0644);
        //     archive_entry_set_mtime(entry, fileInfo.lastModified().toSecsSinceEpoch(), 0);
        //
        //     if (archive_write_header(output, entry) == ARCHIVE_OK) {
        //         QByteArray data = file.readAll();
        //         archive_write_data(output, data.constData(), data.size());
        //         archive_write_finish_entry(output);
        //
        //         File newFile;
        //         newFile.filename = entryPath;
        //         newFile.size = fileInfo.size();
        //         newFile.type = fileInfo.suffix();
        //         newFile.modified = fileInfo.lastModified();
        //         this->files.append(newFile);
        //     }
        //
        //     archive_entry_free(entry);
        //     file.close();
        // }
        //
        // archive_write_close(output);
        // archive_write_free(output);
        //
        // QFile::remove(this->archiveDiskPath);
        // QFile::rename(tempArchivePath, this->archiveDiskPath);

        return true;
    }

    bool Archive::createNewEmptyArchive(const QString &archivePath) {
        this->archiveDiskPath = archivePath;
        this->files.clear();

        archive *a = archive_write_new();
        archive_write_set_format_pax_restricted(a);
        // archive_write_set_compression_gzip(a);
        archive_write_zip_set_compression_lzma(a);

        if (archive_write_open_filename(a, archivePath.toStdString().c_str()) != ARCHIVE_OK) {
            archive_write_free(a);
            return false;
        }

        archive_write_close(a);
        archive_write_free(a);

        this->opened = true;
        return true;
    }

    bool Archive::saveArchiveToDisk() {
        const QString tempArchivePath = this->archiveDiskPath + ".tmp";

        archive *a = archive_write_new();
        archive_write_set_format_pax_restricted(a);
        // archive_write_set_compression_gzip(a);
        archive_write_zip_set_compression_lzma(a);

        if (archive_write_open_filename(a, tempArchivePath.toStdString().c_str()) != ARCHIVE_OK) {
            archive_write_free(a);
            return false;
        }

        for (const auto& file: this->files) {
            QFile fileStream(file.filename);
            if (!fileStream.open(QFile::WriteOnly)) {
                return false;
            }
            struct archive_entry *entry = archive_entry_new();
            archive_entry_set_pathname(entry, tempArchivePath.toStdString().c_str());
            archive_entry_set_size(entry, fileStream.size());
            archive_entry_set_filetype(entry, AE_IFREG);

            // Write header first
            if (archive_write_header(a, entry) != ARCHIVE_OK) {
                archive_entry_free(entry);
                return false;
            }

            // Write file data using archive_write_data (not data_block)
            char buffer[8192];
            qint64 bytesRead;
            while ((bytesRead = fileStream.read(buffer, sizeof(buffer))) > 0) {
                if (archive_write_data(a, buffer, bytesRead) < 0) {
                    archive_entry_free(entry);
                    return false;
                }
            }

            archive_entry_free(entry);
        }

        archive_write_close(a);
        archive_write_free(a);

        QFile::copy(tempArchivePath, this->archiveDiskPath);
        QFile::remove(tempArchivePath);

        return true;
    }
} // nixrar
// dd
