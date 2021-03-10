#include "mainwindow.h"
#include "equipement.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_equipement->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_ajouter_clicked()
{
    int idEquipement=ui->le_id->text().toInt();
    int quantiteEquipement=ui->la_quantite->text().toInt();
    int etatEquipement=ui->le_etat->text().toInt();
    QString nomEquipement=ui->le_nom->text();
    QString typeEquipement=ui->le_type->text();
    QString dateFabrication=ui->la_date->text();

    Equipement E(idEquipement,quantiteEquipement,etatEquipement,nomEquipement,typeEquipement,dateFabrication);
    bool test=E.ajouterEquipement();
    QMessageBox msgBox;

        if(test)
           { msgBox.setText("Ajout avec succés");
            ui->tab_equipement->setModel(E.afficher());
        }
        else
            msgBox.setText("Echec d'e suppression'ajout");
        msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Equipement E1;
       E1.setIdEquipement(ui->le_id_supp->text().toInt());
        bool test=E1.supprimer(E1.getIdEquipement());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Supprimer avec succés");
        ui->tab_equipement->setModel(E1.afficher());
        }
        else
            msgBox.setText("Echec de suppression");
        msgBox.exec();
}
