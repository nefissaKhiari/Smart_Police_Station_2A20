#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql printsupport
QT       += core gui sql network
QT       += multimedia
CONFIG+=console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
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
    arduino.cpp \
    dialog.cpp \
    mailing/mailing/emailaddress.cpp \
    mailing/mailing/mimeattachment.cpp \
    mailing/mailing/mimecontentformatter.cpp \
    mailing/mailing/mimefile.cpp \
    mailing/mailing/mimehtml.cpp \
    mailing/mailing/mimeinlinefile.cpp \
    mailing/mailing/mimemessage.cpp \
    mailing/mailing/mimemultipart.cpp \
    mailing/mailing/mimepart.cpp \
    mailing/mailing/mimetext.cpp \
    mailing/mailing/quotedprintable.cpp \
    mailing/mailing/smtpclient.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    mission.cpp \
    vehicule.cpp

HEADERS += \
    arduino.h \
    dialog.h \
    mailing/mailing/SmtpMime \
    mailing/mailing/emailaddress.h \
    mailing/mailing/mimeattachment.h \
    mailing/mailing/mimecontentformatter.h \
    mailing/mailing/mimefile.h \
    mailing/mailing/mimehtml.h \
    mailing/mailing/mimeinlinefile.h \
    mailing/mailing/mimemessage.h \
    mailing/mailing/mimemultipart.h \
    mailing/mailing/mimepart.h \
    mailing/mailing/mimetext.h \
    mailing/mailing/quotedprintable.h \
    mailing/mailing/smtpclient.h \
    mailing/mailing/smtpexports.h \
        mainwindow.h \
    connection.h \
    mission.h \
    vehicule.h

FORMS += \
        dialog.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
