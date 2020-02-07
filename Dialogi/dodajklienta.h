#ifndef DODAJKLIENTA_H
#define DODAJKLIENTA_H

#include <QDialog>

namespace Ui {
class DodajKlienta;
}

class DodajKlienta : public QDialog
{
    Q_OBJECT

public:
    explicit DodajKlienta(QWidget *parent = nullptr);
    ~DodajKlienta();

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::DodajKlienta *ui;
};

#endif // DODAJKLIENTA_H
