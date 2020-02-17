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
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij nazwę poszukiwanego rejonu lub odznacz szukanie po rejonie"))->show();
            return;
        }
        filtr="Rejon LIKE '%"+rej+"%'";
    }

    if (ui->ulicaCB->isChecked()){
        QString ul = ui->ulicaLE->text();
        if (ul=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij nazwę ulicy lub odznacz szukanie po nazwie"))->show();
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
