#include "mainwindow.h"
#include "client.h"
#include "ui_mainwindow.h"
//#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->le_id->setValidator( new QIntValidator(0, 9999999, this));
   ui->tab_client->setModel(C.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    Client C(id,nom,prenom);
    bool test=C.ajouter();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succés");
        ui->tab_client->setModel(C.afficher());
    }
    else
        msgBox.setText("Echec d'e suppression'ajout");
    msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Client C1; C1.setid(ui->le_id_supp->text().toInt());
    bool test=C1.supprimer(C1.getid());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprimer avec succés");
     ui->tab_client->setModel(C.afficher());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();

}
