#include "modstawka.h"
#include "ui_modstawka.h"

#include <QMessageBox>
#include <QSqlQuery>

modStawka::modStawka(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modStawka)
{
    ui->setupUi(this);
    model.setQuery("Select DISTINCT Kod from Stawka");
    ui->kodStawkiwyb->setModel(&model);
    ui->kodStawkiwyb->setCurrentText("");
}

modStawka::~modStawka()
{
    delete ui;
}

void modStawka::on_anuluj_clicked()
{
    this->close();
    delete this;
}

void modStawka::on_Ok_clicked()
{
    QString kodwyb = ui->kodStawkiwyb->currentText();

    QString kod = ui->kodLineEdit->text();
    QString opis = ui->opisPlainTextEdit->toPlainText();
    QString cena = QVariant(ui->cenaZaKilometrDoubleSpinBox->value()).toString();

    auto w = new QMessageBox();
    if (!(kod==""||opis==""||cena==""))
    {
        QSqlQuery q1;
        QString pol =
                "UPDATE `PolTAXI`.`Stawka` "
                " SET "
                " `Kod` = '"+kod+"',"
                " `Opis` = '"+opis+"',"
                " `Cena_za_km` = "+cena+""

                " WHERE "
                " `Kod` = '"+kodwyb+"'";
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba modyfikacji stawki");
            w->show();
        }
        else{
            w->setText("Pomyślnie zmodyfikowano stawkę");
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
