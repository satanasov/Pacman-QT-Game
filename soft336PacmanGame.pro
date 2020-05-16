#-------------------------------------------------
#
# Project created by QtCreator 2014-12-15T15:50:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

QT    += gui

TARGET = soft336PacmanGame
TEMPLATE = app


SOURCES += main.cpp\
    ball.cpp \
    ghost.cpp \
    leaderboard.cpp \
    pacmanboard.cpp \
    options.cpp \
    powerball.cpp \
    textdrawing.cpp \
    pacmanwindow.cpp \
    pacman.cpp

HEADERS  += \
    ball.h \
    ghost.h \
    leaderboard.h \
    pacmanboard.h \
    options.h \
    powerball.h \
    textdrawing.h \
    pacmanwindow.h \
    pacman.h

FORMS    += \
    leaderboard.ui \
    pacmanwindow.ui \
    options.ui

RESOURCES += \
    Resources.qrc \
    Images.qrc \
    Sounds.qrc
