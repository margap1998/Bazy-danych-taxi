#include "dodajulice.h"
#include "ui_dodajulice.h"

#include <QMessageBox>
#include <QSqlQuery>

DodajUlice::DodajUlice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajUlice)
{
    modelR.setQuery("SELECT nazwa FROM rejon");
    ui->setupUi(this);
    ui->rejonComboBox->setModel(&modelR);
}

DodajUlice::~DodajUlice()
{
    delete ui;
}

void DodajUlice::on_Ok_clicked()
{
    auto w = new QMessageBox();
    QString rej = ui->rejonComboBox->currentText();
    QString nazwa = ui->nazwaUlicyLineEdit->text();
    if (!(rej=="" || nazwa == ""))
    {
        QString pol = "INSERT INTO ulica(Nazwa,Rejon) VALUES('"+nazwa+"', '"+rej+"')";
        QSqlQuery q1;
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba dodania ulicy");
            w->show();
        }
        else{
            w->setText("Pomyślnie dodano ulicę");
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

void DodajUlice::on_anuluj_clicked()
{
    this->hide();
    delete this;
}
