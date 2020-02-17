#ifndef USUNPRZEJAZDY_H
#define USUNPRZEJAZDY_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class UsunPrzejazdy;
}

class UsunPrzejazdy : public QDialog
{
    Q_OBJECT

public:
    explicit UsunPrzejazdy(QWidget *parent = nullptr);
    ~UsunPrzejazdy();

private slots:
    void on_usun_clicked();

    void on_wroc_clicked();

private:
    Ui::UsunPrzejazdy *ui;
    QSqlQueryModel model;
};

#endif // USUNPRZEJAZDY_H
