#ifndef DODAJREJON_H
#define DODAJREJON_H

#include <QDialog>

namespace Ui {
class DodajRejon;
}

class DodajRejon : public QDialog
{
    Q_OBJECT

public:
    explicit DodajRejon(QWidget *parent = nullptr);
    ~DodajRejon();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DodajRejon *ui;
};

#endif // DODAJREJON_H
