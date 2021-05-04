QT       += core gui sql printsupport charts  network widgets \
multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    citoyen.cpp \
    connection.cpp \
    exportexcelobject.cpp \
    main.cpp \
    mainwindow.cpp \
    petition.cpp \
    qcustomplot.cpp \
    smtp.cpp

HEADERS += \
    citoyen.h \
    connection.h \
    exportexcelobject.h \
    mainwindow.h \
    petition.h \
    qcustomplot.h \
    smtp.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
