#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QPushButton>
#include <QTreeView>

namespace dd::nixrar::ui {
QT_BEGIN_NAMESPACE
namespace Ui { class FileExplorer; }
QT_END_NAMESPACE

class FileExplorer : public QTreeView {
Q_OBJECT

public:
    explicit FileExplorer(QWidget *parent = nullptr);
    ~FileExplorer() override;

    void updateView();

signals:
    void filesDropped(const QStringList &filePaths);

protected:
void enterEvent(QEnterEvent *event) override;

void leaveEvent(QEvent *event) override;

void moveEvent(QMoveEvent *event) override;

void dragEnterEvent(QDragEnterEvent *event) override;

void dragLeaveEvent(QDragLeaveEvent *event) override;

void dropEvent(QDropEvent *event) override;

void dragMoveEvent(QDragMoveEvent *event) override;

private:
    bool isDragActive = false;
};
} // dd::nixrar::ui

#endif //FILEEXPLORER_H
