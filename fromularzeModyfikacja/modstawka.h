#ifndef MODSTAWKA_H
#define MODSTAWKA_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class modStawka;
}

class modStawka : public QDialog
{
    Q_OBJECT

public:
    explicit modStawka(QWidget *parent = nullptr);
    ~modStawka();

private slots:
    void on_anuluj_clicked();

    void on_Ok_clicked();


private:
    Ui::modStawka *ui;
    QSqlQueryModel model;
};

#endif // MODSTAWKA_H
