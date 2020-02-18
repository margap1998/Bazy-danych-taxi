#include "naprawy.h"
#include "ui_naprawy.h"

#include <Dialogi/dodajnaprawe.h>
#include <QMessageBox>
#include <QtSql>
#include <warsztat.h>
#include <Szukajki/szukajnaprawy.h>
#include <Usuwanie/usunnaprawe.h>
naprawy::naprawy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::naprawy)
{
    ui->setupUi(this);
    aktywnaTabela = "naprawa";
    on_OdswierzButton_clicked();
    ui->tableView->setEditTriggers(QTableView::EditTrigger::NoEditTriggers);
}

void naprawy::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}

void naprawy::on_OdswierzButton_clicked()
{
    model.setTable(aktywnaTabela);
    model.select();
    ui->tableView->setModel(&model);
}

void naprawy::on_DodajButton_2_clicked()
{
    DodajNaprawe *okn = new DodajNaprawe(this);
    okn->show();
}

void naprawy::on_WyszukajButton_clicked()
{

    auto okn = new szukajNaprawy(&model,this);
    okn->show();
}

naprawy::naprawy(QWidget *parent, QWidget *bef):
    QWidget(parent),
    ui(new Ui::naprawy)
{
    before =bef;

    ui->setupUi(this);
    aktywnaTabela = "naprawa";
    on_OdswierzButton_clicked();
    ui->tableView->setEditTriggers(QTableView::EditTrigger::NoEditTriggers);
}


naprawy::~naprawy()
{
    delete ui;
}

void naprawy::on_pushButton_clicked()
{
    auto okn = new warsztat(this);
    okn->show();
}

void naprawy::on_naprawy_2_clicked()
{
    aktywnaTabela = "naprawawarsztat";
    on_OdswierzButton_clicked();
}

void naprawy::on_napSam_clicked()
{
    aktywnaTabela = "naprawapojazd";
    on_OdswierzButton_clicked();
}

void naprawy::on_UsunButton_clicked()
{
    auto okn = (new UsunNaprawe(this));
    okn->show();
}

void naprawy::on_ZatwierdzButton_2_clicked()
{
    if(!model.submitAll())
    {
        (new QMessageBox(QMessageBox::Icon::Warning,"","Zmiany nie zostały wprowadzone.\nZaistniały niezgodność w typie danych lub w identyfikatorach"))->show();

    }
    model.select();
}
