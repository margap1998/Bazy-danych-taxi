#include "modulica.h"
#include "ui_modulica.h"

#include <QMessageBox>
#include <QSqlQuery>

modUlica::modUlica(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modUlica)
{
    ui->setupUi(this);
}

modUlica::~modUlica()
{
    delete ui;
}

void modUlica::on_anuluj_clicked()
{
    this->hide();
    delete this;
}

void modUlica::on_Ok_clicked()
{
    auto w = new QMessageBox();
    QString rej = ui->rejonComboBox->currentText();
    QString nazwa = ui->nazwaUlicyLineEdit->text();
    if (!(rej=="" || nazwa == ""))
    {
        QString pol = "INSERT INTO ulica(Nazwa,Rejon) VALUES('"+nazwa+"', '"+rej+"')";
        QSqlQuery q1;
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba dodania ulicy");
            w->show();
        }
        else{
            w->setText("Pomyślnie dodano ulicę");
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
