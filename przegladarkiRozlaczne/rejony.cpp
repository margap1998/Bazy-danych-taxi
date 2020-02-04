#include "rejony.h"
#include "ui_rejony.h"

Rejony::Rejony(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rejony)
{
    ui->setupUi(this);
}

Rejony::~Rejony()
{
    delete ui;
}
Rejony::Rejony(QWidget *parent, QWidget *bef) :
    QWidget(parent),
    ui(new Ui::Rejony)
{
    before =bef;

    ui->setupUi(this);
}



void Rejony::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}
void Rejony::on_OdswierzButton_clicked(){}

void Rejony::on_DodajButton_2_clicked(){}

void Rejony::on_WyszukajButton_clicked(){}

