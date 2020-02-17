#ifndef KIEROWCYPOJAZDY_H
#define KIEROWCYPOJAZDY_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class kierowcyPojazdy;
}

class kierowcyPojazdy : public QWidget
{
    Q_OBJECT
public:
    explicit kierowcyPojazdy(QWidget *parent = 0,  QWidget *bef = 0);
    ~kierowcyPojazdy();

    explicit kierowcyPojazdy(QWidget *parent);
private slots:
    void on_ZatwierdzButton_2_clicked();

    void on_pushButton_clicked();

    void on_UsunButton_clicked();

    void on_kieroPoj_clicked();

    void on_tylkoPojazdy_clicked();

    void on_TylkoKierowcy_clicked();

    void on_WyszukajPojazdButton_clicked();

    void on_pushButton_2_clicked();

    void on_usunPojazdButton_clicked();


    void on_stareAuta_clicked();

protected slots:
    void on_WrocButton_2_clicked();
    void on_OdswierzButton_clicked();

    void on_DodajButton_2_clicked();

    void on_WyszukajKierowceButton_clicked();

private:
    QSqlDatabase db;
    QWidget *before;
    Ui::kierowcyPojazdy *ui;
    QSqlRelationalTableModel model;
    int indeks;
    QModelIndex r;
    QString schemat;
    QSqlRelationalDelegate *del;
};

#endif // KIEROWCYPOJAZDY_H
