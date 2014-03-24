#-------------------------------------------------
#
# Project created by QtCreator 2014-02-18T17:30:20
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SKProject_SqlServer
TEMPLATE = app


SOURCES += main.cpp\
        UI/UI_MainWindow.cpp \
    DB/DB_CONNECT.cpp \
    UI/UI_LOGIN.cpp \
    LOGIC/LOGIC_USER.cpp \
    DB/DB_SQL.cpp \
    UI/UI_WELL.cpp \
    INTERFACE/SqlQueryModel_RW.cpp \
    LOGIC/WELL/LOGIC_WELL_BASIC.cpp \
    UI/UI_ADD_DATA.cpp \
    LOGIC/WELL/LOGIC_WELL.cpp \
    INTERFACE/ExportToExcel.cpp

HEADERS  += UI/UI_MainWindow.h \
    DB/DB_CONNECT.h \
    UI/UI_LOGIN.h \
    LOGIC/LOGIC_USER.h \
    DB/DB_SQL.h \
    UI/UI_WELL.h \
    INTERFACE/SqlQueryModel_RW.h \
    LOGIC/WELL/LOGIC_WELL_BASIC.h \
    UI/UI_ADD_DATA.h \
    LOGIC/WELL/LOGIC_WELL.h \
    INTERFACE/ExportToExcel.h

FORMS    += UI/UI_MainWindow.ui \
    UI/UI_LOGIN.ui \
    UI/UI_WELL.ui \
    UI/UI_ADD_DATA.ui
