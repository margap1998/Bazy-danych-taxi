#include "dodajstawke.h"
#include "ui_dodajstawke.h"

DodajStawke::DodajStawke(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajStawke)
{
    ui->setupUi(this);
}

DodajStawke::~DodajStawke()
{
    delete ui;
}
