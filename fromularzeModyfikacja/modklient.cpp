#include "modklient.h"
#include "ui_modklient.h"

#include <QMessageBox>
#include <QSqlQuery>

modKlient::modKlient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modKlient)
{
    ui->setupUi(this);
}

modKlient::~modKlient()
{
    delete ui;
}

void modKlient::on_anuluj_clicked()
{

}

void modKlient::on_Ok_clicked()
{
    QString pol ="CALL Dodaj_Klienta('";
    QString nr = ui->numerTelefonuLineEdit->text();
    QString email = ui->eMailLineEdit->text();
    QString data = ui->dataRejestracjiDateEdit->text();
    QString imie = ui->imiLineEdit->text();
    QString nazwisko = ui->nazwiskoLineEdit->text();
    auto w = new QMessageBox();
    pol.append(nr+"','");
    pol.append(email+"','");
    pol.append(data+"','");
    pol.append(imie+"','");
    pol.append(nazwisko+"')");

    QSqlQuery q1;
    if (!(nr == "" || email==""||data==""))
    {
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba dodania nowego klienta");
            w->show();
        }
        else{
            w->setText("Pomyślnie dodano nowego klienta");
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