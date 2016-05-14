#-------------------------------------------------
#
# Project created by QtCreator 2016-05-03T21:47:24
#
#-------------------------------------------------

QT       += core gui \
         multimedia \
        multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TAIKODRUM
TEMPLATE = app


SOURCES += main.cpp\
    elmo.cpp \
    drum.cpp \
    game.cpp \
    score.cpp \
    good.cpp \
    start.cpp \
    mytimer.cpp \
    end.cpp

HEADERS  += drum.h \
    elmo.h \
    game.h \
    score.h \
    good.h \
    start.h \
    mytimer.h \
    end.h

//FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
