#ifndef REJONY_H
#define REJONY_H

#include <QWidget>
#include <QtSql/QSqlRelationalTableModel>
namespace Ui {
class Rejony;
}

class Rejony : public QWidget
{
    Q_OBJECT
public:
    explicit Rejony(QWidget *parent = 0,  QWidget *bef = 0);
    ~Rejony();

    Rejony(QWidget *parent);
private slots:

    void on_uliceSwitch_clicked();

    void on_rejonySwitch_clicked();

    void on_obslugaBox_clicked();

    void on_obslugaButton_clicked();

    void on_uliceButton_clicked();

    void on_UsunButton_clicked();

    void on_ZatwierdzButton_2_clicked();

protected slots:
    void on_WrocButton_2_clicked();
    void on_OdswierzButton_clicked();

    void on_DodajButton_2_clicked();

    void on_WyszukajButton_clicked();

private:
    QWidget *before;
    Ui::Rejony *ui;
    QString aktywnaTabela;
    QSqlRelationalTableModel model;
};

#endif // REJONY_H
