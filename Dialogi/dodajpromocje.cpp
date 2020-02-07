#include "dodajpromocje.h"
#include "ui_dodajpromocje.h"

DodajPromocje::DodajPromocje(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajPromocje)
{
    ui->setupUi(this);
}

DodajPromocje::~DodajPromocje()
{
    delete ui;
}
