#include "logowanie.h"
#include "taxibaza.h"
#include "ui_logowanie.h"
#include "menu.h"

#include <QMessageBox>
#include <QSqlDatabase>

Logowanie::Logowanie(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Logowanie)
{
    ui->setupUi(this);
}

Logowanie::~Logowanie()
{
    delete ui;
}

void Logowanie::on_pushButton_2_clicked()
{
    TaxiBAZA *d = (TaxiBAZA*)parentWidget();
    d->close();
}

void Logowanie::on_pushButton_clicked()
{
    QString adr = ui->adresSerweraBazyDanychLineEdit->text();
    QVariant port = ui->portLineEdit->text();
    QString user = ui->uYtkownikLineEdit->text();
    QString haslo = ui->hasloLineEdit->text();
    QSqlDatabase db = QSqlDatabase::database();
    if (adr==""||port==""||user=="")
    {
        (new QMessageBox(QMessageBox::Icon::Warning,"","Należy wpisać wymagane dane.\nSkontaktuj się z administratorem, jeśli ich nie posiadasz."))->show();
    }
    else
    {
        db.setPort(port.toInt());
        db.setHostName(adr);
        db.setUserName(user);
        db.setPassword(haslo);
        db.setDatabaseName("poltaxi");
        if(db.open())
        {
            this->hide();
            (new Menu(this,parentWidget()))->show();
        }
        else
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Zalogowanie się nie udane."
                                                           "\nSpróbuj jeszcze raz, sprawdź dane logowania"
                                                           "\nSkontaktuj się z administratorem, jeśli problem się powtarza."))->show();
        }
    }
}
