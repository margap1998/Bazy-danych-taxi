#include "taxibaza.h"
#include "ui_taxibaza.h"
#include "menu.h"

TaxiBAZA::TaxiBAZA(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TaxiBAZA)
{
    ui->setupUi(this);
    ui->centralWidget = new Menu(this);
    ui->centralWidget->show();
}

TaxiBAZA::~TaxiBAZA()
{
    delete ui;
}
