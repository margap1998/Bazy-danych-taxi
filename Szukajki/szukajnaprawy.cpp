#include "szukajnaprawy.h"
#include "ui_szukajnaprawy.h"
#include <QMessageBox>

szukajNaprawy::szukajNaprawy(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajNaprawy)
{
    modelR =model;
    ui->setupUi(this);
}

szukajNaprawy::~szukajNaprawy()
{
    delete ui;
}
void szukajNaprawy::on_wrocButton_clicked()
{
    this->hide();
    delete this;
}

void szukajNaprawy::on_szukajButton_clicked()
{
    QString filtr = "";
    if (ui->numerFakCB->isChecked()){
        QString nF = ui->numerFakLE->text();
        if(nF=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij numer faktury lub odznacz wyszukiwanie po numerze faktury"))->show();
            return;
        }
        filtr+="Numer_faktury LIKE '%"+nF+"%'";
    }
    if (ui->numerRejCB->isChecked()){
        QString nR = ui->numerRejLE->text();
        if(nR=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","uzupełnij numer rejestracyjny lub odznacz wyszukiwanie po numerze rejestracyjnym"))->show();
            return;
        }
        if (filtr!="")filtr+=" AND ";
        filtr+="Numer_rejestracyjny LIKE '%"+nR+"%'";

    }
    if (ui->odKosztCB->isChecked()){
        QString koszt = QVariant(ui->odKosztDoubleSpinBox->value()).toString();
        if (filtr!="")filtr+=" AND ";
        filtr+="Koszt >= "+koszt;
    }
    if (ui->doKosztCB->isChecked()){
        QString koszt = QVariant(ui->doKosztDoubleSpinBox->value()).toString();
        if (filtr!="")filtr+=" AND ";
        filtr+="Koszt <= "+koszt;
    }
    if (ui->odDataCB->isChecked()){
        QString odDat = ui->odDataWykonaniaDateEdit->text();
        if (filtr!="")
            filtr = filtr + " AND ";
        filtr = filtr+"Data_aktywacji >='"+odDat+"'";
    }
    if (ui->doDataCB->isChecked()){
        QString doDat = ui->doDataWykonaniaDateEdit->text();
        if (filtr!="")
            filtr = filtr + " AND ";
        filtr = filtr+"Data_aktywacji <= '"+doDat+"'";
    }

    if (ui->odKosztDoubleSpinBox->value()>ui->doKosztDoubleSpinBox->value() &&
            ui->doKosztCB->isChecked() && ui->odKosztCB->isChecked()){
        (new QMessageBox(QMessageBox::Icon::Warning,"","Koszt \"od\" jest większa od daty \"do\". Odznacz lub popraw jeden z kosztów"))->show();
        return;
    }

    if((ui->odDataWykonaniaDateEdit->date()>ui->doDataWykonaniaDateEdit->date()) &&
            ui->odDataCB->isChecked() &&
            ui->doDataCB->isChecked()){
        (new QMessageBox(QMessageBox::Icon::Warning,"","Data\"od\" jest większa od daty \"do\". Odznacz lub popraw jedną z dat"))->show();
        return;
    }
    modelR->setFilter(filtr);
    modelR->select();
    on_wrocButton_clicked();
}
