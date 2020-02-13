#include "ubezpieczenia.h"
#include "ui_ubezpieczenia.h"

#include <Dialogi/dodajubezpieczenie.h>

#include <QSqlRelationalDelegate>

Ubezpieczenia::Ubezpieczenia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ubezpieczenia)
{
    obecnaTabelka = "ubezpieczenie";
    ui->setupUi(this);
    on_OdswierzButton_clicked();
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
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
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
}

void Ubezpieczenia::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
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
