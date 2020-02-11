#ifndef DODAJULICE_H
#define DODAJULICE_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class DodajUlice;
}

class DodajUlice : public QDialog
{
    Q_OBJECT

public:
    explicit DodajUlice(QWidget *parent = nullptr);
    ~DodajUlice();

private slots:
    void on_Ok_clicked();

    void on_anuluj_clicked();
private:
    Ui::DodajUlice *ui;
    QSqlQueryModel modelR;
};

#endif // DODAJULICE_H
