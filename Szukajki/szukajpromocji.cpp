#include "szukajpromocji.h"
#include "ui_szukajpromocji.h"

szukajPromocji::szukajPromocji(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajPromocji)
{
    modelR =model;
    ui->setupUi(this);
}

szukajPromocji::~szukajPromocji()
{
    delete ui;
}
void szukajPromocji::on_wrocButton_clicked()
{
    this->hide();
    delete this;

}

void szukajPromocji::on_szukajButton_clicked()
{
    if (ui->kodCB->isChecked()){}
    if (ui->nazwaCB->isChecked()){}
    if (ui->odKwotaCB->isChecked()){}
    if (ui->doKwotaCB->isChecked()){}
    if (ui->odProcentCB->isChecked()){}
    if (ui->doProcentCB->isChecked()){}

    if ((ui->odKwotaDSB->value()>ui->doKwotaDSB->value()) && ui->odKwotaCB->isChecked() && ui->doKwotaCB->isChecked()){}

    if ((ui->odProcentZniKiSpinBox->value()>ui->doProcentZniKiSpinBox->value())&&
            ui->odProcentCB->isChecked()&&ui->doProcentCB->isChecked()){}

    QString filtr = modelR->filter();
    modelR->setFilter(filtr);
    modelR->select();
    on_wrocButton_clicked();
}
