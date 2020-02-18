#include "modprzejazd.h"
#include "ui_modprzejazd.h"

#include <QMessageBox>
#include <QSqlQuery>

modPrzejazd::modPrzejazd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modPrzejazd)
{
    ui->setupUi(this);
    modelP.setQuery("Select Numer_paragonu from Przejazd");
    modelT.setQuery("Select Numer_telefonu from klient");
    modelK.setQuery("Select PESEL from kierowca");
    modelS.setQuery("Select kod from stawka");
    ui->nrPCBwyb->setModel(&modelP);
    ui->kierowcaBox->setModel(&modelK);
    ui->numerTelefonucomboBox->setModel(&modelT);
    ui->stawkaComboBox->setModel(&modelS);
}

modPrzejazd::~modPrzejazd()
{
    delete ui;
}

void modPrzejazd::on_anuluj_clicked()
{
    this->close();
    delete this;
}

void modPrzejazd::on_Ok_clicked()
{
    QString nrwyb = ui->nrPCBwyb->currentText();

    QString nrParagonu = ui->numerParagonuLineEdit->text();
    QString PESEL = ui->kierowcaBox->currentText();
    QString nrTel = ui->numerTelefonucomboBox->currentText();
    QString stawka = ui->stawkaComboBox->currentText();
    QString dlugosc = QVariant(ui->dUgoTrasyDoubleSpinBox->value()).toString();
    QString pktpocz =ui->punktPoczTkowyLineEdit->text();
    QString pktkonc = ui->punktKoncowyLineEdit->text();
    QString datarozp = ui->dataRozpoczeciaDateTimeEdit->text();
    QString datakon = ui->dataZakonczeniaDateTimeEdit->text();
    QString cena = QVariant(ui->cenaDoubleSpinBox->value()).toString();
    auto w = new QMessageBox();
    if (!(nrParagonu==""||nrTel==""||PESEL==""||stawka==""||dlugosc==""||pktpocz==""||pktkonc==""||datarozp==""||datakon==""||cena==""))
    {
        QSqlQuery q1;
        QString pol =
                "UPDATE `PolTAXI`.`Przejazd` "
                " SET "
                " `Numer_paragonu` = '"+nrParagonu+"'"
                ", `Numer_telefonu`= '"+nrTel+"'"+
                ", `PESEL`= '"+PESEL+"'"
                ", `Stawka_Kod`= "+stawka+
                ", `Data_rozpoczecia`= '"+datarozp+"' "
                ", `Czas_przejazdu`= SEC_TO_TIME(TIMESTAMPDIFF(SECOND,'"+datarozp+"','"+datakon+"'))"
                ", `Dlugosc_trasy`= '"+dlugosc+"' "
                ", `Punkt_poczatkowy`= '"+pktpocz+"' "
                ", `Punkt_koncowy`= '"+pktkonc+"' "
                ", `Cena`= "+cena+
                " WHERE "
                " `Numer_paragonu` = '"+nrwyb+"'";
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba modyfikacji przejazdu");
            w->show();
        }
        else{
            w->setText("Pomyślnie zmodyfikowano przejazd");
            w->show();
            on_anuluj_clicked();
        }
    }
    else
    {
        w->setText("Uzupełnij puste pola");
        w->show();
    }
}
