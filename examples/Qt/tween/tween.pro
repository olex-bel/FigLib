
SOURCES += \
    main.cpp \
    canva.cpp

HEADERS += \
    canva.h 

INCLUDEPATH = ../../../
QMAKE_LIBDIR += ../../../

QT += opengl
QMAKE_LIBS += -lngon
