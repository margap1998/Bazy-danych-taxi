#ifndef SZUKAJUBEZPIECZENIA_H
#define SZUKAJUBEZPIECZENIA_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class szukajUbezpieczenia;
}

class szukajUbezpieczenia : public QDialog
{
    Q_OBJECT

public:
    explicit szukajUbezpieczenia(QSqlRelationalTableModel *model, QWidget *parent = nullptr);
    ~szukajUbezpieczenia();

private:
    Ui::szukajUbezpieczenia *ui;
    QSqlRelationalTableModel *modelR;
};

#endif // SZUKAJUBEZPIECZENIA_H
