#ifndef USUNWARSZTAT_H
#define USUNWARSZTAT_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class usunWarsztat;
}

class usunWarsztat : public QDialog
{
    Q_OBJECT

public:
    explicit usunWarsztat(QWidget *parent = nullptr);
    ~usunWarsztat();

private slots:
    void on_wroc_clicked();

    void on_usun_clicked();

private:
    Ui::usunWarsztat *ui;
    QSqlQueryModel model;
};

#endif // USUNWARSZTAT_H
