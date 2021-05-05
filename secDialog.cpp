#include "secDialog.h"


secDIALOG::secDIALOG(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secDIALOG)
{
    ui->setupUi(this);
}

secDialog::~secDialog()
{
    delete ui;
}

/*void secDIALOG::on_pb_ajouter_2_clicked()
{

    int id=ui->le_id_2->text().toInt();
    int nbr_vehicule=ui->le_nom_2->text().toInt();
    int nbr_policier=ui->le_prenom_2->text().toInt();
  QString date_mission=ui->le_nom_3->text();
    mission C(id,nbr_vehicule,nbr_policier,date_mission);
    bool test=C.ajouter2();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succés");
        ui->tab_mission->setModel(C.afficher_mission());
    }
    else
        msgBox.setText("Echec d'e suppression'ajout");
    msgBox.exec();
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    mission C1; C1.setid(ui->le_id_supp_2->text().toInt());
    bool test=C1.supprimer(C1.getid());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprimer avec succés");
     ui->tab_mission->setModel(C.afficher_mission());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();


}*/



void secDIALOG::on_pb_ajouter_2_clicked()
{
    int id=ui->le_id_2->text().toInt();
    int nbr_vehicule=ui->le_nom_2->text().toInt();
    int nbr_policier=ui->le_prenom_2->text().toInt();
  QString date_mission=ui->le_nom_3->text();
    mission C(id,nbr_vehicule,nbr_policier,date_mission);
    bool test=C.ajouter2();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succés");
        ui->tab_mission->setModel(C.afficher_mission());
    }
    else
        msgBox.setText("Echec d'e suppression'ajout");
    msgBox.exec();
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    mission C1; C1.setid(ui->le_id_supp_2->text().toInt());
    bool test=C1.supprimer(C1.getid());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprimer avec succés");
     ui->tab_mission->setModel(C.afficher_mission());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();

}
