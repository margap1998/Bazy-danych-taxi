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

private:
    Ui::modObsluga *ui;
    QSqlQueryModel modelR,modelK;
};

#endif // MODOBSLUGA_H
