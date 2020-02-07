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
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DodajKierowce *ui;
};

#endif // DODAJKIEROWCE_H
