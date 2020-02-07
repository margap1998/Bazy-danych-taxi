#include "dodajrejon.h"
#include "ui_dodajrejon.h"

DodajRejon::DodajRejon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajRejon)
{
    ui->setupUi(this);
}

DodajRejon::~DodajRejon()
{
    delete ui;
}

void DodajRejon::on_buttonBox_accepted()
{

}
