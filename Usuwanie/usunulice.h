#ifndef USUNULICE_H
#define USUNULICE_H

#include <QDialog>
#include <QSqlQueryModel>
namespace Ui {
class usunUlice;
}

class usunUlice : public QDialog
{
    Q_OBJECT

public:
    explicit usunUlice(QWidget *parent = nullptr);
    ~usunUlice();

private slots:
    void on_usun_clicked();

    void on_wroc_clicked();

    void on_rejon_currentTextChanged(const QString &arg1);


private:
    Ui::usunUlice *ui;
    QSqlQueryModel modelR,modelU;
};

#endif // USUNULICE_H
