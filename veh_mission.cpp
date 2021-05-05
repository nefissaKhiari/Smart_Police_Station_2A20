#include "veh_mission.h"
#include "ui_veh_mission.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>


VEH_MISSION::VEH_MISSION(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VEH_MISSION)
{
    ui->setupUi(this);
}

VEH_MISSION::~VEH_MISSION()
{
    delete ui;
}

void VEH_MISSION::on_pb_ajouter_3_clicked()
  {

        int nbr_vehicule=ui->le_nom_4->text().toInt();


        VEH_MISSION m(nbr_vehicule);

        bool test=m.ajouter3();
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Ajout avec succés");
           // ui->tab_mission->setModel(C.afficher_mission());
        }
        else
            msgBox.setText("Echec d'e suppression'ajout");
        msgBox.exec();
    }


