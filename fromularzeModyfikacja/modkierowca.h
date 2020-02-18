#ifndef MODKIEROWCA_H
#define MODKIEROWCA_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class modKierowca;
}

class modKierowca : public QDialog
{
    Q_OBJECT

public:
    explicit modKierowca(QWidget *parent = nullptr);
    ~modKierowca();

private:
    Ui::modKierowca *ui;
    QSqlQueryModel model;
};

#endif // MODKIEROWCA_H
