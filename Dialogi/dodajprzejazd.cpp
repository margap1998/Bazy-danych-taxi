#include "dodajprzejazd.h"
#include "ui_dodajprzejazd.h"

DodajPrzejazd::DodajPrzejazd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajPrzejazd)
{
    ui->setupUi(this);
    modelK.setQuery("SELECT PESEL FROM kierowca");
    modelN.setQuery("SELECT Numer_telefonu FROM klient");
    modelS.setQuery("SELECT Kod from stawka");
    ui->kierowcaBox->setModel(&modelK);
    ui->numerTelefonucomboBox->setModel(&modelN);
    ui->stawkaComboBox->setModel(&modelS);
}

DodajPrzejazd::~DodajPrzejazd()
{
    delete ui;
}
