#ifndef MODPOJAZD_H
#define MODPOJAZD_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class modPojazd;
}

class modPojazd : public QDialog
{
    Q_OBJECT

public:
    explicit modPojazd(QWidget *parent = nullptr);
    ~modPojazd();

private slots:
    void on_Ok_clicked();

    void on_anuluj_clicked();

private:
    Ui::modPojazd *ui;
    QSqlQueryModel model;
};

#endif // MODPOJAZD_H
