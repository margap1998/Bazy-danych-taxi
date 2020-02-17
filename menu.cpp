#include "menu.h"
#include "ui_menu.h"
#include "przegladarka.h"
#include "raportdialog.h"
#include "przegladarkiRozlaczne/kierowcypojazdy.h"
#include "przegladarkiRozlaczne/rejony.h"
#include "przegladarkiRozlaczne/klienci.h"
#include "przegladarkiRozlaczne/naprawy.h"
#include "przegladarkiRozlaczne/promocje.h"
#include "przegladarkiRozlaczne/ubezpieczenia.h"
#include "przegladarkiRozlaczne/przejazdy.h"
#include "przegladarkiRozlaczne/stawki.h"
#include <QtSql/QSqlDatabase>
#include <przegladarkiRozlaczne/aktywnepromocje.h>

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    before = nullptr;
}
Menu::Menu(QWidget *bef,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    before =bef;
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}
void Menu::odpalPrzegladarke(QWidget *a)
{
    if (a){
        this->hide();
        a->show();
    }
}
void Menu::on_RejonyButton_clicked()
{
    odpalPrzegladarke(new Rejony(parentWidget(),this));
}

void Menu::on_KierowcyButton_clicked()
{
    odpalPrzegladarke(new kierowcyPojazdy(parentWidget(),this));
}

void Menu::on_UbezpieczeniaButton_clicked()
{
    odpalPrzegladarke(new Ubezpieczenia(parentWidget(),this));
}

void Menu::on_NaprawyButton_clicked()
{
    odpalPrzegladarke(new naprawy(parentWidget(),this));
}

void Menu::on_PrzejazdyButton_clicked()
{
    odpalPrzegladarke(new Przejazdy(parentWidget(),this));
}

void Menu::on_StawkiButton_clicked()
{
    odpalPrzegladarke(new Stawki(parentWidget(),this));
}

void Menu::on_KlienciButton_clicked()
{
    odpalPrzegladarke(new Klienci(parentWidget(),this));
}

void Menu::on_PromocjaButton_clicked()
{
    odpalPrzegladarke(new Promocje(parentWidget(),this));
}

void Menu::on_WylogujButton_clicked()
{if(before!=nullptr){
        before->show();
        this->hide();
        delete this;
    }
}

void Menu::on_WylaczButton_clicked()
{
    parentWidget()->close();
}
void Menu::on_RaportPrzejazdyButton_clicked()
{
    (new RaportDialog("SELECT imie, nazwisko, przejazdy(PESEL) FROM kierowca"))->show();
}

void Menu::on_RaportPlacButton_clicked()
{
}

void Menu::on_pushButton_clicked()
{
    odpalPrzegladarke(new aktywnePromocje(parentWidget(),this));
}
