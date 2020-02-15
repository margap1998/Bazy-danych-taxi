#include "szukajprzejazdu.h"
#include "ui_szukajprzejazdu.h"

#include <QMessageBox>

szukajPrzejazdu::szukajPrzejazdu(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajPrzejazdu)
{
    modelR =model;
    ui->setupUi(this);
}

szukajPrzejazdu::~szukajPrzejazdu()
{
    delete ui;
}
void szukajPrzejazdu::on_wrocButton_clicked()
{
    this->hide();
    delete this;
}

void szukajPrzejazdu::on_szukajButton_clicked()
{
    QString pod = "(SELECT PESEL FROM kierowca WHERE ";
    QString filtr = "";
    if (ui->nrParCB->isChecked()){

    }
    if (ui->nrTelCB->isChecked()){}
    if (ui->doCenaCB->isChecked()){}
    if (ui->odCenaCB->isChecked()) {}
    if (ui->odTrasaCB->isChecked()) {}
    if (ui->doTrasaCB->isChecked()) {}
    if (ui->stawkaCB ->isChecked()) {}
    if (ui->odDatyRozCB->isChecked()){}
    if (ui->doDatyRozCB->isChecked()) {}
    if (ui->imieKierowcyCB->isChecked()){
        QString imie;
        imie = ui->imieKierowcyLE->text();
        if (imie=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Podano pusty wzorzec imienia"))->show();
            return;
        }
        pod=pod+" Imie LIKE '%"+imie+"%' ";
    }
    if (ui->nazwiskoKierowcyCB->isChecked()){
        QString nazwisko = ui->nazwiskoKierowcyLE->text();
        if (nazwisko=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Podano pusty wzorzec nazwiska"))->show();
            return;
        }
        if(ui->imieKierowcyCB->isChecked()) pod =pod+" AND ";
        pod=pod+" Nazwisko LIKE '%"+nazwisko+"%' ";
    }
    pod=pod+")";
    if ((ui->odcenaDoubleSpinBox->value()>ui->docenaDoubleSpinBox->value())
            && ui->odCenaCB->isChecked() && ui->doCenaCB->isChecked()){

    }

   if ((ui->oddataRozpoczeciaDateTimeEdit->date() > ui->dodataRozpoczeciaDateTimeEdit->date())
           && ui->odDatyRozCB->isChecked() && ui->doDatyRozCB->isChecked()){

   }

   if (ui->imieKierowcyCB->isChecked()||ui->nazwiskoKierowcyCB->isChecked()){
      if (filtr!="") filtr+=" AND ";
      filtr+=" PESEL IN "+pod;
   }
    modelR->setFilter(filtr);
}
