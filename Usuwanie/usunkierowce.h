#ifndef USUNKIEROWCE_H
#define USUNKIEROWCE_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class usunkierowce;
}

class usunkierowce : public QDialog
{
    Q_OBJECT

public:
    explicit usunkierowce(QWidget *parent = nullptr);
    ~usunkierowce();

private slots:
    void on_usun_clicked();

    void on_wroc_clicked();

private:
    Ui::usunkierowce *ui;
    QSqlQueryModel model;
};

#endif // USUNKIEROWCE_H
