#include "dodajauto.h"
#include "ui_dodajauto.h"

#include <QMessageBox>
#include <QtSql>
#include <QDebug>

DodajAuto::DodajAuto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajAuto)
{
    ui->setupUi(this);
}

DodajAuto::~DodajAuto()
{
    delete ui;
}

void DodajAuto::on_Ok_clicked()
{
    QSqlQuery poj;
    QMessageBox *w;


    QString nr_rej = ui->NumRLE->text();
    QString mar = ui->MarkaLE->text();
    QString mod = ui->ModelLE->text();
    QString rocznik = ui->rocznikSpinBox->text();
    QString przeg = ui->dataPrzegladuDateEdit->date().toString("yyyy-MM-dd");
    QString rej_osb = ui->osobSpinBox->text();
    QString pol;
    w = new QMessageBox();
    if(!(nr_rej == "" || mar == "" || mod == ""))
    {
        pol = "CALL Dodaj_pojazd("
                  "'"+nr_rej+"',"
                  "'"+mar+"',"
                  "'"+mod+"',"
                  ""+rocznik+","
                  "'"+przeg+"',"+rej_osb+")";
        if(!poj.prepare(pol))
        {
            w->setText("Nie udało się przygotować procedury");
            w->show();
            return;
        }
        w->show();
        if (poj.exec())
        {
            w->setText("Dodanie pojazdu powiodło się");
            on_anuluj_clicked();
        }else
        {
            w->setText("Dodanie pojazdu nie powiodło się");
            qDebug()<<poj.lastError();
        }
    }
    else{
        w->setText("Proszę uzupełnić wszystkie pola");
        w->show();
    }

}


void DodajAuto::on_anuluj_clicked()
{
    this->hide();
    delete this;

}
