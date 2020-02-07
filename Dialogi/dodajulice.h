#ifndef DODAJULICE_H
#define DODAJULICE_H

#include <QDialog>

namespace Ui {
class DodajUlice;
}

class DodajUlice : public QDialog
{
    Q_OBJECT

public:
    explicit DodajUlice(QWidget *parent = nullptr);
    ~DodajUlice();

private:
    Ui::DodajUlice *ui;
};

#endif // DODAJULICE_H
