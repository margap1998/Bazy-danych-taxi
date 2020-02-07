#ifndef DODAJOBSLUGE_H
#define DODAJOBSLUGE_H

#include <QDialog>

namespace Ui {
class DodajObsluge;
}

class DodajObsluge : public QDialog
{
    Q_OBJECT

public:
    explicit DodajObsluge(QWidget *parent = nullptr);
    ~DodajObsluge();

private:
    Ui::DodajObsluge *ui;
};

#endif // DODAJOBSLUGE_H
