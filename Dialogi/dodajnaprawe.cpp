#include "dodajnaprawe.h"
#include "ui_dodajnaprawe.h"

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
DodajNaprawe::DodajNaprawe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajNaprawe)
{
    ui->setupUi(this);
    modelK.setQuery("SELECT Numer_rejestracyjny FROM pojazd");
    modelW.setQuery("SELECT Nazwa FROM warsztat");
    ui->warsztatBox->setModel(&modelW);
    ui->numerRejestracyjnyBox->setModel(&modelK);
}

DodajNaprawe::~DodajNaprawe()
{
    delete ui;
}


void DodajNaprawe::on_Ok_clicked()
{
    QMessageBox *w =new QMessageBox();
    QString nrF = ui->numerFakturyLineEdit->text();
    QString data = ui->dataWykonaniaDateEdit->text();
    QString warsztat = ui->warsztatBox->currentText();
    QString nrRej = ui->numerRejestracyjnyBox->currentText();
    QString opis = ui->opisTextEdit->toPlainText();
    QString koszt = QVariant(ui->kosztDoubleSpinBox->value()).toString();
    if (nrF.length()>20){w->setText("Numer faktury ma do 20 znaków"); w->show();return;}
    if (opis.length()>20){w->setText("Opis ma do 160 znaków"); w->show();return;}
    QString pol= "INSERT INTO naprawa(Numer_faktury,Data,Nazwa,Numer_rejestracyjny,Opis,Koszt) "
                    "VALUES('"+nrF+"',";
    pol.append("'"+data+"','"+warsztat+"',");
    pol.append("'"+nrRej+"','"+opis+"',"+koszt+")");
    QSqlQuery q1;
    if (!(nrF == "" || data==""||warsztat==""||nrRej==""||opis==""||koszt==""))
    {
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba dodania nowej naprawy");
            w->show();
        }
        else{
            w->setText("Pomyślnie dodano nową naprawę");
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

void DodajNaprawe::on_anuluj_clicked()
{
    this->close();
    delete this;
}

