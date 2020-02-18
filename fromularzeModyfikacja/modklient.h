#ifndef MODKLIENT_H
#define MODKLIENT_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class modKlient;
}

class modKlient : public QDialog
{
    Q_OBJECT

public:
    explicit modKlient(QWidget *parent = nullptr);
    ~modKlient();

private:
    Ui::modKlient *ui;
    QSqlQueryModel model;
};

#endif // MODKLIENT_H
