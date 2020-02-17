#include "szukajrejonu.h"
#include "ui_szukajrejonu.h"

#include <QMessageBox>

szukajRejonu::szukajRejonu(QSqlRelationalTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::szukajRejonu)
{
    modelR =model;
    ui->setupUi(this);
}

szukajRejonu::~szukajRejonu()
{
    delete ui;
}
void szukajRejonu::on_wrocButton_clicked()
{
    this->hide();
    delete this;
}

void szukajRejonu::on_szukajButton_clicked()
{

    QString filtr = "";
    QString rej = ui->lineEdit->text();
    if (rej=="")
    {
        (new QMessageBox(QMessageBox::Icon::Warning,"","Wprowadź nazwę poszukiwanego rejonu"))->show();
        return;
    }
    filtr ="Nazwa LIKE '%"+rej+"%'";
    modelR->setFilter(filtr);
    modelR->select();
    on_wrocButton_clicked();
}
