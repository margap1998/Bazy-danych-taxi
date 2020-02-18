#include "modpojazd.h"
#include "ui_modpojazd.h"

modPojazd::modPojazd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modPojazd)
{
    ui->setupUi(this);
}

modPojazd::~modPojazd()
{
    delete ui;
}
