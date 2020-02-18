#include "dodajubezpieczenie.h"
#include "ui_dodajubezpieczenie.h"

#include <QMessageBox>
#include <QSqlQuery>


DodajUbezpieczenie::DodajUbezpieczenie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajUbezpieczenie)
{
    ui->setupUi(this);
    model.setQuery("SELECT Numer_rejestracyjny FROM pojazd");
    ui->numerRejestracyjnyComboBox->setModel(&model);
}

DodajUbezpieczenie::~DodajUbezpieczenie()
{
    delete ui;
}


void DodajUbezpieczenie::on_Ok_clicked()
{
    QString ac = "N";
    if (ui->aCCheckBox->checkState() == Qt::CheckState::Checked)
    {
        ac="T";
    }
    QString oc = "T";
    if (ui->oCCheckBox->checkState() == Qt::CheckState::Unchecked)
    {
        oc = "N";
    }
    QString numerUbez = ui->numerUbezpieczeniaLineEdit->text();
    QString koszt = QVariant(ui->kosztDoubleSpinBox->value()).toString();
    QString kwota = QVariant(ui->kwotaDoubleSpinBox->value()).toString();
    QString nrRej = ui->numerRejestracyjnyComboBox->currentText();
    QString dodatki = ui->dodatkoweOpcjeTextEdit->toPlainText();
    QString dataZaw = ui->dataZawarciaDateEdit->text();
    QString dataZak = ui->dataZakonczeniaDateEdit->text();
    QString ubezpieczyciel = ui->ubezpieczycielLineEdit->text();
    if(ui->dataZawarciaDateEdit->date()>ui->dataZakonczeniaDateEdit->date())
        {(new QMessageBox(QMessageBox::Icon::Information,"","Umowa nie może się zakończyć przed zawarciem."))->show();return;}
    if(dodatki.length()>160){
        (new QMessageBox(QMessageBox::Icon::Information,"","Opis dodatkowych opcji nie może przekraczać 160 znaków"))->show();return;}
    if(ubezpieczyciel.length()>45){
        (new QMessageBox(QMessageBox::Icon::Information,"","Ubezpieczyciel ma mieć do 45 znaków."))->show();return;}
    if (ubezpieczyciel==""||koszt==""||kwota==""||nrRej==""||dataZaw==""||dataZak==""||numerUbez=="")
    {
        (new QMessageBox(QMessageBox::Icon::Information,"","Nie wypełniono wymaganych pól"))->show();
    }
    else
    {
        QString pol = "INSERT INTO `PolTAXI`.`Ubezpieczenie` "
                      "(`Numer_ubezpieczenia`, `Numer_rejestracyjny`, `Ubezpieczyciel`, `Kwota`, `Koszt`, `OC`, `Data_zawarcia`, `Data_zakonczenia`, `AC`, `Dodatkowe_opcje`) "
                      "VALUES ('"+numerUbez+"', '"+nrRej+"', '"+ubezpieczyciel+"', "+kwota+", "+koszt+",'"+oc+"' , '"+dataZaw+"', '"+dataZak+"', '"+ac+"', '"+dodatki+"')";
        QSqlQuery q1;
        auto w = new QMessageBox();
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba dodania ubezpieczenie");
            w->show();
        }
        else{
            w->setText("Pomyślnie dodano ubezpieczenie");
            w->show();
            on_anuluj_clicked();
        }
    }
}

void DodajUbezpieczenie::on_anuluj_clicked()
{
    this->close();
    delete this;
}
