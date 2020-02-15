#ifndef SZUKAJAKTYWNEJPROMOCJI_H
#define SZUKAJAKTYWNEJPROMOCJI_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class szukajAktywnejPromocji;
}

class szukajAktywnejPromocji : public QDialog
{
    Q_OBJECT

public:
    explicit szukajAktywnejPromocji(QSqlRelationalTableModel *model, QWidget *parent = nullptr);
    ~szukajAktywnejPromocji();

private slots:
    void on_wrocButton_clicked();

    void on_szukajButton_clicked();

private:
    Ui::szukajAktywnejPromocji *ui;
    QSqlRelationalTableModel *modelR;
};

#endif // SZUKAJAKTYWNEJPROMOCJI_H
