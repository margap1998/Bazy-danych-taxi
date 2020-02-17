#include "taxibaza.h"
#include "ui_taxibaza.h"
#include "logowanie.h"

TaxiBAZA::TaxiBAZA(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TaxiBAZA)
{
    ui->setupUi(this);
    ui->centralWidget = new Logowanie(this);
    ui->centralWidget->show();
}

TaxiBAZA::~TaxiBAZA()
{
    delete ui;
}
