#include "modklient.h"
#include "ui_modklient.h"

#include <QMessageBox>
#include <QSqlQuery>

modKlient::modKlient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modKlient)
{
    ui->setupUi(this);
    model.setQuery("Select Numer_telefonu from Klient");
    ui->nrTelCBwybor->setModel(&model);
}

modKlient::~modKlient()
{
    delete ui;
}

void modKlient::on_anuluj_clicked()
{
    this->close();
    delete this;
}

void modKlient::on_Ok_clicked()
{
    QString nrWyb = ui->nrTelCBwybor->currentText();
    QString nr = ui->numerTelefonuLineEdit->text();
    QString email = ui->eMailLineEdit->text();
    QString data = ui->dataRejestracjiDateEdit->text();
    QString imie = ui->imiLineEdit->text();
    QString nazwisko = ui->nazwiskoLineEdit->text();
    auto w = new QMessageBox();

    QSqlQuery q1;
    if (!(nr == "" || email==""||data==""||nrWyb==""))
    {
        QString pol ="UPDATE klient SET "
                "Numer_telefonu = '"+nr+"',"
                " email = '"+email+"', "
                " Data_rejestracji = '"+data+"',"
                " Imie = '"+imie+"',"
                " Nazwisko = '"+nazwisko+"'"
                " WHERE Numer_telefonu = '"+nrWyb+"'";
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba modyfikacji klienta");
            w->show();
        }
        else{
            w->setText("Pomyślnie zmodyfikowano klienta");
            w->show();
            on_anuluj_clicked();
        }
    }
    else
    {
        w->setText("Proszę uzupełnić pola oznaczone gwiazdką");
        w->show();
    }
}
