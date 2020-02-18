#ifndef MODAKTYWOWANAPROMOCJA_H
#define MODAKTYWOWANAPROMOCJA_H

#include <QDialog>
#include <QSqlQueryModel>
namespace Ui {
class modAktywowanaPromocja;
}

class modAktywowanaPromocja : public QDialog
{
    Q_OBJECT

public:
    explicit modAktywowanaPromocja(QWidget *parent = nullptr);
    ~modAktywowanaPromocja();

private slots:
    void on_Ok_clicked();

    void on_anuluj_clicked();

    void on_kodPromocjiwyb_currentTextChanged(const QString &arg1);

    void on_numerCBwybor_activated(const QString &arg1);

private:
    Ui::modAktywowanaPromocja *ui;
    QSqlQueryModel model,modelK,modelR;
    QSqlQueryModel umodelK,umodelT;
    void zmiana_stanu();
};

#endif // MODAKTYWOWANAPROMOCJA_H
