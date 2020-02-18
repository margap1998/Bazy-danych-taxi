#include "modaktywowanapromocja.h"
#include "ui_modaktywowanapromocja.h"

modAktywowanaPromocja::modAktywowanaPromocja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modAktywowanaPromocja)
{
    ui->setupUi(this);
}

modAktywowanaPromocja::~modAktywowanaPromocja()
{
    delete ui;
}
