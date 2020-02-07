#ifndef STAWKI_H
#define STAWKI_H

#include <QWidget>
#include <QtSql/QSqlRelationalTableModel>
namespace Ui {
class Stawki;
}

class Stawki : public QWidget
{
    Q_OBJECT
public:
    explicit Stawki(QWidget *parent = 0,  QWidget *bef = 0);
    ~Stawki();

    Stawki(QWidget *parent);
private slots:
protected slots:
    void on_WrocButton_2_clicked();
    void on_OdswierzButton_clicked();

    void on_DodajButton_2_clicked();

    void on_WyszukajButton_clicked();

private:
    QWidget *before;
    Ui::Stawki *ui;
    QSqlRelationalTableModel model;
};

#endif // STAWKI_H
