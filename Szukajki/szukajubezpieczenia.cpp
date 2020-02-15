#include "szukajubezpieczenia.h"
#include "ui_szukajubezpieczenia.h"

szukajUbezpieczenia::szukajUbezpieczenia(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajUbezpieczenia)
{
    modelR =model;
    ui->setupUi(this);
}

szukajUbezpieczenia::~szukajUbezpieczenia()
{
    delete ui;
}
void szukajUbezpieczenia::on_wrocButton_clicked()
{
    this->hide();
    delete this;
}

void szukajUbezpieczenia::on_szukajButton_clicked()
{
    if (ui->numerUbCB->isChecked()){}
    if (ui->numerRejCB->isChecked()){}
    if (ui->odKosztCB->isChecked()){}
    if (ui->doKosztCB->isChecked()){}
    if (ui->odDataZakCB->isChecked()){}
    if (ui->doDataZakCB->isChecked()){}
    if (ui->odDataZawCB->isChecked()){}
    if (ui->doDataZawCB->isChecked()){}
    if (ui->odKwotaUbCB->isChecked()){}
    if (ui->doKwotaUbCB->isChecked()){}
    QString filtr = modelR->filter();
    modelR->setFilter(filtr);
    modelR->select();
    on_wrocButton_clicked();
}
