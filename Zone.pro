TEMPLATE = app
TARGET = AppliDessin
QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    Headers.h \
    Pointer/pointer.h \
    Scenes/Scene.h \
    Scenes/SceneCursor.h \
    Scenes/ScenePixels.h \
    Scenes/SceneShapes.h \
    fenetre.h

SOURCES += \
    Pointer/pointer.cpp \
    Scenes/Scene.cpp \
    Scenes/SceneCursor.cpp \
    Scenes/ScenePixels.cpp \
    Scenes/SceneShapes.cpp \
    fenetre.cpp \
    main.cpp \
