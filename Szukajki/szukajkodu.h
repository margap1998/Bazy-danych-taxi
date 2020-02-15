#ifndef SZUKAJKODU_H
#define SZUKAJKODU_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class szukajKodu;
}

class szukajKodu : public QDialog
{
    Q_OBJECT

public:
    explicit szukajKodu(QSqlRelationalTableModel *model, QWidget *parent = nullptr);
    ~szukajKodu();

private slots:
    void on_wrocButton_clicked();

    void on_szukajButton_clicked();

private:
    QSqlRelationalTableModel *modelR;
    Ui::szukajKodu *ui;
};

#endif // SZUKAJKODU_H
