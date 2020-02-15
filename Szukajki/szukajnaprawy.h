#ifndef SZUKAJNAPRAWY_H
#define SZUKAJNAPRAWY_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class szukajNaprawy;
}

class szukajNaprawy : public QDialog
{
    Q_OBJECT

public:
    explicit szukajNaprawy(QSqlRelationalTableModel *model, QWidget *parent = nullptr);
    ~szukajNaprawy();

private slots:
    void on_wrocButton_clicked();
    void on_szukajButton_clicked();

private:
    Ui::szukajNaprawy *ui;
    QSqlRelationalTableModel *modelR;
};

#endif // SZUKAJNAPRAWY_H
