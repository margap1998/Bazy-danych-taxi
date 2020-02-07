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
    Dialogi/dodajkierowce.cpp \
    Dialogi/dodajklienta.cpp \
    Dialogi/dodajnaprawe.cpp \
    Dialogi/dodajobsluge.cpp \
    Dialogi/dodajpromocje.cpp \
    Dialogi/dodajprzejazd.cpp \
    Dialogi/dodajrejon.cpp \
    Dialogi/dodajstawke.cpp \
    Dialogi/dodajubezpieczenie.cpp \
    Dialogi/dodajulice.cpp \
        main.cpp \
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
    wyszukaj.cpp

HEADERS += \
    Dialogi/dodajkierowce.h \
    Dialogi/dodajklienta.h \
    Dialogi/dodajnaprawe.h \
    Dialogi/dodajobsluge.h \
    Dialogi/dodajpromocje.h \
    Dialogi/dodajprzejazd.h \
    Dialogi/dodajrejon.h \
    Dialogi/dodajstawke.h \
    Dialogi/dodajubezpieczenie.h \
    Dialogi/dodajulice.h \
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
    wyszukaj.h

FORMS += \
    Dialogi/dodajkierowce.ui \
    Dialogi/dodajklienta.ui \
    Dialogi/dodajnaprawe.ui \
    Dialogi/dodajobsluge.ui \
    Dialogi/dodajpromocje.ui \
    Dialogi/dodajprzejazd.ui \
    Dialogi/dodajrejon.ui \
    Dialogi/dodajstawke.ui \
    Dialogi/dodajubezpieczenie.ui \
    Dialogi/dodajulice.ui \
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
    wyszukaj.ui
