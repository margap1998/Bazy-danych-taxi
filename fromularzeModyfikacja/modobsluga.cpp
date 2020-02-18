#include "modobsluga.h"
#include "ui_modobsluga.h"

#include <QMessageBox>
#include <QSqlQuery>

modObsluga::modObsluga(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modObsluga)
{
    ui->setupUi(this);
}

modObsluga::~modObsluga()
{
    delete ui;
}

void modObsluga::on_anuluj_clicked()
{

}

void modObsluga::on_Ok_clicked()
{
    auto w = new QMessageBox();
    QString rej = ui->rejonComboBox->currentText();
    QString pes = ui->kierowcaComboBox->currentText();
    QString pol = "INSERT INTO obsluga(Kierowca, Rejon) VALUES('"+pes+"','"+rej+"')";
    if (!(rej == "" || pes==""))
    {
        QSqlQuery q1;
        if(!q1.prepare(pol))
        {
            w->setText("Problem z przetworzeniem danych");
            w->show();
            return;
        }
        if(!q1.exec())
        {
            w->setText("Nieudana próba dodania kierowcy do obsługi rejonu");
            w->show();
        }
        else{
            w->setText("Pomyślnie dodano kierowcę do obsługi rejonu");
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
