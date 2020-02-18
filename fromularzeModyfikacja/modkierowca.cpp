#include "modkierowca.h"
#include "ui_modkierowca.h"

modKierowca::modKierowca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modKierowca)
{
    ui->setupUi(this);
}

modKierowca::~modKierowca()
{
    delete ui;
}
