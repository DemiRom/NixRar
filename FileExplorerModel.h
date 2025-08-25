#ifndef FILEEXPLORERMODEL_H
#define FILEEXPLORERMODEL_H
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qdatetime.h>

#include "Archive.h"

namespace dd::nixrar {

class FileExplorerModel : public QAbstractTableModel {
public:
    explicit FileExplorerModel(QObject *parent = nullptr);
    [[nodiscard]] int rowCount(const QModelIndex &parent) const override;

    [[nodiscard]] int rowCount() const;

    [[nodiscard]] int columnCount(const QModelIndex &parent) const override;

    [[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;

    [[nodiscard]] QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    [[nodiscard]] Qt::ItemFlags flags(const QModelIndex &index) const override;

    void setArchive(Archive* archive);

private:
    Archive* archive = nullptr;
};

} // nixrar
// dd

#endif //FILEEXPLORERMODEL_H
