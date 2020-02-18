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
    w = new QMessageBox();
    QString nrWyb = ui->nrRejCBwyb->currentText();

    QString nr_rej = ui->NumRLE->text();
    QString mar = ui->MarkaLE->text();
    QString mod = ui->ModelLE->text();
    QString rocznik = ui->rocznikSpinBox->text();
    QString przeg = ui->dataPrzegladuDateEdit->date().toString("yyyy-MM-dd");
    QString rej_osb = ui->osobSpinBox->text();
    QString pol;

    if (nr_rej.length()>10){w->setText("Numer rejestracyjny ma do 10 znaków."); w->show();return;}
    if (mar.length()>15){w->setText("Marka ma do 15 znaków."); w->show();return;}
    if (mod.length()>45){w->setText("Model ma do 45 znaków."); w->show();return;}
    if (rocznik.length()>4){w->setText("Rocznik ma do 4 cyfr."); w->show();return;}
    if (rej_osb.length()>1){w->setText("Liczba osób w rejestracji ma 1 cyfrę."); w->show();return;}

    if(!(nr_rej == "" || mar == "" || mod == ""))
    {
        pol = "UPDATE pojazd SET "
                  " Numer_rejestracyjny = '"+nr_rej+"',"
                  " Marka = '"+mar+"',"
                  " Model = '"+mod+"',"
                  " Rocznik = "+rocznik+","
                  " Koniec_przegladu = '"+przeg+"',"
                  " Osob = "+rej_osb+" WHERE Numer_rejestracyjny = '"+nrWyb+"'";
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
    this->close();
    delete this;
}
