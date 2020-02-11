#ifndef DODAJUBEZPIECZENIE_H
#define DODAJUBEZPIECZENIE_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class DodajUbezpieczenie;
}

class DodajUbezpieczenie : public QDialog
{
    Q_OBJECT

public:
    explicit DodajUbezpieczenie(QWidget *parent = nullptr);
    ~DodajUbezpieczenie();

private slots:
    void on_Ok_clicked();

    void on_anuluj_clicked();
private:
    Ui::DodajUbezpieczenie *ui;
    QSqlQueryModel model;
};

#endif // DODAJUBEZPIECZENIE_H
