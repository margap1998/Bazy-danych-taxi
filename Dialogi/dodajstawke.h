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

private slots:
    void on_Ok_clicked();

    void on_anuluj_clicked();
private:
    Ui::DodajStawke *ui;
};

#endif // DODAJSTAWKE_H
