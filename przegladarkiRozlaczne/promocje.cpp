#include "promocje.h"
#include "ui_promocje.h"

#include <Dialogi/dodajpromocje.h>
#include <QtSql>
#include <Szukajki/szukajpromocji.h>
#include <Usuwanie/usunpromocje.h>

Promocje::Promocje(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Promocje)
{
    ui->setupUi(this);
    on_OdswierzButton_clicked();
}
Promocje::Promocje(QWidget *parent, QWidget *bef) :
    QWidget(parent),
    ui(new Ui::Promocje)
{
    before =bef;

    ui->setupUi(this);
    on_OdswierzButton_clicked();
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
void Promocje::on_OdswierzButton_clicked(){
    model.setTable("promocja");
    model.select();
    ui->tableView->setModel(&model);
}

void Promocje::on_DodajButton_2_clicked(){
    DodajPromocje *okn = new DodajPromocje(this);
    okn->show();
}

void Promocje::on_WyszukajButton_clicked(){
    auto okn = new szukajPromocji(&model,this);
    okn->show();}

void Promocje::on_UsunButton_clicked()
{
    auto okn = (new UsunPromocje(this));
    okn->show();
}
