#include "dodajklienta.h"
#include "ui_dodajklienta.h"

DodajKlienta::DodajKlienta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajKlienta)
{
    ui->setupUi(this);
}

DodajKlienta::~DodajKlienta()
{
    delete ui;
}

void DodajKlienta::on_buttonBox_accepted()
{

}
void DodajKlienta::on_buttonBox_rejected()
{
    this->hide();
    delete this;
}

