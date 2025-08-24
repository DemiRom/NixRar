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
        explicit MainWindow(QStringList args = QStringList(), QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

        ~MainWindow() override;

    private:
        Ui_MainWindow *ui;
        ui::FileExplorer *fileExplorer;
        FileExplorerModel *fileExplorerModel;

        QPushButton *directoryUpButton;
        QLineEdit *directoryLineEdit;
        Archive *archive{};

        void openArchiveInternal(const QString &filename);

    private slots:
        void openArchiveWithDialog();

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

        void saveArchiveCopyAs();

        void changeDrive();

        void setDefaultPassword();

        void copyFilesToClipboard();

        void pasteFilesFromClipboard();

        void copyFullNamesToClipboard();

        void selectAll();

        void selectGroup();

        void deselectGroup();

        void invertSelection();

        void extractToSpecifiedFolder();

        void viewFile();

        void deleteFile();

        void renameFile();

        void printFile();

        void extractWithoutConfirmation();

        void protectArchiveFromDamage();

        void lockArchive();

        void scanArchiveForViruses();

        void convertArchives();

        void convertArchiveToSFX();

        void findFiles();

        void showInformation();

        void generateReport();

        void benchmark();

        void addFilesToArchive();

        void addToFavourites();

        void organizeFavourites();

        void settings();

        void importAndExport();

        void clearHistory();

        void flatFoldersView();

        void listView();

        void details();

        void showDiskFolders();

        void showArchiveFolders();

        void organizeThemes();

        void getMoreThemes();

        void themeDefault();

        void saveCurrent();

        void encodingHelp();

        void encodingDefault();

        void viewLog();

        void clearLog();

        void helpTopics();

        void goToNixRarGithubPage();

    };

} // dd::nixrar

#endif //MAINWINDOW_H
