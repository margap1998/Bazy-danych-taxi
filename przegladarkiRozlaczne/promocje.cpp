#include "promocje.h"
#include "ui_promocje.h"

#include <Dialogi/dodajpromocje.h>
#include <QMessageBox>
#include <QtSql>
#include <Szukajki/szukajpromocji.h>
#include <Usuwanie/usunpromocje.h>
#include <fromularzeModyfikacja/modpromocja.h>

Promocje::Promocje(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Promocje)
{
    ui->setupUi(this);
    on_OdswierzButton_clicked();
    ui->tableView->setEditTriggers(QTableView::EditTrigger::NoEditTriggers);
}
Promocje::Promocje(QWidget *parent, QWidget *bef) :
    QWidget(parent),
    ui(new Ui::Promocje)
{
    before =bef;

    ui->setupUi(this);
    on_OdswierzButton_clicked();
    ui->tableView->setEditTriggers(QTableView::EditTrigger::NoEditTriggers);
}

Promocje::~Promocje()
{
    delete ui;
}


void Promocje::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}
void Promocje::on_OdswierzButton_clicked(){
    model.setTable("promocja");
    model.select();
    ui->tableView->setModel(&model);
}

void Promocje::on_DodajButton_2_clicked(){
    DodajPromocje *okn = new DodajPromocje(this);
    okn->show();
}

void Promocje::on_WyszukajButton_clicked(){
    auto okn = new szukajPromocji(&model,this);
    okn->show();}

void Promocje::on_UsunButton_clicked()
{
    auto okn = (new UsunPromocje(this));
    okn->show();
}

void Promocje::on_ZatwierdzButton_2_clicked()
{
    if(!model.submitAll())
    {
        (new QMessageBox(QMessageBox::Icon::Warning,"","Zmiany nie zostały wprowadzone.\nZaistniały niezgodność w typie danych lub w identyfikatorach"))->show();

    }
    model.select();
}

void Promocje::on_modyfikuj_clicked()
{
    (new modPromocja(this))->show();
}
