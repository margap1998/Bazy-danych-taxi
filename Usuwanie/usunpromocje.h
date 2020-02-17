#ifndef USUNPROMOCJE_H
#define USUNPROMOCJE_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class UsunPromocje;
}

class UsunPromocje : public QDialog
{
    Q_OBJECT

public:
    explicit UsunPromocje(QWidget *parent = nullptr);
    ~UsunPromocje();

private slots:
    void on_usun_clicked();

    void on_wroc_clicked();

private:
    Ui::UsunPromocje *ui;
    QSqlQueryModel model;
};

#endif // USUNPROMOCJE_H
