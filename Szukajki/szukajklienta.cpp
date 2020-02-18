#include "szukajklienta.h"
#include "ui_szukajklienta.h"

#include <QMessageBox>

szukajKlienta::szukajKlienta(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajKlienta)
{
    modelR =model;
    ui->setupUi(this);
}

szukajKlienta::~szukajKlienta()
{
    delete ui;
}

void szukajKlienta::on_wrocButton_clicked()
{
    this->close();
    delete this;
}

void szukajKlienta::on_szukajButton_clicked()
{
    QString filtr = "";
    if (ui->numerCheckBox->isChecked()){
        QString nrTel = ui->NumerLineEdit->text();
        if (nrTel == "")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij numer lub odznacz szukanie po numerze"))->show();
            return;
        }
        filtr ="Numer_telefonu LIKE '%"+nrTel+"%'";
    }
    if (ui->imieCB->isChecked()){
        QString imie = ui->imieLE->text();
        if(imie=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij imie lub odznacz szukanie po imieniu"))->show();
            return;
        }
        if (filtr!="") filtr =" AND ";
        filtr+=" Imie LIKE '%"+imie+"%' ";
    }
    if (ui->nazwiskoCB->isChecked()){
        QString nazwisko = ui->NazwiskoLE->text();
        if(nazwisko=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij nazwisko lub odznacz szukanie po nazwisku"))->show();
            return;
        }
        if (filtr!="") filtr =" AND ";
        filtr=filtr+" Nazwisko LIKE '%"+nazwisko+"%' ";
    }
    if(ui->odCheckBox->isChecked())
    {
        QString data = ui->odDateEdit->text();
        if(filtr!="")filtr+=" AND ";
        filtr += "Data_rejestracji>='"+data+"'";
    }
    if(ui->DocheckBox->isChecked())
    {
        QString data = ui->doDateEdit->text();
        if(filtr!="")filtr+=" AND ";
        filtr += "Data_rejestracji<='"+data+"'";
    }
    if (ui->doDateEdit->date() < ui->odDateEdit->date() &&
            ui->odCheckBox->isChecked() && ui->DocheckBox->isChecked())
    {
        (new QMessageBox(QMessageBox::Icon::Warning,"","Data \"od\" jest większa od daty \"do\", odznacz lub popraw jedną z dat"))->show();
        return;
    }
    modelR->setFilter(filtr);
    modelR->select();
    on_wrocButton_clicked();
}
