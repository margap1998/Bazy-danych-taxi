#include "modaktywowanapromocja.h"
#include "ui_modaktywowanapromocja.h"

#include <QMessageBox>
#include <QSqlQuery>

modAktywowanaPromocja::modAktywowanaPromocja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modAktywowanaPromocja)
{
    ui->setupUi(this);
    ui->setupUi(this);
    modelK.setQuery("Select DISTINCT Kod from Aktywowana_promocja");
    modelR.setQuery("Select DISTINCT Numer_telefonu from Aktywowana_promocja");
    ui->numerCBwybor->setModel(&modelR);
    ui->numerCBwybor->setCurrentText("");
    ui->kodPromocjiwyb->setModel(&modelK);
    ui->kodPromocjiwyb->setCurrentText("");
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
    if (!(kod==""||nrTel==""||wyko==""||data==""||kodWyb==""||telWyb==""))
    {
        QSqlQuery q1;
        QString pol =
                "UPDATE `PolTAXI`.`Aktywowana_Promocja` "
                " SET "
                " `Kod` = '"+kod+"'"+
                ", `Numer_telefonu`= '"+nrTel+"'"+
                ", `Data_aktywacji`= '"+data+"'"
                ", `Wykorzystanie`= "+wyko+
                ", `Numer_paragonu`= '"+nrPar+"' "
                " WHERE "
                " `Kod` = '"+kodWyb+"'"+
                ", `Numer_telefonu`= '"+telWyb+"'";
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
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
        w->setText("Uzupełnij puste pola");
        w->show();
    }
}

void modAktywowanaPromocja::on_anuluj_clicked()
{

}

void modAktywowanaPromocja::on_kodPromocjiwyb_currentTextChanged(const QString &arg1)
{
    modelK.setQuery("Select DISTINCT Kod from Aktywowana_promocja");
    modelR.setQuery("Select Numer_telefonu from Aktywowana_promocja WHERE kod="+arg1);
}

void modAktywowanaPromocja::on_numerCBwybor_activated(const QString &arg1)
{
    modelK.setQuery("Select Kod from Aktywowana_promocja WHERE Numer_telefonu="+arg1);
    modelR.setQuery("Select DISTINCT Numer_telefonu from Aktywowana_promocja");
}
