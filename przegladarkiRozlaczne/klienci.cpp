#include "klienci.h"
#include "ui_klienci.h"

#include <Dialogi/dodajklienta.h>

#include <QMessageBox>
#include <Szukajki/szukajklienta.h>
#include <Usuwanie/usunklienta.h>
Klienci::Klienci(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Klienci)
{
    ui->setupUi(this);
    obecnaTabela = "klient";
    on_OdswierzButton_clicked();
}

Klienci::~Klienci()
{
    delete ui;
}

Klienci::Klienci(QWidget *parent, QWidget *bef) :
    QWidget(parent),
    ui(new Ui::Klienci)
{
    obecnaTabela = "klient";
    before =bef;
    ui->setupUi(this);
    on_OdswierzButton_clicked();
}

void Klienci::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}
void Klienci::on_OdswierzButton_clicked(){
    model.setTable(obecnaTabela);
    model.select();
    ui->tableView->setModel(&model);
}

void Klienci::on_DodajButton_2_clicked(){
    DodajKlienta *okn = new DodajKlienta(this);
    okn->show();
}

void Klienci::on_WyszukajButton_clicked(){

    auto okn = new szukajKlienta(&model,this);
    okn->show();
}

void Klienci::on_UsunButton_clicked()
{
    auto okn =(new UsunKlienta(this));
    okn->show();
}

void Klienci::on_ZatwierdzButton_2_clicked()
{
    if(!model.submitAll())
    {
        (new QMessageBox(QMessageBox::Icon::Warning,"","Zmiany nie zostały wprowadzone.\nZaistniały niezgodność w typie danych lub w identyfikatorach"))->show();

    }
    model.select();
}
