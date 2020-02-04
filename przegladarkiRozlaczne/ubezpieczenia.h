#ifndef UBEZPIECZENIA_H
#define UBEZPIECZENIA_H

#include <QWidget>

namespace Ui {
class Ubezpieczenia;
}

class Ubezpieczenia : public QWidget
{
    Q_OBJECT
public:
    explicit Ubezpieczenia(QWidget *parent = 0,  QWidget *bef = 0);
    ~Ubezpieczenia();

    Ubezpieczenia(QWidget *parent);
private slots:
protected slots:
    void on_WrocButton_2_clicked();
    void on_OdswierzButton_clicked();

    void on_DodajButton_2_clicked();

    void on_WyszukajButton_clicked();

private:
    QWidget *before;
    Ui::Ubezpieczenia *ui;
};

#endif // UBEZPIECZENIA_H
