#include "modobsluga.h"
#include "ui_modobsluga.h"

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
