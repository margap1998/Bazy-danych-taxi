#ifndef USUNSTAWKE_H
#define USUNSTAWKE_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class UsunStawke;
}

class UsunStawke : public QDialog
{
    Q_OBJECT

public:
    explicit UsunStawke(QWidget *parent = nullptr);
    ~UsunStawke();

private slots:
    void on_usun_clicked();

    void on_wroc_clicked();

private:
    Ui::UsunStawke *ui;
    QSqlQueryModel model;
};

#endif // USUNSTAWKE_H
