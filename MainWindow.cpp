#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <archive.h>
#include <archive_entry.h>
#include <iostream>
#include <QMessageBox>
#include <QFileDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QDragMoveEvent>
#include <QMimeData>
#include <QProgressDialog>
#include <QClipboard>

#include "FileExplorer.h"
#include "FileExplorerModel.h"

#include "AboutDialog.h"
#include "PasswordDialog.h"
#include "ui_PasswordDialog.h"

namespace dd::nixrar {
    MainWindow::MainWindow(QStringList args, QWidget *parent, Qt::WindowFlags flags) : QMainWindow(parent),
        ui(new Ui_MainWindow) {
        ui->setupUi(this);

        setAcceptDrops(true);

        // Add stuff that we cannot in Designer here
        this->directoryUpButton = new QPushButton("", this);
        this->directoryUpButton->setIcon(QIcon(":/Icons/icons/up-arrow.png"));
        this->ui->navigationBar->addWidget(directoryUpButton);

        this->directoryLineEdit = new QLineEdit(this);
        this->directoryLineEdit->setPlaceholderText("/");
        this->directoryLineEdit->setEnabled(false);
        this->ui->navigationBar->addWidget(directoryLineEdit);

        this->fileExplorer = new ui::FileExplorer(this);
        this->ui->fileExplorerContainer->addWidget(this->fileExplorer);

        //Set up the model
        this->fileExplorerModel = new FileExplorerModel(this);
        this->fileExplorer->setModel(this->fileExplorerModel);

        connect(this->ui->actionOpen, SIGNAL(triggered()), this, SLOT(openArchiveWithDialog()));
        connect(this->ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
        connect(this->ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));

        connect(this->ui->actionExtractTo, SIGNAL(triggered()), this, SLOT(extractTo()));
        connect(this->ui->actionAddFile, SIGNAL(triggered()), this, SLOT(addFile()));
        connect(this->ui->actionTest, SIGNAL(triggered()), this, SLOT(testArchive()));
        connect(this->ui->actionView, SIGNAL(triggered()), this, SLOT(viewArchive()));
        connect(this->ui->actionDelete, SIGNAL(triggered()), this, SLOT(deleteFileFromArchive()));
        connect(this->ui->actionFind, SIGNAL(triggered()), this, SLOT(findInArchive()));
        connect(this->ui->actionWizard, SIGNAL(triggered()), this, SLOT(startArchiveWizard()));
        connect(this->ui->actionInfo, SIGNAL(triggered()), this, SLOT(showArchiveInfo()));
        connect(this->ui->actionRepair, SIGNAL(triggered()), this, SLOT(repairArchive()));
        connect(this->ui->actionRepair_Archive, SIGNAL(triggered()), this, SLOT(repairArchive()));
        connect(this->ui->actionSave_Archive_Copy_As, SIGNAL(triggered()), this, SLOT(saveArchiveCopyAs()));
        connect(this->ui->actionChange_Drive, SIGNAL(triggered()), this, SLOT(changeDrive()));
        connect(this->ui->actionSet_Default_Password, SIGNAL(triggered()), this, SLOT(setDefaultPassword()));
        connect(this->ui->actionCopy_Files_to_Clipboard, SIGNAL(triggered()), this, SLOT(copyFilesToClipboard()));
        connect(this->ui->actionPaste_Files_from_Clipboard, SIGNAL(triggered()), this, SLOT(pasteFilesFromClipboard()));
        connect(this->ui->actionCopy_Full_Names_to_Clipboard, SIGNAL(triggered()), this,
                SLOT(copyFullNamesToClipboard()));
        connect(this->ui->actionSelect_All, SIGNAL(triggered()), this, SLOT(selectAll()));
        connect(this->ui->actionSelect_Group, SIGNAL(triggered()), this, SLOT(selectGroup()));
        connect(this->ui->actionDeselect_Group, SIGNAL(triggered()), this, SLOT(deselectGroup()));
        connect(this->ui->actionInvert_Selection, SIGNAL(triggered()), this, SLOT(invertSelection()));
        connect(this->ui->actionExtract_to_Specified_Folder, SIGNAL(triggered()), this,
                SLOT(extractToSpecifiedFolder()));
        connect(this->ui->actionView_File, SIGNAL(triggered()), this, SLOT(viewFile()));
        connect(this->ui->actionDelete_File, SIGNAL(triggered()), this, SLOT(deleteFile()));
        connect(this->ui->actionRename_File, SIGNAL(triggered()), this, SLOT(renameFile()));
        connect(this->ui->actionPrint_File, SIGNAL(triggered()), this, SLOT(printFile()));
        connect(this->ui->actionExtract_Without_Confirmation, SIGNAL(triggered()), this,
                SLOT(extractWithoutConfirmation()));
        connect(this->ui->actionProtect_Archive_from_Damage, SIGNAL(triggered()), this,
                SLOT(protectArchiveFromDamage()));
        connect(this->ui->actionLock_Archive, SIGNAL(triggered()), this, SLOT(lockArchive()));
        connect(this->ui->actionScan_Archive_for_Viruses, SIGNAL(triggered()), this, SLOT(scanArchiveForViruses()));
        connect(this->ui->actionConvert_Archive_s, SIGNAL(triggered()), this, SLOT(convertArchives()));
        connect(this->ui->actionConvert_Archive_to_SFX, SIGNAL(triggered()), this, SLOT(convertArchiveToSFX()));
        connect(this->ui->actionFind_Files, SIGNAL(triggered()), this, SLOT(findFiles()));
        connect(this->ui->actionShow_Information, SIGNAL(triggered()), this, SLOT(showInformation()));
        connect(this->ui->actionGenerate_Report, SIGNAL(triggered()), this, SLOT(generateReport()));
        connect(this->ui->actionBenchmark, SIGNAL(triggered()), this, SLOT(benchmark()));
        connect(this->ui->actionAdd_files_to_archive, SIGNAL(triggered()), this, SLOT(addFilesToArchive()));
        connect(this->ui->actionAdd_to_Favourites, SIGNAL(triggered()), this, SLOT(addToFavourites()));
        connect(this->ui->actionOrganize_Favourites, SIGNAL(triggered()), this, SLOT(organizeFavourites()));
        connect(this->ui->actionSettings, SIGNAL(triggered()), this, SLOT(settings()));
        connect(this->ui->actionImport_and_Export, SIGNAL(triggered()), this, SLOT(importAndExport()));
        connect(this->ui->actionClear_History, SIGNAL(triggered()), this, SLOT(clearHistory()));
        connect(this->ui->actionFlat_Folders_View, SIGNAL(triggered()), this, SLOT(flatFoldersView()));
        connect(this->ui->actionList_View, SIGNAL(triggered()), this, SLOT(listView()));
        connect(this->ui->actionDetails, SIGNAL(triggered()), this, SLOT(details()));
        connect(this->ui->actionShow_Disk_Folders, SIGNAL(triggered()), this, SLOT(showDiskFolders()));
        connect(this->ui->actionShow_Archive_Folders, SIGNAL(triggered()), this, SLOT(showArchiveFolders()));
        connect(this->ui->actionOrganize_Themes, SIGNAL(triggered()), this, SLOT(organizeThemes()));
        connect(this->ui->actionGet_More_Themes, SIGNAL(triggered()), this, SLOT(getMoreThemes()));
        connect(this->ui->actionThemeDefault, SIGNAL(triggered()), this, SLOT(themeDefault()));
        connect(this->ui->actionSave_Current, SIGNAL(triggered()), this, SLOT(saveCurrent()));
        connect(this->ui->actionEncodingHelp, SIGNAL(triggered()), this, SLOT(encodingHelp()));
        connect(this->ui->actionEncodingDefault, SIGNAL(triggered()), this, SLOT(encodingDefault()));
        connect(this->ui->actionView_Log, SIGNAL(triggered()), this, SLOT(viewLog()));
        connect(this->ui->actionClear_Log, SIGNAL(triggered()), this, SLOT(clearLog()));
        connect(this->ui->actionHelp_Topics, SIGNAL(triggered()), this, SLOT(helpTopics()));
        connect(this->ui->actionNixRAR_GithubPage, SIGNAL(triggered()), this, SLOT(goToNixRarGithubPage()));

        connect(this->fileExplorer, &ui::FileExplorer::filesDropped, this, &MainWindow::addDroppedFiles);
        connect(this->archive, &Archive::needPassword, this, &MainWindow::getPasswordFromUser);
        if (!args.empty()) {
            // Open the archive the application was opened with
            openArchiveInternal(args[0]);
        } else {
            // Open a blank archive to work with
            const auto currentTimeISOString = QDateTime::currentDateTime().toString(Qt::ISODate);
            const auto filePath = QDir::temp().filePath("archive_%1.zip").arg(currentTimeISOString);
#ifdef QT_DEBUG
            qDebug() << "Temporary Archive File Path: " << filePath;
#endif
            openArchiveInternal(filePath);
        }
    }

    MainWindow::~MainWindow() {
        delete ui;
    }

    void MainWindow::openArchiveInternal(const QString &filename) {
        delete this->archive; //FIXME: This may cause issues if the pointer comes from the stack. This should be fixed

        this->archive = new Archive(filename); //TODO Check the args
        this->archive->open();

        if (!this->archive->open()) {
            //TODO There has been a massive problem because anytime a new object of type Archive is created, it either opens if it exists or creates a new one with the file name
            QMessageBox::warning(this, tr("Archive Error"), tr("Could not open archive!"));
            this->close();
        }

        if (this->fileExplorerModel == nullptr) {
            this->fileExplorerModel = new FileExplorerModel(this);
        }

        this->fileExplorerModel->setArchive(this->archive);

        this->directoryLineEdit->setText(this->archive->getArchivePath());
    }

    void MainWindow::openArchiveWithDialog() {
        const auto fileName = QFileDialog::getOpenFileName(this,
                                                           tr("Open Archive"), QDir::homePath(),
                                                           tr(
                                                               "Archive Files (*.rar *.zip *.cab *.arj *.lzh *.ace *.tar *.gzip *.uue *.bz2 *.tar *.gz)"));

        if (fileName.isEmpty()) {
            return;
        }

        openArchiveInternal(fileName);
    }

    void MainWindow::about() {
        const auto aboutDialog = new AboutDialog(this);
        aboutDialog->show();
    }

    void MainWindow::extractTo() {
        const auto path = QFileDialog::getExistingDirectory(this,
                                                            tr("Open Archive"), QDir::homePath());

        if (path.isEmpty()) {
            return;
        }

        if (this->archive == nullptr) {
            qDebug() << "Archive is null";
            return;
        }

        if (!this->archive->isOpen()) {
            qDebug() << "Archive is not open";
            return;
        }

        if (!this->archive->extractAll(path)) {
            QMessageBox::warning(this, tr("Archive Error"), tr("Could not extract files!"));
        }
    }

    void MainWindow::addFile() {
        if (this->archive == nullptr || !this->archive->isOpen()) {
            QMessageBox::warning(this, tr("Archive Error"), tr("No archive is currently open!"));
            return;
        }

        const QStringList fileNames = QFileDialog::getOpenFileNames(this,
                                                                    tr("Add Files to Archive"), QDir::homePath(),
                                                                    tr("All Files (*.*)"));

        if (fileNames.isEmpty()) {
            return;
        }

        addDroppedFiles(fileNames);
    }

    void MainWindow::addDroppedFiles(const QStringList &filePaths) {
        if (this->archive == nullptr || !this->archive->isOpen()) {
            QMessageBox::warning(this, tr("Archive Error"), tr("No archive is currently open!"));
            return;
        }

        if (filePaths.isEmpty()) {
            return;
        }

        QProgressDialog progressDialog(tr("Adding files to archive..."), tr("Cancel"), 0,
                                       static_cast<int>(filePaths.size()), this);
        progressDialog.setWindowModality(Qt::WindowModal);
        progressDialog.setMinimumDuration(1000);

        bool success = true;
        for (int i = 0; i < filePaths.size(); ++i) {
            if (progressDialog.wasCanceled()) {
                break;
            }

            progressDialog.setValue(i);
            progressDialog.setLabelText(tr("Adding: %1").arg(QFileInfo(filePaths.at(i)).fileName()));
            QApplication::processEvents();

            if (!this->archive->addFile(filePaths.at(i))) {
                success = false;
                QMessageBox::warning(this, tr("Archive Error"),
                                     tr("Failed to add file: %1").arg(QFileInfo(filePaths.at(i)).fileName()));
            }
        }

        progressDialog.setValue(static_cast<int>(filePaths.size()));
        //FIXME: This sets the progress bar value to the length of the list, need to move this up in the for loop

        if (success && !progressDialog.wasCanceled()) {
            // QMessageBox::information(this, tr("Success"),
            //     tr("Successfully added %1 file(s) to the archive.").arg(filePaths.size()));
            if (this->fileExplorerModel != nullptr) {
                this->fileExplorerModel->setArchive(this->archive);
            }
        }
    }

    void MainWindow::testArchive() {
    }

    void MainWindow::viewArchive() {
    }

    void MainWindow::deleteFileFromArchive() {
    }

    void MainWindow::findInArchive() {
    }

    void MainWindow::startArchiveWizard() {
    }

    void MainWindow::showArchiveInfo() {
    }

    void MainWindow::repairArchive() {
        if (this->archive == nullptr) {
            return;
        }

        if (!this->archive->isOpen()) {
            return;
        }

        //TODO: Progress dialog and Archive class implementation to repair archives.
    }

    void MainWindow::saveArchiveCopyAs() {
        assert(this->archive != nullptr);
        if (!this->archive->isOpen()) {
            return;
        }

        const auto fileName = QFileDialog::getSaveFileName(this,
                                                           tr("Save Archive"), QDir::homePath(),
                                                           tr(
                                                               "Archive Files (*.rar *.zip *.cab *.arj *.lzh *.ace *.tar *.gzip *.uue *.bz2 *.tar *.gz)",
                                                               "*.zip"));
        //TODO Set the default file extension to the archive type

        assert(!fileName.isEmpty());

        if (!QFile::copy(this->archive->getArchivePath(), fileName)) {
            QMessageBox::warning(this, tr("Error"), tr("Error Saving Archive!"));
        }

        openArchiveInternal(fileName);
    }

    void MainWindow::changeDrive() {
    }

    void MainWindow::setDefaultPassword() {
        if (this->archive == nullptr) {
            return;
        }

        PasswordDialog dialog(this);

        if (dialog.exec() == QDialog::Accepted) {
            this->archive->setPassword(dialog.getPassword());
        }
    }

    void MainWindow::copyFilesToClipboard() {
    }

    void MainWindow::pasteFilesFromClipboard() {
    }

    void MainWindow::copyFullNamesToClipboard() const {
        auto selection = this->fileExplorer->selectionModel()->selectedRows();

        if (selection.isEmpty()) {
            statusBar()->showMessage("No files selected", 2000);

            return;
        }

        QStringList fileNames;
        for (const auto &index: selection) {
            QString fileName = fileExplorerModel->data(index, Qt::DisplayRole).toString();

            fileNames << fileName;
        }

        const QString text = fileNames.join('\n');
        QApplication::clipboard()->setText(text);

        statusBar()->showMessage(tr("Copied %1 file name(s) to clipboard").arg(fileNames.size(), 3000));
    }

    void MainWindow::selectAll() {
        if (!this->archive || archive->getFileCount() == 0) {
            statusBar()->showMessage("No files in archive", 2000);
            return;
        }

        if (!this->fileExplorer || !this->fileExplorerModel) {
#ifdef QT_DEBUG
            qDebug() << QString("[ERROR] %1:%2 FileExplorer or FileExplorerModel aren't constructed!").arg(__FILE__).
                    arg(__LINE__);
#endif
            return; //TODO Maybe show an error dialog here because this shouldn't happen;
        }

        auto *selectionModel = this->fileExplorer->selectionModel();
        selectionModel->clearSelection();

        // Select each row manually
        for (int row = 0; row < fileExplorerModel->rowCount(); ++row) {
            QModelIndex index = fileExplorerModel->index(row, 0);
            if (index.isValid()) {
                selectionModel->select(index, QItemSelectionModel::Select |
                                              QItemSelectionModel::Rows);
            }
        }

        statusBar()->showMessage(
            QString("Selected all %1 files").arg(fileExplorerModel->rowCount()),
            3000
        );
    }

    void MainWindow::selectGroup() {
        //TODO: I'm not sure what this should actually do...
        //TODO: Test WinRar to see what this functionality actually does.
    }

    void MainWindow::deselectGroup() {
        this->fileExplorer->selectionModel()->clearSelection();
    }

    void MainWindow::invertSelection() {
        if (!fileExplorer || !fileExplorerModel || !fileExplorer->selectionModel()) {
            return;
        }

        QItemSelectionModel* selectionModel = fileExplorer->selectionModel();

        // Store what's currently selected
        QItemSelection currentSelection = selectionModel->selection();

        // Select everything
        fileExplorer->selectAll();

        // Deselect what was previously selected (leaving the inverse)
        selectionModel->select(currentSelection, QItemSelectionModel::Deselect);

        // Show feedback
        int count = selectionModel->selectedRows().count();
        statusBar()->showMessage(QString("Inverted selection: %1 files").arg(count),
    3000);
    }

    void MainWindow::extractToSpecifiedFolder() {
    }

    void MainWindow::viewFile() {
    }

    void MainWindow::deleteFile() {
    }

    void MainWindow::renameFile() {
    }

    void MainWindow::printFile() {
    }

    void MainWindow::extractWithoutConfirmation() {
    }

    void MainWindow::protectArchiveFromDamage() {
    }

    void MainWindow::lockArchive() {
    }

    void MainWindow::scanArchiveForViruses() {
    }

    void MainWindow::convertArchives() {
    }

    void MainWindow::convertArchiveToSFX() {
    }

    void MainWindow::findFiles() {
    }

    void MainWindow::showInformation() {
    }

    void MainWindow::generateReport() {
    }

    void MainWindow::benchmark() {
    }

    void MainWindow::addFilesToArchive() {
    }

    void MainWindow::addToFavourites() {
    }

    void MainWindow::organizeFavourites() {
    }

    void MainWindow::settings() {
    }

    void MainWindow::importAndExport() {
    }

    void MainWindow::clearHistory() {
    }

    void MainWindow::flatFoldersView() {
    }

    void MainWindow::listView() {
    }

    void MainWindow::details() {
    }

    void MainWindow::showDiskFolders() {
    }

    void MainWindow::showArchiveFolders() {
    }

    void MainWindow::organizeThemes() {
    }

    void MainWindow::getMoreThemes() {
    }

    void MainWindow::themeDefault() {
    }

    void MainWindow::saveCurrent() {
    }

    void MainWindow::encodingHelp() {
    }

    void MainWindow::encodingDefault() {
    }

    void MainWindow::viewLog() {
    }

    void MainWindow::clearLog() {
    }

    void MainWindow::helpTopics() {
    }

    void MainWindow::goToNixRarGithubPage() {
    }

    void MainWindow::getPasswordFromUser() {
        if (PasswordDialog dialog(this); dialog.exec() == QDialog::Accepted) {
            this->archive->setPassword(dialog.getPassword());
        }
    }
} // dd::nixrar
