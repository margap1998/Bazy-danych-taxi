#include "menu.h"
#include "raportdialog.h"
#include "ui_raportdialog.h"

RaportDialog::RaportDialog(QWidget *parent, int mode) :
    QDialog(parent),
    ui(new Ui::RaportDialog)
{
    modeDB = mode;
    ui->setupUi(this);
    ui->plainTextEdit->appendPlainText("Raport");
}

RaportDialog::RaportDialog(QString text,QDialog *parent):
    QDialog(parent),
    ui(new Ui::RaportDialog)
{
    ui->plainTextEdit->appendPlainText(text);
}
RaportDialog::~RaportDialog()
{
    delete ui;
}


void RaportDialog::on_Wyjdz_clicked()
{
    this->hide();
    delete this;
}
