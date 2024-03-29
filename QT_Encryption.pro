#-------------------------------------------------
#
# Project created by QtCreator 2012-05-23T15:15:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_Encryption
TEMPLATE = app
#LIBS+=-LD:\MyPro\QT_Encryption\src\ -lsqlite3

SOURCES += main.cpp\
        mainwindowencryption.cpp \
    src/encryption.cpp \
    src/filedescription.cpp \
    src/sqlite3.c \
    src/detaildialog.cpp \
    src/passworddialog.cpp \
    src/waitdialog.cpp

HEADERS  += mainwindowencryption.h \
    src/encryption.h \
    src/filedescription.h \
    src/detaildialog.h \
    src/passworddialog.h \
    src/waitdialog.h


FORMS    += mainwindowencryption.ui \
    src/detaildialog.ui \
    src/passworddialog.ui \
    src/waitdialog.ui
