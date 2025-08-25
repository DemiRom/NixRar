#include "FileExplorerModel.h"

#include <QtGui/QIcon>

namespace dd::nixrar {
    FileExplorerModel::FileExplorerModel(QObject *parent) {
        this->setParent(parent);
    }

    int FileExplorerModel::rowCount(const QModelIndex &parent) const {
        return this->rowCount();
    }

    int FileExplorerModel::rowCount() const {
        if (this->archive == nullptr)
            return 0;

        return static_cast<int>(this->archive->getFileCount());
    }

    int FileExplorerModel::columnCount(const QModelIndex &parent) const {
        return 4;
    }

    QVariant FileExplorerModel::data(const QModelIndex &index, int role) const {
        if (!index.isValid()) {
            return {};
        }

        if (this->archive == nullptr) {
            return {};
        }

        switch (index.column()) {
            case 0:
                if (role == Qt::DecorationRole) {
                    if (archive->getFileSize(index.row()) == 0) {
                        return QIcon(":/Icons/icons/folders.png");
                    }
                    return {};
                }
                if (role == Qt::DisplayRole) {
                    return {};
                }
            case 1:
                if (role == Qt::DisplayRole)
                    return archive->getFilename(index.row());
            case 2:
                if (role == Qt::DisplayRole)
                    return archive->getFileSize(index.row());
            case 3:
                if (role == Qt::DisplayRole)
                    return archive->getFileType(index.row());
            case 4:
                if (role == Qt::DisplayRole)
                    return archive->getFileModifiedDate(index.row());
            default:
                return {};
        }
    }

    QVariant FileExplorerModel::headerData(int section, Qt::Orientation orientation, int role) const {
        if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
            switch (section) {
                case 0:
                    return "";
                case 1:
                    return "Path";
                case 2:
                    return "Size";
                case 3:
                    return "Type";
                case 4:
                    return "Modified";
                default:
                    return {};
            }
        }
        return {};
    }

    Qt::ItemFlags FileExplorerModel::flags(const QModelIndex &index) const {
        if (!index.isValid()) {
            return Qt::ItemIsDropEnabled;    // Allow drops in the top-level (no parent)
        }

        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDropEnabled;
    }

    void FileExplorerModel::setArchive(Archive *archive) {
        this->archive = archive;
        beginResetModel();
        endResetModel();
    }
};
