#include "usunpojazd.h"
#include "ui_usunpojazd.h"

#include <QMessageBox>
#include <QSqlQuery>

usunPojazd::usunPojazd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usunPojazd)
{
    ui->setupUi(this);
    model.setQuery("SELECT Numer_rejestracyjny FROM pojazd");
    ui->comboBox->setModel(&model);
}

void usunPojazd::on_usun_clicked(){
    QString numer = ui->comboBox->currentText();

    if (numer=="")
    {
        new QMessageBox(QMessageBox::Icon::Information,"","Nie wypełniono wymaganych pól");
    }
    else
    {
        QString pol = "DELETE FROM `pojazd` WHERE Numer_rejestracyjny = '"+numer+"'";
        QSqlQuery q1;
        auto w = new QMessageBox();
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba usunięcia pojazdu.");
            w->show();
        }
        else{
            w->setText("Pomyślnie usunięto pojazdu");
            w->show();
        }
    }
}

void usunPojazd::on_wroc_clicked(){
    this->hide();
    delete this;
}

usunPojazd::~usunPojazd()
{
    delete ui;
}
