#ifndef USUNUBEZPIECZENIE_H
#define USUNUBEZPIECZENIE_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class UsunUbezpieczenie;
}

class UsunUbezpieczenie : public QDialog
{
    Q_OBJECT

public:
    explicit UsunUbezpieczenie(QWidget *parent = nullptr);
    ~UsunUbezpieczenie();

private slots:
    void on_usun_clicked();

    void on_wroc_clicked();

private:
    Ui::UsunUbezpieczenie *ui;
    QSqlQueryModel model;
};

#endif // USUNUBEZPIECZENIE_H
