#ifndef MODULICA_H
#define MODULICA_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class modUlica;
}

class modUlica : public QDialog
{
    Q_OBJECT

public:
    explicit modUlica(QWidget *parent = nullptr);
    ~modUlica();

private:
    Ui::modUlica *ui;
    QSqlQueryModel modelR,modelU;
};

#endif // MODULICA_H
