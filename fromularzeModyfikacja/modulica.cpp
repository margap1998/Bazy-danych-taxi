#include "modulica.h"
#include "ui_modulica.h"

modUlica::modUlica(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modUlica)
{
    ui->setupUi(this);
}

modUlica::~modUlica()
{
    delete ui;
}
