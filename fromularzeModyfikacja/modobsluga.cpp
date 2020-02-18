#include "modobsluga.h"
#include "ui_modobsluga.h"

#include <QMessageBox>
#include <QSqlQuery>

modObsluga::modObsluga(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modObsluga)
{
    ui->setupUi(this);
    modelK.setQuery("SELECT DISTINCT Kierowca from obsluga");
    modelR.setQuery("SELECT DISTINCT Rejon from obsluga");
    ui->rejonCBwyb->setModel(&modelR);
    ui->kierCBwybor->setModel(&modelK);

    ui->rejonCBwyb->setCurrentText("");
    ui->kierCBwybor->setCurrentText("");

    umodelK.setQuery("SELECT PESEL FROM kierowca");
    umodelR.setQuery("SELECT Nazwa FROM rejon");
    ui->rejonComboBox->setModel(&modelR);
    ui->kierowcaComboBox->setModel(&modelK);
}

modObsluga::~modObsluga()
{
    delete ui;
}

void modObsluga::on_anuluj_clicked()
{
    this->hide();
    delete this;

}

void modObsluga::on_Ok_clicked()
{
    QString rejWyb = ui->rejonCBwyb->currentText();
    QString kierWyb = ui->kierCBwybor->currentText();

    auto w = new QMessageBox();
    QString rej = ui->rejonComboBox->currentText();
    QString pes = ui->kierowcaComboBox->currentText();
    QString pol = "UPDATE obsluga SET"
                  " Kierowca = '"+pes+"', "
                  " Rejon = '"+rej+"'"
                  " WHERE Kierowca = '"+kierWyb+"', "
                  " Rejon='"+rejWyb+"'";
    if (!(rej == "" || pes=="" ||rejWyb==""||kierWyb==""))
    {
        QSqlQuery q1;
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba modyfikacji informacji o obsłudze");
            w->show();
        }
        else{
            w->setText("Pomyślnie zmieniono kierowcę do obsługi rejonu");
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
