#include "szukajubezpieczenia.h"
#include "ui_szukajubezpieczenia.h"

szukajUbezpieczenia::szukajUbezpieczenia(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajUbezpieczenia)
{
    modelR =model;
    ui->setupUi(this);
}

szukajUbezpieczenia::~szukajUbezpieczenia()
{
    delete ui;
}
