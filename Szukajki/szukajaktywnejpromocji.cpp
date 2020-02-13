#include "szukajaktywnejpromocji.h"
#include "ui_szukajaktywnejpromocji.h"

szukajAktywnejPromocji::szukajAktywnejPromocji(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajAktywnejPromocji)
{
    modelR =model;
    ui->setupUi(this);
}

szukajAktywnejPromocji::~szukajAktywnejPromocji()
{
    delete ui;
}
