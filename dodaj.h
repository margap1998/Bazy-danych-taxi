#ifndef DODAJ_H
#define DODAJ_H

#include <QDialog>

namespace Ui {
class dodaj;
}

class dodaj : public QDialog
{
    Q_OBJECT

public:
    explicit dodaj(QWidget *parent = 0);
    ~dodaj();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::dodaj *ui;
};

#endif // DODAJ_H
