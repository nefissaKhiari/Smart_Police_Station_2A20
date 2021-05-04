#include "mainwindow.h"

#include <QApplication>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"
#include "integ_finale.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

     connection c;
    bool test=c.createconnect();
    a.setStyle("fusion");
    MainWindow w;
    //integ_finale integ;

    if(test)
        { w.show();
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("connection successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Ok);
          // qDebug() <<"Connection reussite";
    }
        else
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        //qDebug() <<"erreur de Connection ";
    return a.exec();
}
