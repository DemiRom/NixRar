#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <ui_MainWindow.h>

#include "Archive.h"
#include "FileExplorer.h"
#include "FileExplorerModel.h"

namespace dd::nixrar {
    QT_BEGIN_NAMESPACE

    namespace Ui {
        class MainWindow;
    }

    QT_END_NAMESPACE

    class MainWindow : public QMainWindow {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

        ~MainWindow() override;

    private:
        Ui_MainWindow *ui;
        ui::FileExplorer *fileExplorer;
        FileExplorerModel *fileExplorerModel;

        QPushButton *directoryUpButton;
        QLineEdit *directoryLineEdit;
        Archive *archive{};

    private slots:
        void openArchive();

        void about();

        void extractTo();

        void addFile();

        void addDroppedFiles(const QStringList &filePaths);

        void testArchive();

        void viewArchive();

        void deleteFileFromArchive();

        void findInArchive();

        void startArchiveWizard();

        void showArchiveInfo();

        void repairArchive();
    };

} // dd::nixrar

#endif //MAINWINDOW_H
