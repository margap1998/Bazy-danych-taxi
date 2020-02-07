#ifndef DODAJPROMOCJE_H
#define DODAJPROMOCJE_H

#include <QDialog>

namespace Ui {
class DodajPromocje;
}

class DodajPromocje : public QDialog
{
    Q_OBJECT

public:
    explicit DodajPromocje(QWidget *parent = nullptr);
    ~DodajPromocje();

private:
    Ui::DodajPromocje *ui;
};

#endif // DODAJPROMOCJE_H
