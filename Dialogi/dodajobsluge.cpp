#include "dodajobsluge.h"
#include "ui_dodajobsluge.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
DodajObsluge::DodajObsluge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajObsluge)
{
    modelK.setQuery("SELECT PESEL FROM kierowca");
    modelR.setQuery("SELECT Nazwa FROM rejon");
    ui->setupUi(this);
    ui->rejonComboBox->setModel(&modelR);
    ui->kierowcaComboBox->setModel(&modelK);
}

DodajObsluge::~DodajObsluge()
{
    delete ui;
}

void DodajObsluge::on_Ok_clicked()
{
    auto w = new QMessageBox();
    QString rej = ui->rejonComboBox->currentText();
    QString pes = ui->kierowcaComboBox->currentText();
    QString pol = "INSERT INTO obsluga(Kierowca, Rejon) VALUES('"+pes+"','"+rej+"')";
    if (!(rej == "" || pes==""))
    {
        QSqlQuery q1;
        if(!q1.prepare(pol))
        {
            qDebug()<<pol<<"\n"<<q1.lastError();
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba dodania kierowcy do obsługi rejonu");
            w->show();
        }
        else{
            w->setText("Pomyślnie dodano kierowcę do obsługi rejonu");
            w->show();
            on_anuluj_clicked();
        }
    }
    else
    {
        w->setText("Proszę uzupełnić wszystkie pola");
        w->show();
    }
}

void DodajObsluge::on_anuluj_clicked()
{
    this->show();
    delete this;
}
