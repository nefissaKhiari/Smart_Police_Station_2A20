#include "mainwindow.h"
#include "detenu.h"
#include "cellule.h"
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
   ui->tab_detenu->setModel(D.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_ajouter_clicked()
{
    int id_detenu=ui->le_id->text().toInt();
    QString nom_detenu=ui->le_nom->text();
    QString prenom_detenu=ui->le_prenom->text();
    QString date_naissance_detenu=ui->la_date->text();
    QString nationalite_detenu=ui->la_nationalite->text();
    QString sexe_detenu=ui->le_sexe->text();
    int taille_detenu=ui->la_taille->text().toInt();
    int poids_detenu=ui->le_poids->text().toInt();
    QString periode_detenu=ui->la_periode->text();
    QString dossier_detenu=ui->le_dossier->text();


    Detenu D(id_detenu, nom_detenu, prenom_detenu,date_naissance_detenu,nationalite_detenu,sexe_detenu,taille_detenu,poids_detenu,periode_detenu,dossier_detenu);
    bool test=D.ajouter();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succés");
        ui->tab_detenu->setModel(D.afficher());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Detenu D1; D1.setid_detenu(ui->le_id_supp->text().toInt());
    bool test=D1.supprimer(D1.getid_detenu());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprimer avec succés");
     ui->tab_detenu->setModel(D.afficher());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();

}

void MainWindow::on_pb_modifier_clicked()
{
    int id_detenu=ui->le_id->text().toInt();
    QString nom_detenu=ui->le_nom->text();
    QString prenom_detenu=ui->le_prenom->text();
    QString date_naissance_detenu=ui->la_date->text();
    QString nationalite_detenu=ui->la_nationalite->text();
    QString sexe_detenu=ui->le_sexe->text();
    int taille_detenu=ui->la_taille->text().toInt();;
    int poids_detenu=ui->le_poids->text().toInt();;
    QString periode_detenu=ui->la_periode->text();
    QString dossier_detenu=ui->le_dossier->text();


    Detenu Det(id_detenu, nom_detenu, prenom_detenu,date_naissance_detenu,nationalite_detenu,sexe_detenu,taille_detenu,poids_detenu,periode_detenu,dossier_detenu);
     bool test=Det.modifier();
     QMessageBox msgBox;

     if(test)
        { msgBox.setText("Modification avec succés");
         ui->tab_detenu->setModel(Det.afficher());
     }
     else
         msgBox.setText("Echec de modification");
     msgBox.exec();
}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int id_cellule=ui->le_id_2->text().toInt();
    QString type_cellule=ui->le_type_cellule->text();
    int nb_lits=ui->le_nb_lits->text().toInt();
    int superficie_cellule=ui->la_superficie->text().toInt();
    int nb_detenus=ui->le_nb_detenus->text().toInt();
   Cellule C(id_cellule, type_cellule, nb_lits, superficie_cellule ,  nb_detenus );
    bool test=C.ajouter2();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succés");
        ui->tab_cellule->setModel(C.afficher2());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}




void MainWindow::on_pb_supprimer_2_clicked()
{
    Cellule C1; C1.setid_cellule(ui->le_id_supp_2->text().toInt());
    bool test=C1.supprimer2(C1.getid_cellule());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprimer avec succés");
     ui->tab_cellule->setModel(C1.afficher2());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}

