#ifndef KIEROWCYPOJAZDY_H
#define KIEROWCYPOJAZDY_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

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

protected slots:
    void on_WrocButton_2_clicked();
    void on_OdswierzButton_clicked();

    void on_DodajButton_2_clicked();

    void on_WyszukajButton_clicked();

private:
    QSqlDatabase db;
    QWidget *before;
    Ui::kierowcyPojazdy *ui;
    QSqlRelationalTableModel model;
};

#endif // KIEROWCYPOJAZDY_H
