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

private:
    Ui::modPromocja *ui;
    QSqlQueryModel model;
};

#endif // MODPROMOCJA_H
