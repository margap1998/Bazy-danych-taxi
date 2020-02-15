#include "szukajaktywnejpromocji.h"
#include "ui_szukajaktywnejpromocji.h"
#include <QMessageBox>
szukajAktywnejPromocji::szukajAktywnejPromocji(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajAktywnejPromocji)
{
    modelR =model;
    ui->setupUi(this);
}

szukajAktywnejPromocji::~szukajAktywnejPromocji()
{
    delete ui;
}

void szukajAktywnejPromocji::on_wrocButton_clicked()
{
    this->hide();
    delete this;
}

void szukajAktywnejPromocji::on_szukajButton_clicked()
{
    QString nrTel,kodProm,odDat,doDat;

    QString filtr = "";
    if(ui->numerCheckBox->isChecked())
    {
        nrTel = ui->NumerLineEdit->text();
        if (nrTel == "")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Proszę uzupełnić numer lub odznaczyć szukanie po numerze"))->show();
            return;
        }
        filtr ="Numer_telefonu LIKE '%"+nrTel+"%'";
    }
    if(ui->kodPromocji->isChecked())
    {
        kodProm = ui->lineEdit->text();
        if (kodProm == "")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Proszę uzupełnić numer lub odznaczyć szukanie po numerze"))->show();
            return;
        }
        if (filtr!="")
            filtr = filtr + " AND ";
        filtr = filtr+"Kod LIKE '%"+ kodProm +"%'";
    }
    if(ui->odCheckBox->isChecked())
    {
        odDat = ui->odDateEdit->text();
        if (filtr!="")
            filtr = filtr + " AND ";
        filtr = filtr+"Data_aktywacji >= STR_TO_DATE('"+odDat+"','yyyy-MM-dd')";
    }
    if(ui->DocheckBox->isChecked())
    {
        doDat = ui->doDateEdit->text();
        if (filtr!="")
            filtr = filtr + " AND ";
        filtr = filtr+"Data_aktywacji <= STR_TO_DATE('"+doDat+"','yyyy-MM-dd')";

    }
    if((ui->odDateEdit->date()>ui->doDateEdit->date())
            && ui->odCheckBox->isChecked()
            && ui->DocheckBox->isChecked())
    {
        new QMessageBox(QMessageBox::Icon::Warning,"","Data \"od\" jest większa od daty\"do\"");
        return;
    }
    modelR->setFilter(filtr);
    modelR->select();
    on_wrocButton_clicked();
}
