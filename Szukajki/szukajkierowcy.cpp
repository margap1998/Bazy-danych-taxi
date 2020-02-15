#include "szukajkierowcy.h"
#include "ui_szukajkierowcy.h"

#include <QMessageBox>

szukajKierowcy::szukajKierowcy(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajKierowcy)
{
    modelR =model;
    ui->setupUi(this);
}

szukajKierowcy::~szukajKierowcy()
{
    delete ui;
}
void szukajKierowcy::on_wrocButton_clicked()
{
    this->hide();
    delete this;
}

void szukajKierowcy::on_szukajButton_clicked()
{
    QString filtr = "";
    if (ui->PESELDB->isChecked())
    {
        QString PESEL = ui->PESELLE->text();
        if (PESEL=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Podano pusty wzorzec PESELu"))->show();
            return;
        }
        filtr += "PESEL LIKE '%"+PESEL+"%'";
    }
    if (ui->imieCB->isChecked())
    {
        QString imie = ui->imieLE->text();
        if (imie=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Podano pusty wzorzec imienia"))->show();
            return;
        }
        if(filtr!="")filtr+=" AND ";
        filtr += "Imie LIKE '%"+imie+"%'";
    }
    if(ui->nazwiskoCB->isChecked())
    {
        QString nazwisko = ui->NazwiskoLE->text();
        if (nazwisko=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Podano pusty wzorzec nazwiska"))->show();
            return;
        }
        if(filtr!="")filtr+=" AND ";
        filtr += "Nazwisko LIKE '%"+nazwisko+"%'";

    }
    if(ui->odCheckBox->isChecked())
    {
        QString data = ui->odDateEdit->text();
        if(filtr!="")filtr+=" AND ";
        filtr += "Data_zatrudnienia>=STR_TO_DATE('"+data+"','yyyy-MM-dd')";
    }
    if(ui->DocheckBox->isChecked())
    {
        QString data = ui->doDateEdit->text();
        if(filtr!="")filtr+=" AND ";
        filtr += "Data_zatrudnienia<=STR_TO_DATE('"+data+"','yyyy-MM-dd')";
    }
    if((ui->odDateEdit->date() > ui->doDateEdit->date()) &&
            ui->odCheckBox->isChecked() && ui->DocheckBox->isChecked())
    {
        (new QMessageBox(QMessageBox::Icon::Warning,"","Data \"od\" jest większa od daty \"do\""))->show();
        return;
    }else{
        modelR->setFilter(filtr);
        modelR->select();
        on_wrocButton_clicked();
    }
}
