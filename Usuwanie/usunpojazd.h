#ifndef USUNPOJAZD_H
#define USUNPOJAZD_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class usunPojazd;
}

class usunPojazd : public QDialog
{
    Q_OBJECT

public:
    explicit usunPojazd(QWidget *parent = nullptr);
    ~usunPojazd();

private slots:
    void on_usun_clicked();

    void on_wroc_clicked();
private:
    Ui::usunPojazd *ui;
    QSqlQueryModel model;
};

#endif // USUNPOJAZD_H
