#include "szukajpromocji.h"
#include "ui_szukajpromocji.h"

#include <QMessageBox>

szukajPromocji::szukajPromocji(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajPromocji)
{
    modelR =model;
    ui->setupUi(this);
}

szukajPromocji::~szukajPromocji()
{
    delete ui;
}
void szukajPromocji::on_wrocButton_clicked()
{
    this->close();
    delete this;
}

void szukajPromocji::on_szukajButton_clicked()
{
    QString filtr = "";
    if (ui->kodCB->isChecked()){
        QString kodProm = ui->kodLE->text();
        if (kodProm == "")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Proszę uzupełnić kod lub odznaczyć szukanie po kodzie promocji"))->show();
            return;
        }
        filtr = filtr+"Kod LIKE '%"+ kodProm +"%'";
    }
    if (ui->nazwaCB->isChecked()){
        QString naz = ui->nazwaLE->text();
        if (naz == "")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Proszę uzupełnić nazwę promocji lub odznaczyć szukanie po nazwie"))->show();
            return;
        }
        if (filtr!="") filtr = filtr + " AND ";
        filtr+="Nazwa LIKE '%"+naz+"%'";
    }
    if (ui->odKwotaCB->isChecked()){
        QString koszt = QVariant(ui->odKwotaDSB->value()).toString();
        if (filtr!="")filtr+=" AND ";
        filtr+="Kwota_znizki >= "+koszt;
    }
    if (ui->doKwotaCB->isChecked()){
        QString koszt = QVariant(ui->doKwotaDSB->value()).toString();
        if (filtr!="")filtr+=" AND ";
        filtr+="Kwota_znizki <= "+koszt;
    }
    if (ui->odProcentCB->isChecked()){
        QString pr = ui->odProcentZniKiSpinBox->text();
        if (filtr!="")filtr+=" AND ";
        filtr+="Procent_znizki >= "+pr;
    }
    if (ui->doProcentCB->isChecked()){
        QString pr = ui->doProcentZniKiSpinBox->text();
        if (filtr!="")filtr+=" AND ";
        filtr+="Procent_znizki <= "+pr;
    }

    if ((ui->odKwotaDSB->value()>ui->doKwotaDSB->value()) && ui->odKwotaCB->isChecked() && ui->doKwotaCB->isChecked()){
        (new QMessageBox(QMessageBox::Icon::Warning,"","Kwota \"od\" jest większa od kwoty \"do\". Odznacz lub popraw jedną z kwót"))->show();
        return;
    }

    if ((ui->odProcentZniKiSpinBox->value()>ui->doProcentZniKiSpinBox->value())&&
            ui->odProcentCB->isChecked()&&ui->doProcentCB->isChecked()){
        (new QMessageBox(QMessageBox::Icon::Warning,"","Procent zniżki \"od\" jest większa od procenta \"do\". Odznacz lub popraw jeden z procentów"))->show();
        return;
    }

    modelR->setFilter(filtr);
    modelR->select();
    on_wrocButton_clicked();
}
