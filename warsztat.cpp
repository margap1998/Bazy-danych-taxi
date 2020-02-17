#include "warsztat.h"
#include "ui_warsztat.h"
#include <QtSql>
#include <Usuwanie/usunwarsztat.h>
warsztat::warsztat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::warsztat)
{
    ui->setupUi(this);
    on_odswierz_clicked();
}

warsztat::~warsztat()
{
    delete ui;
}

void warsztat::on_Zatwierdz_clicked()
{
    model.submitAll();
}

void warsztat::on_dodaj_clicked()
{
    model.insertRow(model.rowCount());
}

void warsztat::on_odswierz_clicked()
{
    model.setTable("warsztat");
    model.select();
    ui->tableView->setModel(&model);

}

void warsztat::on_wyjdz_clicked()
{
    this->hide();
    delete this;
}

void warsztat::on_usun_clicked()
{
    (new usunWarsztat(this))->show();
}
