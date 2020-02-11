#ifndef DODAJPRZEJAZD_H
#define DODAJPRZEJAZD_H

#include <QDialog>
#include <QtSql/QSqlQueryModel>
namespace Ui {
class DodajPrzejazd;
}

class DodajPrzejazd : public QDialog
{
    Q_OBJECT

public:
    explicit DodajPrzejazd(QWidget *parent = nullptr);
    ~DodajPrzejazd();

private slots:
    void on_Ok_clicked();

    void on_anuluj_clicked();
private:
    Ui::DodajPrzejazd *ui;
    QSqlQueryModel modelK,modelS,modelN;
};

#endif // DODAJPRZEJAZD_H
