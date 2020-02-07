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
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::DodajNaprawe *ui;
    QSqlQueryModel model;
};

#endif // DODAJNAPRAWE_H
