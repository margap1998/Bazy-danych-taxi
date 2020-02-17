#ifndef LOGOWANIE_H
#define LOGOWANIE_H

#include <QWidget>

namespace Ui {
class Logowanie;
}

class Logowanie : public QWidget
{
    Q_OBJECT

public:
    explicit Logowanie(QWidget *parent = nullptr);
    ~Logowanie();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Logowanie *ui;
};

#endif // LOGOWANIE_H
