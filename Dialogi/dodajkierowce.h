#ifndef DODAJKIEROWCE_H
#define DODAJKIEROWCE_H

#include <QDialog>

namespace Ui {
class DodajKierowce;
}

class DodajKierowce : public QDialog
{
    Q_OBJECT

public:
    explicit DodajKierowce(QWidget *parent = nullptr);
    ~DodajKierowce();

private slots:

    void on_Ok_clicked();

    void on_anuluj_clicked();

private:
    Ui::DodajKierowce *ui;
};

#endif // DODAJKIEROWCE_H
