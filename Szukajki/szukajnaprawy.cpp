#include "szukajnaprawy.h"
#include "ui_szukajnaprawy.h"

szukajNaprawy::szukajNaprawy(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajNaprawy)
{
    modelR =model;
    ui->setupUi(this);
}

szukajNaprawy::~szukajNaprawy()
{
    delete ui;
}
void szukajNaprawy::on_wrocButton_clicked()
{
    this->hide();
    delete this;
}

void szukajNaprawy::on_szukajButton_clicked()
{
    if (ui->numerFakCB->isChecked()){}
    if (ui->numerRejCB->isChecked()){}
    if (ui->odKosztCB->isChecked()){}
    if (ui->doKosztCB->isChecked()){}
    if (ui->odDataCB->isChecked()){}
    if (ui->doDataCB->isChecked()){}

    if (ui->odKosztDoubleSpinBox->value()>ui->doKosztDoubleSpinBox->value() &&
            ui->doKosztCB->isChecked() && ui->odKosztCB->isChecked()){}

    if((ui->odDataWykonaniaDateEdit->date()>ui->doDataWykonaniaDateEdit->date()) &&
            ui->odDataCB->isChecked() &&
            ui->doDataCB->isChecked()){}
    QString filtr = modelR->filter();
    modelR->setFilter(filtr);
    modelR->select();
    on_wrocButton_clicked();
}
