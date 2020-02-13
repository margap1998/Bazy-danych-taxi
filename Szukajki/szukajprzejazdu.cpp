#include "szukajprzejazdu.h"
#include "ui_szukajprzejazdu.h"

szukajPrzejazdu::szukajPrzejazdu(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajPrzejazdu)
{
    modelR =model;
    ui->setupUi(this);
}

szukajPrzejazdu::~szukajPrzejazdu()
{
    delete ui;
}
