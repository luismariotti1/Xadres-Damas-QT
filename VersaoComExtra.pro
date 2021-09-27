TEMPLATE = app
TARGET = versaoComExtra.pro

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4) QT += widgets

HEADERS += \
    bispo.h \
    cavalo.h \
    damabranca.h \
    damavermelha.h \
    imagens.h \
    imagensdama.h \
    mainwindow.h \
    pecasdama.h \
    pecasxadrez.h \
    rainha.h \
    tabdama.h \
    tabuleiro.h \
    tabxadrez.h \
    torre.h

SOURCES += \
    Main.cpp \
    bispo.cpp \
    cavalo.cpp \
    damabranca.cpp \
    damavermelha.cpp \
    mainwindow.cpp \
    pecasdama.cpp \
    pecasxadrez.cpp \
    rainha.cpp \
    tabdama.cpp \
    tabuleiro.cpp \
    tabxadrez.cpp \
    torre.cpp
