#ifndef USUNKLIENTA_H
#define USUNKLIENTA_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class UsunKlienta;
}

class UsunKlienta : public QDialog
{
    Q_OBJECT

public:
    explicit UsunKlienta(QWidget *parent = nullptr);
    ~UsunKlienta();

private slots:
    void on_usun_clicked();

    void on_wroc_clicked();

private:
    Ui::UsunKlienta *ui;
    QSqlQueryModel model;
};

#endif // USUNKLIENTA_H
