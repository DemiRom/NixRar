#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QPushButton>
#include <QTreeView>
#include <QtCore/qdir.h>

namespace dd::nixrar::ui {
    QT_BEGIN_NAMESPACE

    namespace Ui {
        class FileExplorer;
    }

    QT_END_NAMESPACE

    class FileExplorer : public QTreeView {
        Q_OBJECT

    public:
        explicit FileExplorer(QWidget *parent = nullptr);

        ~FileExplorer() override;

        void setPath(const QDir &path);

        QDir getPath();

    public slots:
        void pathChanged(const QString &path);

    signals:
        void filesDropped(const QStringList &filePaths);

        void directoryChanged(const QString &directory);
        void fileOpened(const QString &filename);

    protected:
        void mouseDoubleClickEvent(QMouseEvent *event) override;

        void enterEvent(QEnterEvent *event) override;

        void leaveEvent(QEvent *event) override;

        void moveEvent(QMoveEvent *event) override;

        void dragEnterEvent(QDragEnterEvent *event) override;

        void dragLeaveEvent(QDragLeaveEvent *event) override;

        void dropEvent(QDropEvent *event) override;

        void dragMoveEvent(QDragMoveEvent *event) override;

    private:
        bool isDragActive = false;

        QDir currentPath;
    };
} // dd::nixrar::ui

#endif //FILEEXPLORER_H
