#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pb_login_clicked()
{
    QString username= ui->username_2->text();
    QString password= ui->pswd->text();
    if ( username == "test" && password =="test" )
    {
        QMessageBox::information(this,"Login","Username and Password is correct ");
        hide();
        mainwindow=new MainWindow(this);
        mainwindow->show();
    }
    else
    {
       QMessageBox::warning(this,"Login","Username and Password is not correct ");
    }
}


