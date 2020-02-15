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

private slots:
    void on_wrocButton_clicked();
    void on_szukajButton_clicked();

private:
    Ui::szukajPrzejazdu *ui;
    QSqlRelationalTableModel *modelR;
};

#endif // SZUKAJPRZEJAZDU_H
