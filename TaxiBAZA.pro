#-------------------------------------------------
#
# Project created by QtCreator 2020-01-21T20:01:47
#
#-------------------------------------------------

QT       += sql core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TaxiBAZA
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
    Dialogi/dodajaktywowanopromocje.cpp \
    Dialogi/dodajauto.cpp \
    Dialogi/dodajkierowce.cpp \
    Dialogi/dodajklienta.cpp \
    Dialogi/dodajnaprawe.cpp \
    Dialogi/dodajobsluge.cpp \
    Dialogi/dodajpromocje.cpp \
    Dialogi/dodajprzejazd.cpp \
    Dialogi/dodajrejon.cpp \
    Dialogi/dodajstawke.cpp \
    Dialogi/dodajtylkokierowce.cpp \
    Dialogi/dodajubezpieczenie.cpp \
    Dialogi/dodajulice.cpp \
    Szukajki/szukajaktywnejpromocji.cpp \
    Szukajki/szukajklienta.cpp \
    Szukajki/szukajkodu.cpp \
    Szukajki/szukajnaprawy.cpp \
    Szukajki/szukajpojazdu.cpp \
    Szukajki/szukajkierowcy.cpp \
    Szukajki/szukajobslugi.cpp \
    Szukajki/szukajpromocji.cpp \
    Szukajki/szukajprzejazdu.cpp \
    Szukajki/szukajrejonu.cpp \
    Szukajki/szukajubezpieczenia.cpp \
    Szukajki/szukajulicy.cpp \
    Usuwanie/usunaktywnapromocje.cpp \
    Usuwanie/usunkierowce.cpp \
    Usuwanie/usunklienta.cpp \
    Usuwanie/usunnaprawe.cpp \
    Usuwanie/usunobsluge.cpp \
    Usuwanie/usunpojazd.cpp \
    Usuwanie/usunpromocje.cpp \
    Usuwanie/usunprzejazdy.cpp \
    Usuwanie/usunrejon.cpp \
    Usuwanie/usunstawke.cpp \
    Usuwanie/usunubezpieczenie.cpp \
    Usuwanie/usunulice.cpp \
    Usuwanie/usunwarsztat.cpp \
    logowanie.cpp \
        main.cpp \
    przegladarkiRozlaczne/aktywnepromocje.cpp \
    przegladarkiRozlaczne/kierowcypojazdy.cpp \
    przegladarkiRozlaczne/klienci.cpp \
    przegladarkiRozlaczne/naprawy.cpp \
    przegladarkiRozlaczne/promocje.cpp \
    przegladarkiRozlaczne/przejazdy.cpp \
    przegladarkiRozlaczne/rejony.cpp \
    przegladarkiRozlaczne/stawki.cpp \
    przegladarkiRozlaczne/ubezpieczenia.cpp \
        taxibaza.cpp \
    menu.cpp \
    przegladarka.cpp \
    raportdialog.cpp \
    warsztat.cpp \
    wyszukaj.cpp

HEADERS += \
    Dialogi/dodajaktywowanopromocje.h \
    Dialogi/dodajauto.h \
    Dialogi/dodajkierowce.h \
    Dialogi/dodajklienta.h \
    Dialogi/dodajnaprawe.h \
    Dialogi/dodajobsluge.h \
    Dialogi/dodajpromocje.h \
    Dialogi/dodajprzejazd.h \
    Dialogi/dodajrejon.h \
    Dialogi/dodajstawke.h \
    Dialogi/dodajtylkokierowce.h \
    Dialogi/dodajubezpieczenie.h \
    Dialogi/dodajulice.h \
    Szukajki/szukajaktywnejpromocji.h \
    Szukajki/szukajklienta.h \
    Szukajki/szukajkodu.h \
    Szukajki/szukajnaprawy.h \
    Szukajki/szukajpojazdu.h \
    Szukajki/szukajkierowcy.h \
    Szukajki/szukajobslugi.h \
    Szukajki/szukajpromocji.h \
    Szukajki/szukajprzejazdu.h \
    Szukajki/szukajrejonu.h \
    Szukajki/szukajubezpieczenia.h \
    Szukajki/szukajulicy.h \
    Usuwanie/usunaktywnapromocje.h \
    Usuwanie/usunkierowce.h \
    Usuwanie/usunklienta.h \
    Usuwanie/usunnaprawe.h \
    Usuwanie/usunobsluge.h \
    Usuwanie/usunpojazd.h \
    Usuwanie/usunpromocje.h \
    Usuwanie/usunprzejazdy.h \
    Usuwanie/usunrejon.h \
    Usuwanie/usunstawke.h \
    Usuwanie/usunubezpieczenie.h \
    Usuwanie/usunulice.h \
    Usuwanie/usunwarsztat.h \
    logowanie.h \
    przegladarkiRozlaczne/aktywnepromocje.h \
    przegladarkiRozlaczne/kierowcypojazdy.h \
    przegladarkiRozlaczne/klienci.h \
    przegladarkiRozlaczne/naprawy.h \
    przegladarkiRozlaczne/promocje.h \
    przegladarkiRozlaczne/przejazdy.h \
    przegladarkiRozlaczne/rejony.h \
    przegladarkiRozlaczne/stawki.h \
    przegladarkiRozlaczne/ubezpieczenia.h \
        taxibaza.h \
    menu.h \
    przegladarka.h \
    raportdialog.h \
    warsztat.h \
    wyszukaj.h

FORMS += \
    Dialogi/dodajaktywowanopromocje.ui \
    Dialogi/dodajauto.ui \
    Dialogi/dodajkierowce.ui \
    Dialogi/dodajklienta.ui \
    Dialogi/dodajnaprawe.ui \
    Dialogi/dodajobsluge.ui \
    Dialogi/dodajpromocje.ui \
    Dialogi/dodajprzejazd.ui \
    Dialogi/dodajrejon.ui \
    Dialogi/dodajstawke.ui \
    Dialogi/dodajtylkokierowce.ui \
    Dialogi/dodajubezpieczenie.ui \
    Dialogi/dodajulice.ui \
    Szukajki/szukajaktywnejpromocji.ui \
    Szukajki/szukajklienta.ui \
    Szukajki/szukajkodu.ui \
    Szukajki/szukajnaprawy.ui \
    Szukajki/szukajpojazdu.ui \
    Szukajki/szukajkierowcy.ui \
    Szukajki/szukajobslugi.ui \
    Szukajki/szukajpromocji.ui \
    Szukajki/szukajprzejazdu.ui \
    Szukajki/szukajrejonu.ui \
    Szukajki/szukajubezpieczenia.ui \
    Szukajki/szukajulicy.ui \
    Usuwanie/usunaktywnapromocje.ui \
    Usuwanie/usunkierowce.ui \
    Usuwanie/usunklienta.ui \
    Usuwanie/usunnaprawe.ui \
    Usuwanie/usunobsluge.ui \
    Usuwanie/usunpojazd.ui \
    Usuwanie/usunpromocje.ui \
    Usuwanie/usunprzejazdy.ui \
    Usuwanie/usunrejon.ui \
    Usuwanie/usunstawke.ui \
    Usuwanie/usunubezpieczenie.ui \
    Usuwanie/usunulice.ui \
    Usuwanie/usunwarsztat.ui \
    logowanie.ui \
    przegladarkiRozlaczne/aktywnepromocje.ui \
    przegladarkiRozlaczne/kierowcypojazdy.ui \
    przegladarkiRozlaczne/klienci.ui \
    przegladarkiRozlaczne/naprawy.ui \
    przegladarkiRozlaczne/promocje.ui \
    przegladarkiRozlaczne/przejazdy.ui \
    przegladarkiRozlaczne/rejony.ui \
    przegladarkiRozlaczne/stawki.ui \
    przegladarkiRozlaczne/ubezpieczenia.ui \
        taxibaza.ui \
    menu.ui \
    przegladarka.ui \
    raportdialog.ui \
    warsztat.ui \
    wyszukaj.ui
