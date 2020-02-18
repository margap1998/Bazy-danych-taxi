#include "modnaprawa.h"
#include "ui_modnaprawa.h"

modNaprawa::modNaprawa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modNaprawa)
{
    ui->setupUi(this);
}

modNaprawa::~modNaprawa()
{
    delete ui;
}
