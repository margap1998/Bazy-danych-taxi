#include "ubezpieczenia.h"
#include "ui_ubezpieczenia.h"

Ubezpieczenia::Ubezpieczenia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ubezpieczenia)
{
    ui->setupUi(this);
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

    ui->setupUi(this);
}

void Ubezpieczenia::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}
void Ubezpieczenia::on_OdswierzButton_clicked(){}

void Ubezpieczenia::on_DodajButton_2_clicked(){

}

void Ubezpieczenia::on_WyszukajButton_clicked(){}

