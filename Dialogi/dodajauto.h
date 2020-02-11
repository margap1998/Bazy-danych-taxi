#ifndef DODAJAUTO_H
#define DODAJAUTO_H

#include <QDialog>

namespace Ui {
class DodajAuto;
}

class DodajAuto : public QDialog
{
    Q_OBJECT

public:
    explicit DodajAuto(QWidget *parent = nullptr);
    ~DodajAuto();

private slots:

    void on_anuluj_clicked();

    void on_Ok_clicked();
private:
    Ui::DodajAuto *ui;
};

#endif // DODAJAUTO_H
