TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++14

SOURCES += main.cpp \
    mainmenu.cpp \
    game.cpp \
    player.cpp


LIBS += -L"/home/hbollon/Projects/SFML-master/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += "/home/hbollon/Projects/SFML-master/include"
DEPENDPATH += "/home/hbollon/Projects/SFML-master/include"

HEADERS += \
    game.h \
    player.h
