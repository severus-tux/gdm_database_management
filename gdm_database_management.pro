#-------------------------------------------------
#
# Project created by QtCreator 2019-07-08T22:58:01
#
#-------------------------------------------------

QT       += core gui sql printsupport
win32:RC_ICONS += GDM.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gdm_database_management
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        collection_details.cpp \
        edit_member_details.cpp \
        edit_payment.cpp \
        gdm_database.cpp \
        main.cpp \
        mainwindow.cpp \
        member_details.cpp \
        member_details_input.cpp \
        payment_input.cpp

HEADERS += \
        collection_details.h \
        edit_member_details.h \
        edit_payment.h \
        gdm_database.h \
        mainwindow.h \
        member_details.h \
        member_details_input.h \
        payment_input.h

FORMS += \
        collection_details.ui \
        edit_member_details.ui \
        edit_payment.ui \
        mainwindow.ui \
        member_details.ui \
        member_details_input.ui \
        payment_input.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
