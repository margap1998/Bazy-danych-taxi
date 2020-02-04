#include "przejazdy.h"
#include "ui_przejazdy.h"

Przejazdy::Przejazdy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Przejazdy)
{
    ui->setupUi(this);
}

Przejazdy::~Przejazdy()
{
    delete ui;
}

Przejazdy::Przejazdy(QWidget *parent, QWidget *bef) :
    QWidget(parent),
    ui(new Ui::Przejazdy)
{
    before =bef;

    ui->setupUi(this);
}


void Przejazdy::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}
void Przejazdy::on_OdswierzButton_clicked(){}

void Przejazdy::on_DodajButton_2_clicked(){}

void Przejazdy::on_WyszukajButton_clicked(){}

