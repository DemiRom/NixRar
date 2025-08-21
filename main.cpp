#include <QApplication>
#include <QPushButton>

#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto mainWindow = dd::nixrar::MainWindow();
    mainWindow.show();
    return QApplication::exec();
}