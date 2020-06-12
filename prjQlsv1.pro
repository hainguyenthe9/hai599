TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Employee.cpp \
        Helpper.cpp \
        StatusDate.cpp \
        main.cpp

DISTFILES += \
    ImportData.csv \
    prjQlsv1.pro.user

HEADERS += \
    Employee.h \
    Helpper.h \
    StatusDate.h
