#include "naprawy.h"
#include "ui_naprawy.h"

naprawy::naprawy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::naprawy)
{
    ui->setupUi(this);
}

void naprawy::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}

void naprawy::on_OdswierzButton_clicked()
{

}

void naprawy::on_DodajButton_2_clicked()
{

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
}

naprawy::~naprawy()
{
    delete ui;
}
