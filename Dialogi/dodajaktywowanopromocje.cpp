#include "dodajaktywowanopromocje.h"
#include "ui_dodajaktywowanopromocje.h"

#include <QtSql>
#include <QMessageBox>

dodajAktywowanoPromocje::dodajAktywowanoPromocje(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dodajAktywowanoPromocje)
{
    ui->setupUi(this);
    modelK.setQuery("SELECT kod FROM promocja");
    modelP.setQuery("SELECT Numer_paragonu FROM przejazd");
    modelT.setQuery("SELECT Numer_telefonu FROM klient");
    ui->kodComboBox->setModel(&modelK);
    ui->kodComboBox->setCurrentText("");
    ui->nrParagonuComboBox->setModel(&modelP);
    ui->nrParagonuComboBox->setCurrentText("");
    ui->numerTelefonuComboBox->setModel(&modelT);
    ui->numerTelefonuComboBox->setCurrentText("");
}

dodajAktywowanoPromocje::~dodajAktywowanoPromocje()
{
    delete ui;
}

void dodajAktywowanoPromocje::on_Ok_clicked()
{
    QString kod = ui->kodComboBox->currentText();
    QString nrPar = ui->nrParagonuComboBox->currentText();
    QString nrTel =ui->numerTelefonuComboBox->currentText();
    QString wyko =ui->wykorzystaniaSpinBox->text();
    QString data =ui->dataAktywacjiDateEdit->text();
    auto w = new QMessageBox();
    if (!(kod==""||nrTel==""||wyko==""||data==""))
    {
        QSqlQuery q1;
        QString pol =
                "INSERT INTO `PolTAXI`.`Aktywowana_Promocja` (`Kod`, `Numer_telefonu`, `Data_aktywacji`, `Wykorzystanie`, `Numer_paragonu`) VALUES "
                "('"+kod+"', '"+nrTel+"','"+data+"',"+wyko+", '"+nrPar+"');";
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
        }else{
            if(!q1.exec())
            {
                w->setText("Nieudana próba aktyacji promocji");
                w->show();
            }
            else{
                w->setText("Pomyślnie aktywowano promocję");
                w->show();
                on_anuluj_clicked();
            }
        }
    }
    else
    {
        w->setText("Uzupełnij puste pola");
        w->show();
    }
}

void dodajAktywowanoPromocje::on_anuluj_clicked()
{
    this->close();
    delete this;
}
