#include "szukajulicy.h"
#include "ui_szukajulicy.h"

#include <QMessageBox>

szukajUlicy::szukajUlicy(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajUlicy)
{
    modelR =model;
    ui->setupUi(this);
}

szukajUlicy::~szukajUlicy()
{
    delete ui;
}
void szukajUlicy::on_wrocButton_clicked()
{
    this->hide();
    delete this;
}

void szukajUlicy::on_szukajButton_clicked()
{
    QString filtr = "";
    if (ui->rejonCB->isChecked()){
        QString rej = ui->rejonLE->text();
        if (rej == "")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Podano pusty wzorzec"))->show();
            return;
        }
        filtr="Rejon LIKE '%"+rej+"%'";
    }

    if (ui->ulicaCB->isChecked()){
        QString ul = ui->ulicaLE->text();
        if (ul=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Podano pusty wzorzec"))->show();
            return;
        }
        if (ul.length()>25)
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Przekroczono dozwoloną długość nazwy ulicy"))->show();
            return;
        }
        if (filtr!="")
            filtr = filtr + " AND ";
        filtr=filtr+"Nazwa LIKE '%"+ul+"%'";
    }


    modelR->setFilter(filtr);
    modelR->select();
    on_wrocButton_clicked();
}
