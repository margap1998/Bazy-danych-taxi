#include "modstawka.h"
#include "ui_modstawka.h"

modStawka::modStawka(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modStawka)
{
    ui->setupUi(this);
}

modStawka::~modStawka()
{
    delete ui;
}
