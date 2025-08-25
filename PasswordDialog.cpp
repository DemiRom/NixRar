#include "PasswordDialog.h"
#include "ui_PasswordDialog.h"

namespace dd::nixrar {
    PasswordDialog::PasswordDialog(QWidget *parent) : QDialog(parent), ui(new Ui::PasswordDialog) {
        ui->setupUi(this);

        this->ui->passwordInput->setEchoMode(QLineEdit::Password);

        connect(this->ui->acceptButton, SIGNAL(clicked()), SLOT(accept()));
        connect(this->ui->cancelButton, SIGNAL(clicked()), SLOT(reject()));
    }

    PasswordDialog::~PasswordDialog() {
        delete ui;
    }

    QString PasswordDialog::getPassword() const {
        return this->ui->passwordInput->text();
    }
} // dd::nixrar