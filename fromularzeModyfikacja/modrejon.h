#ifndef MODREJON_H
#define MODREJON_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class modRejon;
}

class modRejon : public QDialog
{
    Q_OBJECT

public:
    explicit modRejon(QWidget *parent = nullptr);
    ~modRejon();

private slots:
    void on_anuluj_clicked();

    void on_Ok_clicked();

private:
    Ui::modRejon *ui;
    QSqlQueryModel model;
};

#endif // MODREJON_H
