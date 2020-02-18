#include "ubezpieczenia.h"
#include "ui_ubezpieczenia.h"

#include <Dialogi/dodajubezpieczenie.h>

#include <QMessageBox>
#include <QSqlRelationalDelegate>

#include <Szukajki/szukajubezpieczenia.h>

#include <Usuwanie/usunubezpieczenie.h>

#include <fromularzeModyfikacja/modubezpieczenie.h>
Ubezpieczenia::Ubezpieczenia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ubezpieczenia)
{
    obecnaTabelka = "ubezpieczenie";
    ui->setupUi(this);
    on_OdswierzButton_clicked();
    ui->tableView->setEditTriggers(QTableView::EditTrigger::NoEditTriggers);
}

Ubezpieczenia::~Ubezpieczenia()
{
    delete ui;
}
Ubezpieczenia::Ubezpieczenia(QWidget *parent, QWidget *bef) :
    QWidget(parent),
    ui(new Ui::Ubezpieczenia)
{
    before =bef;
    obecnaTabelka = "ubezpieczenie";
    ui->setupUi(this);
    on_OdswierzButton_clicked();
    ui->tableView->setEditTriggers(QTableView::EditTrigger::NoEditTriggers);
}

void Ubezpieczenia::on_WrocButton_2_clicked()
{
    before->show();
    this->close();
    delete this;
}
void Ubezpieczenia::on_OdswierzButton_clicked(){
    ui->Wszystkie->setChecked(true);
    model.setTable(obecnaTabelka);
    model.select();
    ui->tableView->setModel(&model);
}

void Ubezpieczenia::on_DodajButton_2_clicked(){
    DodajUbezpieczenie *okn = new DodajUbezpieczenie(this);
    okn->show();
}

void Ubezpieczenia::on_WyszukajButton_clicked(){
    auto okn = new szukajUbezpieczenia(&model,this);
    okn->show();
}


void Ubezpieczenia::on_Minione_clicked()
{
    model.setFilter("Data_zakonczenia < CURRENT_DATE()");
    model.sort(model.columnCount()-3,Qt::SortOrder::AscendingOrder);
}

void Ubezpieczenia::on_Aktualne_clicked()
{
    model.setFilter("Data_zakonczenia >= CURRENT_DATE()");
    model.sort(model.columnCount()-3,Qt::SortOrder::AscendingOrder);
    model.select();
}

void Ubezpieczenia::on_Wszystkie_clicked()
{
    model.setFilter("");
    on_OdswierzButton_clicked();
}

void Ubezpieczenia::on_zPojazdmi_stateChanged(int arg1)
{
    QString filtr = model.filter();
    if (arg1 == Qt::Checked){
        obecnaTabelka = "pojazdy_z_ubezpieczeniem";
    }else{
        obecnaTabelka = "ubezpieczenie";
    }

    model.setTable(obecnaTabelka);
    model.setFilter(filtr);
    model.select();
}

void Ubezpieczenia::on_UsunButton_clicked()
{
    auto okn =(new UsunUbezpieczenie(this));
    okn->show();
}

void Ubezpieczenia::on_ZatwierdzButton_2_clicked()
{
    if(!model.submitAll())
    {
        (new QMessageBox(QMessageBox::Icon::Warning,"","Zmiany nie zostały wprowadzone.\nZaistniały niezgodność w typie danych lub w identyfikatorach"))->show();

    }
    model.select();
}

void Ubezpieczenia::on_pushButton_clicked()
{
    (new modUbezpieczenie())->show();
}
