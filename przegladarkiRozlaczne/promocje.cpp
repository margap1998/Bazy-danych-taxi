#include "promocje.h"
#include "ui_promocje.h"

Promocje::Promocje(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Promocje)
{
    ui->setupUi(this);
}
Promocje::Promocje(QWidget *parent, QWidget *bef) :
    QWidget(parent),
    ui(new Ui::Promocje)
{
    before =bef;

    ui->setupUi(this);
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
void Promocje::on_OdswierzButton_clicked(){}

void Promocje::on_DodajButton_2_clicked(){}

void Promocje::on_WyszukajButton_clicked(){}
