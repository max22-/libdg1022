TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

unix:!macx: LIBS += -L$$PWD/../build-DG1022-Desktop_Qt_5_13_0_GCC_64bit-Debug/ -lDG1022

INCLUDEPATH += $$PWD/../DG1022
DEPENDPATH += $$PWD/../DG1022
