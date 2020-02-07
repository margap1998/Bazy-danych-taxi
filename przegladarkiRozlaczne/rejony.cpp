#include "rejony.h"
#include "ui_rejony.h"

#include <Dialogi/dodajobsluge.h>
#include <Dialogi/dodajrejon.h>
#include <Dialogi/dodajulice.h>

Rejony::Rejony(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rejony)
{
    ui->setupUi(this);
    on_rejonySwitch_clicked();
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
    on_rejonySwitch_clicked();
}



void Rejony::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}
void Rejony::on_OdswierzButton_clicked(){
    ui->tableView->clearSpans();
    model.setTable(aktywnaTabela);
    model.select();
    ui->tableView->setModel(&model);
}

void Rejony::on_DodajButton_2_clicked(){\
    DodajRejon *okn = new DodajRejon();
    okn->show();
}

void Rejony::on_WyszukajButton_clicked(){}


void Rejony::on_uliceSwitch_clicked()
{
    aktywnaTabela = "ulica";
    on_OdswierzButton_clicked();
}

void Rejony::on_rejonySwitch_clicked()
{
    aktywnaTabela = "rejon";
    on_OdswierzButton_clicked();
}

void Rejony::on_obslugaBox_clicked()
{
    aktywnaTabela="obsluga";
    on_OdswierzButton_clicked();
}

void Rejony::on_obslugaButton_clicked()
{
    DodajObsluge *okn = new DodajObsluge();
    okn->show();
}

void Rejony::on_uliceButton_clicked()
{
    DodajUlice *okn = new DodajUlice();
    okn->show();
}
