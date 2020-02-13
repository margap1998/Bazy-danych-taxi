#include "szukajulicy.h"
#include "ui_szukajulicy.h"

szukajUlicy::szukajUlicy(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajUlicy)
{
    modelR =model;
    ui->setupUi(this);
}

szukajUlicy::~szukajUlicy()
{
    delete ui;
}
