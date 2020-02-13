#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include "przegladarka.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();
    enum mody
{
    KIEROWCY = 1,
    PRZEJAZDY = 2,
    UBEZPIECZENIA = 3,
    PLACE= 4,
    PROMOCJE = 5,
    KLIENCI = 6,
    REJONY = 7,
    NAPRAWY = 8,
    STAWKI = 9,
    NON= 0
};
private slots:

    void on_RejonyButton_clicked();

    void on_KierowcyButton_clicked();

    void on_UbezpieczeniaButton_clicked();

    void on_NaprawyButton_clicked();

    void on_PrzejazdyButton_clicked();

    void on_StawkiButton_clicked();

    void on_KlienciButton_clicked();

    void on_PromocjaButton_clicked();

    void on_WylogujButton_clicked();

    void on_WylaczButton_clicked();

    void on_RaportPrzejazdyButton_clicked();

    void on_RaportPlacButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Menu *ui;
    QSqlDatabase db;
    void odpalPrzegladarke(QWidget *a = 0);
};

#endif // MENU_H
