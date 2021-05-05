#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "integ_finale.h"
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

#include "smtp.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_login_clicked();

    void on_mail_clicked();

    QString generer_code();
    QString get_code();
    void set_code(QString code);
    void on_valider_mdp_clicked();

    void on_retour_clicked();

    void on_mdp_oublie_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db ;
     integ_finale *integ;
     QString code;
     QString text;


};
#endif // MAINWINDOW_H
