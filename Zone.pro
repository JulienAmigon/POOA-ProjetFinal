TEMPLATE = app
TARGET = main
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    Headers.h \
    ModeHeaders.h \
    Pointer/pointer.h \
    Scenes/Scene.h \
    Scenes/SceneCursor.h \
    Scenes/ScenePixels.h \
    Scenes/SceneShapes.h \
    fenetre.h \
    Mode\mode.h \
    Mode\pointeur.h \
    Mode\eraser.h \
    Mode\customform.h \
    Mode\Forme\forme.h \
    Mode\Forme\square.h \
    Mode\Forme\triangle.h \
    Mode\Forme\circle.h \
    fenetre1.h

SOURCES += \
    Pointer/pointer.cpp \
    Scenes/Scene.cpp \
    Scenes/SceneCursor.cpp \
    Scenes/ScenePixels.cpp \
    Scenes/SceneShapes.cpp \
    fenetre1.cpp \
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
