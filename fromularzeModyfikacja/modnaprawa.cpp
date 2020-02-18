#include "modnaprawa.h"
#include "ui_modnaprawa.h"

#include <QMessageBox>
#include <QSqlQuery>

modNaprawa::modNaprawa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modNaprawa)
{
    ui->setupUi(this);

    model.setQuery("Select DISTINCT  Numer_faktury from Naprawa");
    ui->nrFakCBwybor->setModel(&model);
    modelR.setQuery("Select DISTINCT Numer_rejestracyjny from Naprawa");
    ui->nrRejCBwybor->setModel(&modelR);
    modelW.setQuery("Select DISTINCT Nazwa from Naprawa");
    ui->warsztatCBwybor->setModel(&modelW);
    umodelK.setQuery("SELECT Numer_rejestracyjny FROM pojazd");
    umodelW.setQuery("SELECT Nazwa FROM warsztat");
    ui->warsztatBox->setModel(&modelW);
    ui->numerRejestracyjnyBox->setModel(&umodelK);
}

modNaprawa::~modNaprawa()
{
    delete ui;
}

void modNaprawa::on_anuluj_clicked()
{
    this->close();
    delete this;
}

void modNaprawa::on_Ok_clicked()
{
    QString fakturaWyb = ui->nrFakCBwybor->currentText();
    QString nrRejWyb= ui->nrRejCBwybor->currentText();
    QString warsztatWyb = ui->warsztatCBwybor->currentText();

    QMessageBox *w =new QMessageBox();
    QString nrF = ui->numerFakturyLineEdit->text();
    QString data = ui->dataWykonaniaDateEdit->text();
    QString warsztat = ui->warsztatBox->currentText();
    QString nrRej = ui->numerRejestracyjnyBox->currentText();
    QString opis = ui->opisTextEdit->toPlainText();
    QString koszt = QVariant(ui->kosztDoubleSpinBox->value()).toString();
    QString pol= "UPDATE naprawa SET "
                 " Numer_faktury = '"+nrF+"',"
                 " Data = '"+data+"',"
                 " Nazwa = '"+warsztat+"',"
                 " Numer_rejestracyjny = '"+nrRej+"',"
                 " Opis = '"+opis+"',"
                 " Koszt = "+koszt+" "
                 " WHERE "
                 " Numer_faktury = '"+fakturaWyb+"' AND"
                 " Numer_rejestracyjny = '"+nrRejWyb+"' AND"
                 " Nazwa = '"+warsztatWyb+"'";
    QSqlQuery q1;
    if (!(nrF == "" || data==""||warsztat==""||nrRej==""||opis==""||koszt==""|| fakturaWyb=="" ||nrRejWyb=="" || warsztatWyb==""))
    {
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba dodania nowej naprawy");
            w->show();
        }
        else{
            w->setText("Pomyślnie dodano nową naprawę");
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
