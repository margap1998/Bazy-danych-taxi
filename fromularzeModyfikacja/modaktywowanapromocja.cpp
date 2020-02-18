#include "modaktywowanapromocja.h"
#include "ui_modaktywowanapromocja.h"

#include <QMessageBox>
#include <QSqlQuery>

modAktywowanaPromocja::modAktywowanaPromocja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modAktywowanaPromocja)
{
    ui->setupUi(this);
    modelK.setQuery("Select DISTINCT Kod from Aktywowana_promocja");
    modelR.setQuery("Select DISTINCT Numer_telefonu from Aktywowana_promocja");
    umodelK.setQuery("SELECT kod FROM promocja");
    umodelT.setQuery("SELECT Numer_telefonu FROM klient");
    umodelP.setQuery("SELECT Numer_paragonu FROM przejazd");
    ui->numerTelefonuComboBox->setModel(&umodelT);
    ui->kodComboBox->setModel(&umodelK);
    ui->numerCBwybor->setModel(&modelR);
    ui->kodPromocjiwyb->setModel(&modelK);
    ui->nrParagonuComboBox->setModel(&umodelP);
}

modAktywowanaPromocja::~modAktywowanaPromocja()
{
    delete ui;
}

void modAktywowanaPromocja::on_Ok_clicked()
{
    QString kodWyb = ui->kodPromocjiwyb->currentText();
    QString telWyb = ui->numerCBwybor->currentText();

    QString kod = ui->kodComboBox->currentText();
    QString nrPar = ui->nrParagonuComboBox->currentText();
    QString nrTel =ui->numerTelefonuComboBox->currentText();
    QString wyko =ui->wykorzystaniaSpinBox->text();
    QString data =ui->dataAktywacjiDateEdit->text();
    auto w = new QMessageBox();

    if (kod.length()>10){w->setText("Kod promocji ma do 10 znaków."); w->show();return;}
    if (nrPar.length()>25){w->setText("Numer paragonu ma do 25 znaków."); w->show();return;}
    if (nrTel.length()>25){w->setText("Numer telefonu ma do 15 znaków."); w->show();return;}
    if (wyko.length()>1){w->setText("Liczba wykorzystań ma 1 cyfrę."); w->show();return;}

    if (!(kod==""||nrTel==""||wyko==""||data==""||kodWyb==""||telWyb==""))
    {
        QSqlQuery q1;
        QString pol =
                "UPDATE Aktywowana_Promocja "
                " SET "
                " Kod = '"+kod+"'"+
                ", Numer_telefonu= '"+nrTel+"'"+
                ", Data_aktywacji= '"+data+"'"
                ", Wykorzystanie= "+wyko+""
                ", Numer_paragonu= '"+nrPar+"' "
                " WHERE "
                " Kod = '"+kodWyb+"'"+
                "AND Numer_telefonu= '"+telWyb+"'";
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
        }else{
            if(!q1.exec())
            {
                w->setText("Nieudana próba modyfikacji aktywowanej promocji");
            }
            else{
                w->setText("Pomyślnie zmodyfikowano aktywowaną promocję");
                w->show();
                on_anuluj_clicked();
            }
        }
    }
    else
    {
        w->setText("Uzupełnij puste pola");
    }
    w->show();
}

void modAktywowanaPromocja::on_anuluj_clicked()
{
    this->close();
    delete this;
}
