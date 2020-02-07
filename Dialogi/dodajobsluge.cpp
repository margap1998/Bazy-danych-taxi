#include "dodajobsluge.h"
#include "ui_dodajobsluge.h"

DodajObsluge::DodajObsluge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajObsluge)
{
    ui->setupUi(this);
}

DodajObsluge::~DodajObsluge()
{
    delete ui;
}
