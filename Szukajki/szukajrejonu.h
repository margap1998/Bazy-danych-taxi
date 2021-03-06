#ifndef SZUKAJREJONU_H
#define SZUKAJREJONU_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class szukajRejonu;
}

class szukajRejonu : public QDialog
{
    Q_OBJECT

public:
    explicit szukajRejonu(QSqlRelationalTableModel *model, QWidget *parent = nullptr);
    ~szukajRejonu();

private slots:
    void on_wrocButton_clicked();
    void on_szukajButton_clicked();

private:
    Ui::szukajRejonu *ui;
    QSqlRelationalTableModel *modelR;
};

#endif // SZUKAJREJONU_H
