#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include"integ_finale.h"
#include<QLineEdit>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
      ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_login_clicked()
{
   // click->play() ;

    QString username= ui->lineEdit_username->text();
        QString password= ui->lineEdit_Password->text();
    if ( username == "test" && password =="test" )
    {
       //QMessageBox::information(this,"Login","Username and Password is correct ");
       ui->labelLogin->setText("login et mot de passe sont correctes");
        this->hide();
        integ_finale integ;
        integ.setModal(true);
        integ.exec();
    }
    else
    {
      // QMessageBox::warning(this,"Login","Username and Password is not correct ");
         ui->labelLogin->setText("login et mot de passe sont incorrectes");

    }
  /*  QString username= ui->lineEdit_username->text();
    QString password= ui->lineEdit_Password->text();
  if (!db.isOpen())
    {
      qDebug()<<"Failed to open the database";
      return;

     }
  QSqlQuery qry;
    if (qry.exec("select * from stpsadmin where username='"+username+"' and password='"+password+"'"))
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
            ui->labelLogin->setText("login et mot de passe sont correctes");
            this->hide();
            integ_finale integ;
            integ.setModal(true);
            integ.exec();
        if(count>1)
            ui->labelLogin->setText("login et mot de passe sont incorrectes");
        if(count<1)
            ui->labelLogin->setText("login et mot de passe sont duplices");*/



    }


void MainWindow::on_pushButton_clicked()
{

}
