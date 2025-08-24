#include "AboutDialog.h"
#include "ui_AboutDialog.h"

namespace dd::nixrar {
    AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AboutDialog) {
        ui->setupUi(this);

        connect(this->ui->closeButton, &QPushButton::clicked, [this]() {
            this->close();
        });
    }

    AboutDialog::~AboutDialog() {
        delete ui;
    }
} // dd::nixrar