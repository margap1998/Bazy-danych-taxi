#include "kierowcypojazdy.h"
#include "ui_kierowcypojazdy.h"
#include "../Dialogi/dodajkierowce.h"
#include <QMessageBox>
#include <QtSql>
#include <Dialogi/dodajauto.h>
#include <Szukajki/szukajkierowcy.h>
#include <Dialogi/dodajtylkokierowce.h>
#include <Usuwanie/usunpojazd.h>
#include "Szukajki/szukajpojazdu.h"
#include "Usuwanie/usunkierowce.h"

kierowcyPojazdy::kierowcyPojazdy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kierowcyPojazdy)
{
    del =nullptr;
    schemat = "kierowcypojazdy";
    db = QSqlDatabase::database();
    ui->setupUi(this);
    on_OdswierzButton_clicked();
    ui->tableView->setEditTriggers(QTableView::EditTrigger::NoEditTriggers);
}

kierowcyPojazdy::kierowcyPojazdy(QWidget *parent, QWidget *bef):
    QWidget(parent),
    ui(new Ui::kierowcyPojazdy)
{
    del=nullptr;
    db = QSqlDatabase::database();
    schemat = "kierowcypojazdy";
    before =bef;
    ui->setupUi(this);
    on_OdswierzButton_clicked();
    ui->tableView->setEditTriggers(QTableView::EditTrigger::NoEditTriggers);
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
    model.setTable(schemat);
    model.select();
    ui->tableView->setModel(&model);
}

void kierowcyPojazdy::on_DodajButton_2_clicked(){
    DodajKierowce *okn = new DodajKierowce(this);
    okn->show();
}

void kierowcyPojazdy::on_WyszukajKierowceButton_clicked(){
    auto okn = new szukajKierowcy(&model,this);
    okn->show();

}

void kierowcyPojazdy::on_ZatwierdzButton_2_clicked()
{
    if(!model.submitAll())
    {
        (new QMessageBox(QMessageBox::Icon::Warning,"","Zmiany nie zostały wprowadzone.\nZaistniały niezgodność w typie danych lub w identyfikatorach"))->show();

    }
    model.select();
}

void kierowcyPojazdy::on_pushButton_clicked()
{
    auto *okn = new DodajAuto(this);
    okn->show();
}

void kierowcyPojazdy::on_UsunButton_clicked()
{
    auto w = (new usunkierowce(this));
    w->show();
}


void kierowcyPojazdy::on_kieroPoj_clicked()
{
    schemat = "kierowcypojazdy";
    on_OdswierzButton_clicked();
}

void kierowcyPojazdy::on_tylkoPojazdy_clicked()
{
    schemat = "pojazd";
    on_OdswierzButton_clicked();
}

void kierowcyPojazdy::on_TylkoKierowcy_clicked()
{

    schemat = "kierowca";
    on_OdswierzButton_clicked();
}

void kierowcyPojazdy::on_WyszukajPojazdButton_clicked()
{
    auto okn = new szukajpojazdu(&model,this);
    okn->show();
}

void kierowcyPojazdy::on_pushButton_2_clicked()
{
    auto okn = new dodajTylkoKierowce(this);
    okn->show();
}

void kierowcyPojazdy::on_usunPojazdButton_clicked()
{
    auto w =(new usunPojazd(this));
    w->show();
}
