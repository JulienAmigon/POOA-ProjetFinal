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
    fenetre1.h

SOURCES += \
    Pointer/pointer.cpp \
    Scenes/Scene.cpp \
    Scenes/SceneCursor.cpp \
    Scenes/ScenePixels.cpp \
    Scenes/SceneShapes.cpp \
    fenetre1.cpp \
    main.cpp \
