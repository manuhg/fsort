#-------------------------------------------------
#
# Project created by QtCreator 2018-03-31T11:23:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fsort
TEMPLATE = app

#QMAKE_LFLAGS += -Wl,-rpath,"'$$ORIGIN/lib'"

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mappings.cpp

HEADERS += \
        mainwindow.h \
    mappings.h \
    deps.h

FORMS += \
        mainwindow.ui \
    mappings.ui


unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += opencv
#unix:!macx: LIBS += -L/usr/local/lib64 -lopencv_highgui opencv_videoio opencv_imgcodecs opencv_imgproc opencv_core
unix:!macx: LIBS += -L$$PWD/../../../lib/ -lfsort  -lcaffe -lbhtsne
unix:!macx: LIBS += -L /usr/lib/x86_64-linux-gnu/ -lboost_system -lglog -lcblas -lgflags -lprotobuf -lm -lhdf5_hl -lhdf5  -lboost_filesystem -lboost_thread -llmdb -lleveldb

INCLUDEPATH += $$PWD/../../../include
DEPENDPATH += $$PWD/../../../include

RESOURCES += \
    resources.qrc
