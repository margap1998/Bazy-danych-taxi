#ifndef SZUKAJPOJAZDU_H
#define SZUKAJPOJAZDU_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class szukajpojazdu;
}

class szukajpojazdu : public QDialog
{
    Q_OBJECT

public:
    explicit szukajpojazdu(QSqlRelationalTableModel *model, QWidget *parent = nullptr);
    ~szukajpojazdu();

private:
    Ui::szukajpojazdu *ui;
    QSqlRelationalTableModel *modelR;
};

#endif // SZUKAJPOJAZDU_H
