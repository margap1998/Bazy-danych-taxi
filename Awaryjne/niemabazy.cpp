#include "niemabazy.h"
#include "ui_niemabazy.h"

niemabazy::niemabazy(QString text,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::niemabazy)
{
    ui->textEdit->append(text);
}

niemabazy::~niemabazy()
{
    delete ui;
}

void niemabazy::on_pushButton_clicked()
{
    close();
}
