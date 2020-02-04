#include "klienci.h"
#include "ui_klienci.h"

Klienci::Klienci(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Klienci)
{
    ui->setupUi(this);
}

Klienci::~Klienci()
{
    delete ui;
}

Klienci::Klienci(QWidget *parent, QWidget *bef) :
    QWidget(parent),
    ui(new Ui::Klienci)
{
    before =bef;

    ui->setupUi(this);
}

void Klienci::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}
void Klienci::on_OdswierzButton_clicked(){}

void Klienci::on_DodajButton_2_clicked(){}

void Klienci::on_WyszukajButton_clicked(){}
