#include "dodajstawke.h"
#include "ui_dodajstawke.h"

#include <QMessageBox>
#include <QSqlQuery>

DodajStawke::DodajStawke(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajStawke)
{
    ui->setupUi(this);
}

DodajStawke::~DodajStawke()
{
    delete ui;
}

void DodajStawke::on_Ok_clicked()
{
    auto w = new QMessageBox();
    QString cena = QVariant(ui->cenaZaKilometrDoubleSpinBox->value()).toString();
    QString kod = ui->kodLineEdit->text();
    QString opis = ui->opisPlainTextEdit->toPlainText();
    if(!kod.contains(QRegExp("[0-9]+")))
    {
        w->setText("Kod składa się wyłącznie z cyfr");
        w->show();
        return;
    }
    if (!(kod== ""||cena==""||opis==""))
    {
        QString pol ="INSERT INTO `PolTAXI`.`Stawka` (`Kod`, `Opis`, `Cena_za_km`) VALUES('"+kod+"','"+opis+"',"+cena+")";
        QSqlQuery q1;
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba dodania stawki");
            w->show();
        }
        else{
            w->setText("Pomyślnie dodano stawkę");
            w->show();
            on_anuluj_clicked();
        }
    }
    else
    {
        w->setText("Proszę uzupełnić wszystkie pola");
        w->show();
    }
}


void DodajStawke::on_anuluj_clicked()
{
    this->close();
    delete this;
}
