#ifndef PRZEJAZDY_H
#define PRZEJAZDY_H

#include <QWidget>

namespace Ui {
class Przejazdy;
}

class Przejazdy : public QWidget
{
    Q_OBJECT
public:
    explicit Przejazdy(QWidget *parent = 0,  QWidget *bef = 0);
    ~Przejazdy();

    Przejazdy(QWidget *parent);
private slots:
protected slots:
    void on_WrocButton_2_clicked();
    void on_OdswierzButton_clicked();

    void on_DodajButton_2_clicked();

    void on_WyszukajButton_clicked();

private:
    QWidget *before;
    Ui::Przejazdy *ui;
};

#endif // PRZEJAZDY_H
