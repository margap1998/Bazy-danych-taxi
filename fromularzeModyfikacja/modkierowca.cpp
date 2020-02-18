#include "modkierowca.h"
#include "ui_modkierowca.h"

#include <QMessageBox>
#include <QSqlQuery>

modKierowca::modKierowca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modKierowca)
{
    ui->setupUi(this);
    model.setQuery("Select PESEL from Kierowca");
    ui->peselCwyb->setModel(&model);
    modelK.setQuery("SELECT Numer_rejestracyjny FROM pojazd");
    ui->numerRejestracyjnyBox->setModel(&modelK);
}

modKierowca::~modKierowca()
{
    delete ui;
}

void modKierowca::on_anuluj_clicked()
{
    this->hide();
    delete this;

}

void modKierowca::on_Ok_clicked()
{
    QSqlQuery kier;
    QString kierWyb = ui->peselCwyb->currentText();
    QString pes = ui->PESELLE->text();
    QString im = ui->imieLE->text();
    QString nazwisko = ui->NazwiskoLE->text();
    QString zatr = ui->dataZatrudnieniaDataEdit->date().toString("yyyy-MM-dd");
    QString nr_rej = ui->numerRejestracyjnyBox->currentText();
    QString p2 = "UPDATE kierowca SET "
                 " PESEL ='"+pes+"',"
                 " Numer_rejestracyjny = '"+nr_rej+"', "
                 " Imie = '"+im+"',"
                 " Nazwisko ='"+nazwisko+"',"
                 " Data_zatrudnienia = '"+zatr+"'"
                 " WHERE PESEL = '"+kierWyb+"'";
    if(!(nr_rej == "" ||pes == ""||im == ""|| nazwisko==""))
    {
        if (kier.prepare(p2))
        {
            auto w = new QMessageBox();
            if (kier.exec())
            {
                w->setText("Pomyślnie zmodyfikowano dane o kierowcy");
                w->show();
                on_anuluj_clicked();
            }else
            {
                w->setText("Modyfikacja kierowcy nie powiodła się");
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
