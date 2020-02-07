#include "dodajkierowce.h"
#include "ui_dodajkierowce.h"
#include <QtSql>
DodajKierowce::DodajKierowce(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajKierowce)
{
    ui->setupUi(this);
}

DodajKierowce::~DodajKierowce()
{
    delete ui;
}

void DodajKierowce::on_buttonBox_accepted()
{
    QSqlDatabase db = QSqlDatabase::database();

}

void DodajKierowce::on_buttonBox_rejected()
{
    this->hide();
    delete this;
}
