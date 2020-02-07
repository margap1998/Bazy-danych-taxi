#include "dodajubezpieczenie.h"
#include "ui_dodajubezpieczenie.h"


DodajUbezpieczenie::DodajUbezpieczenie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajUbezpieczenie)
{
    ui->setupUi(this);
    model.setQuery("SELECT Numer_rejestracyjny FROM pojazd");
    ui->numerRejestracyjnyComboBox->setModel(&model);
}

DodajUbezpieczenie::~DodajUbezpieczenie()
{
    delete ui;
}

void DodajUbezpieczenie::on_buttonBox_accepted()
{

}

void DodajUbezpieczenie::on_buttonBox_rejected()
{

}
