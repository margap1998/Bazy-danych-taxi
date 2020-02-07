#ifndef PROMOCJE_H
#define PROMOCJE_H

#include <QWidget>
#include <QtSql/QSqlRelationalTableModel>
namespace Ui {
class Promocje;
}

class Promocje : public QWidget
{
    Q_OBJECT
public:
    explicit Promocje(QWidget *parent = 0,  QWidget *bef = 0);
    ~Promocje();

    Promocje(QWidget *parent);
private slots:
protected slots:
    void on_WrocButton_2_clicked();
    void on_OdswierzButton_clicked();

    void on_DodajButton_2_clicked();

    void on_WyszukajButton_clicked();

private:
    QWidget *before;
    Ui::Promocje *ui;
    QSqlRelationalTableModel model;
};

#endif // PROMOCJE_H
