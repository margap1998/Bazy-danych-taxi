#include "dodaj.h"
#include "ui_dodaj.h"

dodaj::dodaj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dodaj)
{
    ui->setupUi(this);
}

dodaj::~dodaj()
{
    delete ui;
}

void dodaj::on_buttonBox_accepted()
{

}

void dodaj::on_buttonBox_rejected()
{

}
