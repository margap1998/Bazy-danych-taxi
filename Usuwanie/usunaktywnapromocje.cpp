#include "usunaktywnapromocje.h"
#include "ui_usunaktywnapromocje.h"

#include <QMessageBox>
#include <QSqlQuery>

UsunAktywnaPromocje::UsunAktywnaPromocje(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsunAktywnaPromocje)
{
    ui->setupUi(this);
    model.setQuery("Select DISTINCT Data_aktywacji from Aktywowana_promocja");
    modelK.setQuery("Select DISTINCT Kod from Aktywowana_promocja");
    modelR.setQuery("Select DISTINCT Numer_telefonu from Aktywowana_promocja");
    ui->comboBox->setModel(&model);
    ui->numerCB->setModel(&modelR);
    ui->kodPromocji->setModel(&modelK);
}

UsunAktywnaPromocje::~UsunAktywnaPromocje()
{
    delete ui;
}

void UsunAktywnaPromocje::on_usun_clicked()
{
    QString data = ui->comboBox->currentText();
    QString kod = ui->kodPromocji->currentText();
    QString kto = ui->numerCB->currentText();
    if (data==""||kod==""||kto=="")
    {
        new QMessageBox(QMessageBox::Icon::Information,"","Nie wypełniono wymaganych pól");
    }
    else
    {
        auto w = new QMessageBox();
        QString pol = "DELETE FROM `Aktywowana_promocja` WHERE Data_aktywacji = '"+data+"' AND Kod ='"+kod+"'";
        QSqlQuery q1;
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba usunięcia Aktywowanej promocji.");
            w->show();
        }
        else{
            w->setText("Pomyślnie usunięto Aktywowaną promocję.");
            w->show();
            on_wroc_clicked();
        }
    }

}

void UsunAktywnaPromocje::on_wroc_clicked()
{
    this->hide();
    delete this;
}
