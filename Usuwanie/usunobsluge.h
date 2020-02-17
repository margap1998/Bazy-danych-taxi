#ifndef USUNOBSLUGE_H
#define USUNOBSLUGE_H

#include <QDialog>
#include <QSqlQueryModel>
namespace Ui {
class usunObsluge;
}

class usunObsluge : public QDialog
{
    Q_OBJECT

public:
    explicit usunObsluge(QWidget *parent = nullptr);
    ~usunObsluge();

private slots:
    void on_usun_clicked();

    void on_wroc_clicked();
private:
    Ui::usunObsluge *ui;
    QSqlQueryModel modelK,modelR;
};

#endif // USUNOBSLUGE_H
