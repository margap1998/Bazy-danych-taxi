#include "szukajpromocji.h"
#include "ui_szukajpromocji.h"

szukajPromocji::szukajPromocji(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajPromocji)
{
    modelR =model;
    ui->setupUi(this);
}

szukajPromocji::~szukajPromocji()
{
    delete ui;
}
