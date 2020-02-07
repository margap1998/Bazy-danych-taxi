#include "naprawy.h"
#include "ui_naprawy.h"

#include <Dialogi/dodajnaprawe.h>

naprawy::naprawy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::naprawy)
{
    ui->setupUi(this);
    on_OdswierzButton_clicked();
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

}

naprawy::naprawy(QWidget *parent, QWidget *bef):
    QWidget(parent),
    ui(new Ui::naprawy)
{
    before =bef;

    ui->setupUi(this);
    on_OdswierzButton_clicked();
}

naprawy::~naprawy()
{
    delete ui;
}
