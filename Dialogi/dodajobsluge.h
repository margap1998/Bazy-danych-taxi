#ifndef DODAJOBSLUGE_H
#define DODAJOBSLUGE_H

#include <QDialog>
#include <QSqlQueryModel>
namespace Ui {
class DodajObsluge;
}

class DodajObsluge : public QDialog
{
    Q_OBJECT

public:
    explicit DodajObsluge(QWidget *parent = nullptr);
    ~DodajObsluge();

private slots:

    void on_Ok_clicked();

private:
    Ui::DodajObsluge *ui;
    QSqlQueryModel modelR,modelK;
};

#endif // DODAJOBSLUGE_H
