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
    this->hide();
    delete this;
}

void szukajKlienta::on_szukajButton_clicked()
{
    QString filtr = "";
    if (ui->numerCheckBox->isChecked()){
        QString nrTel = ui->NumerLineEdit->text();
        if (nrTel == "")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Proszę uzupełnić numer lub odznaczyć szukanie po numerze"))->show();
            return;
        }
        filtr ="Numer_telefonu LIKE '%"+nrTel+"%'";
    }
    if (ui->imieCB->isChecked()){
        QString imie;
        imie = ui->imieLE->text();
        if (filtr!="") filtr =" AND ";
        filtr+=" Imie LIKE '%"+imie+"%' ";
    }
    if (ui->nazwiskoCB->isChecked()){
        QString nazwisko = ui->NazwiskoLE->text();
        if (filtr!="") filtr =" AND ";
        filtr=filtr+" Nazwisko LIKE '%"+nazwisko+"%' ";
    }
    if(ui->odCheckBox->isChecked())
    {
        QString data = ui->odDateEdit->text();
        if(filtr!="")filtr+=" AND ";
        filtr += "Data_rejestracji>=STR_TO_DATE('"+data+"','yyyy-MM-dd')";
    }
    if(ui->DocheckBox->isChecked())
    {
        QString data = ui->doDateEdit->text();
        if(filtr!="")filtr+=" AND ";
        filtr += "Data_rejestracji<=STR_TO_DATE('"+data+"','yyyy-MM-dd')";
    }
    if (ui->doDateEdit->date() < ui->odDateEdit->date() &&
            ui->odCheckBox->isChecked() && ui->DocheckBox->isChecked())
    {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Ustawiono sprzeczny przedział dat"))->show();
            return;
    }
    modelR->setFilter(filtr);
    modelR->select();
    on_wrocButton_clicked();
}
