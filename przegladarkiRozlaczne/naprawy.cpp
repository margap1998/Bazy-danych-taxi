#include "naprawy.h"
#include "ui_naprawy.h"

#include <Dialogi/dodajnaprawe.h>
#include <QtSql>
#include <Szukajki/szukajnaprawy.h>
naprawy::naprawy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::naprawy)
{
    ui->setupUi(this);
    on_OdswierzButton_clicked();
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
}

void naprawy::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}

void naprawy::on_OdswierzButton_clicked()
{
    model.setTable("naprawa");
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
    on_OdswierzButton_clicked();
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
}

naprawy::~naprawy()
{
    delete ui;
}
