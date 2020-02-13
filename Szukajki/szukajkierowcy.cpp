#include "szukajkierowcy.h"
#include "ui_szukajkierowcy.h"

szukajKierowcy::szukajKierowcy(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajKierowcy)
{
    modelR =model;
    ui->setupUi(this);
}

szukajKierowcy::~szukajKierowcy()
{
    delete ui;
}
