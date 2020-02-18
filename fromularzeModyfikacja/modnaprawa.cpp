#include "modnaprawa.h"
#include "ui_modnaprawa.h"

#include <QMessageBox>
#include <QSqlQuery>

modNaprawa::modNaprawa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modNaprawa)
{
    ui->setupUi(this);
}

modNaprawa::~modNaprawa()
{
    delete ui;
}

void modNaprawa::on_anuluj_clicked()
{

}

void modNaprawa::on_Ok_clicked()
{
    QMessageBox *w =new QMessageBox();
    QString nrF = ui->numerFakturyLineEdit->text();
    QString data = ui->dataWykonaniaDateEdit->text();
    QString warsztat = ui->warsztatBox->currentText();
    QString nrRej = ui->numerRejestracyjnyBox->currentText();
    QString opis = ui->opisTextEdit->toPlainText();
    QString koszt = QVariant(ui->kosztDoubleSpinBox->value()).toString();
    QString pol= "INSERT INTO naprawa(Numer_faktury,Data,Nazwa,Numer_rejestracyjny,Opis,Koszt) "
                    "VALUES('"+nrF+"',";
    pol.append("'"+data+"','"+warsztat+"',");
    pol.append("'"+nrRej+"','"+opis+"',"+koszt+")");
    QSqlQuery q1;
    if (!(nrF == "" || data==""||warsztat==""||nrRej==""||opis==""||koszt==""))
    {
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba dodania nowej naprawy");
            w->show();
        }
        else{
            w->setText("Pomyślnie dodano nową naprawę");
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
