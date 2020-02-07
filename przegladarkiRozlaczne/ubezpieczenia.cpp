#include "ubezpieczenia.h"
#include "ui_ubezpieczenia.h"

#include <Dialogi/dodajubezpieczenie.h>

Ubezpieczenia::Ubezpieczenia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ubezpieczenia)
{
    obecnaTabelka = "ubezpieczenie";
    ui->setupUi(this);
    on_OdswierzButton_clicked();
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
}

void Ubezpieczenia::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}
void Ubezpieczenia::on_OdswierzButton_clicked(){
    model.setTable(obecnaTabelka);
    model.select();
    ui->tableView->setModel(&model);
}

void Ubezpieczenia::on_DodajButton_2_clicked(){
    DodajUbezpieczenie *okn = new DodajUbezpieczenie(this);
    okn->show();
}

void Ubezpieczenia::on_WyszukajButton_clicked(){
}


void Ubezpieczenia::on_Minione_clicked()
{
    model.setFilter("Data_zakonczenia < CURRENT_DATE");
    on_OdswierzButton_clicked();
}

void Ubezpieczenia::on_Aktualne_clicked()
{
    model.setFilter("Data_zakonczenia >= CURRENT_DATE");
    model.sort(7,Qt::SortOrder::AscendingOrder);
    on_OdswierzButton_clicked();
}

void Ubezpieczenia::on_Wszystkie_clicked()
{
    model.setFilter("");
    on_OdswierzButton_clicked();
}

void Ubezpieczenia::on_zPojazdmi_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){
        obecnaTabelka = "pojazdy_z_ubezpieczeniem";
        on_OdswierzButton_clicked();
    }else{
        obecnaTabelka = "ubezpieczenie";
        on_OdswierzButton_clicked();
    }
}
