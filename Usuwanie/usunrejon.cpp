#include "usunrejon.h"
#include "ui_usunrejon.h"

#include <QMessageBox>
#include <QSqlQuery>

usunrejon::usunrejon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usunrejon)
{
    ui->setupUi(this);
    model.setQuery("Select nazwa from rejon");
    ui->comboBox->setModel(&model);
}

usunrejon::~usunrejon()
{
    delete ui;
}

void usunrejon::on_usun_clicked()
{
    QString nazwa = ui->comboBox->currentText();

    if (nazwa=="")
    {
        new QMessageBox(QMessageBox::Icon::Information,"","Nie wypełniono wymaganych pól");
    }
    else
    {
        QString pol = "DELETE FROM rejon WHERE nazwa = '"+nazwa+"'";
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
            w->setText("Nieudana próba usunięcia rejonu.");
            w->show();
        }
        else{
            w->setText("Pomyślnie usunięto rejon");
            w->show();
            on_wroc_clicked();
        }
    }

}

void usunrejon::on_wroc_clicked()
{
    this->hide();
    delete this;
}

