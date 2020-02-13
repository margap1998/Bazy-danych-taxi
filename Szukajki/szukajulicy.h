#ifndef SZUKAJULICY_H
#define SZUKAJULICY_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class szukajUlicy;
}

class szukajUlicy : public QDialog
{
    Q_OBJECT

public:
    explicit szukajUlicy(QSqlRelationalTableModel *model, QWidget *parent = nullptr);
    ~szukajUlicy();

private:
    Ui::szukajUlicy *ui;
    QSqlRelationalTableModel *modelR;
};

#endif // SZUKAJULICY_H
