#include "dodajkierowce.h"
#include "ui_dodajkierowce.h"
#include <QtSql>
#include <QMessageBox>
DodajKierowce::DodajKierowce(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajKierowce)
{
    ui->setupUi(this);
}

DodajKierowce::~DodajKierowce()
{
    delete ui;
}

void DodajKierowce::on_buttonBox_accepted()
{
    QSqlQuery poj,kier;
    QMessageBox *w;
    QString p1, p2;

    QString nr_rej = ui->NumRLE->text();
    QString mar = ui->MarkaLE->text();
    QString mod = ui->MarkaLE->text();
    QString rocznik = ui->rocznikSpinBox->text();
    QString przeg = ui->dataPrzegladuDateEdit->date().toString("yyyy-MM-dd");
    QString rej_osb = ui->osobSpinBox->text();

    p1 = "CALL Dodaj_pojazd("
              "'"+nr_rej+"',"
              "'"+mar+"',"
              "'"+mod+"',"
              ""+rocznik+","
              "'"+przeg+"',"+rej_osb+")";


    QString pes = ui->PESELLE->text();
    QString im = ui->imieLE->text();
    QString nazwisko = ui->NazwiskoLE->text();
    QString zatr = ui->dataZatrudnieniaDataEdit->date().toString("yyyy-MM-dd");
    p2 = "CALL Dodaj_kierowce('"+pes+"','"+nr_rej+"','"+im+"','"+nazwisko+"','"+zatr+"')";
    if(!(poj.prepare(p1)&& kier.prepare(p2)))
    {
        qDebug()<< p1 <<"\n"<<p2;
        qDebug()<<poj.lastError();
        qDebug()<<kier.lastError();
        w = new QMessageBox(parentWidget());
        w->setText("Nie udało się przygotować procedury");
        w->show();
        return;
    }
    if(!(nr_rej == "" || mar == "" || mod == ""||pes == ""||im == ""|| nazwisko==""))
    {
        w = new QMessageBox(parentWidget());
        if (poj.exec())
        {
            if (kier.exec())
            {
                w->setText("Dodanie kierowcy powiodło się");
            }else
            {
                w->setText("Dodanie kierowcy nie powiodło się");
            }
        }else
        {
            w->setText("Dodanie pojazdu i kierowcy nie powiodło się");
        }
        on_buttonBox_rejected();
    }
    else{
        w = new QMessageBox(this);
        w->setText("Proszę uzupełnić wszystkie pola");
    }
    w->show();
}

void DodajKierowce::on_buttonBox_rejected()
{
    this->hide();
    delete this;
}