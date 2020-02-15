#include "szukajpojazdu.h"
#include "ui_szukajpojazdu.h"

szukajpojazdu::szukajpojazdu(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajpojazdu)
{
    modelR =model;
    ui->setupUi(this);
}

szukajpojazdu::~szukajpojazdu()
{
    delete ui;
}
void szukajpojazdu::on_wrocButton_clicked()
{
    this->hide();
    delete this;
}

void szukajpojazdu::on_szukajButton_clicked()
{
    if (ui->numerRejCB->isChecked()){}
    if (ui->markaCB->isChecked()){}
    if (ui->modelCB->isChecked()){}
    if (ui->doDatyCB->isChecked()){}
    if (ui->odDatyCB->isChecked()){}
    if (ui->doRocznikaCB->isChecked()){}
    if (ui->odRocznikaCB->isChecked()){}

    if ((ui->odDatyDE->date()>ui->doDatyDE->date()) && ui->doRocznikaCB->isChecked() && ui->odRocznikaCB->isChecked()){}

    if ((ui->odRocznikSpinBox->value()>ui->doRocznikSpinBox->value()) && ui->odRocznikaCB->isChecked() && ui->doRocznikaCB->isChecked()){}

    QString filtr = modelR->filter();
    modelR->setFilter(filtr);
    modelR->select();
    on_wrocButton_clicked();
}
