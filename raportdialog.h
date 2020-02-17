#ifndef RAPORTDIALOG_H
#define RAPORTDIALOG_H

#include "menu.h"

#include <QDialog>

namespace Ui {
class RaportDialog;
}

class RaportDialog : public QDialog
{
    Q_OBJECT

public:
    ~RaportDialog();

    RaportDialog(QString text, QDialog *parent = 0);
private slots:

    void on_Wyjdz_clicked();

private:
    Ui::RaportDialog *ui;
};

#endif // RAPORTDIALOG_H
