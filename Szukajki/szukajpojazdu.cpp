#include "szukajpojazdu.h"
#include "ui_szukajpojazdu.h"
#include <QMessageBox>

szukajpojazdu::szukajpojazdu(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajpojazdu)
{
    modelR =model;
    ui->setupUi(this);
}

szukajpojazdu::~szukajpojazdu()
{
    delete ui;
}
void szukajpojazdu::on_wrocButton_clicked()
{
    this->close();
    delete this;
}

void szukajpojazdu::on_szukajButton_clicked()
{
    QString filtr = "";
    if (ui->numerRejCB->isChecked()){
        QString nR = ui->nrRejLE->text();
        if(nR=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij numer rejestracyjny lub odznacz wyszukiwanie po numerze rejestracyjnym"))->show();
            return;
        }
        if (filtr!="")filtr+=" AND ";
        filtr+="Numer_rejestracyjny LIKE '%"+nR+"%'";

    }
    if (ui->markaCB->isChecked()){
        QString marka = ui->markaLE->text();
        if(marka=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij markę lub odznacz wyszukiwanie po marce"))->show();
            return;
        }
        if (filtr!="")filtr+=" AND ";
        filtr+="Marka LIKE '%"+marka+"%'";
    }
    if (ui->modelCB->isChecked()){
        QString model = ui->modelLE->text();
        if(model=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij model lub odznacz wyszukiwanie po modelu"))->show();
            return;
        }
        if (filtr!="")filtr+=" AND ";
        filtr+="Model LIKE '%"+model+"%'";
    }
    if (ui->odDatyCB->isChecked()){
        QString data = ui->odDatyDE->text();
        if(filtr!="")filtr+=" AND ";
        filtr += "Koniec_przegladu>='"+data+"'";
    }
    if (ui->doDatyCB->isChecked()){
        QString data = ui->doDatyDE->text();
        if(filtr!="")filtr+=" AND ";
        filtr += "Koniec_przegladu<='"+data+"'";
    }
    if (ui->doRocznikaCB->isChecked()){
        QString data = QVariant(ui->doRocznikSpinBox->value()).toString();
        if(filtr!="")filtr+=" AND ";
        filtr += "Rocznik<="+data;
    }
    if (ui->odRocznikaCB->isChecked()){
        QString data = QVariant(ui->odRocznikSpinBox->value()).toString();
        if(filtr!="")filtr+=" AND ";
        filtr += "Rocznik>="+data;
    }

    if ((ui->odDatyDE->date()>ui->doDatyDE->date()) && ui->doDatyCB->isChecked() && ui->odDatyCB->isChecked()){
        (new QMessageBox(QMessageBox::Icon::Warning,"","Data \"od\" jest większa od daty \"do\", odznacz lub popraw jedną z dat"))->show();
        return;
    }

    if ((ui->odRocznikSpinBox->value()>ui->doRocznikSpinBox->value()) && ui->odRocznikaCB->isChecked() && ui->doRocznikaCB->isChecked()){
        (new QMessageBox(QMessageBox::Icon::Warning,"","Rocznik \"od\" jest większa od daty \"do\", odznacz lub popraw jedną z rocznik"))->show();
        return;
    }

    modelR->setFilter(filtr);
    modelR->select();
    on_wrocButton_clicked();
}
