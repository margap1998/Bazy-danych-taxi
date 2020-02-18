#ifndef MODAKTYWOWANAPROMOCJA_H
#define MODAKTYWOWANAPROMOCJA_H

#include <QDialog>
#include <QSqlQueryModel>
namespace Ui {
class modAktywowanaPromocja;
}

class modAktywowanaPromocja : public QDialog
{
    Q_OBJECT

public:
    explicit modAktywowanaPromocja(QWidget *parent = nullptr);
    ~modAktywowanaPromocja();

private:
    Ui::modAktywowanaPromocja *ui;
    QSqlQueryModel model,modelK,modelR;
};

#endif // MODAKTYWOWANAPROMOCJA_H
