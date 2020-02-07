#include "przejazdy.h"
#include "ui_przejazdy.h"

#include <Dialogi/dodajprzejazd.h>

Przejazdy::Przejazdy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Przejazdy)
{
    ui->setupUi(this);
    on_OdswierzButton_clicked();
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
    on_OdswierzButton_clicked();
}


void Przejazdy::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}
void Przejazdy::on_OdswierzButton_clicked(){
    model.setTable("przejazd");
    model.select();
    ui->tableView->setModel(&model);
}

void Przejazdy::on_DodajButton_2_clicked(){
    DodajPrzejazd *okn = new DodajPrzejazd(this);
    okn->show();
}

void Przejazdy::on_WyszukajButton_clicked(){}

