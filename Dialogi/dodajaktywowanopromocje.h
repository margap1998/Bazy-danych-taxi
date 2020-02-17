#ifndef DODAJAKTYWOWANOPROMOCJE_H
#define DODAJAKTYWOWANOPROMOCJE_H

#include <QDialog>
#include <QSqlQueryModel>
namespace Ui {
class dodajAktywowanoPromocje;
}

class dodajAktywowanoPromocje : public QDialog
{
    Q_OBJECT

public:
    explicit dodajAktywowanoPromocje(QWidget *parent = nullptr);
    ~dodajAktywowanoPromocje();

private slots:
    void on_Ok_clicked();

    void on_anuluj_clicked();

private:
    Ui::dodajAktywowanoPromocje *ui;
    QSqlQueryModel modelK;
    QSqlQueryModel modelP;
    QSqlQueryModel modelT;
};

#endif // DODAJAKTYWOWANOPROMOCJE_H
