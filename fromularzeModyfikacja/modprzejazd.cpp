#include "modprzejazd.h"
#include "ui_modprzejazd.h"

modPrzejazd::modPrzejazd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modPrzejazd)
{
    ui->setupUi(this);
}

modPrzejazd::~modPrzejazd()
{
    delete ui;
}
