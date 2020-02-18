#ifndef MODPRZEJAZD_H
#define MODPRZEJAZD_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class modPrzejazd;
}

class modPrzejazd : public QDialog
{
    Q_OBJECT

public:
    explicit modPrzejazd(QWidget *parent = nullptr);
    ~modPrzejazd();

private slots:
    void on_anuluj_clicked();

    void on_Ok_clicked();

private:
    Ui::modPrzejazd *ui;
    QSqlQueryModel model,modelP,modelK, modelS, modelT;
};

#endif // MODPRZEJAZD_H
