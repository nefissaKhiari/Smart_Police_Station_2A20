#include "mainwindow.h"
#include "detenu.h"
#include "cellule.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QIntValidator>
#include <QMessageBox>
#include<QPrinter>
#include<QPrintDialog>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QtWidgets>

//#include <QUrDesktopServices>
#include "stats.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->le_id->setValidator( new QIntValidator(0, 999, this));
   ui->tab_detenu->setModel(D.afficher_detenu());

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
    bool test=D.ajouter_detenu();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succés");
        ui->tab_detenu->setModel(D.afficher_detenu());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Detenu D1; D1.setid_detenu(ui->le_id->text().toInt());
    bool test=D1.supprimer_detenu(D1.getid_detenu());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprimer avec succés");
     ui->tab_detenu->setModel(D.afficher_detenu());
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
     bool test=Det.modifier_detenu(Det.getid_detenu(),Det.getnom_detenu(),Det.getprenom_detenu(),Det.getdate_naissance_detenu(),Det.getnationalite_detenu(),Det.getsexe_detenu(),Det.gettaille_detenu(),Det.getpoids_detenu(),Det.getperiode_detenu(),Det.getdossier_detenu());
     QMessageBox msgBox;

     if(test)
        { msgBox.setText("Modification avec succés");
         ui->tab_detenu->setModel(Det.afficher_detenu());
     }
     else
         msgBox.setText("Echec de modification");
     msgBox.exec();
}

void MainWindow::on_tab_detenu_activated(const QModelIndex &index)
{
    QString val=ui->tab_detenu->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select* from detenu where id_detenu='"+val+"' ");
        if (query.exec())
        { while(query.next())
            {
                ui->le_id->setText(query.value(0).toString());
                ui->le_id->setText(query.value(0).toString());//suppression
                ui->le_nom->setText(query.value(1).toString());
                ui->le_prenom->setText(query.value(2).toString());
                ui->la_date->setText(query.value(3).toString());
                ui->la_nationalite->setText(query.value(4).toString());
                ui->le_sexe->setText(query.value(5).toString());
                ui->la_taille->setText(query.value(6).toString());
                ui->le_poids->setText(query.value(7).toString());
                ui->la_periode->setText(query.value(8).toString());
                ui->le_dossier->setText(query.value(9).toString());

              }
}
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
    Cellule C1; C1.setid_cellule(ui->le_id_2->text().toInt());
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




void MainWindow::on_tab_cellule_activated(const QModelIndex &index)
{
    QString val=ui->tab_cellule->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select* from cellule where id_cellule='"+val+"' ");
        if (query.exec())
        { while(query.next())
            {
                ui->le_id_2->setText(query.value(0).toString());
                ui->le_id_2->setText(query.value(0).toString());//suppression
                ui->le_type_cellule->setText(query.value(1).toString());
                ui->le_nb_lits->setText(query.value(2).toString());
                ui->la_superficie->setText(query.value(3).toString());
                ui->le_nb_detenus->setText(query.value(4).toString());

              }
}
}



void MainWindow::on_modifier_cellule_clicked()
{
    int id_cellule=ui->le_id_2->text().toInt();
    QString type_cellule=ui->le_nom->text();
    int nb_lits=ui->le_nb_lits->text().toInt();
    int superficie_cellule=ui->la_superficie->text().toInt();
    int nb_detenus=ui->le_nb_detenus->text().toInt();

    Cellule C(id_cellule, type_cellule, nb_lits, superficie_cellule ,  nb_detenus );
     bool test=C.modifier_cellule(C.getid_cellule(),C.gettype_cellule(),C.getnb_lits(),C.getsuperficie_cellule(),C.getnb_detenus());
     QMessageBox msgBox;

     if(test)
        { msgBox.setText("Modification avec succés");
         ui->tab_cellule->setModel(C.afficher2());
     }
     else
         msgBox.setText("Echec de modification");
     msgBox.exec();



}

/*void MainWindow::on_pushButton_6_clicked()
{
    ui->tab_cellule->setModel(tmpcellule.tri_cellule());
    ui->tab_cellule->setModel(tmpcellule.tri_cellule());//refresh
}*/

void MainWindow::on_pdf_detenu_clicked()
{

    //QDateTime datecreation = date.currentDateTime();
                       //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                              QPdfWriter pdf("C:/Users/ASUS/Desktop/pdf detenu.pdf");
                              QPainter painter(&pdf);
                             int i = 4000;
                                  painter.setPen(Qt::red);
                                  painter.setFont(QFont("Arial Black", 30));
                                  painter.drawText(1500,1200," Tableau de Detenu");
                                  painter.setPen(Qt::black);
                                  painter.setFont(QFont("Arial", 50));
                                 // painter.drawText(1100,2000,afficheDC);
                                 //painter.drawRect(100,100,100,100);
                                    painter.drawRect(200,100,7700,2100);
                                  //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                                  painter.drawRect(0,3000,9600,500);
                                  painter.setFont(QFont("Arial", 9));
                                  painter.drawText(200,3300,"Id");
                                  painter.drawText(1200,3300,"Nom");
                                  painter.drawText(2400,3300,"Prenom");
                                  painter.drawText(3400,3300,"Date naissance");
                                  painter.drawText(4600,3300,"Nationalite");
                                  painter.drawText(5600,3300,"Sexe");
                                  painter.drawText(6200,3300,"Taille");
                                  painter.drawText(7100,3300,"Poids");
                                  painter.drawText(8000,3300,"Periode");
                                  painter.drawText(9000,3300,"Dossier");

                                  QSqlQuery query;
                                  query.prepare("select * from detenu");
                                  query.exec();
                                  while (query.next())
                                  {
                                      painter.drawText(200,i,query.value(0).toString());
                                      painter.drawText(1200,i,query.value(1).toString());
                                      painter.drawText(2400,i,query.value(2).toString());
                                      painter.drawText(3400,i,query.value(3).toString());
                                      painter.drawText(4600,i,query.value(4).toString());
                                     painter.drawText(5600,i,query.value(5).toString());
                                      painter.drawText(6200,i,query.value(6).toString());
                                      painter.drawText(7100,i,query.value(7).toString());
                                      painter.drawText(8000,i,query.value(8).toString());
                                      painter.drawText(9000,i,query.value(8).toString());

                                    i = i + 500;
                                  }
                                  int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                      if (reponse == QMessageBox::Yes)
                                      {
                                          QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/pdf detenu.pdf"));
                                      }
                                      if (reponse == QMessageBox::No)
                                      {
                                           painter.end();
                                      }
}

void MainWindow::on_pb_trier_cellule_clicked()
{
    QString type = ui->comboBox_cellule->currentText();
        if (type == "nb_detenus")
        {
            ui->tab_cellule->setModel(tmpcellule.tri_nb_detenus());
        }else if (type == "id_cellule")
        {
            ui->tab_cellule->setModel(tmpcellule.tri_id_cellule());
}else if (type == "nb_lits")
        {
            ui->tab_cellule->setModel(tmpcellule.tri_nb_lits());
}
}
/*void MainWindow::on_pb_rechercher_cellule_clicked()
{
    QString type = ui->comboBox_recherche->currentText();
        QString valeur = ui->recher_cellule->currentText();
        bool test = false, test1 = false, test2 = false;
        if (type == "id_cellule")
            test = tmpcellule.recherche_id_cellule(valeur);
        else if (type == "type_cellule")
            test1 = tmpcellule.recherche_type_cellule(valeur);
        else if (type == "nb_detenus")
            test2 = tmpcellule.recherche_nb_detenus(valeur);

        if (test || test1 || test2)
        {
            int id_cellule = tmpcellule.getid_cellule();
            QString type_cellule = tmpcellule.gettype_cellule();
            int nb_lits = tmpcellule.getnb_detenus();
            int superficie_cellule = tmpcellule.getsuperficie_cellule();
            int nb_detenus = tmpcellule.getnb_detenus();

            ui->recher_cellule->setCurrentText(id_cellule);
            ui->comboBox_mail_4->setCurrentText(email);
            ui->comboBox_film_3->setCurrentText(film);
            ui->spinBox_quantite_4->setValue(quantite);
            ui->spinBox_remise_3->setValue(remise);
            ui->comboBox_salle_3->setCurrentText(salle);
            ui->sieges_3->setText(siege);
            ui->spinBox_prix_3->setValue(prix);
            ui->dateEdit_billet->setDate(QDate::fromString(date,"MM/dd/yyyy"));
            ui->timeEdit_billet->setTime(QTime::fromString(heure,"hh:mm"));
            ui->comboBox_tarif_3->setCurrentText(tarif);
        }
    }
*/

void MainWindow::on_pushButton_clicked()
{
    stats stat;
    stat.setModal(true);
    stat.exec();
}
