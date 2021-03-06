#include "dodajpromocje.h"
#include "ui_dodajpromocje.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

DodajPromocje::DodajPromocje(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajPromocje)
{
    ui->setupUi(this);
}

DodajPromocje::~DodajPromocje()
{
    delete ui;
}

void DodajPromocje::on_Ok_clicked()
{
    QString kod = ui->kodLineEdit->text();
    QString kwota = QVariant(ui->kwotaZniKiDoubleSpinBox->value()).toString();
    QString procent = ui->procentZniKiSpinBox->text();
    QString nazwa = ui->nazwaLineEdit->text();
    QString pol = "INSERT INTO promocja(Kod, Nazwa, Kwota_znizki, Procent_znizki)"
                    " VALUES('"+kod+"','"+nazwa+"',"+kwota+","+procent+")";
    QSqlQuery q1;
    auto w = new QMessageBox();
    if(kod.length()>10){w->setText("Kod promocji ma do 10 znaków.");w->show();return;}
    if(nazwa.length()>45){w->setText("Nazwa promocji ma do 45 znaków.");w->show();return;}
    if (!(kod == "" || nazwa==""))
    {
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba dodania promocji");
            w->show();
        }
        else{
            w->setText("Pomyślnie dodano promocję");
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

void DodajPromocje::on_anuluj_clicked()
{
    this->close();
    delete this;
}
