#ifndef NIEMABAZY_H
#define NIEMABAZY_H

#include <QMainWindow>

namespace Ui {
class niemabazy;
}

class niemabazy : public QMainWindow
{
    Q_OBJECT

public:
    explicit niemabazy(QString text, QWidget *parent = 0);
    ~niemabazy();

private slots:
    void on_pushButton_clicked();

private:
    Ui::niemabazy *ui;
};

#endif // NIEMABAZY_H
