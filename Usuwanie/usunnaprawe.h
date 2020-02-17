#ifndef USUNNAPRAWE_H
#define USUNNAPRAWE_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class UsunNaprawe;
}

class UsunNaprawe : public QDialog
{
    Q_OBJECT

public:
    explicit UsunNaprawe(QWidget *parent = nullptr);
    ~UsunNaprawe();

private slots:
    void on_usun_clicked();

    void on_wroc_clicked();

private:
    Ui::UsunNaprawe *ui;
    QSqlQueryModel model,modelW,modelR;
};

#endif // USUNNAPRAWE_H
