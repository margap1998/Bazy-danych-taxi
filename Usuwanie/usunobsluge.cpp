#include "usunobsluge.h"
#include "ui_usunobsluge.h"

#include <QMessageBox>
#include <QSqlQuery>

usunObsluge::usunObsluge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usunObsluge)
{
    ui->setupUi(this);
    modelK.setQuery("SELECT DISTINCT Kierowca from obsluga");
    modelR.setQuery("SELECT DISTINCT Rejon from obsluga");
    ui->rejon->setModel(&modelR);
    ui->ulica->setModel(&modelK);
}

usunObsluge::~usunObsluge()
{
    delete ui;
}
void usunObsluge::on_usun_clicked()
{
    QString nazwa = ui->rejon->currentText();
    QString pes = ui->ulica->currentText();
    if (nazwa==""||pes=="")
    {
        new QMessageBox(QMessageBox::Icon::Information,"","Nie wypełniono wymaganych pól");
    }
    else
    {
        QString pol = "DELETE FROM obsluga WHERE rejon = '"+nazwa+"' AND Kierowca = '"+pes+"'";
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
            w->setText("Nieudana próba usunięcia obsługi.");
            w->show();
        }
        else{
            w->setText("Pomyślnie usunięto obsługę");
            w->show();
            on_wroc_clicked();
        }
    }

}


void usunObsluge::on_wroc_clicked()
{
    this->close();
    delete this;
}
