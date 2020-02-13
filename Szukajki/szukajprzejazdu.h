#ifndef SZUKAJPRZEJAZDU_H
#define SZUKAJPRZEJAZDU_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class szukajPrzejazdu;
}

class szukajPrzejazdu : public QDialog
{
    Q_OBJECT

public:
    explicit szukajPrzejazdu(QSqlRelationalTableModel *model, QWidget *parent = nullptr);
    ~szukajPrzejazdu();

private:
    Ui::szukajPrzejazdu *ui;
    QSqlRelationalTableModel *modelR;
};

#endif // SZUKAJPRZEJAZDU_H
