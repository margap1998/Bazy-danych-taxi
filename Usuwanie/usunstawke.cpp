#include "usunstawke.h"
#include "ui_usunstawke.h"

#include <QMessageBox>
#include <QSqlQuery>

UsunStawke::UsunStawke(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UsunStawke)
{
    ui->setupUi(this);
    model.setQuery("Select Kod from Stawka");
    ui->comboBox->setModel(&model);
}

UsunStawke::~UsunStawke()
{
    delete ui;
}

void UsunStawke::on_usun_clicked()
{
    QString kod = ui->comboBox->currentText();

    if (kod=="")
    {
        (new QMessageBox(QMessageBox::Icon::Information,"","Nie wypełniono wymaganych pól"))->show();
    }
    else
    {
        QString pol = "DELETE FROM `Stawka` WHERE Kod = "+kod+"";
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
            w->setText("Nieudana próba usunięcia Stawki.");
            w->show();
        }
        else{
            w->setText("Pomyślnie usunięto Stawkę");
            w->show();
            on_wroc_clicked();
        }
    }

}

void UsunStawke::on_wroc_clicked()
{
    this->close();
    delete this;
}
