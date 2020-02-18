#include "rejony.h"
#include "ui_rejony.h"

#include <Dialogi/dodajobsluge.h>
#include <Dialogi/dodajrejon.h>
#include <Dialogi/dodajulice.h>

#include <QMessageBox>
#include <QSqlRelationalDelegate>

#include <Usuwanie/usunrejon.h>
#include <Usuwanie/usunobsluge.h>
#include <Usuwanie/usunulice.h>

#include <Szukajki/szukajobslugi.h>
#include <Szukajki/szukajrejonu.h>
#include <Szukajki/szukajulicy.h>

#include <fromularzeModyfikacja/modobsluga.h>
#include <fromularzeModyfikacja/modrejon.h>
#include <fromularzeModyfikacja/modulica.h>

Rejony::Rejony(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rejony)
{
    ui->setupUi(this);
    on_rejonySwitch_clicked();
    ui->tableView->setEditTriggers(QTableView::EditTrigger::NoEditTriggers);
}

Rejony::~Rejony()
{
    delete ui;
}
Rejony::Rejony(QWidget *parent, QWidget *bef) :
    QWidget(parent),
    ui(new Ui::Rejony)
{
    before =bef;
    ui->setupUi(this);
    on_rejonySwitch_clicked();
    ui->tableView->setEditTriggers(QTableView::EditTrigger::NoEditTriggers);
}



void Rejony::on_WrocButton_2_clicked()
{
    before->show();
    this->close();
    delete this;
}
void Rejony::on_OdswierzButton_clicked(){
    model.setTable(aktywnaTabela);
    model.select();
    ui->tableView->setModel(&model);
}

void Rejony::on_DodajButton_2_clicked(){\
    if (aktywnaTabela == "ulica")
    {
        auto okn =(new DodajUlice(this));
        okn->show();
    }else if (aktywnaTabela== "rejon")
    {
        auto okn=(new DodajRejon(this));
        okn->show();
    }else if (aktywnaTabela == "obsluga")
    {
        auto okn =(new DodajObsluge(this));
        okn->show();
    }
}

void Rejony::on_WyszukajButton_clicked(){
    if (aktywnaTabela == "ulica")
    {
        auto okn = new szukajUlicy(&model,this);
        okn->show();
    }else if (aktywnaTabela== "rejon")
    {
        auto okn = new szukajRejonu(&model,this);
        okn->show();
    }else if (aktywnaTabela == "obsluga")
    {
        auto okn = new szukajObslugi(&model,this);
        okn->show();
    }
}


void Rejony::on_uliceSwitch_clicked()
{
    aktywnaTabela = "ulica";
    on_OdswierzButton_clicked();
}

void Rejony::on_rejonySwitch_clicked()
{
    aktywnaTabela = "rejon";
    on_OdswierzButton_clicked();
}

void Rejony::on_obslugaBox_clicked()
{
    aktywnaTabela="obsluga";
    on_OdswierzButton_clicked();
}

void Rejony::on_obslugaButton_clicked()
{
    DodajObsluge *okn = new DodajObsluge();
    okn->show();
}

void Rejony::on_uliceButton_clicked()
{
    DodajUlice *okn = new DodajUlice();
    okn->show();
}

void Rejony::on_UsunButton_clicked()
{    if (aktywnaTabela == "ulica")
    {
        auto okn =(new usunUlice(this));
        okn->show();
    }else if (aktywnaTabela== "rejon")
    {
        auto okn =(new usunrejon(this));
        okn->show();
    }else if (aktywnaTabela == "obsluga")
    {
        auto okn=(new usunObsluge(this));
        okn->show();
    }
}

void Rejony::on_ZatwierdzButton_2_clicked()
{
    if(!model.submitAll())
    {
        (new QMessageBox(QMessageBox::Icon::Warning,"","Zmiany nie zostały wprowadzone.\nZaistniały niezgodność w typie danych lub w identyfikatorach"))->show();

    }
    model.select();
}

void Rejony::on_modyfikuj_clicked()
{
    if (aktywnaTabela == "ulica")
    {
        auto okn =(new modUlica());
        okn->show();
    }else if (aktywnaTabela== "rejon")
    {
        auto okn =(new modRejon());
        okn->show();
    }else if (aktywnaTabela == "obsluga")
    {
        auto okn=(new modObsluga());
        okn->show();
    }
}
