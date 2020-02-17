#include "usunpromocje.h"
#include "ui_usunpromocje.h"

#include <QMessageBox>
#include <QSqlQuery>

UsunPromocje::UsunPromocje(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsunPromocje)
{
    ui->setupUi(this);
    model.setQuery("Select Kod from Promocja");
    ui->comboBox->setModel(&model);
}

UsunPromocje::~UsunPromocje()
{
    delete ui;
}

void UsunPromocje::on_usun_clicked()
{
    QString numer = ui->comboBox->currentText();

    if (numer=="")
    {
        new QMessageBox(QMessageBox::Icon::Information,"","Nie wypełniono wymaganych pól");
    }
    else
    {
        QString pol = "DELETE FROM `Promocja` WHERE Kod = '"+numer+"'";
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
            w->setText("Nieudana próba usunięcia promocji.");
            w->show();
        }
        else{
            w->setText("Pomyślnie usunięto promocję");
            w->show();
            on_wroc_clicked();
        }
    }

}

void UsunPromocje::on_wroc_clicked()
{
    this->hide();
    delete this;
}
