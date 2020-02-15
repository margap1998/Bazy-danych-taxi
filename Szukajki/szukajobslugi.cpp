#include "szukajobslugi.h"
#include "ui_szukajobslugi.h"

#include <QMessageBox>

szukajObslugi::szukajObslugi(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajObslugi)
{
    modelR =model;
    ui->setupUi(this);
}

szukajObslugi::~szukajObslugi()
{
    delete ui;
}
void szukajObslugi::on_wrocButton_clicked()
{
    this->hide();
    delete this;
}

void szukajObslugi::on_szukajButton_clicked()
{
    QString pod = "(SELECT PESEL FROM kierowca WHERE ";
    QString filtr = "";
    if (ui->imieCB->isChecked()){
        QString imie;
        imie = ui->imieLE->text();
        if (imie=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Podano pusty wzorzec imienia"))->show();
            return;
        }
        pod=pod+" Imie LIKE '%"+imie+"%' ";
    }
    if (ui->nazwiskoCB->isChecked()){
        QString nazwisko = ui->nazwiskoLE->text();
        if (nazwisko=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Podano pusty wzorzec nazwiska"))->show();
            return;
        }
        if(ui->imieCB->isChecked()) pod =pod+" AND ";
        pod=pod+" Nazwisko LIKE '%"+nazwisko+"%' ";
    }
    pod=pod+")";
    if(ui->imieCB->isChecked()||ui->imieCB->isChecked()) filtr ="Kierowca IN "+pod;
    if (ui->rejonCB->isChecked()){
        QString rej = ui->rejonLE->text();
        if (rej=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Podano pusty wzorzec"))->show();
            return;
        }
        if (filtr!="") filtr+=" AND ";
        filtr+=" rejon LIKE '%"+rej+"%'";
    }
    modelR->setFilter(filtr);
    modelR->select();
    on_wrocButton_clicked();
}
