#ifndef NIXRAR_PASSWORDDIALOG_H
#define NIXRAR_PASSWORDDIALOG_H

#include <QDialog>

namespace dd::nixrar {
    QT_BEGIN_NAMESPACE

    namespace Ui {
        class PasswordDialog;
    }

    QT_END_NAMESPACE

    class PasswordDialog : public QDialog {
        Q_OBJECT

    public:
        explicit PasswordDialog(QWidget *parent = nullptr);

        ~PasswordDialog() override;

        QString getPassword() const;
    private:
        Ui::PasswordDialog *ui;
    };
} // dd::nixrar

#endif //NIXRAR_PASSWORDDIALOG_H