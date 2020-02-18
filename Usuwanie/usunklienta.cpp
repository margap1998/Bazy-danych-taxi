#include "usunklienta.h"
#include "ui_usunklienta.h"

#include <QMessageBox>
#include <QSqlQuery>

UsunKlienta::UsunKlienta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsunKlienta)
{
    ui->setupUi(this);
    model.setQuery("Select Numer_telefonu from Klient");
    ui->comboBox->setModel(&model);
}

UsunKlienta::~UsunKlienta()
{
    delete ui;
}

void UsunKlienta::on_usun_clicked()
{
    QString numer = ui->comboBox->currentText();

    if (numer=="")
    {
        new QMessageBox(QMessageBox::Icon::Information,"","Nie wypełniono wymaganych pól");
    }
    else
    {
        QString pol = "DELETE FROM `Klient` WHERE Numer_telefonu = '"+numer+"'";
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
            w->setText("Nieudana próba usunięcia klienta.");
            w->show();
        }
        else{
            w->setText("Pomyślnie usunięto klienta.");
            w->show();
            on_wroc_clicked();
        }
    }

}

void UsunKlienta::on_wroc_clicked()
{
    this->close();
    delete this;
}
