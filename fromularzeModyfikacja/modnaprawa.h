#ifndef MODNAPRAWA_H
#define MODNAPRAWA_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class modNaprawa;
}

class modNaprawa : public QDialog
{
    Q_OBJECT

public:
    explicit modNaprawa(QWidget *parent = nullptr);
    ~modNaprawa();

private slots:
    void on_anuluj_clicked();

    void on_Ok_clicked();

private:
    Ui::modNaprawa *ui;
    QSqlQueryModel model,modelW,modelR,umodelK,umodelW;
};

#endif // MODNAPRAWA_H
