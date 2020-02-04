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
    explicit RaportDialog(QWidget *parent = 0, int mode= Menu::mody::KIEROWCY);
    ~RaportDialog();

    RaportDialog(QString text, QDialog *parent = 0);
private slots:

    void on_Wyjdz_clicked();

private:
    int modeDB;
    Ui::RaportDialog *ui;
};

#endif // RAPORTDIALOG_H
