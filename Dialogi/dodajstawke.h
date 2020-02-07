#ifndef DODAJSTAWKE_H
#define DODAJSTAWKE_H

#include <QDialog>

namespace Ui {
class DodajStawke;
}

class DodajStawke : public QDialog
{
    Q_OBJECT

public:
    explicit DodajStawke(QWidget *parent = nullptr);
    ~DodajStawke();

private:
    Ui::DodajStawke *ui;
};

#endif // DODAJSTAWKE_H
