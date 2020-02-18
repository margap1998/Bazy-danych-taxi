#include "przejazdy.h"
#include "ui_przejazdy.h"

#include <Dialogi/dodajprzejazd.h>

#include <QMessageBox>
#include <QSqlRelationalDelegate>

#include <Szukajki/szukajprzejazdu.h>
#include <Usuwanie/usunprzejazdy.h>
#include <fromularzeModyfikacja/modprzejazd.h>

Przejazdy::Przejazdy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Przejazdy)
{
    ui->setupUi(this);
    on_OdswierzButton_clicked();
    ui->tableView->setEditTriggers(QTableView::EditTrigger::NoEditTriggers);
}

Przejazdy::~Przejazdy()
{
    delete ui;
}

Przejazdy::Przejazdy(QWidget *parent, QWidget *bef) :
    QWidget(parent),
    ui(new Ui::Przejazdy)
{
    before =bef;

    ui->setupUi(this);
    on_OdswierzButton_clicked();
    ui->tableView->setEditTriggers(QTableView::EditTrigger::NoEditTriggers);
}


void Przejazdy::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}
void Przejazdy::on_OdswierzButton_clicked(){
    model.setTable("przejazd");
    model.select();
    ui->tableView->setModel(&model);
}

void Przejazdy::on_DodajButton_2_clicked(){
    DodajPrzejazd *okn = new DodajPrzejazd(this);
    okn->show();
}

void Przejazdy::on_WyszukajButton_clicked(){
    auto okn = new szukajPrzejazdu(&model,this);
    okn->show();
}


void Przejazdy::on_UsunButton_clicked()
{
    auto okn = (new UsunPrzejazdy(this));
    okn->show();
}

void Przejazdy::on_ZatwierdzButton_2_clicked()
{
    if(!model.submitAll())
    {
        (new QMessageBox(QMessageBox::Icon::Warning,"","Zmiany nie zostały wprowadzone.\nZaistniały niezgodność w typie danych lub w identyfikatorach"))->show();

    }
    model.select();
}

void Przejazdy::on_modyfikuj_clicked()
{
    (new modPrzejazd(this))->show();
}
