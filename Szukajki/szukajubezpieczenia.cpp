#include "szukajubezpieczenia.h"
#include "ui_szukajubezpieczenia.h"

#include <QMessageBox>

szukajUbezpieczenia::szukajUbezpieczenia(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajUbezpieczenia)
{
    modelR =model;
    ui->setupUi(this);
}

szukajUbezpieczenia::~szukajUbezpieczenia()
{
    delete ui;
}
void szukajUbezpieczenia::on_wrocButton_clicked()
{
    this->hide();
    delete this;
}

void szukajUbezpieczenia::on_szukajButton_clicked()
{
    QString filtr = "";
    if (ui->numerUbCB->isChecked()){
        QString nrUb =ui->numerUbkLE->text();
        if(nrUb=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij numerze ubezpieczenia lub odznacz szukanie po numerze ubezpieczenia"))->show();
            return;
        }
        filtr+="Numer_ubezpiecznia LIKE '%"+nrUb+"%'";
    }
    if (ui->numerRejCB->isChecked()){
        QString nrRej = ui->numerRejLE->text();
        if(nrRej=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij numerze ubezpieczenia lub odznacz szukanie po numerze ubezpieczenia"))->show();
            return;
        }
        if (filtr!="") filtr+=" AND ";
        filtr+="Numer_rejestracyjny LIKE '%"+nrRej+"%'";
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
    if (ui->odDataZakCB->isChecked()){
        QString data = ui->odDataZakDateEdit->text();
        if(filtr!="")filtr+=" AND ";
        filtr += "Data_zakonczenia>='"+data+"'";}
    if (ui->doDataZakCB->isChecked()){
        QString data = ui->doDataZakDateEdit->text();
        if(filtr!="")filtr+=" AND ";
        filtr += "Data_zakonczenia<='"+data+"'";}
    if (ui->odDataZawCB->isChecked()){
        QString data = ui->odDataZawDateEdit->text();
        if(filtr!="")filtr+=" AND ";
        filtr += "Data_zawarcia>='"+data+"'";}
    if (ui->doDataZawCB->isChecked()){
        QString data = ui->doDataZawDateEdit->text();
        if(filtr!="")filtr+=" AND ";
        filtr += "Data_zawarcia<='"+data+"'";}

    if (ui->odKwotaUbCB->isChecked()){
        QString koszt = QVariant(ui->odkwotaDoubleSpinBox->value()).toString();
        if (filtr!="")filtr+=" AND ";
        filtr+="Kwota >= "+koszt;
    }
    if (ui->doKwotaUbCB->isChecked()){
        QString koszt = QVariant(ui->dokwotaDoubleSpinBox->value()).toString();
        if (filtr!="")filtr+=" AND ";
        filtr+="Kwota <= "+koszt;
    }

    if (ui->odKosztCB->isChecked() && ui->doKosztCB->isChecked() &&
            (ui->odKosztDoubleSpinBox->value()>ui->doKosztDoubleSpinBox->value())){
        (new QMessageBox(QMessageBox::Icon::Warning,"","Koszt \"od\" jest większa od kosztu \"do\". Odznacz lub popraw jednen z kosztów"))->show();
        return;
    }
    if (ui->odKwotaUbCB->isChecked() && ui->doKwotaUbCB->isChecked() &&
            (ui->odkwotaDoubleSpinBox->value()>ui->dokwotaDoubleSpinBox->value())){
        (new QMessageBox(QMessageBox::Icon::Warning,"","Kwota \"od\" jest większa od kwoty \"do\". Odznacz lub popraw jedną z kwot"))->show();
        return;
    }
    if (ui->odDataZawCB->isChecked() && ui->doDataZawCB->isChecked() &&
            (ui->odDataZawDateEdit->date()>ui->doDataZawDateEdit->date())){
        (new QMessageBox(QMessageBox::Icon::Warning,"","Data zawarcia \"od\" jest większa od daty \"do\". Odznacz lub popraw jedną z dat"))->show();
        return;
    }
    if (ui->odDataZakCB->isChecked() && ui->doDataZakCB->isChecked() &&
            (ui->odDataZakDateEdit->date()>ui->doDataZakDateEdit->date())){
        (new QMessageBox(QMessageBox::Icon::Warning,"","Data zakończenia \"od\" jest większa od daty \"do\". Odznacz lub popraw jedną z dat"))->show();
        return;
    }

    modelR->setFilter(filtr);
    modelR->select();
    on_wrocButton_clicked();
}
