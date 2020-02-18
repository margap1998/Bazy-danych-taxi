#include "modklient.h"
#include "ui_modklient.h"

modKlient::modKlient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modKlient)
{
    ui->setupUi(this);
}

modKlient::~modKlient()
{
    delete ui;
}
