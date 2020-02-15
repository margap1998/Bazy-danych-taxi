#ifndef WARSZTAT_H
#define WARSZTAT_H

#include <QDialog>
#include <QSqlRelationalTableModel>
namespace Ui {
class warsztat;
}

class warsztat : public QDialog
{
    Q_OBJECT

public:
    explicit warsztat(QWidget *parent = nullptr);
    ~warsztat();

private slots:
    void on_Zatwierdz_clicked();

    void on_dodaj_clicked();

    void on_odswierz_clicked();

private:
    Ui::warsztat *ui;
    QSqlRelationalTableModel model;
};

#endif // WARSZTAT_H
