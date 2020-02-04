#include "wyszukaj.h"
#include "ui_wyszukaj.h"

wyszukaj::wyszukaj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wyszukaj)
{
    ui->setupUi(this);
}

wyszukaj::~wyszukaj()
{
    delete ui;
}
