#-------------------------------------------------
#
# Project created by QtCreator 2012-02-07T16:04:09
#
#-------------------------------------------------

QT       += core gui opengl
QT       += widgets

TARGET = practica2Basica
TEMPLATE = app

SOURCES +=\
    Camera.cpp \
    Light.cpp \
    Material.cpp \
    MainWindow.cpp \
    Main.cpp \
    GLWidget.cpp \
    library/Common.cpp \
    objects/cara.cpp \
    objects/Object.cpp \
    scenes/Scene.cpp \
    scenes/SceneFactory.cpp \
    scenes/SceneFactoryBasica.cpp \
    TG/TG.cpp \
    TG/Rotate.cpp \
    TG/RotateBoundary.cpp \
    TG/ScaleBoundary.cpp \
    animations/Animation.cpp \
    TG/TranslateG.cpp \
    TG/ScaleG.cpp \
    scenes/FactoryConcurso.cpp

HEADERS  += \
    library/vec.h \
    library/mat.h \
    library/Common.h \
    Camera.h \
    Light.h \
    Material.h \
    MainWindow.h \
    objects/cara.h \
    objects/Object.h \
    scenes/Scene.h \
    scenes/SceneFactory.h \
    scenes/SceneFactoryBasica.h \
    GLWidget.h \
    TG/TG.h \
    TG/Rotate.h \
    TG/RotateBoundary.h \
    TG/ScaleBoundary.h \
    animations/Animation.h \
    TG/TranslateG.h \
    TG/ScaleG.h \
    scenes/FactoryConcurso.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    vshader1.glsl \
    fshader1.glsl \
    vshaderGouraud.glsl \
    fshaderGouraud.glsl \
    vshaderPhong.glsl \
    fshaderPhong.glsl \
    vshaderToon.glsl \
    fshaderToon.glsl \
    vshaderPhongTex.glsl \
    fshaderPhongTex.glsl

RESOURCES += resources.qrc

DISTFILES +=
