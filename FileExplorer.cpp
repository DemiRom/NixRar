#include "FileExplorer.h"

#include <QDragEnterEvent>
#include <QMimeData>
#include <QFileInfo>
#include <QUrl>

namespace dd::nixrar::ui {
    FileExplorer::FileExplorer(QWidget *parent) : QTreeView(parent) {
        setAcceptDrops(true);
        setDropIndicatorShown(true);
    }

    void FileExplorer::mouseDoubleClickEvent(QMouseEvent *event) {
        auto selectedItems = this->selectionModel()->selectedRows();

        for (auto item : selectedItems) {
            // Get the filename from the model
            QString filename = this->model()->data(item.sibling(item.row(), 1), Qt::DisplayRole).toString();

            // Check if it's a directory (size == 0)
            qint64 fileSize = this->model()->data(item.sibling(item.row(), 2), Qt::DisplayRole).toLongLong();

            if (fileSize == 0) {
#ifdef QT_DEBUG
                qDebug() << "Directory!" << filename;
#endif
                emit directoryChanged(filename);
                this->currentPath.cd(filename);
                qDebug() << "CurrentPath!" << this->currentPath ;
            } else {
#ifdef QT_DEBUG
                qDebug() << "File!" << filename;
#endif
                emit fileOpened(filename);
            }
        }

        QTreeView::mouseDoubleClickEvent(event);
    }

    void FileExplorer::enterEvent(QEnterEvent *event) {
        QTreeView::enterEvent(event);
    }

    void FileExplorer::leaveEvent(QEvent *event) {
        QTreeView::leaveEvent(event);
    }

    void FileExplorer::moveEvent(QMoveEvent *event) {
        QTreeView::moveEvent(event);
    }

    void FileExplorer::dragEnterEvent(QDragEnterEvent *event) {
        if (event->mimeData()->hasUrls()) {
            bool hasValidFiles = false;
            const QList<QUrl> urls = event->mimeData()->urls();
            
            for (const QUrl &url : urls) {
                if (url.isLocalFile()) {
                    QFileInfo fileInfo(url.toLocalFile());
                    if (fileInfo.exists() && fileInfo.isFile()) {
                        hasValidFiles = true;
                        break;
                    }
                }
            }
            
            if (hasValidFiles) {
                event->setDropAction(Qt::CopyAction);
                event->acceptProposedAction();

                if (!isDragActive) {
                    isDragActive = true;
                    setStyleSheet("QTreeView { border: 2px dashed #0078d4; background-color: rgba(0, 120, 212, 0.1); }");
                }
                event->accept();
                return;
            }
        }
        
        event->ignore();
    }

    void FileExplorer::dragLeaveEvent(QDragLeaveEvent *event) {
        if (isDragActive) {
            isDragActive = false;
            setStyleSheet("");
        }
        event->accept();
    }

    void FileExplorer::dropEvent(QDropEvent *event) {
        const QMimeData *mimeData = event->mimeData();
        
        if (mimeData->hasUrls()) {
            QStringList filePaths;
            const QList<QUrl> urls = mimeData->urls();
            
            for (const QUrl &url : urls) {
                if (url.isLocalFile()) {
                    QString filePath = url.toLocalFile();
                    QFileInfo fileInfo(filePath);
                    if (fileInfo.exists() && fileInfo.isFile()) {
                        filePaths << filePath;
                    }
                }
            }
            
            if (!filePaths.isEmpty()) {
                emit filesDropped(filePaths);
            }
        }
        
        if (isDragActive) {
            isDragActive = false;
            setStyleSheet("");
        }
        
        event->accept();
    }

    void FileExplorer::dragMoveEvent(QDragMoveEvent *event) {
        if (event->mimeData()->hasUrls()) {
            event->setDropAction(Qt::CopyAction);
            event->accept();
        } else {
            event->ignore();
        }
    }

    FileExplorer::~FileExplorer() = default;

    void FileExplorer::setPath(const QDir &path) {
        this->currentPath = path;
    }

    QDir FileExplorer::getPath() {
        return this->currentPath;
    }

    void FileExplorer::pathChanged(const QString &path) {
        this->currentPath = path;
    }
} // dd::nixrar::ui
