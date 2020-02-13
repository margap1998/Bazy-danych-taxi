#include "szukajpojazdu.h"
#include "ui_szukajpojazdu.h"

szukajpojazdu::szukajpojazdu(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajpojazdu)
{
    modelR =model;
    ui->setupUi(this);
}

szukajpojazdu::~szukajpojazdu()
{
    delete ui;
}
