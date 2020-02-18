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

private slots:
    void on_anuluj_clicked();

    void on_Ok_clicked();

private:
    Ui::modKierowca *ui;
    QSqlQueryModel model,modelK;
};

#endif // MODKIEROWCA_H
