#include "Awaryjne/niemabazy.h"
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
        db.setHostName("127.0.0.1");
        db.setDatabaseName("poltaxi");
        db.setPort(3306);
        db.setUserName("Halinka");
        db.setPassword("Marek1984");
        if(db.open()){
            w = new TaxiBAZA();
        }else{
            w = new QMessageBox(QMessageBox::Critical,"PROBLEM", "Nastąpił problem z bazą danych. Poproś administratora o pomoc");
        }
    }
    else{
        w = new QMessageBox(QMessageBox::Critical,"PROBLEM", "Nie ma sterownika do bazy danych. Poproś administratora o pomoc");
    }
    if (w) w->show();
    return a.exec();
}
