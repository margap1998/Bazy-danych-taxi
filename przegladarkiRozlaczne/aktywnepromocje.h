#ifndef AKTYWNEPROMOCJE_H
#define AKTYWNEPROMOCJE_H

#include <QWidget>
#include <QSqlRelationalTableModel>
namespace Ui {
class aktywnePromocje;
}

class aktywnePromocje : public QWidget
{
    Q_OBJECT

public:
    explicit aktywnePromocje(QWidget *parent = nullptr);

    explicit aktywnePromocje(QWidget *parent = nullptr,QWidget *bef = nullptr);
    ~aktywnePromocje();

private slots:
    void on_OdswierzButton_clicked();

    void on_DodajButton_2_clicked();

    void on_ZatwierdzButton_2_clicked();

    void on_UsunButton_clicked();

    void on_WyszukajButton_clicked();

    void on_WrocButton_2_clicked();


private:
    QWidget *before;
    Ui::aktywnePromocje *ui;
    QSqlRelationalTableModel model;
};

#endif // AKTYWNEPROMOCJE_H
