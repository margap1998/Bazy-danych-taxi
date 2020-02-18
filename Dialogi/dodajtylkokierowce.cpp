#include "dodajtylkokierowce.h"
#include "ui_dodajtylkokierowce.h"

#include <QMessageBox>
#include <QSqlQuery>

dodajTylkoKierowce::dodajTylkoKierowce(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dodajTylkoKierowce)
{
    ui->setupUi(this);
    modelK.setQuery("SELECT Numer_rejestracyjny FROM pojazd");
    ui->numerRejestracyjnyBox->setModel(&modelK);
}

dodajTylkoKierowce::~dodajTylkoKierowce()
{
    delete ui;
}

void dodajTylkoKierowce::on_Ok_clicked()
{
    QSqlQuery kier;
    QString pes = ui->PESELLE->text();
    QString im = ui->imieLE->text();
    QString nazwisko = ui->NazwiskoLE->text();
    QString zatr = ui->dataZatrudnieniaDataEdit->date().toString("yyyy-MM-dd");
    QString nr_rej = ui->numerRejestracyjnyBox->currentText();
    QString p2 = "CALL Dodaj_kierowce('"+pes+"','"+nr_rej+"','"+im+"','"+nazwisko+"','"+zatr+"')";
    if (kier.prepare(p2))
    {
        if(!(nr_rej == "" ||pes == ""||im == ""|| nazwisko==""))
        {
            auto w = new QMessageBox();
            if (kier.exec())
            {
                w->setText("Dodanie kierowcy powiodło się");
                w->show();
                on_anuluj_clicked();
            }else
            {
                w->setText("Dodanie kierowcy nie powiodło się");
            }
            w->show();
        }else
        {
            auto w = new QMessageBox(QMessageBox::Icon::Warning,"","Problem z przetworzeniem danych");
            w->show();
            return;
        }
    }
}

void dodajTylkoKierowce::on_anuluj_clicked()
{
    this->close();
    delete this;
}
