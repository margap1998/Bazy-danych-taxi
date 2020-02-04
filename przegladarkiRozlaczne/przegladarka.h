#ifndef PRZEGLADARKA_H
#define PRZEGLADARKA_H

#include <QWidget>
namespace Ui {
class Przegladarka;
}

class Przegladarka : public QWidget
{
    Q_OBJECT
public:
    explicit Przegladarka(QWidget *parent = 0,  QWidget *bef = 0);
    ~Przegladarka();

private slots:
protected slots:
    virtual void on_WrocButton_2_clicked();
    virtual void on_OdswierzButton_clicked();

    virtual void on_DodajButton_2_clicked();

    virtual void on_WyszukajButton_clicked();

private:
    QWidget *before;
    Ui::Przegladarka *ui;
};

#endif // PRZEGLADARKA_H
