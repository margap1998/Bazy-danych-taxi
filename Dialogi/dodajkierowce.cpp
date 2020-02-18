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

void DodajKierowce::on_Ok_clicked()
{
    QSqlQuery poj,kier;
    QMessageBox *w;
    w = new QMessageBox();
    QString p1, p2;

    QString nr_rej = ui->NumRLE->text();
    QString mar = ui->MarkaLE->text();
    QString mod = ui->ModelLE->text();
    QString rocznik = ui->rocznikSpinBox->text();
    QString przeg = ui->dataPrzegladuDateEdit->date().toString("yyyy-MM-dd");
    QString rej_osb = ui->osobSpinBox->text();

    if (nr_rej.length()>10){w->setText("Numer rejestracyjny ma do 10 znaków."); w->show();return;}
    if (mar.length()>15){w->setText("Marka ma do 15 znaków."); w->show();return;}
    if (mod.length()>45){w->setText("Model ma do 45 znaków."); w->show();return;}
    if (rocznik.length()>4){w->setText("Rocznik ma do 4 cyfr."); w->show();return;}
    if (rej_osb.length()>1){w->setText("Liczba osób w rejestracji ma 1 cyfrę."); w->show();return;}

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

    if(pes.length()!=11){w->setText("PESEL ma równo 11 znaków."); w->show();return;}
    if(im.length()>20){w->setText("Imię ma do 20 znaków."); w->show();return;}
    if(nazwisko.length()>45){w->setText("Nazwisko ma do 45 znaków."); w->show();return;}

    p2 = "CALL Dodaj_kierowce('"+pes+"','"+nr_rej+"','"+im+"','"+nazwisko+"','"+zatr+"')";
    if(!(poj.prepare(p1)&& kier.prepare(p2)))
    {
        w->setText("Problem z przetworzenie danych");
        w->show();
        return;
    }
    if(!(nr_rej == "" || mar == "" || mod == ""||pes == ""||im == ""|| nazwisko==""))
    {
        if (poj.exec())
        {
            if (kier.exec())
            {
                w->setText("Dodanie kierowcy powiodło się");
                w->show();
                on_anuluj_clicked();
            }else
            {
                w->setText("Dodanie kierowcy nie powiodło się");
            }
        }else
        {
            if (poj.exec())
            {
                if (kier.exec())
                {
                    w->setText("Pojazd o podanym numerze rejestracyjnym istnieje. Przypisano do niego danego kierowcę.");
                }else
                {
                    w->setText("Dodanie kierowcy i pojazdu nie powiodło się");
                }
            }
        }
    }else{
        w->setText("Proszę uzupełnić wszystkie pola");
    }
    w->show();
}

void DodajKierowce::on_anuluj_clicked()
{
    this->close();
    delete this;
}
