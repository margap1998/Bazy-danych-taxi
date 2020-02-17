#ifndef DODAJTYLKOKIEROWCE_H
#define DODAJTYLKOKIEROWCE_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class dodajTylkoKierowce;
}

class dodajTylkoKierowce : public QDialog
{
    Q_OBJECT

public:
    explicit dodajTylkoKierowce(QWidget *parent = nullptr);
    ~dodajTylkoKierowce();

private slots:
    void on_Ok_clicked();

    void on_anuluj_clicked();

private:
    Ui::dodajTylkoKierowce *ui;
    QSqlQueryModel modelK;
};

#endif // DODAJTYLKOKIEROWCE_H
