#include "modrejon.h"
#include "ui_modrejon.h"

#include <QMessageBox>
#include <QSqlQuery>

modRejon::modRejon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modRejon)
{
    ui->setupUi(this);
    model.setQuery("Select Nazwa from Rejon");
    ui->rejonCBwyb->setModel(&model);
}

modRejon::~modRejon()
{
    delete ui;
}

void modRejon::on_anuluj_clicked()
{
    this->close();
    delete this;
}

void modRejon::on_Ok_clicked()
{
    QString nazwawyb = ui->rejonCBwyb->currentText();

    QString nazwa = ui->lineEdit->text();

    auto w = new QMessageBox();
    if(nazwa.length()>25){w->setText("Nazwa rejonu nie może przekraczać 25 znaków");w->show();return;}
    if (!(nazwa==""))
    {
        QSqlQuery q1;
        QString pol =
                "UPDATE `PolTAXI`.`Rejon` "
                " SET "
                " `Nazwa` = '"+nazwa+"'"

                " WHERE "
                " `Nazwa` = '"+nazwawyb+"'";
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba modyfikacji rejonu");
            w->show();
        }
        else{
            w->setText("Pomyślnie zmodyfikowano rejon");
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

