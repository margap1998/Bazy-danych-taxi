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
    this->close();
    delete this;
}

void szukajPrzejazdu::on_szukajButton_clicked()
{
    QString pod = "(SELECT PESEL FROM kierowca WHERE ";
    QString filtr = "";
    if (ui->nrParCB->isChecked()){
        QString nrPar = ui->nrParLE->text();
        if(nrPar=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij numer paragonu lub odznacz szukanie po numerze paragonu"))->show();
            return;
        }
        filtr+="Numer_paragonu LIKE '%"+nrPar+"%'";
    }
    if (ui->nrTelCB->isChecked()){
        QString nrTel = ui->nrTelLE->text();
        if(nrTel=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij numer telefonu lub odznacz szukanie po numerze telefonu"))->show();
            return;
        }
        if(filtr!="") filtr+= " AND ";
        filtr+="Numer_telefonu LIKE '%"+nrTel+"%'";
    }
    if (ui->doCenaCB->isChecked()){
        QString cena = QVariant(ui->docenaDoubleSpinBox->value()).toString();
        if(filtr!="") filtr+= " AND ";
        filtr+="Cena<="+cena;
    }
    if (ui->odCenaCB->isChecked()) {
        QString cena = QVariant(ui->odcenaDoubleSpinBox->value()).toString();
        if(filtr!="") filtr+= " AND ";
        filtr+="Cena>="+cena;
    }
    if (ui->odTrasaCB->isChecked()) {
        QString tr = QVariant(ui->odUgoTrasyDoubleSpinBox->value()).toString();
        if(filtr!="") filtr+= " AND ";
        filtr+=" Dlugosc_trasy>="+tr;
    }
    if (ui->doTrasaCB->isChecked()) {
        QString tr = QVariant(ui->dodUgoTrasyDoubleSpinBox_2->value()).toString();
        if(filtr!="") filtr+= " AND ";
        filtr+=" Dlugosc_trasy<="+tr;
    }
    if (ui->stawkaCB ->isChecked()) {
        QString kod = ui->stawkaLE->text();
        if(kod==""){
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij kod stawki lub odznacz wyszukiwanie po kodzie stawki"))->show();
            return;
        }
        if(filtr!="") filtr+= " AND ";
        filtr += "CAST(kod AS CHAR) LIKE '%"+kod+"%'";
    }
    if (ui->odDatyRozCB->isChecked()){
        QString data = ui->oddataRozpoczeciaDateTimeEdit->text();
        if(filtr!="")filtr+=" AND ";
        filtr += "Data_rozpoczecia>='"+data+"'";
    }
    if (ui->doDatyRozCB->isChecked()) {
        QString data = ui->dodataRozpoczeciaDateTimeEdit->text();
        if(filtr!="")filtr+=" AND ";
        filtr += "Data_rozpoczecia<='"+data+"'";
    }
    if (ui->imieKierowcyCB->isChecked()){
        QString imie;
        imie = ui->imieKierowcyLE->text();
        if (imie=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij imię kierowcy lub odznacz szukanie po imieniu kierowcy"))->show();
            return;
        }
        pod=pod+" Imie LIKE '%"+imie+"%' ";
    }
    if (ui->nazwiskoKierowcyCB->isChecked()){
        QString nazwisko = ui->nazwiskoKierowcyLE->text();
        if (nazwisko=="")
        {
            (new QMessageBox(QMessageBox::Icon::Warning,"","Uzupełnij nazwisko kierowcy lub odznacz szukanie po nazwisku kierowcy"))->show();
            return;
        }
        if(ui->imieKierowcyCB->isChecked()) pod =pod+" AND ";
        pod=pod+" Nazwisko LIKE '%"+nazwisko+"%' ";
    }
    pod=pod+")";
    if(ui->imieKierowcyCB->isChecked()||ui->nazwiskoKierowcyCB->isChecked()) filtr ="Kierowca IN "+pod;
    if ((ui->odcenaDoubleSpinBox->value()>ui->docenaDoubleSpinBox->value())
            && ui->odCenaCB->isChecked() && ui->doCenaCB->isChecked()){
        (new QMessageBox(QMessageBox::Icon::Warning,"","Cena \"od\" jest większa od ceny \"do\". Odznacz lub popraw jedną z cen"))->show();
        return;

    }

   if ((ui->oddataRozpoczeciaDateTimeEdit->date() > ui->dodataRozpoczeciaDateTimeEdit->date())
           && ui->odDatyRozCB->isChecked() && ui->doDatyRozCB->isChecked()){
       (new QMessageBox(QMessageBox::Icon::Warning,"","Data \"od\" jest większa od daty \"do\". Odznacz lub popraw jedną z dat"))->show();
       return;

   }

   if (ui->imieKierowcyCB->isChecked()||ui->nazwiskoKierowcyCB->isChecked()){
      if (filtr!="") filtr+=" AND ";
      filtr+=" PESEL IN "+pod;
   }
    modelR->setFilter(filtr);
}
