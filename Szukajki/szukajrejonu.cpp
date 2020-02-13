#include "szukajrejonu.h"
#include "ui_szukajrejonu.h"

szukajRejonu::szukajRejonu(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajRejonu)
{
    modelR =model;
    ui->setupUi(this);
}

szukajRejonu::~szukajRejonu()
{
    delete ui;
}
