#ifndef MODPROMOCJA_H
#define MODPROMOCJA_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class modPromocja;
}

class modPromocja : public QDialog
{
    Q_OBJECT

public:
    explicit modPromocja(QWidget *parent = nullptr);
    ~modPromocja();

private slots:
    void on_anuluj_clicked();

private:
    Ui::modPromocja *ui;
    QSqlQueryModel model;
};

#endif // MODPROMOCJA_H
