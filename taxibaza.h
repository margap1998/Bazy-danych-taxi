#ifndef TAXIBAZA_H
#define TAXIBAZA_H

#include <QMainWindow>

namespace Ui {
class TaxiBAZA;
}

class TaxiBAZA : public QMainWindow
{
    Q_OBJECT

public:
    explicit TaxiBAZA(QWidget *parent = 0);
    ~TaxiBAZA();

private:
    Ui::TaxiBAZA *ui;
};

#endif // TAXIBAZA_H
