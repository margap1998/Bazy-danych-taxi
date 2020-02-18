#ifndef KLIENCI_H
#define KLIENCI_H

#include <QWidget>
#include <QtSql/QSqlRelationalTableModel>

namespace Ui {
class Klienci;
}

class Klienci : public QWidget
{
    Q_OBJECT
public:
    explicit Klienci(QWidget *parent = 0,  QWidget *bef = 0);
    ~Klienci();

    Klienci(QWidget *parent);
private slots:
    void on_UsunButton_clicked();

    void on_ZatwierdzButton_2_clicked();

    void on_modyfikuj_clicked();

protected slots:
    void on_WrocButton_2_clicked();
    void on_OdswierzButton_clicked();

    void on_DodajButton_2_clicked();

    void on_WyszukajButton_clicked();

private:
    QWidget *before;
    Ui::Klienci *ui;
    QSqlRelationalTableModel model;
    QString obecnaTabela;
};

#endif // KLIENCI_H
