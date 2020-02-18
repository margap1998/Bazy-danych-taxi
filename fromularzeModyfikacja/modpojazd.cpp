#include "modpojazd.h"
#include "ui_modpojazd.h"

#include <QMessageBox>
#include <QSqlQuery>

modPojazd::modPojazd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modPojazd)
{
    ui->setupUi(this);
    model.setQuery("SELECT Numer_rejestracyjny FROM pojazd");
    ui->nrRejCBwyb->setModel(&model);
}

modPojazd::~modPojazd()
{
    delete ui;
}

void modPojazd::on_Ok_clicked()
{
    QSqlQuery poj;
    QMessageBox *w;
    QString nrWyb = ui->nrRejCBwyb->currentText();

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
        pol = "UPDATE pojazd SET "
                  " Numer_rejestracyjny = '"+nr_rej+"',"
                  " Marka = '"+mar+"',"
                  " Model = '"+mod+"',"
                  " Rocznik = "+rocznik+","
                  " Koniec_przegladu = '"+przeg+"',"
                  " Osob = "+rej_osb+" WHERE Numer_rejestracyjny = "+nrWyb;
        if(!poj.prepare(pol))
        {
            w->setText("Nie udało się przygotować procedury");
            w->show();
            return;
        }
        w->show();
        if (poj.exec())
        {
            w->setText("Pomyślnie zmodyfikowano pojazd");
            on_anuluj_clicked();
        }else
        {
            w->setText("Zmodyfikowanie pojazdu nie powiodło się");
        }
    }
    else{
        w->setText("Proszę uzupełnić wszystkie pola");
        w->show();
    }
}

void modPojazd::on_anuluj_clicked()
{
    this->hide();
    delete this;

}
