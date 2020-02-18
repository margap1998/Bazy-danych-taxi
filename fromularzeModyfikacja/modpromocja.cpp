#include "modpromocja.h"
#include "ui_modpromocja.h"

modPromocja::modPromocja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modPromocja)
{
    ui->setupUi(this);
}

modPromocja::~modPromocja()
{
    delete ui;
}
