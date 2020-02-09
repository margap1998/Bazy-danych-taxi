#include "dodajauto.h"
#include "ui_dodajauto.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
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

void DodajAuto::on_buttonBox_accepted()
{
    QSqlQuery poj;
    QMessageBox *w;

    QString nr_rej = ui->NumRLE->text();
    QString mar = ui->MarkaLE->text();
    QString mod = ui->MarkaLE->text();
    QString rocznik = ui->rocznikSpinBox->text();
    QString przeg = ui->dataPrzegladuDateEdit->date().toString("yyyy-MM-dd");
    QString rej_osb = ui->osobSpinBox->text();
    QString pol;
    if(!(nr_rej == "" || mar == "" || mod == ""))
    {
        pol = "CALL Dodaj_pojazd("
                  "'"+nr_rej+"',"
                  "'"+mar+"',"
                  "'"+mod+"',"
                  ""+rocznik+","
                  "'"+przeg+"',"+rej_osb+")";
        qDebug(pol.toStdString().c_str());
        if(!poj.prepare(pol))
        {
            w = new QMessageBox(parentWidget());
            w->setText("Nie udało się przygotować procedury");
            w->show();
            qDebug(poj.lastError().text().toStdString().c_str());
            return;
        }
        w = new QMessageBox(parentWidget());
        w->show();
        if (poj.exec())
        {
            w->setText("Dodanie pojazdu powiodło się");
            on_buttonBox_rejected();
        }else
        {
            w->setText("Dodanie pojazdu nie powiodło się");
            qDebug()<<poj.lastError();
        }
    }
    else{
        w = new QMessageBox(this);
        w->setText("Proszę uzupełnić wszystkie pola");
        w->show();
    }

}

void DodajAuto::on_buttonBox_rejected()
{
    this->hide();
    delete this;
}
