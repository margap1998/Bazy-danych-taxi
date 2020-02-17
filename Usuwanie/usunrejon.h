#ifndef USUNREJON_H
#define USUNREJON_H

#include <QDialog>
#include <QSqlQueryModel>


namespace Ui {
class usunrejon;
}

class usunrejon : public QDialog
{
    Q_OBJECT

public:
    explicit usunrejon(QWidget *parent = nullptr);
    ~usunrejon();

private slots:
    void on_wroc_clicked();

    void on_usun_clicked();

private:
    Ui::usunrejon *ui;
    QSqlQueryModel model;
};

#endif // USUNREJON_H
