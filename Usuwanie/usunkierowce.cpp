#include "usunkierowce.h"
#include "ui_usunkierowce.h"

#include <QMessageBox>
#include <QSqlQuery>

usunkierowce::usunkierowce(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usunkierowce)
{
    ui->setupUi(this);
    model.setQuery("Select PESEL from Kierowca");
    ui->comboBox->setModel(&model);
}

usunkierowce::~usunkierowce()
{
    delete ui;
}

void usunkierowce::on_usun_clicked()
{
    QString PESEL = ui->comboBox->currentText();

    if (PESEL=="")
    {
        new QMessageBox(QMessageBox::Icon::Information,"","Nie wypełniono wymaganych pól");
    }
    else
    {
        QString pol = "DELETE FROM `Kierowca` WHERE PESEL = '"+PESEL+"'";
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
            w->setText("Nieudana próba usunięcia kierowcy.");
            w->show();
        }
        else{
            w->setText("Pomyślnie usunięto kierowcę");
            w->show();
            on_wroc_clicked();
        }
    }

}

void usunkierowce::on_wroc_clicked()
{
    this->close();
    delete this;
}

