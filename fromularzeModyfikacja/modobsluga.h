#ifndef MODOBSLUGA_H
#define MODOBSLUGA_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class modObsluga;
}

class modObsluga : public QDialog
{
    Q_OBJECT

public:
    explicit modObsluga(QWidget *parent = nullptr);
    ~modObsluga();

private slots:
    void on_anuluj_clicked();

    void on_Ok_clicked();

private:
    Ui::modObsluga *ui;
    QSqlQueryModel modelR,modelK,umodelR,umodelK;
};

#endif // MODOBSLUGA_H
