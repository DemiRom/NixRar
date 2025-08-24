/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAddFile;
    QAction *actionExtractTo;
    QAction *actionTest;
    QAction *actionView;
    QAction *actionDelete;
    QAction *actionFind;
    QAction *actionWizard;
    QAction *actionInfo;
    QAction *actionRepair;
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionSave_Archive_Copy_As;
    QAction *actionChange_Drive;
    QAction *actionSet_Default_Password;
    QAction *actionCopy_Files_to_Clipboard;
    QAction *actionPaste_Files_from_Clipboard;
    QAction *actionCopy_Full_Names_to_Clipboard;
    QAction *actionSelect_All;
    QAction *actionSelect_Group;
    QAction *actionDeselect_Group;
    QAction *actionInvert_Selection;
    QAction *actionExtract_to_Specified_Folder;
    QAction *actionView_File;
    QAction *actionDelete_File;
    QAction *actionRename_File;
    QAction *actionPrint_File;
    QAction *actionExtract_Without_Confirmation;
    QAction *actionProtect_Archive_from_Damage;
    QAction *actionLock_Archive;
    QAction *actionScan_Archive_for_Viruses;
    QAction *actionConvert_Archive_s;
    QAction *actionRepair_Archive;
    QAction *actionConvert_Archive_to_SFX;
    QAction *actionFind_Files;
    QAction *actionShow_Information;
    QAction *actionGenerate_Report;
    QAction *actionBenchmark;
    QAction *actionAdd_files_to_archive;
    QAction *actionAdd_to_Favourites;
    QAction *actionOrganize_Favourites;
    QAction *actionSettings;
    QAction *actionImport_and_Export;
    QAction *actionClear_History;
    QAction *actionFlat_Folders_View;
    QAction *actionList_View;
    QAction *actionDetails;
    QAction *actionShow_Disk_Folders;
    QAction *actionShow_Archive_Folders;
    QAction *actionOrganize_Themes;
    QAction *actionGet_More_Themes;
    QAction *actionThemeDefault;
    QAction *actionSave_Current;
    QAction *actionEncodingHelp;
    QAction *actionEncodingDefault;
    QAction *actionView_Log;
    QAction *actionClear_Log;
    QAction *actionHelp_Topics;
    QAction *actionNixRAR_GithubPage;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *fileExplorerContainer;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuCommands;
    QMenu *menuTools;
    QMenu *menuFavourites;
    QMenu *menuOptions;
    QMenu *menuFile_List;
    QMenu *menuFolder_Tree;
    QMenu *menuThemes;
    QMenu *menuName_Encoding;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *navigationBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionAddFile = new QAction(MainWindow);
        actionAddFile->setObjectName("actionAddFile");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/icons/rar-format.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionAddFile->setIcon(icon);
        actionAddFile->setMenuRole(QAction::MenuRole::NoRole);
        actionExtractTo = new QAction(MainWindow);
        actionExtractTo->setObjectName("actionExtractTo");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/icons/folders.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionExtractTo->setIcon(icon1);
        actionExtractTo->setMenuRole(QAction::MenuRole::NoRole);
        actionTest = new QAction(MainWindow);
        actionTest->setObjectName("actionTest");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/icons/checklist.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionTest->setIcon(icon2);
        actionTest->setMenuRole(QAction::MenuRole::NoRole);
        actionView = new QAction(MainWindow);
        actionView->setObjectName("actionView");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/icons/open-book.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionView->setIcon(icon3);
        actionView->setMenuRole(QAction::MenuRole::NoRole);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName("actionDelete");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/icons/bin.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionDelete->setIcon(icon4);
        actionDelete->setMenuRole(QAction::MenuRole::NoRole);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName("actionFind");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icons/icons/loupe.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionFind->setIcon(icon5);
        actionFind->setMenuRole(QAction::MenuRole::NoRole);
        actionWizard = new QAction(MainWindow);
        actionWizard->setObjectName("actionWizard");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Icons/icons/magic-wand.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionWizard->setIcon(icon6);
        actionWizard->setMenuRole(QAction::MenuRole::NoRole);
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName("actionInfo");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Icons/icons/info.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionInfo->setIcon(icon7);
        actionInfo->setMenuRole(QAction::MenuRole::NoRole);
        actionRepair = new QAction(MainWindow);
        actionRepair->setObjectName("actionRepair");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Icons/icons/band-aid.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionRepair->setIcon(icon8);
        actionRepair->setMenuRole(QAction::MenuRole::NoRole);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Icons/icons/open.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionOpen->setIcon(icon9);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Icons/icons/exit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionExit->setIcon(icon10);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionAbout->setIcon(icon7);
        actionSave_Archive_Copy_As = new QAction(MainWindow);
        actionSave_Archive_Copy_As->setObjectName("actionSave_Archive_Copy_As");
        actionChange_Drive = new QAction(MainWindow);
        actionChange_Drive->setObjectName("actionChange_Drive");
        actionSet_Default_Password = new QAction(MainWindow);
        actionSet_Default_Password->setObjectName("actionSet_Default_Password");
        actionCopy_Files_to_Clipboard = new QAction(MainWindow);
        actionCopy_Files_to_Clipboard->setObjectName("actionCopy_Files_to_Clipboard");
        actionPaste_Files_from_Clipboard = new QAction(MainWindow);
        actionPaste_Files_from_Clipboard->setObjectName("actionPaste_Files_from_Clipboard");
        actionCopy_Full_Names_to_Clipboard = new QAction(MainWindow);
        actionCopy_Full_Names_to_Clipboard->setObjectName("actionCopy_Full_Names_to_Clipboard");
        actionSelect_All = new QAction(MainWindow);
        actionSelect_All->setObjectName("actionSelect_All");
        actionSelect_Group = new QAction(MainWindow);
        actionSelect_Group->setObjectName("actionSelect_Group");
        actionDeselect_Group = new QAction(MainWindow);
        actionDeselect_Group->setObjectName("actionDeselect_Group");
        actionInvert_Selection = new QAction(MainWindow);
        actionInvert_Selection->setObjectName("actionInvert_Selection");
        actionExtract_to_Specified_Folder = new QAction(MainWindow);
        actionExtract_to_Specified_Folder->setObjectName("actionExtract_to_Specified_Folder");
        actionView_File = new QAction(MainWindow);
        actionView_File->setObjectName("actionView_File");
        actionDelete_File = new QAction(MainWindow);
        actionDelete_File->setObjectName("actionDelete_File");
        actionRename_File = new QAction(MainWindow);
        actionRename_File->setObjectName("actionRename_File");
        actionPrint_File = new QAction(MainWindow);
        actionPrint_File->setObjectName("actionPrint_File");
        actionExtract_Without_Confirmation = new QAction(MainWindow);
        actionExtract_Without_Confirmation->setObjectName("actionExtract_Without_Confirmation");
        actionProtect_Archive_from_Damage = new QAction(MainWindow);
        actionProtect_Archive_from_Damage->setObjectName("actionProtect_Archive_from_Damage");
        actionLock_Archive = new QAction(MainWindow);
        actionLock_Archive->setObjectName("actionLock_Archive");
        actionScan_Archive_for_Viruses = new QAction(MainWindow);
        actionScan_Archive_for_Viruses->setObjectName("actionScan_Archive_for_Viruses");
        actionConvert_Archive_s = new QAction(MainWindow);
        actionConvert_Archive_s->setObjectName("actionConvert_Archive_s");
        actionRepair_Archive = new QAction(MainWindow);
        actionRepair_Archive->setObjectName("actionRepair_Archive");
        actionConvert_Archive_to_SFX = new QAction(MainWindow);
        actionConvert_Archive_to_SFX->setObjectName("actionConvert_Archive_to_SFX");
        actionFind_Files = new QAction(MainWindow);
        actionFind_Files->setObjectName("actionFind_Files");
        actionShow_Information = new QAction(MainWindow);
        actionShow_Information->setObjectName("actionShow_Information");
        actionGenerate_Report = new QAction(MainWindow);
        actionGenerate_Report->setObjectName("actionGenerate_Report");
        actionBenchmark = new QAction(MainWindow);
        actionBenchmark->setObjectName("actionBenchmark");
        actionAdd_files_to_archive = new QAction(MainWindow);
        actionAdd_files_to_archive->setObjectName("actionAdd_files_to_archive");
        actionAdd_to_Favourites = new QAction(MainWindow);
        actionAdd_to_Favourites->setObjectName("actionAdd_to_Favourites");
        actionOrganize_Favourites = new QAction(MainWindow);
        actionOrganize_Favourites->setObjectName("actionOrganize_Favourites");
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName("actionSettings");
        actionImport_and_Export = new QAction(MainWindow);
        actionImport_and_Export->setObjectName("actionImport_and_Export");
        actionClear_History = new QAction(MainWindow);
        actionClear_History->setObjectName("actionClear_History");
        actionFlat_Folders_View = new QAction(MainWindow);
        actionFlat_Folders_View->setObjectName("actionFlat_Folders_View");
        actionList_View = new QAction(MainWindow);
        actionList_View->setObjectName("actionList_View");
        actionDetails = new QAction(MainWindow);
        actionDetails->setObjectName("actionDetails");
        actionShow_Disk_Folders = new QAction(MainWindow);
        actionShow_Disk_Folders->setObjectName("actionShow_Disk_Folders");
        actionShow_Archive_Folders = new QAction(MainWindow);
        actionShow_Archive_Folders->setObjectName("actionShow_Archive_Folders");
        actionOrganize_Themes = new QAction(MainWindow);
        actionOrganize_Themes->setObjectName("actionOrganize_Themes");
        actionGet_More_Themes = new QAction(MainWindow);
        actionGet_More_Themes->setObjectName("actionGet_More_Themes");
        actionThemeDefault = new QAction(MainWindow);
        actionThemeDefault->setObjectName("actionThemeDefault");
        actionSave_Current = new QAction(MainWindow);
        actionSave_Current->setObjectName("actionSave_Current");
        actionEncodingHelp = new QAction(MainWindow);
        actionEncodingHelp->setObjectName("actionEncodingHelp");
        actionEncodingDefault = new QAction(MainWindow);
        actionEncodingDefault->setObjectName("actionEncodingDefault");
        actionView_Log = new QAction(MainWindow);
        actionView_Log->setObjectName("actionView_Log");
        actionClear_Log = new QAction(MainWindow);
        actionClear_Log->setObjectName("actionClear_Log");
        actionHelp_Topics = new QAction(MainWindow);
        actionHelp_Topics->setObjectName("actionHelp_Topics");
        actionNixRAR_GithubPage = new QAction(MainWindow);
        actionNixRAR_GithubPage->setObjectName("actionNixRAR_GithubPage");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        fileExplorerContainer = new QVBoxLayout();
        fileExplorerContainer->setObjectName("fileExplorerContainer");

        verticalLayout->addLayout(fileExplorerContainer);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuCommands = new QMenu(menubar);
        menuCommands->setObjectName("menuCommands");
        menuTools = new QMenu(menubar);
        menuTools->setObjectName("menuTools");
        menuFavourites = new QMenu(menubar);
        menuFavourites->setObjectName("menuFavourites");
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName("menuOptions");
        menuFile_List = new QMenu(menuOptions);
        menuFile_List->setObjectName("menuFile_List");
        menuFolder_Tree = new QMenu(menuOptions);
        menuFolder_Tree->setObjectName("menuFolder_Tree");
        menuThemes = new QMenu(menuOptions);
        menuThemes->setObjectName("menuThemes");
        menuName_Encoding = new QMenu(menuOptions);
        menuName_Encoding->setObjectName("menuName_Encoding");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setIconSize(QSize(48, 48));
        toolBar->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        navigationBar = new QToolBar(MainWindow);
        navigationBar->setObjectName("navigationBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, navigationBar);
        MainWindow->insertToolBarBreak(navigationBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuCommands->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuFavourites->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_Archive_Copy_As);
        menuFile->addAction(actionChange_Drive);
        menuFile->addAction(actionSet_Default_Password);
        menuFile->addSeparator();
        menuFile->addAction(actionCopy_Files_to_Clipboard);
        menuFile->addAction(actionPaste_Files_from_Clipboard);
        menuFile->addAction(actionCopy_Full_Names_to_Clipboard);
        menuFile->addSeparator();
        menuFile->addAction(actionSelect_All);
        menuFile->addAction(actionSelect_Group);
        menuFile->addAction(actionDeselect_Group);
        menuFile->addAction(actionInvert_Selection);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuCommands->addAction(actionAdd_files_to_archive);
        menuCommands->addAction(actionExtract_to_Specified_Folder);
        menuCommands->addSeparator();
        menuCommands->addAction(actionView_File);
        menuCommands->addAction(actionDelete_File);
        menuCommands->addAction(actionRename_File);
        menuCommands->addAction(actionPrint_File);
        menuCommands->addSeparator();
        menuCommands->addAction(actionExtract_Without_Confirmation);
        menuCommands->addAction(actionProtect_Archive_from_Damage);
        menuCommands->addAction(actionLock_Archive);
        menuTools->addAction(actionWizard);
        menuTools->addSeparator();
        menuTools->addAction(actionScan_Archive_for_Viruses);
        menuTools->addAction(actionConvert_Archive_s);
        menuTools->addAction(actionRepair_Archive);
        menuTools->addAction(actionConvert_Archive_to_SFX);
        menuTools->addSeparator();
        menuTools->addAction(actionFind_Files);
        menuTools->addAction(actionShow_Information);
        menuTools->addAction(actionGenerate_Report);
        menuTools->addAction(actionBenchmark);
        menuFavourites->addAction(actionAdd_to_Favourites);
        menuFavourites->addAction(actionOrganize_Favourites);
        menuOptions->addAction(actionSettings);
        menuOptions->addAction(actionImport_and_Export);
        menuOptions->addAction(actionClear_History);
        menuOptions->addSeparator();
        menuOptions->addAction(menuFile_List->menuAction());
        menuOptions->addAction(menuFolder_Tree->menuAction());
        menuOptions->addAction(menuThemes->menuAction());
        menuOptions->addAction(menuName_Encoding->menuAction());
        menuOptions->addSeparator();
        menuOptions->addAction(actionView_Log);
        menuOptions->addAction(actionClear_Log);
        menuFile_List->addAction(actionFlat_Folders_View);
        menuFile_List->addSeparator();
        menuFile_List->addAction(actionList_View);
        menuFile_List->addAction(actionDetails);
        menuFolder_Tree->addAction(actionShow_Disk_Folders);
        menuFolder_Tree->addAction(actionShow_Archive_Folders);
        menuThemes->addAction(actionOrganize_Themes);
        menuThemes->addAction(actionGet_More_Themes);
        menuThemes->addSeparator();
        menuThemes->addAction(actionThemeDefault);
        menuName_Encoding->addAction(actionSave_Current);
        menuName_Encoding->addAction(actionEncodingHelp);
        menuName_Encoding->addSeparator();
        menuName_Encoding->addAction(actionEncodingDefault);
        menuHelp->addAction(actionHelp_Topics);
        menuHelp->addAction(actionNixRAR_GithubPage);
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionAddFile);
        toolBar->addAction(actionExtractTo);
        toolBar->addAction(actionTest);
        toolBar->addAction(actionView);
        toolBar->addAction(actionDelete);
        toolBar->addAction(actionFind);
        toolBar->addAction(actionWizard);
        toolBar->addAction(actionInfo);
        toolBar->addSeparator();
        toolBar->addAction(actionRepair);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "NixRar", nullptr));
        actionAddFile->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
#if QT_CONFIG(tooltip)
        actionAddFile->setToolTip(QCoreApplication::translate("MainWindow", "Add File(s) to Archive", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionAddFile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExtractTo->setText(QCoreApplication::translate("MainWindow", "Extract To", nullptr));
#if QT_CONFIG(tooltip)
        actionExtractTo->setToolTip(QCoreApplication::translate("MainWindow", "Extract files to directory", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionExtractTo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionTest->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
#if QT_CONFIG(tooltip)
        actionTest->setToolTip(QCoreApplication::translate("MainWindow", "Test Archive", nullptr));
#endif // QT_CONFIG(tooltip)
        actionView->setText(QCoreApplication::translate("MainWindow", "View", nullptr));
#if QT_CONFIG(tooltip)
        actionView->setToolTip(QCoreApplication::translate("MainWindow", "View archive info", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
#if QT_CONFIG(tooltip)
        actionDelete->setToolTip(QCoreApplication::translate("MainWindow", "Delete item from archive", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionDelete->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFind->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
#if QT_CONFIG(tooltip)
        actionFind->setToolTip(QCoreApplication::translate("MainWindow", "Find item in archive", nullptr));
#endif // QT_CONFIG(tooltip)
        actionWizard->setText(QCoreApplication::translate("MainWindow", "Wizard", nullptr));
#if QT_CONFIG(tooltip)
        actionWizard->setToolTip(QCoreApplication::translate("MainWindow", "Start the archive wizard", nullptr));
#endif // QT_CONFIG(tooltip)
        actionInfo->setText(QCoreApplication::translate("MainWindow", "Info", nullptr));
#if QT_CONFIG(tooltip)
        actionInfo->setToolTip(QCoreApplication::translate("MainWindow", "Show archive information", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRepair->setText(QCoreApplication::translate("MainWindow", "Repair", nullptr));
#if QT_CONFIG(tooltip)
        actionRepair->setToolTip(QCoreApplication::translate("MainWindow", "Repair archive", nullptr));
#endif // QT_CONFIG(tooltip)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open Archive", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionSave_Archive_Copy_As->setText(QCoreApplication::translate("MainWindow", "Save Archive Copy As", nullptr));
        actionChange_Drive->setText(QCoreApplication::translate("MainWindow", "Change Drive", nullptr));
        actionSet_Default_Password->setText(QCoreApplication::translate("MainWindow", "Set Default Password", nullptr));
        actionCopy_Files_to_Clipboard->setText(QCoreApplication::translate("MainWindow", "Copy Files to Clipboard", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy_Files_to_Clipboard->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste_Files_from_Clipboard->setText(QCoreApplication::translate("MainWindow", "Paste Files from Clipboard", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste_Files_from_Clipboard->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy_Full_Names_to_Clipboard->setText(QCoreApplication::translate("MainWindow", "Copy Full Names to Clipboard", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy_Full_Names_to_Clipboard->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSelect_All->setText(QCoreApplication::translate("MainWindow", "Select All", nullptr));
        actionSelect_Group->setText(QCoreApplication::translate("MainWindow", "Select Group", nullptr));
        actionDeselect_Group->setText(QCoreApplication::translate("MainWindow", "Deselect Group", nullptr));
        actionInvert_Selection->setText(QCoreApplication::translate("MainWindow", "Invert Selection", nullptr));
        actionExtract_to_Specified_Folder->setText(QCoreApplication::translate("MainWindow", "Extract to Specified Folder", nullptr));
        actionView_File->setText(QCoreApplication::translate("MainWindow", "View File", nullptr));
        actionDelete_File->setText(QCoreApplication::translate("MainWindow", "Delete File", nullptr));
        actionRename_File->setText(QCoreApplication::translate("MainWindow", "Rename File", nullptr));
        actionPrint_File->setText(QCoreApplication::translate("MainWindow", "Print File", nullptr));
        actionExtract_Without_Confirmation->setText(QCoreApplication::translate("MainWindow", "Extract Without Confirmation ", nullptr));
        actionProtect_Archive_from_Damage->setText(QCoreApplication::translate("MainWindow", "Protect Archive from Damage", nullptr));
        actionLock_Archive->setText(QCoreApplication::translate("MainWindow", "Lock Archive", nullptr));
        actionScan_Archive_for_Viruses->setText(QCoreApplication::translate("MainWindow", "Scan Archive for Viruses", nullptr));
        actionConvert_Archive_s->setText(QCoreApplication::translate("MainWindow", "Convert Archive(s)", nullptr));
        actionRepair_Archive->setText(QCoreApplication::translate("MainWindow", "Repair Archive", nullptr));
        actionConvert_Archive_to_SFX->setText(QCoreApplication::translate("MainWindow", "Convert Archive to SFX", nullptr));
        actionFind_Files->setText(QCoreApplication::translate("MainWindow", "Find Files", nullptr));
        actionShow_Information->setText(QCoreApplication::translate("MainWindow", "Show Information", nullptr));
        actionGenerate_Report->setText(QCoreApplication::translate("MainWindow", "Generate Report", nullptr));
        actionBenchmark->setText(QCoreApplication::translate("MainWindow", "Benchmark", nullptr));
        actionAdd_files_to_archive->setText(QCoreApplication::translate("MainWindow", "Add File(s) to Archive", nullptr));
        actionAdd_to_Favourites->setText(QCoreApplication::translate("MainWindow", "Add to Favourites", nullptr));
        actionOrganize_Favourites->setText(QCoreApplication::translate("MainWindow", "Organize Favourites", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        actionImport_and_Export->setText(QCoreApplication::translate("MainWindow", "Import and Export", nullptr));
        actionClear_History->setText(QCoreApplication::translate("MainWindow", "Clear History", nullptr));
        actionFlat_Folders_View->setText(QCoreApplication::translate("MainWindow", "Flat Folders View", nullptr));
        actionList_View->setText(QCoreApplication::translate("MainWindow", "List View", nullptr));
        actionDetails->setText(QCoreApplication::translate("MainWindow", "Details", nullptr));
        actionShow_Disk_Folders->setText(QCoreApplication::translate("MainWindow", "Show Disk Folders", nullptr));
        actionShow_Archive_Folders->setText(QCoreApplication::translate("MainWindow", "Show Archive Folders", nullptr));
        actionOrganize_Themes->setText(QCoreApplication::translate("MainWindow", "Organize Themes", nullptr));
        actionGet_More_Themes->setText(QCoreApplication::translate("MainWindow", "Get More Themes", nullptr));
        actionThemeDefault->setText(QCoreApplication::translate("MainWindow", "Default", nullptr));
        actionSave_Current->setText(QCoreApplication::translate("MainWindow", "Save Current", nullptr));
        actionEncodingHelp->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        actionEncodingDefault->setText(QCoreApplication::translate("MainWindow", "Default", nullptr));
        actionView_Log->setText(QCoreApplication::translate("MainWindow", "View Log", nullptr));
        actionClear_Log->setText(QCoreApplication::translate("MainWindow", "Clear Log", nullptr));
        actionHelp_Topics->setText(QCoreApplication::translate("MainWindow", "Help Topics", nullptr));
        actionNixRAR_GithubPage->setText(QCoreApplication::translate("MainWindow", "NixRAR GitHub Page", nullptr));
#if QT_CONFIG(tooltip)
        actionNixRAR_GithubPage->setToolTip(QCoreApplication::translate("MainWindow", "NixRAR GitHub Page", nullptr));
#endif // QT_CONFIG(tooltip)
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuCommands->setTitle(QCoreApplication::translate("MainWindow", "Commands", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuFavourites->setTitle(QCoreApplication::translate("MainWindow", "Favourites", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
        menuFile_List->setTitle(QCoreApplication::translate("MainWindow", "File List", nullptr));
        menuFolder_Tree->setTitle(QCoreApplication::translate("MainWindow", "Folder Tree", nullptr));
        menuThemes->setTitle(QCoreApplication::translate("MainWindow", "Themes", nullptr));
        menuName_Encoding->setTitle(QCoreApplication::translate("MainWindow", "Name Encoding", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        navigationBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
