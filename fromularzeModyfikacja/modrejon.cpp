#include "modrejon.h"
#include "ui_modrejon.h"

#include <QMessageBox>
#include <QSqlQuery>

modRejon::modRejon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modRejon)
{
    ui->setupUi(this);
}

modRejon::~modRejon()
{
    delete ui;
}

void modRejon::on_anuluj_clicked()
{
    this->hide();
    delete this;

}

void modRejon::on_Ok_clicked()
{
    auto w = new QMessageBox();
    QString rej = ui->lineEdit->text();
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
