#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Petition_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
        ui->Petition->setGeometry(0,142,151,61);
        ui->Materiel->setGeometry(-40,180,201,81);
        ui->Agent->setGeometry(-14,246,151,51);
        ui->Crimes->setGeometry(0,299,121,51);
        ui->Plaintes->setGeometry(0,350,121,51);
        ui->Mission->setGeometry(9,400,111,41);
}

void MainWindow::on_Materiel_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
        ui->Petition->setGeometry(-17,142,151,61);
        ui->Materiel->setGeometry(-23,180,201,81);
        ui->Agent->setGeometry(-14,246,151,51);
        ui->Crimes->setGeometry(0,299,121,51);
        ui->Plaintes->setGeometry(0,350,121,51);
        ui->Mission->setGeometry(9,400,111,41);
}

void MainWindow::on_Agent_clicked()
{
    ui->stackedWidget->setCurrentIndex(3) ;
        ui->Petition->setGeometry(-17,142,151,61);
        ui->Materiel->setGeometry(-40,180,201,81);
        ui->Agent->setGeometry(0,246,151,51);
        ui->Crimes->setGeometry(0,299,121,51);
        ui->Plaintes->setGeometry(0,350,121,51);
        ui->Mission->setGeometry(9,400,111,41);
}

void MainWindow::on_Crimes_clicked()
{
    ui->stackedWidget->setCurrentIndex(4) ;
        ui->Petition->setGeometry(-17,142,151,61);
        ui->Materiel->setGeometry(-40,180,201,81);
        ui->Agent->setGeometry(-14,246,151,51);
        ui->Crimes->setGeometry(17,299,121,51);
        ui->Plaintes->setGeometry(0,350,121,51);
        ui->Mission->setGeometry(9,400,111,41);
}

void MainWindow::on_Plaintes_clicked()
{
    ui->stackedWidget->setCurrentIndex(5) ;
        ui->Petition->setGeometry(-17,142,151,61);
        ui->Materiel->setGeometry(-40,180,201,81);
        ui->Agent->setGeometry(-14,246,151,51);
        ui->Crimes->setGeometry(0,299,121,51);
        ui->Plaintes->setGeometry(17,350,121,51);
        ui->Mission->setGeometry(9,400,111,41);
}

void MainWindow::on_Mission_clicked()
{
    ui->stackedWidget->setCurrentIndex(6) ;
        ui->Petition->setGeometry(-17,142,151,61);
        ui->Materiel->setGeometry(-40,180,201,81);
        ui->Agent->setGeometry(-14,246,151,51);
        ui->Crimes->setGeometry(0,299,121,51);
        ui->Plaintes->setGeometry(0,350,121,51);
        ui->Mission->setGeometry(26,400,111,41);
}
