#ifndef DODAJNAPRAWE_H
#define DODAJNAPRAWE_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class DodajNaprawe;
}

class DodajNaprawe : public QDialog
{
    Q_OBJECT

public:
    explicit DodajNaprawe(QWidget *parent = nullptr);
    ~DodajNaprawe();

private slots:
    void on_anuluj_clicked();

    void on_Ok_clicked();

private:
    Ui::DodajNaprawe *ui;
    QSqlQueryModel modelW, modelK;
};

#endif // DODAJNAPRAWE_H
