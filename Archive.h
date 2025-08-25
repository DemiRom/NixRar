#ifndef ARCHIVE_H
#define ARCHIVE_H
#include <archive.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qstring.h>
#include <QObject>

namespace dd::nixrar {

class File {
public:
    QString filename;
    qsizetype size;
    QString type;
    QDateTime modified;
    QByteArray data;
};

class Archive final : public QObject {
Q_OBJECT
public:
    explicit Archive(const QString &path);

    bool open();
    [[nodiscard]] bool isOpen() const;

    QString getFilename(int idx);
    QString getFileType(int idx);
    qsizetype getFileSize(int idx);
    QDateTime getFileModifiedDate(int idx);

    QString getArchivePath();

    [[nodiscard]] bool extractFile(int idx, const QString &pathToExtractTo) const;
    [[nodiscard]] bool extractAll(const QString &pathToExtractTo) const;
    [[nodiscard]] qsizetype getFileCount() const;
    
    bool addFile(const QString &filePath);
    bool addFiles(const QStringList &filePaths);
    bool createNewEmptyArchive(const QString &archivePath);

    void setPassword(const QString &password);
    [[nodiscard]] QString getPassword() const;

signals:
    void needPassword();

private:
    mutable QByteArray currentPassword;

    QString archivePassword;
    QString archiveDiskPath;

    QVector<File> files;
    bool opened = false;

    bool saveArchiveToDisk();


    static const char* passphraseCallback(archive*, void*);
    const char * getPassphraseForCallback();

};

} // nixrar
// dd

#endif //ARCHIVE_H
