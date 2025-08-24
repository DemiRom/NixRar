#include <QApplication>
#include <QPushButton>

#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto mainWindow = dd::nixrar::MainWindow(); //TODO Check the program args for a file path
    mainWindow.show();
    return QApplication::exec();
}