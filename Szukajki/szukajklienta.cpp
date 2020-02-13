#include "szukajklienta.h"
#include "ui_szukajklienta.h"

szukajKlienta::szukajKlienta(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajKlienta)
{
    modelR =model;
    ui->setupUi(this);
}

szukajKlienta::~szukajKlienta()
{
    delete ui;
}
