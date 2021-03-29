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
   // ui->tab_equipement->setModel(E.afficher());
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

void MainWindow::on_pb_modifier_clicked()
{

    int idEquipement=ui->le_id->text().toInt();
    int quantiteEquipement=ui->la_quantite->text().toInt();
    int etatEquipement=ui->le_etat->text().toInt();
    QString nomEquipement=ui->le_nom->text();
    QString typeEquipement=ui->le_type->text();
    QString dateFabrication=ui->la_date->text();


  Equipement E(idEquipement,quantiteEquipement,etatEquipement,nomEquipement,typeEquipement,dateFabrication);



      bool test=E.modifier(idEquipement,nomEquipement, typeEquipement ,quantiteEquipement,etatEquipement,dateFabrication );
         QMessageBox msgBox;

         if(test)
            { msgBox.setText("Modification avec succés");
             ui->tab_equipement->setModel(E.afficher());
         }
         else
             msgBox.setText("Echec de modification");
         msgBox.exec();

}

void MainWindow::on_pb_ajouterMaintenance_clicked()
{
    int idMaintenance=ui->id_maintenance->text().toInt();
        int frais=ui->frais_maintenance->text().toInt();

   QString dureeMaintenance=ui->duree_maintenance->text();
   QString dateEntreeM=ui->date_entree_maintenance->text();
   QString dateSortieM=ui->date_sortie_maintenance->text();

        Maintenance M(idMaintenance,dureeMaintenance,dateEntreeM,dateSortieM,frais);
        bool test=M.ajouterMaintenance();
        QMessageBox msgBox;

            if(test)
               { msgBox.setText("Ajout avec succés");
                ui->tab_maintenance->setModel(M.afficherMaintenance());
            }
            else
                msgBox.setText("Echec d'e suppression'ajout");
            msgBox.exec();
}

void MainWindow::on_tab_equipement_activated(const QModelIndex &index)
{
    QString val=ui->tab_equipement->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select* from equipement where idEquipement='"+val+"' ");
    if (query.exec())
    { while(query.next())
        {
            ui->le_id->setText(query.value(0).toString());
            ui->le_id_supp->setText(query.value(0).toString());
            ui->le_nom->setText(query.value(1).toString());
            ui->le_type->setText(query.value(2).toString());
            ui->la_quantite->setText(query.value(3).toString());
            ui->le_etat->setText(query.value(4).toString());
            ui->la_date->setText(query.value(5).toString());
          }

     }
}



void MainWindow::on_trier_clicked()
{
    QString type = ui->comboBox_equipement->currentText();
    if (type == "etatEquipement")
    {
        ui->tab_equipement->setModel(E.tri_etat());
    }else if (type == "quantiteEquipement")
    {
        ui->tab_equipement->setModel(E.tri_quantite());

}

}






void MainWindow::on_pushButton_rechercher_clicked()
{
    QString res=ui->rech_equipement->text();

           ui->tab_equipement->setModel(E.rechercherEquipement(res));

}
