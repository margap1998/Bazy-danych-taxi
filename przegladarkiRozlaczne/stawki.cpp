#include "stawki.h"
#include "ui_stawki.h"

#include <Dialogi/dodajstawke.h>

#include <QMessageBox>
#include <Szukajki/szukajkodu.h>
#include <Usuwanie/usunstawke.h>
Stawki::Stawki(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stawki)
{
    ui->setupUi(this);
    on_OdswierzButton_clicked();
}

Stawki::~Stawki()
{
    delete ui;
}
Stawki::Stawki(QWidget *parent, QWidget *bef) :
    QWidget(parent),
    ui(new Ui::Stawki)
{
    before =bef;

    ui->setupUi(this);
    on_OdswierzButton_clicked();
}



void Stawki::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}
void Stawki::on_OdswierzButton_clicked(){
    model.setTable("stawka");
    model.select();
    ui->tableView->setModel(&model);
}

void Stawki::on_DodajButton_2_clicked(){
    DodajStawke *okn = new DodajStawke(this);
    okn->show();
}

void Stawki::on_WyszukajButton_clicked(){
    auto okn = new szukajKodu(&model,this);
    okn->show();
}

void Stawki::on_UsunButton_clicked()
{
    auto okn =(new UsunStawke(this));
    okn->show();
}

void Stawki::on_ZatwierdzButton_2_clicked()
{
    if(!model.submitAll())
    {
        (new QMessageBox(QMessageBox::Icon::Warning,"","Zmiany nie zostały wprowadzone.\nZaistniały niezgodność w typie danych lub w identyfikatorach"))->show();

    }
    model.select();
}
