#include "modpromocja.h"
#include "ui_modpromocja.h"

#include <QMessageBox>
#include <QSqlQuery>

modPromocja::modPromocja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modPromocja)
{
    ui->setupUi(this);
    model.setQuery("Select Kod from Promocja");
    ui->kodPromocjiwyb->setModel(&model);
}

modPromocja::~modPromocja()
{
    delete ui;
}

void modPromocja::on_anuluj_clicked()
{
    this->hide();
    delete this;
}

void modPromocja::on_Ok_clicked()
{
    QString kodWyb = ui->kodPromocjiwyb->currentText();

    QString kod = ui->kodLineEdit->text();
    QString kwota = QVariant(ui->kwotaZniKiDoubleSpinBox->value()).toString();
    QString procent = ui->procentZniKiSpinBox->text();
    QString nazwa = ui->nazwaLineEdit->text();
    QString pol = "UPDATE promocja SET "
                  " Kod = '"+kod+"',"
                  " Nazwa = '"+nazwa+"',"
                  " Kwota_znizki = "+kwota+","
                  " Procent_znizki = "+procent+""
                  " WHERE Kod = '"+kodWyb+"'";
    QSqlQuery q1;
    auto w = new QMessageBox();
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
            w->setText("Nieudana próba modyfikacji promocji");
            w->show();
        }
        else{
            w->setText("Pomyślnie zmodyfikowano promocję");
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
