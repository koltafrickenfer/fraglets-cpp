######################################################################
# Automatically generated by qmake (3.1) Sun Oct 27 20:39:44 2019
######################################################################

TEMPLATE = app
TARGET = src
INCLUDEPATH += .
INCLUDEPATH += /usr/include/x86_64-linux-gnu/qt5/

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += fraglets.h keymultiset.h moleculemultiset.h
SOURCES += fraglets.cpp keymultiset.cpp main.cpp moleculemultiset.cpp
QT += charts
LIBS += -lgvc -lcgraph -lcdt

#target.path = $$[QT_INSTALL_EXAMPLES]/charts/linechart
#INSTALLS += target