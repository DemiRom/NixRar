/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../MainWindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN2dd6nixrar10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto dd::nixrar::MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN2dd6nixrar10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "dd::nixrar::MainWindow",
        "openArchiveWithDialog",
        "",
        "about",
        "extractTo",
        "addFile",
        "addDroppedFiles",
        "filePaths",
        "testArchive",
        "viewArchive",
        "deleteFileFromArchive",
        "findInArchive",
        "startArchiveWizard",
        "showArchiveInfo",
        "repairArchive",
        "saveArchiveCopyAs",
        "changeDrive",
        "setDefaultPassword",
        "copyFilesToClipboard",
        "pasteFilesFromClipboard",
        "copyFullNamesToClipboard",
        "selectAll",
        "selectGroup",
        "deselectGroup",
        "invertSelection",
        "extractToSpecifiedFolder",
        "viewFile",
        "deleteFile",
        "renameFile",
        "printFile",
        "extractWithoutConfirmation",
        "protectArchiveFromDamage",
        "lockArchive",
        "scanArchiveForViruses",
        "convertArchives",
        "convertArchiveToSFX",
        "findFiles",
        "showInformation",
        "generateReport",
        "benchmark",
        "addFilesToArchive",
        "addToFavourites",
        "organizeFavourites",
        "settings",
        "importAndExport",
        "clearHistory",
        "flatFoldersView",
        "listView",
        "details",
        "showDiskFolders",
        "showArchiveFolders",
        "organizeThemes",
        "getMoreThemes",
        "themeDefault",
        "saveCurrent",
        "encodingHelp",
        "encodingDefault",
        "viewLog",
        "clearLog",
        "helpTopics",
        "goToNixRarGithubPage"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'openArchiveWithDialog'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'about'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'extractTo'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'addFile'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'addDroppedFiles'
        QtMocHelpers::SlotData<void(const QStringList &)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QStringList, 7 },
        }}),
        // Slot 'testArchive'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'viewArchive'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'deleteFileFromArchive'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'findInArchive'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'startArchiveWizard'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'showArchiveInfo'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'repairArchive'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'saveArchiveCopyAs'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'changeDrive'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'setDefaultPassword'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'copyFilesToClipboard'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'pasteFilesFromClipboard'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'copyFullNamesToClipboard'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'selectAll'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'selectGroup'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'deselectGroup'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'invertSelection'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'extractToSpecifiedFolder'
        QtMocHelpers::SlotData<void()>(25, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'viewFile'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'deleteFile'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'renameFile'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'printFile'
        QtMocHelpers::SlotData<void()>(29, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'extractWithoutConfirmation'
        QtMocHelpers::SlotData<void()>(30, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'protectArchiveFromDamage'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'lockArchive'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'scanArchiveForViruses'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'convertArchives'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'convertArchiveToSFX'
        QtMocHelpers::SlotData<void()>(35, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'findFiles'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'showInformation'
        QtMocHelpers::SlotData<void()>(37, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'generateReport'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'benchmark'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'addFilesToArchive'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'addToFavourites'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'organizeFavourites'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'settings'
        QtMocHelpers::SlotData<void()>(43, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'importAndExport'
        QtMocHelpers::SlotData<void()>(44, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'clearHistory'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'flatFoldersView'
        QtMocHelpers::SlotData<void()>(46, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'listView'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'details'
        QtMocHelpers::SlotData<void()>(48, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'showDiskFolders'
        QtMocHelpers::SlotData<void()>(49, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'showArchiveFolders'
        QtMocHelpers::SlotData<void()>(50, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'organizeThemes'
        QtMocHelpers::SlotData<void()>(51, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'getMoreThemes'
        QtMocHelpers::SlotData<void()>(52, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'themeDefault'
        QtMocHelpers::SlotData<void()>(53, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'saveCurrent'
        QtMocHelpers::SlotData<void()>(54, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'encodingHelp'
        QtMocHelpers::SlotData<void()>(55, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'encodingDefault'
        QtMocHelpers::SlotData<void()>(56, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'viewLog'
        QtMocHelpers::SlotData<void()>(57, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'clearLog'
        QtMocHelpers::SlotData<void()>(58, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'helpTopics'
        QtMocHelpers::SlotData<void()>(59, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'goToNixRarGithubPage'
        QtMocHelpers::SlotData<void()>(60, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN2dd6nixrar10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject dd::nixrar::MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2dd6nixrar10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2dd6nixrar10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN2dd6nixrar10MainWindowE_t>.metaTypes,
    nullptr
} };

void dd::nixrar::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->openArchiveWithDialog(); break;
        case 1: _t->about(); break;
        case 2: _t->extractTo(); break;
        case 3: _t->addFile(); break;
        case 4: _t->addDroppedFiles((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 5: _t->testArchive(); break;
        case 6: _t->viewArchive(); break;
        case 7: _t->deleteFileFromArchive(); break;
        case 8: _t->findInArchive(); break;
        case 9: _t->startArchiveWizard(); break;
        case 10: _t->showArchiveInfo(); break;
        case 11: _t->repairArchive(); break;
        case 12: _t->saveArchiveCopyAs(); break;
        case 13: _t->changeDrive(); break;
        case 14: _t->setDefaultPassword(); break;
        case 15: _t->copyFilesToClipboard(); break;
        case 16: _t->pasteFilesFromClipboard(); break;
        case 17: _t->copyFullNamesToClipboard(); break;
        case 18: _t->selectAll(); break;
        case 19: _t->selectGroup(); break;
        case 20: _t->deselectGroup(); break;
        case 21: _t->invertSelection(); break;
        case 22: _t->extractToSpecifiedFolder(); break;
        case 23: _t->viewFile(); break;
        case 24: _t->deleteFile(); break;
        case 25: _t->renameFile(); break;
        case 26: _t->printFile(); break;
        case 27: _t->extractWithoutConfirmation(); break;
        case 28: _t->protectArchiveFromDamage(); break;
        case 29: _t->lockArchive(); break;
        case 30: _t->scanArchiveForViruses(); break;
        case 31: _t->convertArchives(); break;
        case 32: _t->convertArchiveToSFX(); break;
        case 33: _t->findFiles(); break;
        case 34: _t->showInformation(); break;
        case 35: _t->generateReport(); break;
        case 36: _t->benchmark(); break;
        case 37: _t->addFilesToArchive(); break;
        case 38: _t->addToFavourites(); break;
        case 39: _t->organizeFavourites(); break;
        case 40: _t->settings(); break;
        case 41: _t->importAndExport(); break;
        case 42: _t->clearHistory(); break;
        case 43: _t->flatFoldersView(); break;
        case 44: _t->listView(); break;
        case 45: _t->details(); break;
        case 46: _t->showDiskFolders(); break;
        case 47: _t->showArchiveFolders(); break;
        case 48: _t->organizeThemes(); break;
        case 49: _t->getMoreThemes(); break;
        case 50: _t->themeDefault(); break;
        case 51: _t->saveCurrent(); break;
        case 52: _t->encodingHelp(); break;
        case 53: _t->encodingDefault(); break;
        case 54: _t->viewLog(); break;
        case 55: _t->clearLog(); break;
        case 56: _t->helpTopics(); break;
        case 57: _t->goToNixRarGithubPage(); break;
        default: ;
        }
    }
}

const QMetaObject *dd::nixrar::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dd::nixrar::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN2dd6nixrar10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int dd::nixrar::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 58)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 58;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 58)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 58;
    }
    return _id;
}
QT_WARNING_POP
