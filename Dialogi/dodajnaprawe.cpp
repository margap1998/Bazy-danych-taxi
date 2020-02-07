#include "dodajnaprawe.h"
#include "ui_dodajnaprawe.h"

DodajNaprawe::DodajNaprawe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajNaprawe)
{
    ui->setupUi(this);
    model.setQuery("SELECT Numer_rejestracyjny FROM pojazdy");
}

DodajNaprawe::~DodajNaprawe()
{
    delete ui;
}

void DodajNaprawe::on_buttonBox_accepted()
{

}

void DodajNaprawe::on_buttonBox_rejected()
{
    this->hide();
    delete this;
}
