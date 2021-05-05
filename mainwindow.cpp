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
#include <QPropertyAnimation>
//#include "secDialog.h"
#include "mailing/mailing/SmtpMime"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent)
  ,
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    animation = new QPropertyAnimation (ui ->text,"geometry" );
      // animation = new QPropertyAnimation (ui ->text_2,"geometry" );
       animation->setDuration(10000) ;
       animation->setStartValue(ui->text->geometry());
       animation->setEndValue(QRect(10,10,0,0)) ;
       animation->start() ;

  click = new QMediaPlayer ();
  click-> setMedia(QUrl("C:/Users/Utilisateur/Desktop/click.wav"));




     /* // animation2 = new QPropertyAnimation (ui ->text,"geometry" );
       animation2 = new QPropertyAnimation (ui ->text_2,"geometry" );
       animation2->setDuration(10000) ;
       animation2->setStartValue(ui->text->geometry());
       animation2->setEndValue(QRect(10,40,741,101)) ;
       animation2->start() ;*/


   ui->le_id->setValidator( new QIntValidator(0, 9999999, this));
   ui->tab_vehicule->setModel(v.afficher_vehicule());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_ajouter_clicked()
{
     click->play() ;
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
    click->play() ;

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

    click->play() ;
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
    click->play() ;
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

   /* if(test)  //mailing
       {
          SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

      smtp.setUser("ahmed.ayedi@esprit.tn");

 smtp.setPassword("191JFT4295");

    MimeMessage message;

    message.setSender(new EmailAddress("ahmed.ayedi@esprit.tn", "ahmed"));
  message.addRecipient(new EmailAddress("ahmedayedi41@ gmail.com", "ahmed ayedi "));
 message.setSubject("SmtpClient for Qt - Demo");
      MimeText text;
   text.setText("Hi,\n une personne est ajouter\n");


                  message.addPart(&text);





                  smtp.connectToHost();

                  smtp.login();

                  if(smtp.sendMail(message))
                  {
                      QMessageBox::information(nullptr, QObject::tr("mailing"),
                                      QObject::tr("mailing.\n"
                                                  "Click Ok to exit."), QMessageBox::Accepted);
                  }
















}*/}

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

void MainWindow::on_pb_rechercher_mission_clicked()
{
    QString res=ui->recher_mission->text();

        ui->tab_mission->setModel(C.rechercher_mission(res));
}


void MainWindow::on_pushButton_4_clicked()
{
    MainWindow conn;
            QSqlQueryModel * modal = new QSqlQueryModel();
            QSqlQuery * qry = new QSqlQuery(conn.mydb);


            qry-> prepare("select id,nbr_vehicule,nbr_policier,date_mission from mission");
            qry->exec();
            modal->setQuery(*qry);
            ui->tab_mission->setModel(modal);


}

/*void MainWindow::on_pushButton_2_clicked()
{
    secDialog secDialog;
    secDialog.setModal(true);
    secDialog.exec();
}*/

void MainWindow::on_pushButton_6_clicked()
{


        lng="ang";
            // page biblo
            ui->l1->setText("ID mission");
           // ui->l1->setStyleSheet("QLabel{color: rgb(255, 255, 255); font: 75 24pt MS Shell Dlg 2;text-decoration:underline;font-weight:600; color:#ffffff;}");
            ui->l2->setText("nbr cars");
            ui->l3->setText("nbr cops");
            ui->l4->setText("date mission");
            ui->l4_2->setText("username");
            ui->pb_ajouter_2->setText("ADD");
            ui->pb_rechercher_mission->setText("FIND");
            //ui->Liv_ajouter->setText("ADD");
            ui->modifier_mission->setText("EDIT");
            ui->pb_supprimer_2->setText("REMOVE");
           // ui->pushButton_rch_livre->setText("RESEARCH");
            //ui->pushButton_tri_livre->setText("SORTING");
           // ui->oui_liv->setText("YES");
           // ui->non_liv_2->setText("NO");




            //----------------------------------//


    }


void MainWindow::on_pushButton_5_clicked()

{
     lng="fr";

     // page biblo
     ui->l1->setText("Identifiant Mission ");
    // ui->l1->setStyleSheet("QLabel{color: rgb(255, 255, 255); font: 75 24pt MS Shell Dlg 2;text-decoration:underline;font-weight:600; color:#ffffff;}");
     ui->l2->setText("Nombres vehicules");
     ui->l3->setText("Nombres policiers ");
     ui->l4->setText("date de mission");
     ui->l4_2->setText("Identifiant");
     ui->pb_ajouter_2->setText("Ajouter");
     ui->pb_rechercher_mission->setText("Recherche");
     //ui->Liv_ajouter->setText("ADD");
     ui->modifier_mission->setText("Modifier");
     ui->pb_supprimer_2->setText("Supprimer");
    // ui->pushButton_rch_livre->setText("RESEARCH");
     //ui->pushButton_tri_livre->setText("SORTING");
    // ui->oui_liv->setText("YES");
    // ui->non_liv_2->setText("NO");

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
{ui->stackedWidget->setCurrentIndex(6) ;
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





void MainWindow::on_pushButton_3_clicked()
{

     dialog = new Dialog(this) ;
     dialog->show();
}
