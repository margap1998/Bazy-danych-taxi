#ifndef MODUBEZPIECZENIE_H
#define MODUBEZPIECZENIE_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class modUbezpieczenie;
}

class modUbezpieczenie : public QDialog
{
    Q_OBJECT

public:
    explicit modUbezpieczenie(QWidget *parent = nullptr);
    ~modUbezpieczenie();

private:
    Ui::modUbezpieczenie *ui;
    QSqlQueryModel model;
};

#endif // MODUBEZPIECZENIE_H
