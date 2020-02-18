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

private:
    Ui::modPrzejazd *ui;
    QSqlQueryModel model;
};

#endif // MODPRZEJAZD_H
