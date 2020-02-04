#ifndef WYSZUKAJ_H
#define WYSZUKAJ_H

#include <QDialog>

namespace Ui {
class wyszukaj;
}

class wyszukaj : public QDialog
{
    Q_OBJECT

public:
    explicit wyszukaj(QWidget *parent = 0);
    ~wyszukaj();

private:
    Ui::wyszukaj *ui;
};

#endif // WYSZUKAJ_H
