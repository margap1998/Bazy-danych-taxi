#include "usunubezpieczenie.h"
#include "ui_usunubezpieczenie.h"

#include <QMessageBox>
#include <QSqlQuery>

UsunUbezpieczenie::UsunUbezpieczenie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsunUbezpieczenie)
{
    ui->setupUi(this);
    model.setQuery("Select Numer_ubezpieczenia from Ubezpieczenie");
    ui->comboBox->setModel(&model);
}

UsunUbezpieczenie::~UsunUbezpieczenie()
{
    delete ui;
}

void UsunUbezpieczenie::on_usun_clicked()
{
    QString numer = ui->comboBox->currentText();

    if (numer=="")
    {
        (new QMessageBox(QMessageBox::Icon::Information,"","Nie wypełniono wymaganych pól"))->show();
    }
    else
    {
        QString pol = "DELETE FROM `Ubezpieczenie` WHERE Numer_ubezpieczenia = '"+numer+"'";
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
            w->setText("Nieudana próba usunięcia Ubezpieczenia.");
            w->show();
        }
        else{
            w->setText("Pomyślnie usunięto Ubezpieczenie");
            w->show();
            on_wroc_clicked();
        }
    }

}

void UsunUbezpieczenie::on_wroc_clicked()
{
    this->close();
    delete this;
}
