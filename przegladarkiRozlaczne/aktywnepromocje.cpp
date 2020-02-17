#include "aktywnepromocje.h"
#include "ui_aktywnepromocje.h"
#include <QtSql>
#include <Szukajki/szukajaktywnejpromocji.h>
#include <Usuwanie/usunaktywnapromocje.h>
#include "Dialogi/dodajaktywowanopromocje.h"
aktywnePromocje::aktywnePromocje(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aktywnePromocje)
{
    ui->setupUi(this);

    on_OdswierzButton_clicked();
}

aktywnePromocje::aktywnePromocje(QWidget *parent, QWidget *bef):
    QWidget(parent),
    ui(new Ui::aktywnePromocje)
{
    before = bef;
    ui->setupUi(this);
    on_OdswierzButton_clicked();
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
}

aktywnePromocje::~aktywnePromocje()
{
    delete ui;
}

void aktywnePromocje::on_OdswierzButton_clicked()
{
    model.setTable("aktywowana_promocja");
    model.select();
    ui->tableView->setModel(&model);
}

void aktywnePromocje::on_DodajButton_2_clicked()
{
    auto w =(new dodajAktywowanoPromocje(this));
    w->show();
}

void aktywnePromocje::on_ZatwierdzButton_2_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    db.commit();
    model.submit();
}

void aktywnePromocje::on_UsunButton_clicked()
{
    auto w =(new UsunAktywnaPromocje(this));
    w->show();
}

void aktywnePromocje::on_WyszukajButton_clicked()
{
    auto okn = new szukajAktywnejPromocji(&model,this);
    okn->show();
}

void aktywnePromocje::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}

