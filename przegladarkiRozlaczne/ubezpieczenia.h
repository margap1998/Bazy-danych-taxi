#ifndef UBEZPIECZENIA_H
#define UBEZPIECZENIA_H

#include <QWidget>
#include <QtSql/QSqlRelationalTableModel>
namespace Ui {
class Ubezpieczenia;
}

class Ubezpieczenia : public QWidget
{
    Q_OBJECT
public:
    explicit Ubezpieczenia(QWidget *parent = 0,  QWidget *bef = 0);
    ~Ubezpieczenia();

    Ubezpieczenia(QWidget *parent);
private slots:
    void on_Minione_clicked();

    void on_Aktualne_clicked();

    void on_Wszystkie_clicked();

    void on_zPojazdmi_stateChanged(int arg1);

    void on_UsunButton_clicked();

    void on_ZatwierdzButton_2_clicked();

    void on_pushButton_clicked();

protected slots:
    void on_WrocButton_2_clicked();
    void on_OdswierzButton_clicked();

    void on_DodajButton_2_clicked();

    void on_WyszukajButton_clicked();

private:
    QWidget *before;
    Ui::Ubezpieczenia *ui;
    QString obecnaTabelka;
    QSqlRelationalTableModel model;
};

#endif // UBEZPIECZENIA_H
