#include "kierowcypojazdy.h"
#include "ui_kierowcypojazdy.h"
#include "../Dialogi/dodajkierowce.h"
#include <QtSql>
#include <Dialogi/dodajauto.h>
#include <Szukajki/szukajkierowcy.h>
#include "Szukajki/szukajpojazdu.h"
kierowcyPojazdy::kierowcyPojazdy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kierowcyPojazdy)
{
    del =nullptr;
    schemat = "kierowcypojazdy";
    indeks = -1;
    db = QSqlDatabase::database();
    ui->setupUi(this);
    on_OdswierzButton_clicked();
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
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
    delete del;
    model.setTable(schemat);
    ui->tableView->setEditTriggers(QTableView::EditTrigger::AllEditTriggers);
    if(schemat=="kierowcypojazdy")
    {
        ui->tableView->setEditTriggers(QTableView::EditTrigger::NoEditTriggers);
        model.setRelation(0,QSqlRelation("pojazd","Numer_rejestracyjny","Numer_rejestracyjny"));
        //model.setEditStrategy()
    }else if (schemat == "kierowca")
    {
        model.setRelation(1,QSqlRelation("pojazd","Numer_rejestracyjny","Numer_rejestracyjny"));
    }

    model.select();
    ui->tableView->setModel(&model);
    del =new QSqlRelationalDelegate(ui->tableView);
    ui->tableView->setItemDelegate(del);
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
    model.submit();
    db.commit();
}

void kierowcyPojazdy::on_pushButton_clicked()
{
    auto *okn = new DodajAuto(this);
    okn->show();
}

void kierowcyPojazdy::on_UsunButton_clicked()
{
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
