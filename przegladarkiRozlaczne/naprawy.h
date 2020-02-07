#ifndef NAPRAWY_H
#define NAPRAWY_H

#include <QWidget>
#include <QtSql/QSqlRelationalTableModel>
namespace Ui {
class naprawy;
}

class naprawy : public QWidget
{
    Q_OBJECT
public:
    explicit naprawy(QWidget *parent = 0,  QWidget *bef = 0);
    ~naprawy();

    explicit naprawy(QWidget *parent = 0);
private slots:
protected slots:
    void on_WrocButton_2_clicked();
    void on_OdswierzButton_clicked();

    void on_DodajButton_2_clicked();

    void on_WyszukajButton_clicked();

private:
    QWidget *before;
    Ui::naprawy *ui;
    QSqlRelationalTableModel model;
};

#endif // NAPRAWY_H
