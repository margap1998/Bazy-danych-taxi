#include "kierowcypojazdy.h"
#include "ui_kierowcypojazdy.h"
#include <QtSql>
kierowcyPojazdy::kierowcyPojazdy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kierowcyPojazdy)
{
    db = QSqlDatabase::database();
    QSqlRelationalTableModel *model = new QSqlRelationalTableModel();
    model->setQuery("select * from ");
    ui->tableView->setModel(model);
    ui->setupUi(this);
}

kierowcyPojazdy::kierowcyPojazdy(QWidget *parent, QWidget *bef):
    QWidget(parent),
    ui(new Ui::kierowcyPojazdy)
{
    before =bef;

    ui->setupUi(this);
}

kierowcyPojazdy::~kierowcyPojazdy()
{
    delete ui;
}

void kierowcyPojazdy::on_WrocButton_2_clicked()
{
    before->show();
    this->hide();
    delete this;
}
void kierowcyPojazdy::on_OdswierzButton_clicked(){}

void kierowcyPojazdy::on_DodajButton_2_clicked(){}

void kierowcyPojazdy::on_WyszukajButton_clicked(){}
