#include "szukajkodu.h"
#include "ui_szukajkodu.h"

szukajKodu::szukajKodu(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajKodu)
{
    modelR=model;
    ui->setupUi(this);
}

szukajKodu::~szukajKodu()
{
    delete ui;
}

void szukajKodu::on_wrocButton_clicked()
{
    this->hide();
    delete this;
}

void szukajKodu::on_szukajButton_clicked()
{
    QString filtr ="";
    if(ui->kodCB->isChecked()){
        QString kod = ui->kodLE->text();

        filtr += "CAST(kod AS CHAR) LIKE '%"+kod+"%'";
    }
    if(ui->nazwaCB->isChecked()){
        QString nazwa;
        if (filtr!="") filtr+=" AND ";

        filtr += "nazwa LIKE '%"+nazwa+"%'";
    }
    if(ui->odCenyCB->isChecked()){
        QString odCena = QVariant(ui->odCenyDSB->value()).toString();

        if (filtr!="")filtr+=" AND ";
        filtr+=" Cena_za_km>="+odCena;
    }
    if(ui->doCenyCB->isChecked()){
        QString doCena = QVariant(ui->doCenyDSB->value()).toString();
        if (filtr!="")filtr+=" AND ";
        filtr+=" Cena_za_km<="+doCena;
    }
    if(ui->odCenyCB->isChecked() && ui->doCenyCB->isChecked()){
        if(ui->odCenyDSB->value()>ui->doCenyDSB->value()) {
            return;
        }
    }
    modelR->setFilter(filtr);
    modelR->select();
    on_wrocButton_clicked();
}
