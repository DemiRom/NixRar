#ifndef ARCHIVE_H
#define ARCHIVE_H
#include <archive.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qstring.h>


namespace dd::nixrar {

class File {
public:
    QString filename;
    qsizetype size;
    QString type;
    QDateTime modified;
    QByteArray data;
};

class Archive {
public:
    explicit Archive(const QString &path);
    ~Archive() = default;

    bool open();
    bool isOpen() const;

    QString getFilename(int idx);
    QString getFileType(int idx);
    qsizetype getFileSize(int idx);
    QDateTime getFileModifiedDate(int idx);

    QString getArchivePath();

    void encrypt(QString password);
    void decrypt(QString password);

    [[nodiscard]] bool extractFile(int idx, const QString &pathToExtractTo) const;
    [[nodiscard]] bool extractAll(const QString &pathToExtractTo) const;
    [[nodiscard]] qsizetype getFileCount() const;
    
    bool addFile(const QString &filePath, const QString &archivePath = "");
    bool addFiles(const QStringList &filePaths, const QString &archivePath = "");
    bool createNewArchive(const QString &archivePath);

private:
    QString archiveDiskPath;
    QVector<File> files;
    bool opened = false;

    static int copyData(archive* ar, archive* aw);
};

} // nixrar
// dd

#endif //ARCHIVE_H
