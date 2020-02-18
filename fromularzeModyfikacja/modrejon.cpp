#include "modrejon.h"
#include "ui_modrejon.h"

modRejon::modRejon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modRejon)
{
    ui->setupUi(this);
}

modRejon::~modRejon()
{
    delete ui;
}
