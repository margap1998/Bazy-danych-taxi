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

private:
    Ui::modNaprawa *ui;
    QSqlQueryModel model,modelW,modelR;
};

#endif // MODNAPRAWA_H
