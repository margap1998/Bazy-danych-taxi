#include "kierowcypojazdy.h"
#include "ui_kierowcypojazdy.h"
#include "../Dialogi/dodajkierowce.h"
#include <QtSql>
#include <Dialogi/dodajauto.h>
kierowcyPojazdy::kierowcyPojazdy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kierowcyPojazdy)
{
    db = QSqlDatabase::database();
    ui->setupUi(this);
    on_OdswierzButton_clicked();
}

kierowcyPojazdy::kierowcyPojazdy(QWidget *parent, QWidget *bef):
    QWidget(parent),
    ui(new Ui::kierowcyPojazdy)
{
    before =bef;
    ui->setupUi(this);
    on_OdswierzButton_clicked();
}

kierowcyPojazdy::~kierowcyPojazdy()
{
    delete ui;
}

void kierowcyPojazdy::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}
void kierowcyPojazdy::on_OdswierzButton_clicked(){
    model.setTable("kierowcypojazdy");
    model.select();
    ui->tableView->setModel(&model);
}

void kierowcyPojazdy::on_DodajButton_2_clicked(){
    DodajKierowce *okn = new DodajKierowce(this);
    okn->show();
}

void kierowcyPojazdy::on_WyszukajButton_clicked(){
}

void kierowcyPojazdy::on_ZatwierdzButton_2_clicked()
{
    db.commit();
}

void kierowcyPojazdy::on_pushButton_clicked()
{
    auto *okn = new DodajAuto(this);
    okn->show();
}
