#include "modubezpieczenie.h"
#include "ui_modubezpieczenie.h"

modUbezpieczenie::modUbezpieczenie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modUbezpieczenie)
{
    ui->setupUi(this);
}

modUbezpieczenie::~modUbezpieczenie()
{
    delete ui;
}
