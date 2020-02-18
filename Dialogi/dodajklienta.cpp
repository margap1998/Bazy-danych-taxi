#include "dodajklienta.h"
#include "ui_dodajklienta.h"

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
DodajKlienta::DodajKlienta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajKlienta)
{
    ui->setupUi(this);
}

DodajKlienta::~DodajKlienta()
{
    delete ui;
}


void DodajKlienta::on_Ok_clicked()
{
    auto w = new QMessageBox();
    QString pol ="CALL Dodaj_Klienta('";
    QString nr = ui->numerTelefonuLineEdit->text();
    QString email = ui->eMailLineEdit->text();
    QString data = ui->dataRejestracjiDateEdit->text();
    QString imie = ui->imiLineEdit->text();
    QString nazwisko = ui->nazwiskoLineEdit->text();

    if(nr.length()>15){w->setText("Numer telefonu ma do 15 znaków.");w->show();return;}
    if(email.length()>45){w->setText("e-mail ma do 45 znaków.");w->show();return;}
    if(imie.length()>20){w->setText("Imię ma do 20 znaków.");w->show();return;}
    if(nazwisko.length()>30){w->setText("Nazwisko klienta ma do 30 znaków.");w->show();return;}

    pol.append(nr+"','");
    pol.append(email+"','");
    pol.append(data+"','");
    pol.append(imie+"','");
    pol.append(nazwisko+"')");

    QSqlQuery q1;
    if (!(nr == "" || email==""||data==""))
    {
        if(!q1.prepare(pol))
        {
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
            on_anuluj_clicked();
        }
    }
    else
    {
        w->setText("Proszę uzupełnić pola oznaczone gwiazdką");
        w->show();
    }

}
void DodajKlienta::on_anuluj_clicked()
{
    this->close();
    delete this;
}

