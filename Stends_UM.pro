#-------------------------------------------------
#
# Project created by QtCreator 2015-04-01T16:22:53
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#qtHaveModule(opengl): QT += opengl

CONFIG += c++11

TARGET = Stends_UM
TEMPLATE = app


SOURCES += main.cpp\
    src/SEELIB/TumblerRegister.cpp \
    src/SEELIB/UmLedWidget.cpp \
    src/SEELIB/UmTumblerWidget.cpp \
    src/SEELIB/DTrigger.cpp \
    src/SEELIB/Memory.cpp \
    src/SEELIB/UmElement.cpp \
    src/SEELIB/ALU.cpp \
    src/SEELIB/ClockGenerator.cpp \
    src/SEELIB/DigitalIndicator4Bit.cpp \
    src/StendSelectionDialog.cpp \
    src/Stand01.cpp \
    src/Stand02.cpp \
    src/SEELIB/DigitalIndicator8Bit.cpp \
    src/Stand00.cpp \
    src/SEELIB/RSTrigger.cpp \
    src/SEELIB/UmButton.cpp \
    src/SEELIB/JKTrigger.cpp \
    src/SEELIB/TTrigger.cpp \
    src/SEELIB/ShiftRegister.cpp \
    TestWindow.cpp \
    src/SEELIB/InputPin.cpp \
    src/SEELIB/OutputPin.cpp \
    src/SEELIB/Summator.cpp \
    src/SEELIB/GateAnd.cpp \
    src/SEELIB/GateNot.cpp \
    src/SEELIB/GateOr.cpp

HEADERS  += \
    src/SEELIB/TumblerRegister.h \
    src/SEELIB/UmTumblerWidget.h \
    src/SEELIB/UmLedWidget.h \
    src/SEELIB/DTrigger.h \
    src/SEELIB/Memory.h \
    src/SEELIB/UmElement.h \
    src/SEELIB/ALU.h \
    src/SEELIB/ClockGenerator.h \
    src/SEELIB/DigitalIndicator4Bit.h \
    src/StendSelectionDialog.h \
    src/Stand01.h \
    src/Stand02.h \
    src/SEELIB/DigitalIndicator8Bit.h \
    src/Stand00.h \
    src/SEELIB/RSTrigger.h \
    src/SEELIB/UmButton.h \
    src/SEELIB/JKTrigger.h \
    src/SEELIB/TTrigger.h \
    src/SEELIB/ShiftRegister.h \
    TestWindow.h \
    src/SEELIB/InputPin.h \
    src/SEELIB/OutputPin.h \
    src/SEELIB/Summator.h \
    src/SEELIB/GateAnd.h \
    src/SEELIB/GateNot.h \
    src/SEELIB/GateOr.h

FORMS    += \
    src/StendSelectionDialog.ui \
    src/Stand01.ui \
    src/Stand02.ui \
    src/Stand00.ui \
    TestWindow.ui

RESOURCES += \
    widgets_graphics.qrc

INCLUDEPATH += /
INCLUDEPATH += src
INCLUDEPATH += src/SEELIB
