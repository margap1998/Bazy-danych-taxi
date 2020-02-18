#include "modubezpieczenie.h"
#include "ui_modubezpieczenie.h"

#include <QMessageBox>
#include <QSqlQuery>

modUbezpieczenie::modUbezpieczenie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modUbezpieczenie)
{
    ui->setupUi(this);
    model.setQuery("Select DISTINCT Numer_ubezpieczenia from Ubezpieczenie");
    modelR.setQuery("Select Numer_rejestracyjny from Ubezpieczenie");
    ui->nrUCBwyb->setModel(&model);
    ui->numerRejestracyjnyComboBox->setModel(&modelR);
}

modUbezpieczenie::~modUbezpieczenie()
{
    delete ui;
}

void modUbezpieczenie::on_anuluj_clicked()
{
    this->close();
    delete this;
}

void modUbezpieczenie::on_Ok_clicked()
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
    QString numerwyb = ui->nrUCBwyb->currentText();

    QString numerub = ui->numerUbezpieczeniaLineEdit->text();
    QString koszt = QVariant(ui->kosztDoubleSpinBox->value()).toString();
    QString kwota = QVariant(ui->kwotaDoubleSpinBox->value()).toString();
    QString nrRej = ui->numerRejestracyjnyComboBox->currentText();
    QString dodatki = ui->dodatkoweOpcjeTextEdit->toPlainText();
    QString dataZaw = ui->dataZawarciaDateEdit->text();
    QString dataZak = ui->dataZakonczeniaDateEdit->text();
    QString ubezpieczyciel = ui->ubezpieczycielLineEdit->text();

    auto w = new QMessageBox();
    if (!(ubezpieczyciel==""||koszt==""||kwota==""||nrRej==""||dataZaw==""||dataZak==""||numerub==""))
    {
        QSqlQuery q1;
        QString pol =
                "UPDATE `PolTAXI`.`Ubezpieczenie` "
                " SET "
                " `Numer_ubezpieczenia` = '"+numerub+"',"
                " `Koszt` = '"+koszt+"',"
                " `Kwota` = '"+kwota+"',"
                " `Numer_rejestracyjny` = '"+nrRej+"',"
                " `Dodatkowe_opcje` = '"+dodatki+"',"
                " `Data_zawarcia` = '"+dataZaw+"',"
                " `Data_zakonczenia` = '"+dataZak+"',"
                " `Ubezpieczyciel` = '"+ubezpieczyciel+"',"
                " `OC` = '"+oc+"',"
                " `AC` = '"+ac+"'"

                " WHERE "
                " `Numer_ubezpieczenia` = '"+numerwyb+"'";
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba modyfikacji ubezpieczenia");
            w->show();
        }
        else{
            w->setText("Pomyślnie zmodyfikowano ubezpieczenie");
            w->show();
            on_anuluj_clicked();
        }
    }
    else
    {
        w->setText("Uzupełnij puste pola");
        w->show();
    }

}
/*
void modUbezpieczenie::on_nrUCBwyb_currentTextChanged(const QString &arg1)
{
    model.setQuery("Select DISTINCT Numer_ubezpieczenia from Ubezpieczenie");
    modelR.setQuery("Select Numer_rejestracyjny from Ubezpieczenie WHERE Numer_ubezpieczenia="+arg1);
}
*/
