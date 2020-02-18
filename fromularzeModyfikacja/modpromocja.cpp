#include "modpromocja.h"
#include "ui_modpromocja.h"

#include <QMessageBox>
#include <QSqlQuery>

modPromocja::modPromocja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modPromocja)
{
    ui->setupUi(this);
}

modPromocja::~modPromocja()
{
    delete ui;
}

void modPromocja::on_anuluj_clicked()
{
    QString kod = ui->kodLineEdit->text();
    QString kwota = QVariant(ui->kwotaZniKiDoubleSpinBox->value()).toString();
    QString procent = ui->procentZniKiSpinBox->text();
    QString nazwa = ui->nazwaLineEdit->text();
    QString pol = "INSERT INTO promocja(Kod, Nazwa, Kwota_znizki, Procent_znizki)"
                    " VALUES('"+kod+"','"+nazwa+"',"+kwota+","+procent+")";
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
