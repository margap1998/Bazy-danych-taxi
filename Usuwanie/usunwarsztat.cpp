#include "usunwarsztat.h"
#include "ui_usunwarsztat.h"

#include <QMessageBox>
#include <QSqlQuery>

usunWarsztat::usunWarsztat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usunWarsztat)
{
    ui->setupUi(this);
}

usunWarsztat::~usunWarsztat()
{
    delete ui;
}

void usunWarsztat::on_wroc_clicked()
{
    this->hide();
    delete this;
}

void usunWarsztat::on_usun_clicked()
{
    QString war = ui->comboBox->currentText();

    if (war=="")
    {
        (new QMessageBox(QMessageBox::Icon::Information,"","Nie wypełniono wymaganych pól"))->show();
    }
    else
    {
        QString pol = "DELETE FROM warsztat WHERE nazwa = '"+war+"'";
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
            w->setText("Nieudana próba usunięcia warsztatu.");
            w->show();
        }
        else{
            w->setText("Pomyślnie usunięto warsztat");
            w->show();
            on_wroc_clicked();
        }
    }
}
