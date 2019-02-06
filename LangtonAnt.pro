TEMPLATE = app
TARGET = LangtonAnt
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src\main.cpp \
    src\grid.cpp \
    src\langtonant.cpp \
    src\turingm.cpp \
    src/ant.cpp \
    src/langtonantddii.cpp \
    src/langtonantiidd.cpp \
    src/langtonantiddi.cpp

HEADERS += \
    include/grid.h \
    include/langtonant.h \
    include/turingm.h \
    include/definitions.h \
    include/ant.h \
    include/langtonantddii.h \
    include/langtonantiidd.h \
    include/langtonantiddi.h

#INCLUDEPATH += /path/to/ncurses/headers/
#LIBS += -L/path/to/ncurses/library/ -lncurses

DISTFILES += config/dataset.txt
