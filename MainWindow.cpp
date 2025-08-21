#include "MainWindow.h"
#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <archive.h>
#include <archive_entry.h>
#include <iostream>
#include <QMessageBox>
#include <QFileDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QMimeData>
#include <QProgressDialog>
#include <QApplication>
#include <QFileInfo>

#include "FileExplorer.h"
#include "FileExplorerModel.h"

namespace dd::nixrar {
MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags) :
    QMainWindow(parent), ui(new Ui_MainWindow) {
    ui->setupUi(this);

    setAcceptDrops(true);

    // Add stuff that we cannot in Designer here
    this->directoryUpButton = new QPushButton("", this);
    this->directoryUpButton->setIcon(QIcon(":/Icons/icons/up-arrow.png"));
    this->ui->navigationBar->addWidget(directoryUpButton);

    this->directoryLineEdit = new QLineEdit(this);
    this->directoryLineEdit->setPlaceholderText("/");
    this->ui->navigationBar->addWidget(directoryLineEdit);

    this->fileExplorer = new ui::FileExplorer(this);
    this->ui->fileExplorerContainer->addWidget(this->fileExplorer);

    //Set up the model
    this->fileExplorerModel = new FileExplorerModel(this);
    this->fileExplorer->setModel(this->fileExplorerModel);

    connect(this->ui->actionOpen, SIGNAL(triggered()), this, SLOT(openArchive()));
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
    
    connect(this->fileExplorer, &ui::FileExplorer::filesDropped, this, &MainWindow::addDroppedFiles);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::openArchive() {
    const auto fileName = QFileDialog::getOpenFileName(this,
         tr("Open Archive"), QDir::homePath(), tr("Archive Files (*.rar *.zip *.cab *.arj *.lzh *.ace *.tar *.gzip *.uue *.bz2 *.tar *.gz)"));

    if (fileName.isEmpty()) {
        return;
    }

    this->archive = new Archive(fileName);

    if (!this->archive->open()) {
        QMessageBox::warning(this, tr("Archive Error"), tr("Could not open archive!"));
    }

    if (this->fileExplorerModel != nullptr)
        this->fileExplorerModel->setArchive(this->archive);
    else {
        this->fileExplorerModel = new FileExplorerModel(this);
        this->fileExplorerModel->setArchive(this->archive);
    }
}

void MainWindow::about() {
    QMessageBox::about(this, tr("About NixRar"), tr("NixRar v0.0.1"));
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
         tr("Add Files to Archive"), QDir::homePath(), tr("All Files (*.*)"));

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

    QProgressDialog progressDialog(tr("Adding files to archive..."), tr("Cancel"), 0, filePaths.size(), this);
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

    progressDialog.setValue(filePaths.size());

    if (success && !progressDialog.wasCanceled()) {
        QMessageBox::information(this, tr("Success"), 
            tr("Successfully added %1 file(s) to the archive.").arg(filePaths.size()));
    }

    if (this->fileExplorerModel != nullptr) {
        this->fileExplorerModel->setArchive(this->archive);
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
}

} // dd::nixrar
