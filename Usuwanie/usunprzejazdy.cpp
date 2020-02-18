#include "usunprzejazdy.h"
#include "ui_usunprzejazdy.h"

#include <QMessageBox>
#include <QSqlQuery>

UsunPrzejazdy::UsunPrzejazdy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsunPrzejazdy)
{
    ui->setupUi(this);
    model.setQuery("Select Numer_paragonu from Przejazd");
    ui->comboBox->setModel(&model);
}

UsunPrzejazdy::~UsunPrzejazdy()
{
    delete ui;
}

void UsunPrzejazdy::on_usun_clicked()
{
    QString numer = ui->comboBox->currentText();

    if (numer=="")
    {
        new QMessageBox(QMessageBox::Icon::Information,"","Nie wypełniono wymaganych pól");
    }
    else
    {
        QString pol = "DELETE FROM `Przejazd` WHERE Numer_paragonu = '"+numer+"'";
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
            w->setText("Nieudana próba usunięcia przejazdu.");
            w->show();
        }
        else{
            w->setText("Pomyślnie usunięto przejazd");
            w->show();
            on_wroc_clicked();
        }
    }

}

void UsunPrzejazdy::on_wroc_clicked()
{
    this->close();
    delete this;
}
