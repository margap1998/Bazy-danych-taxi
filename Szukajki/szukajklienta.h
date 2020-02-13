#ifndef SZUKAJKLIENTA_H
#define SZUKAJKLIENTA_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class szukajKlienta;
}

class szukajKlienta : public QDialog
{
    Q_OBJECT

public:
    explicit szukajKlienta(QSqlRelationalTableModel *model, QWidget *parent = nullptr);
    ~szukajKlienta();

private:
    Ui::szukajKlienta *ui;
    QSqlRelationalTableModel *modelR;
};

#endif // SZUKAJKLIENTA_H
