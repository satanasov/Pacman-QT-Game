QT       += core gui sql widgets multimedia

TARGET = Pacman-QT-Game
TEMPLATE = app


SOURCES += main.cpp\
    ball.cpp \
    db_settings.cpp \
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
    db_settings.h \
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
    db_settings.ui \
    leaderboard.ui \
    options.ui \
    pacmanwindow.ui

RESOURCES += \
    Resources.qrc \
    Images.qrc \
    Sounds.qrc
