#include "modulica.h"
#include "ui_modulica.h"

#include <QMessageBox>
#include <QSqlQuery>

modUlica::modUlica(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modUlica)
{
    ui->setupUi(this);
    modelU.setQuery("Select DISTINCT Nazwa from Ulica");
    model.setQuery("Select DISTINCT Rejon from Ulica");
    modelR.setQuery("Select Nazwa from Rejon");
    ui->ulica->setModel(&modelU);
    ui->rejonCBwyb->setModel(&model);
    ui->rejonComboBox->setModel(&modelR);
}

modUlica::~modUlica()
{
    delete ui;
}

void modUlica::on_anuluj_clicked()
{
    this->close();
    delete this;
}

void modUlica::on_Ok_clicked()
{
    QString rejwyb = ui->rejonCBwyb->currentText();
    QString nazwawyb = ui->ulica->currentText();

    QString rej = ui->rejonComboBox->currentText();
    QString nazwa = ui->nazwaUlicyLineEdit->text();
    auto w = new QMessageBox();
    if (!(rej=="" || nazwa == ""||rejwyb==""||nazwawyb==""))
    {
        QSqlQuery q1;
        QString pol =
                "UPDATE Ulica "
                " SET "
                " Nazwa = '"+nazwa+"',"
                " Rejon = '"+rej+"'"
                " WHERE "
                " Rejon = '"+rejwyb+"' "
                " AND Nazwa = '"+nazwawyb+"'";
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba modyfikacji ulicy");
            w->show();
        }
        else{
            w->setText("Pomyślnie zmodyfikowano ulicę");
            w->show();
            on_anuluj_clicked();
        }
    }
    else
    {
        w->setText("Uzupełnij puste pola");
        w->show();
    }


}


