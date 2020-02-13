#include "szukajnaprawy.h"
#include "ui_szukajnaprawy.h"

szukajNaprawy::szukajNaprawy(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajNaprawy)
{
    modelR =model;
    ui->setupUi(this);
}

szukajNaprawy::~szukajNaprawy()
{
    delete ui;
}
