#include<QPrinter>
#include<QPrintDialog>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QtWidgets>
#include "mainwindow.h"
#include "vehicule.h"
#include "mission.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->le_id->setValidator( new QIntValidator(0, 9999999, this));
   ui->tab_vehicule->setModel(v.afficher_vehicule());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString marque=ui->le_nom->text();
    QString model=ui->le_prenom->text();
    vehicule v(id,marque,model);
    bool test=v.ajouter();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succés");
        ui->tab_vehicule->setModel(v.afficher_vehicule());
    }
    else
        msgBox.setText("Echec d'e suppression'ajout");
    msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    vehicule C1; C1.setid(ui->le_id_supp->text().toInt());
    bool test=C1.supprimer(C1.getid());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprimer avec succés");
     ui->tab_vehicule->setModel(v.afficher_vehicule());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();

}

void MainWindow::on_modifier_vehicule_clicked()
{
    int id=ui->le_id->text().toInt();
    QString marque=ui->le_nom->text();
    QString model=ui->le_prenom->text();
  ;


   vehicule v(id, marque, model);
     bool test=v.modifier_vehicule(v.getid(),v.getmarque(),v.getmodel());
     QMessageBox msgBox;

     if(test)
        { msgBox.setText("Modification avec succés");
         ui->tab_vehicule->setModel(v.afficher_vehicule());
     }
     else
         msgBox.setText("Echec de modification");
     msgBox.exec();
}

void MainWindow::on_tab_vehicule_activated(const QModelIndex &index)
{
    QString val=ui->tab_vehicule->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select* from vehicule where id='"+val+"' ");
        if (query.exec())
        { while(query.next())
            {
                ui->le_id->setText(query.value(0).toString());
                ui->le_nom->setText(query.value(0).toString());
                ui->le_prenom->setText(query.value(1).toString());



              }
}
}




void MainWindow::on_pb_ajouter_2_clicked()
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

void MainWindow::on_tab_mission_activated(const QModelIndex &index)
{
    QString val=ui->tab_mission->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select* from mission where id='"+val+"' ");
        if (query.exec())
        { while(query.next())
            {
                ui->le_id_2->setText(query.value(0).toString());
                ui->le_nom_2->setText(query.value(0).toString());
                ui->le_prenom_2->setText(query.value(1).toString());
                ui->le_nom_3->setText(query.value(2).toString());
                ui->le_id_supp_2->setText(query.value(3).toString());


              }
}
}

void MainWindow::on_modifier_mission_clicked()
{
    int id=ui->le_id_2->text().toInt();
    int nbr_vehicule=ui->le_nom_2->text().toInt();
    int nbr_policier=ui->le_prenom_2->text().toInt();
     QString date_mission=ui->le_nom_3->text();

   mission C (id, nbr_vehicule, nbr_policier, date_mission );
     bool test=C.modifier_mission(C.getid(),C.getnbr_vehicule(),C.getnbr_policier(),C.getdate_mission());
     QMessageBox msgBox;

     if(test)
        { msgBox.setText("Modification avec succés");
         ui->tab_mission->setModel(C.afficher_mission());
     }
     else
         msgBox.setText("Echec de modification");
     msgBox.exec();



}



void MainWindow::on_tri_mission_clicked()
{
    QString type = ui->comboBox_mission->currentText();
        if (type == "id")
        {
            ui->tab_mission->setModel(C.tri_id());
        }else if (type == "nbr de vehicule")
        {
            ui->tab_mission->setModel(C.tri_nbr_veh());

        }
}

void MainWindow::on_pushButton_clicked()
{


        QPdfWriter pdf("C:/Users/Utilisateur/Desktop/ahmed PDF/PdfAbonnes.pdf");
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(2300,1200,"Liste Des missions");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
       //painter.drawText(1100,2000,afficheDC);
        painter.drawRect(1500,200,7300,2600);
        //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(300,3300,"id");
        painter.drawText(2300,3300,"nbr vehicule");
        painter.drawText(2300,3300,"nbr policiers");
        painter.drawText(6300,3300,"Date");
        QSqlQuery query;
        query.prepare("select * from mission");
        query.exec();
        while (query.next())
        {
            painter.drawText(300,i,query.value(0).toString());
            painter.drawText(2300,i,query.value(1).toString());
            painter.drawText(4300,i,query.value(2).toString());
            painter.drawText(6300,i,query.value(3).toString());
            painter.drawText(8000,i,query.value(4).toString());
            i = i +500;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Utilisateur/Desktop/ahmed PDF/PdfAbonnes.pdf"));

            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();
        }
    }
