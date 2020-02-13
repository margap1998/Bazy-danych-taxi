#ifndef SZUKAJPROMOCJI_H
#define SZUKAJPROMOCJI_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class szukajPromocji;
}

class szukajPromocji : public QDialog
{
    Q_OBJECT

public:
    explicit szukajPromocji(QSqlRelationalTableModel *model, QWidget *parent = nullptr);
    ~szukajPromocji();

private:
    Ui::szukajPromocji *ui;
    QSqlRelationalTableModel *modelR;
};

#endif // SZUKAJPROMOCJI_H
