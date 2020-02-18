#include "dodajrejon.h"
#include "ui_dodajrejon.h"

#include <QMessageBox>
#include <QSqlQuery>

DodajRejon::DodajRejon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajRejon)
{
    ui->setupUi(this);
}

DodajRejon::~DodajRejon()
{
    delete ui;
}


void DodajRejon::on_Ok_clicked()
{
    auto w = new QMessageBox();
    QString rej = ui->lineEdit->text();
    if(rej.length()>25){w->setText("Nazwa rejonu nie może przekraczać 25 znaków");w->show();return;}
    if (rej!= "")
    {
        QString pol = "INSERT INTO rejon VALUES('"+rej+"')";
        QSqlQuery q1;
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba dodania rejonu");
            w->show();
        }
        else{
            w->setText("Pomyślnie dodano rejon");
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
void DodajRejon::on_anuluj_clicked()
{
    this->close();
    delete this;
}
