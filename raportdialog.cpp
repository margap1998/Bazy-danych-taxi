#include "menu.h"
#include "raportdialog.h"
#include "ui_raportdialog.h"
#include <QtSql>

RaportDialog::RaportDialog(QString text,QDialog *parent):
    QDialog(parent),
    ui(new Ui::RaportDialog)
{
    ui->setupUi(this);
    ui->plainTextEdit->setPlainText("");
    QSqlQuery q1;
    q1.exec(text);
    do
    {
        int i=0;
        QString linia = "";
        while (!q1.isNull(i)) {
            linia+=q1.value(i).toString()+" ";
            i++;
        }
        ui->plainTextEdit->appendPlainText(linia);
    }
    while(q1.next());

}
RaportDialog::~RaportDialog()
{
    delete ui;
}


void RaportDialog::on_Wyjdz_clicked()
{
    this->close();
    delete this;
}
