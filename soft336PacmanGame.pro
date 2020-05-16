QT       += core gui sql

TARGET = soft336PacmanGame
TEMPLATE = app


SOURCES += main.cpp\
    ball.cpp \
    ghost.cpp \
    leaderboard.cpp \
    pacmanboard.cpp \
    options.cpp \
    powerball.cpp \
    sqlwraper.cpp \
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
    sqlwraper.h \
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
