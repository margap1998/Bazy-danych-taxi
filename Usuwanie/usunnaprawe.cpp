#include "usunnaprawe.h"
#include "ui_usunnaprawe.h"

#include <QMessageBox>
#include <QSqlQuery>

UsunNaprawe::UsunNaprawe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsunNaprawe)
{
    ui->setupUi(this);
    model.setQuery("Select DISTINCT  Numer_faktury from Naprawa");
    ui->comboBox->setModel(&model);
    modelR.setQuery("Select DISTINCT Numer_rejestracyjny from Naprawa");
    ui->nrRejCB->setModel(&modelR);
    modelW.setQuery("Select DISTINCT Nazwa from Naprawa");
    ui->warsztat->setModel(&modelW);
}

UsunNaprawe::~UsunNaprawe()
{
    delete ui;
}

void UsunNaprawe::on_usun_clicked()
{
    QString numer = ui->comboBox->currentText();
    QString war = ui->warsztat->currentText();
    QString nrRej = ui->nrRejCB->currentText();
    if (numer=="")
    {
        new QMessageBox(QMessageBox::Icon::Information,"","Nie wypełniono wymaganych pól");
    }
    else
    {
        QString pol = "DELETE FROM `naprawa` WHERE Numer_faktury = '"+numer+"' AND Numer_rejestracyjny = '"+nrRej+"' AND Nazwa = '"+war+"'";
        QSqlQuery q1;
        auto w = new QMessageBox();
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych.");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba usunięcia naprawy.");
            w->show();
        }
        else{
            w->setText("Pomyślnie usunięto naprawę.");
            w->show();
            on_wroc_clicked();
        }
    }

}

void UsunNaprawe::on_wroc_clicked()
{
    this->hide();
    delete this;
}
