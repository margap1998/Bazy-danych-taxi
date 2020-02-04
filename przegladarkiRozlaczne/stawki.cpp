#include "stawki.h"
#include "ui_stawki.h"

Stawki::Stawki(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stawki)
{
    ui->setupUi(this);
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
}



void Stawki::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}
void Stawki::on_OdswierzButton_clicked(){}

void Stawki::on_DodajButton_2_clicked(){}

void Stawki::on_WyszukajButton_clicked(){}

