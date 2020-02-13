#ifndef SZUKAJKIEROWCY_H
#define SZUKAJKIEROWCY_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class szukajKierowcy;
}

class szukajKierowcy : public QDialog
{
    Q_OBJECT

public:
    explicit szukajKierowcy(QSqlRelationalTableModel *model, QWidget *parent = nullptr);
    ~szukajKierowcy();

private:
    Ui::szukajKierowcy *ui;
    QSqlRelationalTableModel *modelR;
};

#endif // SZUKAJKIEROWCY_H
