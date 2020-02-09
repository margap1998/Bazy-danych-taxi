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
    model.setQuery("SELECT Numer_rejestracyjny FROM pojazdy");
}

DodajNaprawe::~DodajNaprawe()
{
    delete ui;
}

void DodajNaprawe::on_buttonBox_accepted()
{
    QMessageBox *w =new QMessageBox();
    QString nrF = ui->numerFakturyLineEdit->text();
    QString data = ui->dataWykonaniaLabel->text();
    QString warsztat = ui->warsztatBox->currentText();
    QString nrRej = ui->numerRejestracyjnyBox->currentText();
    QString opis = ui->opisTextEdit->toPlainText();
    QString koszt =ui->kosztDoubleSpinBox->text();
    QString pol= "INSER INTO naprawa(Numer_faktury,Data,Nazwa,Numer_rejestracyjny,Opis,Koszt) "
                    "VALUES('"+nrF+"',";
    pol.append("'"+data+"','"+warsztat+"',");
    pol.append("'"+nrRej+"','"+opis+"','"+koszt+"')");
    QSqlQuery q1;
    if (!(nrF == "" || data==""||warsztat==""||nrRej==""||opis==""||koszt==""))
    {
        if(!q1.prepare(pol))
        {
            qDebug()<<pol<<"\n"<<q1.lastError();
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba dodania nowego klienta");
            w->show();
        }
        else{
            w->setText("Pomyślnie dodano nowego klienta");
            w->show();
        }
    }
    else
    {
        w->setText("Proszę uzupełnić wszystkie pola");
        w->show();
    }
}

void DodajNaprawe::on_buttonBox_rejected()
{
    this->hide();
    delete this;
}
