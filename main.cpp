#include "taxibaza.h"
#include <QApplication>
#include <QMessageBox>
#include <QtSql>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *w = NULL;
    if(QSqlDatabase::drivers().contains("QMYSQL"))
       {

        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        w = new TaxiBAZA();
    }
    else{
        w = new QMessageBox(QMessageBox::Critical,"PROBLEM", "Nie ma sterownika do bazy danych. Poproś administratora o pomoc");
    }
    if (w) w->show();
    return a.exec();
}
