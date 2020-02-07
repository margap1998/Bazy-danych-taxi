#include "dodajulice.h"
#include "ui_dodajulice.h"

DodajUlice::DodajUlice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajUlice)
{
    ui->setupUi(this);
}

DodajUlice::~DodajUlice()
{
    delete ui;
}
