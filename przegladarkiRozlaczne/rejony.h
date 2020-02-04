#ifndef REJONY_H
#define REJONY_H

#include <QWidget>

namespace Ui {
class Rejony;
}

class Rejony : public QWidget
{
    Q_OBJECT
public:
    explicit Rejony(QWidget *parent = 0,  QWidget *bef = 0);
    ~Rejony();

    Rejony(QWidget *parent);
private slots:
protected slots:
    void on_WrocButton_2_clicked();
    void on_OdswierzButton_clicked();

    void on_DodajButton_2_clicked();

    void on_WyszukajButton_clicked();

private:
    QWidget *before;
    Ui::Rejony *ui;
};

#endif // REJONY_H
