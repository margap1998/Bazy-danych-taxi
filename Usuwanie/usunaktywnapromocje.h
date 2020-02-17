#ifndef USUNAKTYWNAPROMOCJE_H
#define USUNAKTYWNAPROMOCJE_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class UsunAktywnaPromocje;
}

class UsunAktywnaPromocje : public QDialog
{
    Q_OBJECT

public:
    explicit UsunAktywnaPromocje(QWidget *parent = nullptr);
    ~UsunAktywnaPromocje();

private slots:
    void on_usun_clicked();

    void on_wroc_clicked();

private:
    Ui::UsunAktywnaPromocje *ui;
    QSqlQueryModel model,modelK,modelR;
};

#endif // USUNAKTYWNAPROMOCJE_H
