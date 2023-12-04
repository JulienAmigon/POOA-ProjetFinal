TEMPLATE = app
TARGET = ZoneDeDessin

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    Headers.h \
    ModeHeaders.h \
    fenetre.h \
    Mode\mode.h \
    Mode\pointeur.h \
    Mode\eraser.h \
    Mode\customform.h \
    Mode\Forme\forme.h \
    Mode\Forme\square.h \
    Mode\Forme\triangle.h \
    Mode\Forme\circle.h \

SOURCES += \
    main.cpp \
    fenetre.cpp \
    Mode\mode.cpp \
    Mode\pointeur.cpp \
    Mode\eraser.cpp \
    Mode\customform.cpp \
    Mode\Forme\forme.cpp \
    Mode\Forme\square.cpp \
    Mode\Forme\triangle.cpp \
    Mode\Forme\circle.cpp
