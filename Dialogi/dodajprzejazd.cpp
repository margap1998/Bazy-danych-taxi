#include "dodajprzejazd.h"
#include "ui_dodajprzejazd.h"

#include <QMessageBox>
#include <QSqlQuery>

DodajPrzejazd::DodajPrzejazd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajPrzejazd)
{
    ui->setupUi(this);
    modelK.setQuery("SELECT PESEL FROM kierowca");
    modelN.setQuery("SELECT Numer_telefonu FROM klient");
    modelS.setQuery("SELECT Kod from stawka");
    ui->kierowcaBox->setModel(&modelK);
    ui->numerTelefonucomboBox->setModel(&modelN);
    ui->stawkaComboBox->setModel(&modelS);
}

DodajPrzejazd::~DodajPrzejazd()
{
    delete ui;
}

void DodajPrzejazd::on_Ok_clicked()
{
    QString kierowca = ui->kierowcaBox->currentText();
    QString stawka = ui->stawkaComboBox->currentText();
    QString nrPar = ui->numerParagonuLineEdit->text();
    QString nrTel = ui->numerTelefonucomboBox->currentText();
    QString pktKon = ui->punktKoncowyLineEdit->text();
    QString pktPoc = ui->punktPoczTkowyLineEdit->text();
    QString dlTrasy = QVariant(ui->dUgoTrasyDoubleSpinBox->value()).toString();
    QString dataRoz = ui->dataRozpoczeciaDateTimeEdit->text();
    QString dataZak = ui->dataZakonczeniaDateTimeEdit->text();
    QString z = QVariant(ui->cenaDoubleSpinBox->value()).toString();
    QString pol = "INSERT INTO `PolTAXI`.`Przejazd`"
        "(`Numer_paragonu`, `PESEL`, `Numer_telefonu`, `Stawka_Kod`, `Data_rozpoczecia`, `Dlugosc_trasy`, `Punkt_poczatkowy`, `Punk_koncowy`, `Czas_przejazdu`, `Cena`)"
        " VALUES ('"+nrPar+"','"+kierowca+"','"+nrTel+"', '"+stawka+"', '"+dataRoz+"', "+dlTrasy+", '"+pktPoc+"', '"+pktKon+"',"
            "SEC_TO_TIME(TIMESTAMPDIFF(SECOND,'"+dataRoz+"','"+dataZak+"')),"+z+")";
    if(kierowca==""||stawka==""||nrPar==""||nrTel==""||pktKon==""||pktPoc==""||dlTrasy==""||dataRoz==""||dataZak==""||z=="")
    {
        new QMessageBox(QMessageBox::Icon::Information,"","Proszę uzupełnić wszystkie pola");
    }else{
        QSqlQuery q1;
        auto w = new QMessageBox();
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba dodania przejazdu");
            w->show();
        }
        else{
            w->setText("Pomyślnie dodano przejazd");
            w->show();
            on_anuluj_clicked();
        }
    }
}

void DodajPrzejazd::on_anuluj_clicked()
{
    this->hide();
    delete this;
}
