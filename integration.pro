


QT       += core gui sql printsupport
QT       += core gui charts
QT       += printsupport
QT       += multimedia
QT       +=serialport
CONFIG+=console
#QT       += pdf

QT += widgets multimedia


QT       += core gui
QT       += printsupport multimedia texttospeech
QT       += core gui multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets

TARGET =integration
TEMPLATE = app

CONFIG += c++11
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agent.cpp \
    arduino.cpp \
    cellule.cpp \
    citoyen.cpp \
    connection.cpp \
    detenu.cpp \
    equipement.cpp \
    exportexcelobject.cpp \
    integ_finale.cpp \
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
    maintenance.cpp \
    mainwindow.cpp \
    mission.cpp \
    petition.cpp \
    service.cpp \
    smtp.cpp \
    vehicule.cpp

HEADERS += \
    agent.h \
    arduino.h \
    cellule.h \
    citoyen.h \
    connection.h \
    detenu.h \
    equipement.h \
    exportexcelobject.h \
    integ_finale.h \
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
    maintenance.h \
    mainwindow.h \
    mission.h \
    petition.h \
    service.h \
    smtp.h \
    vehicule.h

FORMS += \
    integ_finale.ui \
    mainwindow.ui
    QMAKE_CXXFLAGS+= -std=gnu++14

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc
