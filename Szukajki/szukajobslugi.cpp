#include "szukajobslugi.h"
#include "ui_szukajobslugi.h"

szukajObslugi::szukajObslugi(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajObslugi)
{
    modelR =model;
    ui->setupUi(this);
}

szukajObslugi::~szukajObslugi()
{
    delete ui;
}
