#include "usunulice.h"
#include "ui_usunulice.h"

#include <QMessageBox>
#include <QSqlQuery>

usunUlice::usunUlice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usunUlice)
{
    ui->setupUi(this);
    modelR.setQuery("Select DISTINCT Rejon from ulica");
    ui->rejon->setModel(&modelR);
    modelU.setQuery("Select DISTINCT Nazwa from ulica");
    ui->ulica->setModel(&modelU);
}

usunUlice::~usunUlice()
{
    delete ui;
}

void usunUlice::on_usun_clicked()
{
    QString nazwa = ui->rejon->currentText();
    QString ulica = ui->ulica->currentText();
    if (nazwa==""||ulica=="")
    {
        new QMessageBox(QMessageBox::Icon::Information,"","Nie wypełniono wymaganych pól");
    }
    else
    {
        QString pol = "DELETE FROM ulica WHERE rejon = '"+nazwa+"' AND nazwa = '"+ulica+"'";
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
            w->setText("Nieudana próba usunięcia ulicy.");
            w->show();
        }
        else{
            w->setText("Pomyślnie usunięto ulicę");
            w->show();
            on_wroc_clicked();
        }
    }

}


void usunUlice::on_rejon_currentTextChanged(const QString &arg1)
{
    modelU.setQuery("Select Nazwa from ulica WHERE rejon = '"+arg1+"'");
    ui->ulica->setModel(&modelU);
}

void usunUlice::on_wroc_clicked()
{
    this->hide();
    delete this;
}
