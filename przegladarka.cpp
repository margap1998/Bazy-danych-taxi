
#include "ui_przegladarka.h"
#include "menu.h"
Przegladarka::Przegladarka(QWidget *parent, QWidget *bef) :
    QWidget(parent),
    ui(new Ui::Przegladarka)
{
    before =bef;

    ui->setupUi(this);
}

Przegladarka::Przegladarka(QWidget *parent, int mode, QWidget *bef) :
    QWidget(parent),
    ui(new Ui::Przegladarka)
{
    before =bef;

    ui->setupUi(this);
}

Przegladarka::~Przegladarka()
{
    delete ui;
}


void Przegladarka::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}
void Przegladarka::on_OdswierzButton_clicked(){}

void Przegladarka::on_DodajButton_2_clicked(){}

void Przegladarka::on_WyszukajButton_clicked(){}

