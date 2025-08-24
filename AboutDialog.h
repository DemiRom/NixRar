#ifndef NIXRAR_ABOUTDIALOG_H
#define NIXRAR_ABOUTDIALOG_H

#include <QDialog>

namespace dd::nixrar {
    QT_BEGIN_NAMESPACE

    namespace Ui {
        class AboutDialog;
    }

    QT_END_NAMESPACE

    class AboutDialog : public QDialog {
        Q_OBJECT

    public:
        explicit AboutDialog(QWidget *parent = nullptr);

        ~AboutDialog() override;

    private:
        Ui::AboutDialog *ui;
    };
} // dd::nixrar

#endif //NIXRAR_ABOUTDIALOG_H