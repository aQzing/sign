#-------------------------------------------------
#
# Project created by QtCreator 2021-03-09T15:09:37
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtSign
TEMPLATE = app
DEFINES += HAVE_CONFIG_H

SOURCES += main.cpp\
        mainwindow.cpp \
    codewidget.cpp \
    datawidget.cpp \
    qrencode/bitstream.c \
    qrencode/mask.c \
    qrencode/mmask.c \
    qrencode/mqrspec.c \
    qrencode/qrencode.c \
    qrencode/qrinput.c \
    qrencode/qrspec.c \
    qrencode/rsecc.c \
    qrencode/split.c

HEADERS  += mainwindow.h \
    codewidget.h \
    datawidget.h \
    qrencode/bitstream.h \
    qrencode/config.h \
    qrencode/mask.h \
    qrencode/mmask.h \
    qrencode/mqrspec.h \
    qrencode/qrencode.h \
    qrencode/qrencode_inner.h \
    qrencode/qrinput.h \
    qrencode/qrspec.h \
    qrencode/rsecc.h \
    qrencode/split.h

FORMS    += mainwindow.ui \
    codewidget.ui \
    datawidget.ui
