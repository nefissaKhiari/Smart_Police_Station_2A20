#include "integ_finale.h"
#include "ui_integ_finale.h"
#include "equipement.h"
#include "detenu.h"
#include "agent.h"
#include "service.h"
#include "mission.h"
#include "vehicule.h"
#include "exportexcelobject.h"
#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>
#include <QPrinter>
#include<QPrintDialog>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QtWidgets>
#include<QDate>
#include <QtCharts>
#include <QChartView>
//#include "QImage"
#include "mailing/mailing/SmtpMime"
#include <QDateTime>
#include <QTime>

#include<QBarSet>
#include<QBarSeries>
#include <QtWidgets>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QQuickItem>

#include "QrCode.hpp"
#include "citoyen.h"

#include "notepad.h"
#include "personne.h"
#include "plaintes.h"
using namespace qrcodegen;
integ_finale::integ_finale(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::integ_finale)
{
    ui->setupUi(this);


     ui->tab_citoyen->setModel(tmp_citoyen.afficher_citoyen());

     ui->tab_petition->setModel(tmp_petition.afficher_petition());

        ui->tab_citoyen->sortByColumn(1,Qt::DescendingOrder);


     timerr=new QTimer(this) ;
     connect(timerr , SIGNAL(timeout()),this,SLOT(myfunctionn())) ;
     timerr->start(1000) ;
    ui->le_id2->setValidator( new QIntValidator(0, 99, this));
      ui->le_id_cel->setValidator( new QIntValidator(0, 99, this));
      ui->le_id->setValidator( new QIntValidator(0,999,this));
      ui->id_serv->setValidator( new QIntValidator(0,999,this));
      ui->cin_agent->setValidator( new QIntValidator(0,999,this));
       ui->id_maintenance->setValidator( new QIntValidator(0,999,this));
       ui->le_id_2->setValidator( new QIntValidator(0, 9999999, this));//ahmed
            ui->le_id_3->setValidator( new QIntValidator(0, 9999999, this));//ahmed
    ui->tab_equipement->setModel(E.afficher());
    ui->tab_maintenance->setModel(M.afficherMaintenance());
    ui->tab_detenu_2->setModel(D.afficher_detenu());
    ui->tab_cellule->setModel(C.afficher_cellule());
    ui->tab_agent->setModel(tmp_agent.afficher_agent());
    ui->tab_vehicule->setModel(v.afficher_vehicule());//ahmed
     ui->tab_mission->setModel(m.afficher_mission());//ahmed
     ui->tab_personne->setModel(P.afficher());
     ui->tab_plainte->setModel(T.afficher(aff));
       click = new QMediaPlayer ();//ahmed
         click-> setMedia(QUrl("D:/projetC++/integration_base/Smart_Police_Station_2A20-master/click.wav"));//ahmed
    //ui->tab_service->setModel(tmp_service.afficher_service());
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
         ui->quickWidget->show();
         auto obj =ui->quickWidget->rootObject();
         connect(this,SIGNAL(setCenter(QVaritant,QVariant)),obj,SLOT(setCenter(QVaritant,QVariant)));
    emit setCenter(25.000,50.000);
 //**********Partie_Arduino_Nour_Ahlem*************//
         int ret=A.connect_arduino(); // lancer la connexion à arduino
             switch(ret){
             case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                 break;
             case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
                break;
             case(-1):qDebug() << "arduino is not available";
             }
              QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
              //le slot update_label suite à la reception du signal readyRead (reception des données).


//***********Camera ****************//
    mCamera= new QCamera (this);
        mCameraViewfinder = new QCameraViewfinder(this);
        mCameraImageCapture = new QCameraImageCapture(mCamera, this);
        mLayout = new QVBoxLayout;
    mOpcionesMenu = new QMenu ("Opciones",this);
    mEncenderAction = new QAction ("Ouvrir Caméra",this);
    mApagarAction = new QAction ("Figer",this);
    mCapturarAction = new QAction ("Prendre une photo",this);

    mOpcionesMenu->addActions({mEncenderAction,mApagarAction,mCapturarAction});
    ui->options_2->setMenu (mOpcionesMenu);
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea_2->setLayout(mLayout);

    connect (mEncenderAction,&QAction::triggered, [&] () {    mCamera->start();    });
    connect (mApagarAction,&QAction::triggered, [&] () {
    mCamera->stop();
    });
    connect (mCapturarAction,&QAction::triggered, [&] () {
    auto filename = QFileDialog::getSaveFileName(this, "Capture","/","Imagen(.jpg;.jpeg)");
    if (filename.isEmpty() )
    {
       return;
    }
    mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    QImageEncoderSettings imageEncoderSettings;
    imageEncoderSettings.setCodec("image/jpeg");
    imageEncoderSettings.setResolution(1600,1200);
    mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
    mCamera->setCaptureMode(QCamera::CaptureStillImage);
    mCamera->start();
    mCamera->searchAndLock();
    mCameraImageCapture->capture(filename);
    mCamera->unlock();
    });




//***********Animation logo ****************//
    animation = new QPropertyAnimation (ui ->label,"geometry" );
                      // animation = new QPropertyAnimation (ui ->text_2,"geometry" );
                       animation->setDuration(3000) ;
                       animation->setStartValue(ui->label->geometry());
                       animation->setEndValue(QRect(25,1,250,140)) ;
                       animation->start() ;
     /***************TIME**************************/
                                            QTimer *timer=new QTimer(this);
                                          connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));
                                          timer->start();
                                          /*************************date*****************/
                                          QDate date = QDate ::currentDate();
                                          QString datee=date.toString();

                                          ui->Date_2->setText(datee) ;
  //***********Statistique 1 ****************//
 QSqlQuery query;
          int count=0 ;
          QSqlQuery requete("select * from equipement where etatequipement=0") ;
          while(requete.next())
          {
                  count++ ;
          }
   QSqlQuery query1;
            int count1=0 ;
            QSqlQuery requete1("select * from equipement where etatequipement=1") ;
            while(requete1.next())
            {
                    count1++ ;
            }

            QBarSet *set0= new QBarSet(" Nombre des équipements endommagés");
            QBarSet *set1= new QBarSet("Nombre des équipements en bon etat");

            *set0 <<count;
            *set1<<count1;

            QBarSeries *series= new QBarSeries();
              series->append(set0);
              series->append(set1);

           QChart * chart =new QChart();
              chart-> addSeries(series);
              chart->setTitle("Statistiques des Equipement par Etat ");
              chart->setAnimationOptions(QChart::SeriesAnimations);
            QStringList categories;
            categories <<"Jan"<<"Feb"<<"Mar"<<"Apr"<<"May"<<"Jul";
            QBarCategoryAxis *axis= new QBarCategoryAxis();
            axis->append(categories);
            chart->createDefaultAxes();
            chart->setAxisX(axis,series);

              QChartView *chartview= new QChartView (chart);
            chartview->setParent(ui->frame_charts);

  //***********Statistique 2 ****************//

           QSqlQuery queryD;
           int countD=0 ;
           QSqlQuery requeteD("select * from detenu where sexe_detenu='femme'") ;
           while(requeteD.next())
           {
                  countD++ ;
           }


           QSqlQuery query1D;
            int count1D=0 ;
            QSqlQuery requete1D("select * from detenu where sexe_detenu='homme'") ;
            while(requete1D.next())
            {
                    count1D++ ;
            }
            QBarSet *set0D= new QBarSet(" Nombre des femmes");
            QBarSet *set1D= new QBarSet("Nombre des hommes");


                        *set0D <<countD ;
                        *set1D<<count1D;

                        QBarSeries *seriesD= new QBarSeries();
                          seriesD->append(set0D);
                            seriesD->append(set1D);


                       QChart * chartD =new QChart();
                          chartD-> addSeries(seriesD);
                          chartD->setTitle("Statistiques des detenus par rapport au sexe ");
                          chartD->setAnimationOptions(QChart::SeriesAnimations);
                        QStringList categoriesD;
                        categoriesD <<"Jan"<<"Feb"<<"Mar"<<"Apr"<<"May"<<"Jul";
                        QBarCategoryAxis *axisD= new QBarCategoryAxis();
                        axisD->append(categoriesD);
                        chartD->createDefaultAxes();
                        chartD->setAxisX(axisD,seriesD);




                        QChartView *chartviewD= new QChartView (chartD);
                         chartviewD->setParent(ui->frame_charts_2);


/*****************Statiqtique3*****************/
 QSqlQuery query2;
          int compter=0 ;
          QSqlQuery requete4("select * from personne where sexe='homme'") ;
          while(requete4.next())
          {
                  compter++ ;
          }
   QSqlQuery query3;
            int compter1=0 ;
            QSqlQuery requete5("select * from personne where sexe='femme'") ;
            while(requete5.next())
            {
                    compter1++ ;
            }

            QBarSet *set0P= new QBarSet("Nombre des femmes");
            QBarSet *set1P= new QBarSet("Nombre des hommes");

            *set0P <<compter;
            *set1P<<compter1;

            QBarSeries *seriesP= new QBarSeries();
              seriesP->append(set0P);
              seriesP->append(set1P);

           QChart * chartP =new QChart();
              chartP-> addSeries(seriesP);
              chartP->setTitle("Statistiques sexe homme femme ");
              chartP->setAnimationOptions(QChart::SeriesAnimations);
            QStringList categoriesP;
            categoriesP <<"homme"<<"femme";
            QBarCategoryAxis *axisP= new QBarCategoryAxis();
            axisP->append(categoriesP);
            chartP->createDefaultAxes();
            chartP->setAxisX(axisP,seriesP);

              QChartView *chartviewP= new QChartView (chartP);
            chartviewP->setParent(ui->frame_charts_personne);

}
integ_finale::~integ_finale()
{
    delete ui;
}
bool integ_finale::verifnom()
{
    if (ui->nom_citoyen->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->nom_citoyen->text().isEmpty())
    {
        ui->nom_citoyen->clear();

        ui->verif_nom_citoyen->setPixmap(PixFalseIcon);
        ui->nom_citoyen->setPlaceholderText("contient que des caracteres") ;
        return false;
    }else
    {
        ui->verif_nom_citoyen->setPixmap(PixTrueIcon);
        return true;
    }
}
bool integ_finale::verifcin()
{
    if ( ui->cin_citoyen->text().isEmpty())
    {
        ui->cin_citoyen->clear();

        ui->verif_cin_citoyen->setPixmap(PixFalseIcon);
        ui->cin_citoyen->setPlaceholderText("Le ID est vide") ;

        return false;
    }else
    {
        ui->verif_cin_citoyen->setPixmap(PixTrueIcon);
        return true;
    }
}
bool integ_finale::verifprenom()
{
    if (ui->prenom_citoyen->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->prenom_citoyen->text().isEmpty())
    {
        ui->prenom_citoyen->clear();

        ui->verif_cin_citoyen->setPixmap(PixFalseIcon);
        ui->prenom_citoyen->setPlaceholderText("contient que des caracteres") ;

        return false;
    }else
    {
        ui->verif_cin_citoyen->setPixmap(PixTrueIcon);
        return true;
    }
}
bool integ_finale::veriftel()
{
    if (ui->tel_citoyen->text().contains(QRegExp("[^0-9]") ) || ui->tel_citoyen->text().isEmpty())
    {
        ui->tel_citoyen->clear();

        ui->verif_tel->setPixmap(PixFalseIcon);
        ui->tel_citoyen->setPlaceholderText("contient que des chiffres") ;

        return false;
    }else
    {
        ui->verif_tel->setPixmap(PixTrueIcon);
        return true;
    }
}

bool integ_finale::verifnationalite()
{
    if (ui->nationalite_citoyen->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->nationalite_citoyen->text().isEmpty())
    {
        ui->nationalite_citoyen->clear();

        ui->verif_nationnalite_citoyen->setPixmap(PixFalseIcon);
        ui->nationalite_citoyen->setPlaceholderText("contient que des caracteres") ;

        return false;
    }else
    {
        ui->verif_nationnalite_citoyen->setPixmap(PixTrueIcon);
        return true;
    }
}

bool integ_finale::verifsexe()
{
    if (ui->comboBox_citoyen->currentIndex()>-1)
    {
        ui->verif_sexe->setPixmap(PixTrueIcon);
        return true;
    }else
    {
        ui->verif_sexe->setPixmap(PixFalseIcon);
        return false;
    }
}

bool integ_finale::verifemail()
{
    if ( ui->email_citoyen->text().isEmpty())
    {
        ui->email_citoyen->clear();
        ui->verif_email->setPixmap(PixFalseIcon);
        ui->email_citoyen->setPlaceholderText("Le email est vide") ;
        return false;
    }else
    {
        ui->verif_email->setPixmap(PixTrueIcon);
        return true;
    }
}

bool integ_finale::verifadresse()
{
    if ( ui->adresse_citoyen->text().isEmpty())
    {
        ui->adresse_citoyen->clear();
        ui->verif_adresse->setPixmap(PixFalseIcon);
        ui->adresse_citoyen->setPlaceholderText("L adresse est vide") ;
        return false;
    }else
    {
        ui->verif_adresse->setPixmap(PixTrueIcon);
        return true;
    }
}
bool integ_finale::verifdesc()
{
    if ( ui->description_pet->toPlainText().isEmpty())
    {
        ui->description_pet->clear();
        ui->label_description->setPixmap(PixFalseIcon);
        ui->description_pet->setPlaceholderText("L adresse est vide") ;
        return false;
    }else
    {
        ui->label_description->setPixmap(PixTrueIcon);
        return true;
    }
}

bool integ_finale::veriftitre()
{
    if (ui->titre_pet->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->titre_pet->text().isEmpty())
    {
        ui->titre_pet->clear();

        ui->label_titre->setPixmap(PixFalseIcon);
        ui->titre_pet->setPlaceholderText("contient que des caracteres") ;
        return false;
    }else
    {
        ui->label_titre->setPixmap(PixTrueIcon);
        return true;
    }
}

bool integ_finale::verifid()
{
    if ( ui->id_pet->text().isEmpty())
    {
        ui->id_pet->clear();

        ui->label_id_pet->setPixmap(PixFalseIcon);
        ui->id_pet->setPlaceholderText("Le ID est vide") ;

        return false;
    }else
    {
        ui->label_id_pet->setPixmap(PixTrueIcon);
        return true;
    }
}

bool integ_finale::verifnbr()
{
    if (ui->nbr_pet->text().contains(QRegExp("[^0-9]") ) || ui->nbr_pet->text().isEmpty())
    {
        ui->nbr_pet->clear();

        ui->label_nbr->setPixmap(PixFalseIcon);
        ui->nbr_pet->setPlaceholderText("contient que des chiffres") ;

        return false;
    }else
    {
        ui->label_nbr->setPixmap(PixTrueIcon);
        return true;
    }
}
bool integ_finale::verifauteur()
{
    if (ui->auteur_pet->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->auteur_pet->text().isEmpty())
    {
        ui->auteur_pet->clear();

        ui->label_auteur->setPixmap(PixFalseIcon);
        ui->auteur_pet->setPlaceholderText("contient que des caracteres") ;

        return false;
    }else
    {
        ui->label_auteur->setPixmap(PixTrueIcon);
        return true;
    }
}

bool integ_finale::verifvalidite()
{
    if (ui->validite_pet->currentIndex()>-1)
    {
        ui->label_validite->setPixmap(PixTrueIcon);
        return true;
    }else
    {
        ui->label_validite->setPixmap(PixFalseIcon);
        return false;
    }
}



void integ_finale::on_Petition_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
        ui->Petition->setGeometry(0,142,151,61);
        ui->Materiel->setGeometry(-40,180,201,81);
        ui->Agent->setGeometry(-14,246,151,51);
        ui->Crimes->setGeometry(0,299,121,51);
       ui->Plaintes->setGeometry(0,350,121,51);
        ui->Mission->setGeometry(9,400,111,41);
}

void integ_finale::on_Materiel_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
       ui->Petition->setGeometry(-17,142,151,61);
       ui->Materiel->setGeometry(-23,180,201,81);
       ui->Agent->setGeometry(-14,246,151,51);
       ui->Crimes->setGeometry(0,299,121,51);
       ui->Plaintes->setGeometry(0,350,121,51);
       ui->Mission->setGeometry(9,400,111,41);
}

void integ_finale::on_Agent_clicked()
{
    ui->stackedWidget->setCurrentIndex(3) ;
       ui->Petition->setGeometry(-17,142,151,61);
       ui->Materiel->setGeometry(-40,180,201,81);
       ui->Agent->setGeometry(0,246,151,51);
       ui->Crimes->setGeometry(0,299,121,51);
      ui->Plaintes->setGeometry(0,350,121,51);
       ui->Mission->setGeometry(9,400,111,41);
}

void integ_finale::on_Crimes_clicked()
{
    ui->stackedWidget->setCurrentIndex(4) ;
      ui->Petition->setGeometry(-17,142,151,61);
      ui->Materiel->setGeometry(-40,180,201,81);
      ui->Agent->setGeometry(-14,246,151,51);
      ui->Crimes->setGeometry(17,299,121,51);
      ui->Plaintes->setGeometry(0,350,121,51);
      ui->Mission->setGeometry(9,400,111,41);
}

void integ_finale::on_Plaintes_clicked()
{
    ui->stackedWidget->setCurrentIndex(5) ;
        ui->Petition->setGeometry(-17,142,151,61);
        ui->Materiel->setGeometry(-40,180,201,81);
        ui->Agent->setGeometry(-14,246,151,51);
        ui->Crimes->setGeometry(0,299,121,51);
        ui->Plaintes->setGeometry(17,350,121,51);
        ui->Mission->setGeometry(9,400,111,41);
}

void integ_finale::on_Mission_clicked()
{
    ui->stackedWidget->setCurrentIndex(6) ;
      ui->Petition->setGeometry(-17,142,151,61);
      ui->Materiel->setGeometry(-40,180,201,81);
      ui->Agent->setGeometry(-14,246,151,51);
      ui->Crimes->setGeometry(0,299,121,51);
      ui->Plaintes->setGeometry(0,350,121,51);
      ui->Mission->setGeometry(26,400,111,41);
}


void integ_finale::on_pb_ajouter_clicked()
{
    int idEquipement=ui->le_id->text().toInt();
        int quantiteEquipement=ui->la_quantite->text().toInt();
         int etatEquipement = ui->le_etat->text().toInt();

        QString nomEquipement=ui->le_nom->text();
        QString typeEquipement=ui->le_type->text();
         QString fk_agentEq=ui->lineEdit_agent_equipement->text();
        QDate dateFabrication=ui->la_date->date();
        QString DateFab= dateFabrication.toString("dd/MM/yyyy");

        Equipement E(idEquipement,quantiteEquipement,etatEquipement,nomEquipement,typeEquipement,DateFab,fk_agentEq);
        bool test=E.ajouterEquipement();
        QMessageBox msgBox;

           if(test)
               { msgBox.setText("Ajout avec succés");
                ui->tab_equipement->setModel(E.afficher());
            }
            else
                msgBox.setText("Echec d'ajout");
            msgBox.exec();
}



void integ_finale::on_quit_clicked()
{
     QApplication::quit();
}


void integ_finale::on_pb_modifier_detenu_clicked()
{
    int id_detenu=ui->le_id2->text().toInt();
        QString nom_detenu=ui->le_nom2->text();
        QString prenom_detenu=ui->le_prenom_2->text();
        QString date_naissance_detenu=ui->la_date2->text();
        QString nationalite_detenu=ui->la_nationalite_2->text();
        QString sexe_detenu=ui->le_sexe_2->text();
        int taille_detenu=ui->la_taille_2->text().toInt();;
        int poids_detenu=ui->le_poids_2->text().toInt();;
        QString periode_detenu=ui->la_periode_2->text();
        QString dossier_detenu=ui->le_dossier_2->text();
       // int id_cellule=ui->le_id_cellule->text().toInt();

        Detenu Det(id_detenu, nom_detenu, prenom_detenu,date_naissance_detenu,nationalite_detenu,sexe_detenu,taille_detenu,poids_detenu,periode_detenu,dossier_detenu/*id_cellule*/);
         bool test=Det.modifier_detenu(Det.getid_detenu(),Det.getnom_detenu(),Det.getprenom_detenu(),Det.getdate_naissance_detenu(),Det.getnationalite_detenu(),Det.getsexe_detenu(),Det.gettaille_detenu(),Det.getpoids_detenu(),Det.getperiode_detenu(),Det.getdossier_detenu()/*,Det.getid_cellule()*/);
         QMessageBox msgBox;

         if(test)
            { msgBox.setText("Modification avec succés");
             ui->tab_detenu_2->setModel(Det.afficher_detenu());
         }
         else
             msgBox.setText("Echec de modification");
         msgBox.exec();
}

void integ_finale::on_tab_detenu_2_activated(const QModelIndex &index)
{
    QString val=ui->tab_detenu_2->model()->data(index).toString();
           QSqlQuery query;
           query.prepare("select* from detenu where id_detenu='"+val+"' ");
           if (query.exec())
           { while(query.next())
               {
                   ui->le_id2->setText(query.value(0).toString());
                   ui->le_id2->setText(query.value(0).toString());//suppression
                   ui->le_nom2->setText(query.value(1).toString());
                   ui->le_prenom_2->setText(query.value(2).toString());
                   ui->la_date2->setText(query.value(3).toString());
                   ui->la_nationalite_2->setText(query.value(4).toString());
                   ui->le_sexe_2->setText(query.value(5).toString());
                   ui->la_taille_2->setText(query.value(6).toString());
                   ui->le_poids_2->setText(query.value(7).toString());
                   ui->la_periode_2->setText(query.value(8).toString());
                   ui->le_dossier_2->setText(query.value(9).toString());
                }
           }
}


void integ_finale::on_modifier_cellule_clicked()
{
    int id_cellule=ui->le_id_cel->text().toInt();
        QString type_cellule=ui->le_type_cellule->text();
        int nb_lits=ui->le_nb_lits->text().toInt();
        int superficie_cellule=ui->la_superficie->text().toInt();
        int nb_detenus=ui->le_nb_detenus->text().toInt();

        Cellule C(id_cellule, type_cellule, nb_lits, superficie_cellule ,  nb_detenus );
         bool test=C.modifier_cellule(C.getid_cellule(),C.gettype_cellule(),C.getnb_lits(),C.getsuperficie_cellule(),C.getnb_detenus());
         QMessageBox msgBox;

         if(test)
            { msgBox.setText("Modification avec succés");
             ui->tab_cellule->setModel(C.afficher_cellule());
         }
         else
             msgBox.setText("Echec de modification");
         msgBox.exec();
}

void integ_finale::on_tab_cellule_activated(const QModelIndex &index)
{
    QString val=ui->tab_cellule->model()->data(index).toString();
            QSqlQuery query;
            query.prepare("select* from cellule where id_cellule='"+val+"' ");
            if (query.exec())
            { while(query.next())
                {
                    ui->le_id_cel->setText(query.value(0).toString());
                    ui->le_id_cel->setText(query.value(0).toString());//suppression
                    ui->le_type_cellule->setText(query.value(1).toString());
                    ui->le_nb_lits->setText(query.value(2).toString());
                    ui->la_superficie->setText(query.value(3).toString());
                    ui->le_nb_detenus->setText(query.value(4).toString());

                  }
    }
}

void integ_finale::on_pb_supprimer_detenu_clicked()
{
    Detenu D1; D1.setid_detenu(ui->le_id2->text().toInt());
        bool test=D1.supprimer_detenu(D1.getid_detenu());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Supprimer avec succés");
         ui->tab_detenu_2->setModel(D.afficher_detenu());
        }
        else
            msgBox.setText("Echec de suppression");
        msgBox.exec();

}

void integ_finale::on_pb_supprimer_cellule_clicked()
{
    Cellule C1; C1.setid_cellule(ui->le_id_cel->text().toInt());
        bool test=C1.supprimer_cellule(C1.getid_cellule());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Supprimer avec succés");
         ui->tab_cellule->setModel(C1.afficher_cellule());
        }
        else
            msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void integ_finale::on_pb_ajouter_detenu_clicked()
{
    int id_detenu=ui->le_id2->text().toInt();
        QString nom_detenu=ui->le_nom2->text();
        QString prenom_detenu=ui->le_prenom_2->text();
        QString date_naissance_detenu=ui->la_date2->text();
        QString nationalite_detenu=ui->la_nationalite_2->text();
        QString sexe_detenu=ui->le_sexe_2->text();
        int taille_detenu=ui->la_taille_2->text().toInt();
        int poids_detenu=ui->le_poids_2->text().toInt();
        QString periode_detenu=ui->la_periode_2->text();
        QString dossier_detenu=ui->le_dossier_2->text();
       // QString id_cellule=ui->comboBox->currentText();
        //int id_cellule=ui->le_id_cellule->text().toInt();

        Detenu D(id_detenu, nom_detenu, prenom_detenu,date_naissance_detenu,nationalite_detenu,sexe_detenu,taille_detenu,poids_detenu,periode_detenu,dossier_detenu);
        bool test=D.ajouter_detenu();
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Ajout avec succés");
            ui->tab_detenu_2->setModel(D.afficher_detenu());
        }
        else
            msgBox.setText("Echec d'ajout");
        msgBox.exec();
}

void integ_finale::on_pb_ajouter_cellule_clicked()
{
    int id_cellule=ui->le_id_cel->text().toInt();
        QString type_cellule=ui->le_type_cellule->text();
        int nb_lits=ui->le_nb_lits->text().toInt();
        int superficie_cellule=ui->la_superficie->text().toInt();
        int nb_detenus=ui->le_nb_detenus->text().toInt();
       Cellule C(id_cellule, type_cellule, nb_lits, superficie_cellule ,  nb_detenus );
        bool test=C.ajouter_cellule();
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Ajout avec succés");
            ui->tab_cellule->setModel(C.afficher_cellule());
        }
        else
            msgBox.setText("Echec d'ajout");
        msgBox.exec();
}

void integ_finale::on_pb_trier_cellule_clicked()
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

void integ_finale::on_pb_rechercher_cellule_clicked()
{
    QString res=ui->recher_cellule->text();

            ui->tab_cellule->setModel(tmpcellule.rechercher_cellule(res));
}

void integ_finale::on_pb_modifier_clicked()
{
    int idEquipement=ui->le_id->text().toInt();
       int quantiteEquipement=ui->la_quantite->text().toInt();
       int etatEquipement=ui->le_etat->text().toInt();
       QString nomEquipement=ui->le_nom->text();
       QString typeEquipement=ui->le_type->text();
       QString dateFabrication=ui->la_date->text();
       QString fk_agentEq=ui->lineEdit_agent_equipement->text();


     Equipement E(idEquipement,quantiteEquipement,etatEquipement,nomEquipement,typeEquipement,dateFabrication,fk_agentEq);



         bool test=E.modifier(idEquipement,nomEquipement, typeEquipement ,quantiteEquipement,etatEquipement,dateFabrication,fk_agentEq);
            QMessageBox msgBox;

            if(test)
               { msgBox.setText("Modification avec succés");
                ui->tab_equipement->setModel(E.afficher());
            }
            else
                msgBox.setText("Echec de modification");
            msgBox.exec();
}

void integ_finale::on_pb_supprimer_clicked()
{

    Equipement E1;
       E1.setIdEquipement(ui->le_id->text().toInt());
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

void integ_finale::on_pb_ajouterMaintenance_clicked()
{
    int idMaintenance=ui->id_maintenance->text().toInt();
    int frais=ui->frais_maintenance->text().toInt();
    int fk_equipement=ui->fk_equipement_equipement->text().toInt();

    QString dureeMaintenance=ui->duree_maintenance->text();
    QString dateEntreeM=ui->date_entree_maintenance->text();
    QString dateSortieM=ui->date_sortie_maintenance->text();


  Maintenance M(idMaintenance,dureeMaintenance,dateEntreeM,dateSortieM,frais,fk_equipement);


            bool test=M.ajouterMaintenance();
            QMessageBox msgBox;

                if(test)
                   { msgBox.setText("Ajout avec succés");
                    ui->tab_maintenance->setModel(M.afficherMaintenance());
                }
                else
                    msgBox.setText("Echec d'ajout");
                msgBox.exec();
}

void integ_finale::on_pushButton_modifier_maintenance_clicked()
{
       int idMaintenance=ui->id_maintenance->text().toInt();
       int frais=ui->frais_maintenance->text().toInt();
       int fk_equipement=ui->fk_equipement_equipement->text().toInt();

       QString dureeMaintenance=ui->duree_maintenance->text();
       QString dateEntreeM=ui->date_entree_maintenance->text();
       QString dateSortieM=ui->date_sortie_maintenance->text();


     Maintenance M(idMaintenance,dureeMaintenance,dateEntreeM,dateSortieM,frais,fk_equipement);



         bool test=M.modifierMaintenance(idMaintenance,dureeMaintenance,dateEntreeM,dateSortieM,frais,fk_equipement);
            QMessageBox msgBox;

            if(test)
               { msgBox.setText("Modification avec succés");
                ui->tab_maintenance->setModel(M.afficherMaintenance());
            }
            else
                msgBox.setText("Echec de modification");
            msgBox.exec();
}

void integ_finale::on_pushButton_supprimer_maintenance_clicked()
{
    Maintenance M;
         M.setIdMaintenance(ui->id_sup->text().toInt());
          bool test=M.supprimerMaintenance(M.getIdMaintenance());
          QMessageBox msgBox;

          if(test)
             { msgBox.setText("Supprimer avec succés");
          ui->tab_maintenance->setModel(M.afficherMaintenance());
          }
          else
              msgBox.setText("Echec de suppression");
          msgBox.exec();

}

void integ_finale::on_tab_equipement_activated(const QModelIndex &index)
{
    QString val=ui->tab_equipement->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select* from equipement where idEquipement='"+val+"' ");
        if (query.exec())
        { while(query.next())
            {
                ui->le_id->setText(query.value(0).toString());
               // ui->le_id_supp->setText(query.value(0).toString());
                ui->le_nom->setText(query.value(1).toString());
                ui->le_type->setText(query.value(2).toString());
                ui->la_quantite->setText(query.value(3).toString());
                ui->le_etat->setText(query.value(4).toString());
                ui->la_date->setDate(query.value(5).toDate());
                ui->lineEdit_agent_equipement->setText(query.value(6).toString());

              }

         }
}

void integ_finale::on_tab_maintenance_activated(const QModelIndex &index)
{
    QString val=ui->tab_maintenance->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select* from maintenance where idMaintenance='"+val+"' ");
        if (query.exec())
        { while(query.next())
            {
                ui->id_maintenance->setText(query.value(0).toString());
                ui->id_sup->setText(query.value(0).toString());
                ui->duree_maintenance->setText(query.value(1).toString());
                ui->date_entree_maintenance->setText(query.value(2).toString());
                ui->date_sortie_maintenance->setText(query.value(3).toString());
                ui->frais_maintenance->setText(query.value(4).toString());
                ui->fk_equipement_equipement->setText(query.value(5).toString());
              }

         }
}

void integ_finale::on_trier_clicked()
{
    QString type = ui->comboBox_equipement->currentText();
       if (type == "etatEquipement")
       {
           ui->tab_equipement->setModel(E.tri_etat());
       }else if (type == "quantiteEquipement")
       {
           ui->tab_equipement->setModel(E.tri_quantite());}
}

void integ_finale::on_imprimer_clicked()
{   QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tab_equipement->model()->rowCount();
    const int columnCount = ui->tab_equipement->model()->columnCount();
                    QString TT = QDate::currentDate().toString("yyyy/MM/dd");

                    out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("strTitle")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"

                       //     "<align='right'> " << datefich << "</align>"
                            "<img src='C:/Users/zraib/OneDrive/Bureau/ifinal/Logo.png' width='300' height='150'>"


                        "<center> <H1>Liste des équipements "+TT+" </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                    out << "<thead><tr bgcolor=#FF2E01> <th>Numero</th>";
                    for (int column = 0; column < columnCount; column++)
                       if (!ui->tab_equipement->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tab_equipement->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tab_equipement->isColumnHidden(column)) {
                                QString data =ui->tab_equipement->model()->data(ui->tab_equipement->model()->index(row, column)).toString().simplified();
                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));


                            }
                        }
                        out << "</tr>\n";
                    }
                    out <<  "</table> </center>\n";
out << "<tr>\n"

                        "</body>\n"
                        "</html>\n";

                    QTextDocument *document = new QTextDocument();
                    document->setHtml(strStream);
                    QPrinter printer;

                    QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                    if (dialog->exec() == QDialog::Accepted) {
                        document->print(&printer);
                    }

                    delete document;

}

void integ_finale::on_rech_equipement_textChanged(const QString &arg1)
{
    ui->tab_equipement->setModel(E.rechercherEquipement(arg1));
}

void integ_finale::on_imprimer_detenu_clicked()
{
    QString strStream;
         QTextStream out(&strStream);
         const int rowCount = ui->tab_detenu_2->model()->rowCount();
         const int columnCount = ui->tab_detenu_2->model()->columnCount();
                         QString TT = QDate::currentDate().toString("yyyy/MM/dd");

                         out <<  "<html>\n"
                             "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             <<  QString("<title>%1</title>\n").arg("strTitle")
                             <<  "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"

                            //    "<align='right'> " << datefich << "</align>"
                                 "<img src='C:/Users/zraib/OneDrive/Bureau/ifinal/Logo.png' width='300' height='150'>"


                             "<center> <H1>Liste des detenus "+TT+" </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                         // headers
                         out << "<thead><tr bgcolor=#FF2E01> <th>Numero</th>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tab_detenu_2->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tab_detenu_2->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tab_detenu_2->isColumnHidden(column)) {
                                     QString data = ui->tab_detenu_2->model()->data(ui->tab_detenu_2->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));


                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table> </center>\n";
    out << "<tr>\n"

                             "</body>\n"
                             "</html>\n";

                         QTextDocument *document = new QTextDocument();
                         document->setHtml(strStream);
                         QPrinter printer;

                         QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                         if (dialog->exec() == QDialog::Accepted) {
                             document->print(&printer);
                         }

                         delete document;
}

void integ_finale::showtime ()
{
    QTime time = QTime::currentTime();

           QString time_text=time.toString("hh : mm : ss");
           if((time.second() % 2) == 0 )
           {
               time_text[3] = ' ';
               time_text[8] = ' ';
           }
           ui->digitalclock_2->setText(time_text) ;
}

void integ_finale::on_Video_clicked()
{
    QMediaPlayer* player=new QMediaPlayer;
        QVideoWidget* Vw=new QVideoWidget(this);
        player->setVideoOutput(Vw);
     /*  QString filename=QFileDialog::getOpenFileName((this));
                if(filename.isEmpty())
                return;
            player->setMedia(QUrl::fromLocalFile(filename));;*/
       player->setMedia(QUrl::fromLocalFile("C:/Users/zraib/Downloads/Videoo.mpg"));
        Vw->setGeometry(100,100,600,400);


        Vw->show();



        player->play();
        qDebug()<<player->state();




}

void integ_finale::on_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                               tr("Excel Files (*.xls)"));
               if (fileName.isEmpty())
                   return;

               ExportExcelObject obj(fileName, "mydata", ui->tab_cellule);

               //colums to export
               obj.addField(0, "IdCellule", "char(20)");
               obj.addField(1, "TypeCellule", "char(20)");
               obj.addField(2, "Nblits", "char(20)");
               obj.addField(3, "Superficie", "char(20)");
               obj.addField(4, "Nbdetenus", "char(50)");






               int retVal = obj.export2Excel();
               if( retVal > 0)
               {
                   QMessageBox::information(this, tr("Done"),
                                            QString(tr("%1 records exported!")).arg(retVal)
                                            );
               }
}


void integ_finale::on_ajouter_agent_clicked()
{
    QString cin_agent=ui->cin_agent->text();
        QString nom_agent=ui->nom_agent->text();
        QString prenom_agent=ui->prenom_agent->text();
        QString date_naissance_agent=ui->dateEdit_4->text();
        QString nationalite_agent=ui->nationalite_agent->text();
        QString sexe_agent=ui->comboBox_agent->currentText();
        QString etat_civil_agent=ui->etat_civil->text() ;
        QString telephone_agent=ui->tel_agent->text() ;
        QString email_agent=ui->email_agent->text() ;
        QString adresse_agent=ui->adresse_agent->text();
        QString image=ui->label_photo_2->text();


        agent c(cin_agent, nom_agent, prenom_agent,sexe_agent,date_naissance_agent,adresse_agent, telephone_agent,nationalite_agent, etat_civil_agent,email_agent, image);
        c.AjoutImage(fileNameImage);

        fileNameImage="";
        bool test=c.ajouter_agent();
        QMessageBox msgBox;

        if(test)
        { msgBox.setText("Ajout avec succés");
            ui->tab_agent->setModel(tmp_agent.afficher_agent());
        }
        else
            msgBox.setText("Echec d'ajout");
        msgBox.exec();
}

void integ_finale::on_ajouter_image_2_clicked()
{
    QString fileName=QFileDialog::getOpenFileName( this, tr("Open Document"), QDir::currentPath(), tr("Document files (*.doc *.rtf);;All files (*.*)"),0 );
        QPixmap pixmap;
        if (QFile::exists(fileName))
        {
            fileNameImage=fileName;
            pixmap=fileName;
            ui->label_photo_2->setPixmap(pixmap);
}


}

void integ_finale::on_modifier_agent_clicked()
{

    QString cin_agent=ui->cin_agent->text();
    QString nom_agent=ui->nom_agent->text();
    QString prenom_agent=ui->prenom_agent->text();
    QString date_naissance_agent=ui->dateEdit_4->text();
    QString nationalite_agent=ui->nationalite_agent->text();
    QString sexe_agent=ui->comboBox_agent->currentText();
    QString etat_civil=ui->etat_civil->text() ;
    QString tel=ui->tel_agent->text() ;
    QString email=ui->email_agent->text() ;
    QString adresse=ui->adresse_agent->text();
    QString image=ui->label_photo_2->text();


    agent c (cin_agent, nom_agent, prenom_agent,sexe_agent,date_naissance_agent,adresse, tel,nationalite_agent, etat_civil,email, image);
    bool test=c.modifier_agent(c.getcin_agent(),c.getnom_agent(),c.getprenom_agent(),c.getsexe_agent(),c.getdate_naissance_agent(),c.getadresse_agent(),c.gettelephone_agent(),c.getnationalite_agent(),c.getetat_civil_agent(),c.getemail_agent(),c.getimage());
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Modification avec succés");
        ui->tab_agent->setModel(tmp_agent.afficher_agent());
    }
    else
        msgBox.setText("Echec de modification");
    msgBox.exec();
}

void integ_finale::on_supprimer_agent_clicked()
{
    QString cin=ui->cin_agent->text();
       bool test=tmp_agent.supprimer_agent(cin);
       QMessageBox msgBox;

       if(test)
       { msgBox.setText("Supprimer avec succés");
           ui->tab_agent->setModel(tmp_agent.afficher_agent());
       }
       else
           msgBox.setText("Echec de suppression");
       msgBox.exec();

}

void integ_finale::on_tab_agent_activated(const QModelIndex &index)
{
    QString val=ui->tab_agent->model()->data(index).toString();
      QSqlQuery query;
      query.prepare("select* from agent where cin_agent='"+val+"' ");
      if (query.exec())
      { while(query.next())
          {
              ui->cin_agent->setText(query.value(0).toString());
              ui->nom_agent->setText(query.value(1).toString());
              ui->prenom_agent->setText(query.value(2).toString());
              ui->dateEdit_4->setDate(query.value(3).toDate());
              ui->nationalite_agent->setText(query.value(4).toString());
              ui->comboBox_agent->setCurrentText(query.value(5).toString());
              ui->etat_civil->setText(query.value(6).toString());
              ui->tel_agent->setText(query.value(7).toString());
              ui->email_agent->setText(query.value(8).toString());
              ui->adresse_agent->setText(query.value(9).toString());
              ui->label_photo_2->setText(query.value(10).toString());

              array = query.value(11).toByteArray();
              QBuffer buffer(&array);
              image=(array);
              QPixmap outPixmap = QPixmap();
              outPixmap.loadFromData( image );
              ui->label_photo_2->setPixmap(outPixmap) ;


          }


      }
}

void integ_finale::on_ajouter_service_clicked()
{
    QString id_service=ui->id_serv->text();
        QString libelle_service=ui->titre_serv->text();
        QString agent_service=ui->auteur_serv->text();
        QString date_service=ui->dateEdit->text();
        QString description_service=ui->description_serv->toPlainText();
        QString genre_service=ui->genre_serv->currentText();
        QString nom_departement=ui->nbr_serv->text();

        service p(id_service,libelle_service,agent_service,date_service,description_service,genre_service,nom_departement);
        bool test=p.ajouter_service();
        QMessageBox msgBox;

        if(test)
        { msgBox.setText("Ajout avec succés");
            ui->tab_service->setModel(tmp_service.afficher_service());
        }
        else
            msgBox.setText("Echec d'ajout");
        msgBox.exec();
}

void integ_finale::on_modifier_service_clicked()
{
    QString id_service=ui->id_serv->text();
        QString libelle_service=ui->titre_serv->text();
        QString agent_service=ui->auteur_serv->text();
        QString date_service=ui->dateEdit->text();
        QString description_service=ui->description_serv->toPlainText();
        QString genre_service=ui->genre_serv->currentText();
        QString nom_departement=ui->nbr_serv->text();

       service p(id_service,libelle_service,agent_service,date_service,description_service,genre_service,nom_departement);
        bool test=p.modifier_service(p.getid_service(),p.getlibelle_service(),p.getagent_service(),p.getdate_service(),p.getdescription_service(),p.getgenre_service(),p.getnom_departement());
        QMessageBox msgBox;

        if(test)
        { msgBox.setText("Modification avec succés");
           // ui->tab_agent->setModel(tmp_agent.afficher_agent());
              ui->tab_service->setModel(tmp_service.afficher_service());
        }
        else
            msgBox.setText("Echec de modification");
        msgBox.exec();
}

void integ_finale::on_supprimer_service_clicked()
{
    QString id=ui->id_serv->text();
        bool test=tmp_service.supprimer_service(id);
        QMessageBox msgBox;

        if(test)
        { msgBox.setText("Suppression avec succés");
            ui->tab_service->setModel(tmp_service.afficher_service());
        }
        else
            msgBox.setText("Echec de suppression");
        msgBox.exec();
}



/*void integ_finale::on_trier_service_clicked()
{

}*/

void integ_finale::on_pushButton_36_clicked()
{

    QString cin=ui->recherche_agent->text();
    ui->tab_agent->setModel(tmp_agent.rechercher_id_agent(cin));
}

void integ_finale::on_pushButton_37_clicked()
{
    QString type = ui->comboBox_agent_2->currentText();
      if (type == "cin_agent")
      {
          ui->tab_agent->setModel(tmp_agent.tri_cin());
      }else if (type == "date de naissance")
      {
          ui->tab_agent->setModel(tmp_agent.tri_date());
}
}

void integ_finale::on_pdf_service_clicked()
{
    QString strStream;
           QTextStream out(&strStream);
           const int rowCount = ui->tab_service->model()->rowCount();
           const int columnCount = ui->tab_service->model()->columnCount();
                           QString TT = QDate::currentDate().toString("yyyy/MM/dd");

                           out <<  "<html>\n"
                               "<head>\n"
                               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                               <<  QString("<title>%1</title>\n").arg("strTitle")
                               <<  "</head>\n"
                               "<body bgcolor=#ffffff link=#5000A0>\n"

                              //     "<align='right'> " << datefich << "</align>"
                                   "<img src='C:/Users/zraib/OneDrive/Bureau/ifinal/logo.png' width='300' height='150'>"


                               "<center> <H1>Liste des services "+TT+" </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                           // headers
                           out << "<thead><tr bgcolor=#FF2E01> <th>Numero</th>";
                           for (int column = 0; column < columnCount; column++)
                               if (!ui->tab_service->isColumnHidden(column))
                                   out << QString("<th>%1</th>").arg(ui->tab_service->model()->headerData(column, Qt::Horizontal).toString());
                           out << "</tr></thead>\n";

                           // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tab_service->isColumnHidden(column)) {
                                       QString data = ui->tab_service->model()->data(ui->tab_service->model()->index(row, column)).toString().simplified();
                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));


                                   }
                               }
                               out << "</tr>\n";
                           }
                           out <<  "</table> </center>\n";
      out << "<tr>\n"

                               "</body>\n"
                               "</html>\n";

                           QTextDocument *document = new QTextDocument();
                           document->setHtml(strStream);
                           QPrinter printer;

                           QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                           if (dialog->exec() == QDialog::Accepted) {
                               document->print(&printer);
                           }

                           delete document;
}

void integ_finale::on_map_clicked()
{
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
         ui->quickWidget->show();
         auto obj =ui->quickWidget->rootObject();
         connect(this,SIGNAL(setCenter(QVaritant,QVariant)),obj,SLOT(setCenter(QVaritant,QVariant)));
    emit setCenter(25.000,50.000);
}

void integ_finale::on_refresh_c_clicked()
{
    ui->tab_cellule->setModel(C.afficher_cellule());
}

//**********************************Ahmed*******************
//ajouter ahmed
void integ_finale::on_pb_ajouter_2_clicked()
{
   click->play() ;
        int id=ui->le_id_2->text().toInt();
        QString marque=ui->le_nom_2->text();
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
//supprimer ahmed
void integ_finale::on_pb_supprimer_2_clicked()
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
//modifier ahmed
void integ_finale::on_modifier_vehicule_clicked()
{
  click->play() ;
        int id=ui->le_id_2->text().toInt();
        QString marque=ui->le_nom_2->text();
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
//partie ahmed
void integ_finale::on_tab_vehicule_activated(const QModelIndex &index)
{
    QString val=ui->tab_vehicule->model()->data(index).toString();
            QSqlQuery query;
            query.prepare("select* from vehicule where id='"+val+"' ");
            if (query.exec())
            { while(query.next())
                {
                    ui->le_id_2->setText(query.value(0).toString());
                    ui->le_nom_2->setText(query.value(0).toString());
                    ui->le_prenom->setText(query.value(1).toString());



                  }
    }
}


//ajouter 2 ahmed
void integ_finale::on_pb_ajouter_3_clicked()
{
   click->play() ;
        int id=ui->le_id_3->text().toInt();
        int nbr_vehicule=ui->le_nom_3->text().toInt();
        int nbr_policier=ui->le_prenom_3->text().toInt();
      QString date_mission=ui->le_nom_4->text();
        mission m(id,nbr_vehicule,nbr_policier,date_mission);
        bool test=m.ajouter2();
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Ajout avec succés");
            ui->tab_mission->setModel(m.afficher_mission());
        }
        else
            msgBox.setText("Echec d'e suppression'ajout");
        msgBox.exec();
        //int control=1;
        if(test==1)  //mailing
           {
               SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

          smtp.setUser("ahmed.ayedi@esprit.tn");

     smtp.setPassword("191JFT4295");

        MimeMessage message;

        message.setSender(new EmailAddress("ahmed.ayedi@esprit.tn", "ajout"));
        message.addRecipient(new EmailAddress("ahmedayedi41@gmail.com", "ahmed"));
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
    }
}
// modifier 2 ahmed
void integ_finale::on_modifier_mission_clicked()
{
    int id=ui->le_id_3->text().toInt();
        int nbr_vehicule=ui->le_nom_3->text().toInt();
        int nbr_policier=ui->le_prenom_3->text().toInt();
         QString date_mission=ui->le_nom_4->text();

       mission m (id, nbr_vehicule, nbr_policier, date_mission );
         bool test=m.modifier_mission(m.getid(),m.getnbr_vehicule(),m.getnbr_policier(),m.getdate_mission());
         QMessageBox msgBox;

         if(test)
            { msgBox.setText("Modification avec succés");
             ui->tab_mission->setModel(m.afficher_mission());
         }
         else
             msgBox.setText("Echec de modification");
         msgBox.exec();
}

// supprimer 2 ahmed
void integ_finale::on_pb_supprimer_3_clicked()
{
    mission C1; C1.setid(ui->le_id_supp_2->text().toInt());
        bool test=C1.supprimer(C1.getid());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Supprimer avec succés");
         ui->tab_mission->setModel(m.afficher_mission());
        }
        else
            msgBox.setText("Echec de suppression");
        msgBox.exec();
}
//partie2 ahmed
void integ_finale::on_tab_mission_activated(const QModelIndex &index)
{
    QString val=ui->tab_mission->model()->data(index).toString();
            QSqlQuery query;
            query.prepare("select* from mission where id='"+val+"' ");
            if (query.exec())
            { while(query.next())
                {
                    ui->le_id_3->setText(query.value(0).toString());
                    ui->le_nom_3->setText(query.value(0).toString());
                    ui->le_prenom_3->setText(query.value(1).toString());
                    ui->le_nom_4->setText(query.value(2).toString());
                    ui->le_id_supp_2->setText(query.value(3).toString());


                  }
    }
}

void integ_finale::on_tri_mission_clicked()
{
    QString type = ui->comboBox_mission->currentText();
            if (type == "id")
            {
                ui->tab_mission->setModel(m.tri_id());
            }else if (type == "nbr de vehicule")
            {
                ui->tab_mission->setModel(m.tri_nbr_veh());

            }
}

void integ_finale::on_pushButton_clicked()
{     QPdfWriter pdf("C:/Users/ARIJ/Desktop/ahmed PDF/PdfAbonnes.pdf");
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
          QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/zraib/OneDrive/Bureau/ahmed PDF/PdfAbonnes.pdf"));

          painter.end();
      }
      if (reponse == QMessageBox::No)
      {
          painter.end();
      }
}
//ahmed
void integ_finale::on_pb_rechercher_mission_clicked()
{
    QString res=ui->recher_mission->text();

            ui->tab_mission->setModel(m.rechercher_mission(res));
}
//ahmed
void integ_finale::on_pushButton_6_clicked()
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
}
//ahmed
void integ_finale::on_pushButton_5_clicked()
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

void integ_finale::update_label()
{
    data=A.read_from_arduino();

   ui->label_distance->setText(data);

   /* ui->label_indication->setText("distance est inférieur a 10 DANGER");}
    else if(data>"15")
      {ui->label_distance->setText(data);
      ui->label_indication->setText("distance supérieur a 10 SANS DANGER");}


  if(data=="4")
           ui->label_indication->setText("distance est inférieur a 10");

    else  if(data=="5")
           ui->label_indication->setText("distance safe");


    else if(data=="1")
            ui->label_lampe->setText("ON");

     else  if(data=="0")
            ui->label_lampe->setText("OFF");*/


}








void integ_finale::on_pushButton_4_clicked()
{
     ui->tab_mission->setModel(m.afficher_mission());
}


void integ_finale::on_pushButton_on_clicked()
{
     A.write_to_arduino("1");
}

void integ_finale::on_pushButton_off_clicked()
{
        A.write_to_arduino("0");
}

void integ_finale::on_qrpushbutton_clicked()
{
    int tabeq=ui->tab_equipement->currentIndex().row();
        QVariant idd=ui->tab_equipement->model()->data(ui->tab_equipement->model()->index(tabeq,0));
        QString id= idd.toString();
        QSqlQuery qry;
        qry.prepare("select * from equipement where idEquipement=:id");
        qry.bindValue(":id",id);
        qry.exec();
        QString nomEquipement, typeEquipement ,quantiteEquipement,dateFabrication,ide;
        int etatEquipement;
        while(qry.next()){
            nomEquipement=qry.value(1).toString();
            typeEquipement=qry.value(2).toString();
            quantiteEquipement=qry.value(3).toString();
            dateFabrication=qry.value(4).toString();
        }
        ide=QString(id);
        ide="ID: "+ide+" Nom: "+nomEquipement+" typeEquipement: "+typeEquipement+" quantiteEquipement: "+quantiteEquipement+" dateFabrication : "+dateFabrication;
        QrCode qr = QrCode::encodeText(ide.toUtf8().constData(), QrCode::Ecc::HIGH);

        // Read the black & white pixels
        QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
        for (int y = 0; y < qr.getSize(); y++) {
            for (int x = 0; x < qr.getSize(); x++) {
                int color = qr.getModule(x, y);  // 0 for white, 1 for black

                // You need to modify this part
                if(color==0)
                    im.setPixel(x, y,qRgb(254, 254, 254));
                else
                    im.setPixel(x, y,qRgb(0, 0, 0));
            }
        }
        im=im.scaled(200,200);
        ui->qrlabel->setPixmap(QPixmap::fromImage(im));
        int i=0 ;
        for(i=0;i<100;i=i+0.1){
            i++;
            ui->progressBar->setValue(i);
        }
}
void integ_finale::on_ajouter_citoyen_clicked()
{
    QString cin_citoyen=ui->cin_citoyen->text();
    QString nom_citoyen=ui->nom_citoyen->text();
    QString prenom_citoyen=ui->prenom_citoyen->text();
    QString date_naissance_citoyen=ui->date_citoyen->text();
    QString nationalite_citoyen=ui->nationalite_citoyen->text();
    QString sexe_citoyen=ui->comboBox_citoyen->currentText();
    QString etat_civil=ui->etat_civil_citoyen->text() ;
    QString tel=ui->tel_citoyen->text() ;
    QString email=ui->email_citoyen->text() ;
    QString adresse=ui->adresse_citoyen->text();
      QMessageBox msgBox;

if( verifnom() && verifcin() && verifprenom() && veriftel() &&   verifnationalite() && verifsexe() && verifemail() && verifadresse() )
{
    Citoyen c(cin_citoyen, nom_citoyen, prenom_citoyen,sexe_citoyen,date_naissance_citoyen,adresse, tel,nationalite_citoyen, etat_civil,email);
    c.AjoutImage(fileNameImage);

    fileNameImage="";
    bool test=c.ajouter_citoyen();


    if(test)
    { msgBox.setText("Ajout avec succés");
        ui->tab_citoyen->setModel(tmp_citoyen.afficher_citoyen());
    }
}
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void integ_finale::on_modifier_citoyen_clicked()
{
    QString cin_citoyen=ui->cin_citoyen->text();
    QString nom_citoyen=ui->nom_citoyen->text();
    QString prenom_citoyen=ui->prenom_citoyen->text();
    QString date_naissance_citoyen=ui->date_citoyen->text();
    QString nationalite_citoyen=ui->nationalite_citoyen->text();
    QString sexe_citoyen=ui->comboBox_citoyen->currentText();
    QString etat_civil=ui->etat_civil_citoyen->text() ;
    QString tel=ui->tel_citoyen->text() ;
    QString email=ui->email_citoyen->text() ;
    QString adresse=ui->adresse_citoyen->text();

 QMessageBox msgBox;
    Citoyen C(cin_citoyen, nom_citoyen, prenom_citoyen,sexe_citoyen,date_naissance_citoyen,adresse, tel,nationalite_citoyen, etat_civil,email);
    bool test=C.modifier_citoyen(C.getcin_citoyen(),C.getnom_citoyen(),C.getprenom_citoyen(),C.getsexe_citoyen(),C.getdate_naissance_citoyen(),C.getadresse_citoyen(),C.gettelephone_citoyen(),C.getnationalite_citoyen(),C.getetat_civil_citoyen(),C.getemail_citoyen());
    if( verifnom() && verifcin() && verifprenom() && veriftel() &&   verifnationalite() && verifsexe() && verifemail() && verifadresse() )

   {

    if(test)
    { msgBox.setText("Modification avec succés");
        ui->tab_citoyen->setModel(tmp_citoyen.afficher_citoyen());
    }
    }
    else
        msgBox.setText("Echec de modification");
    msgBox.exec();
}

void integ_finale::on_supprimer_citoyen_clicked()
{
    QString cin=ui->cin_citoyen->text();
    bool test=tmp_citoyen.supprimer_citoyen(cin);
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Supprimer avec succés");
        ui->tab_citoyen->setModel(tmp_citoyen.afficher_citoyen());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}


void integ_finale::on_tab_citoyen_activated(const QModelIndex &index)
{
    QString val=ui->tab_citoyen->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select* from citoyens where cin_citoyen='"+val+"' ");
    if (query.exec())
    { while(query.next())
        {
            ui->cin_citoyen->setText(query.value(0).toString());
            ui->nom_citoyen->setText(query.value(1).toString());
            ui->prenom_citoyen->setText(query.value(2).toString());
            ui->date_citoyen->setDate(query.value(3).toDate());
            ui->nationalite_citoyen->setText(query.value(4).toString());
            ui->comboBox_citoyen->setCurrentText(query.value(5).toString());
            ui->etat_civil_citoyen->setText(query.value(6).toString());
            ui->tel_citoyen->setText(query.value(7).toString());
            ui->email_citoyen->setText(query.value(8).toString());
            ui->adresse_citoyen->setText(query.value(9).toString());
            array = query.value(10).toByteArray();
            QBuffer buffer(&array);
            image=(array);
            QPixmap outPixmap = QPixmap();
            outPixmap.loadFromData( image );
            ui->label_photo->setPixmap(outPixmap) ;


        }


    }
}

void integ_finale::on_ajouter_petition_clicked()
{
    QString id_petition=ui->id_pet->text();
    QString titre_petition=ui->titre_pet->text();
    QString auteur_petition=ui->auteur_pet->text();
    QString date_petition=ui->date_pet->text();
    QString description_petition=ui->description_pet->toPlainText();
    QString validite_petition=ui->validite_pet->currentText();
    QString nbr_signatures_requis=ui->nbr_pet->text();
    if( verifid()&&veriftitre()&&verifauteur()&&verifvalidite()&&verifnbr()&&verifdesc())

   {

    Petition p(id_petition,titre_petition,auteur_petition,date_petition,description_petition,validite_petition,nbr_signatures_requis);
    bool test=p.ajouter_petition();
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Ajout avec succés");
        ui->tab_petition->setModel(tmp_petition.afficher_petition());
    }

    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}
}
void integ_finale::on_supprimer_petition_clicked()
{
    QString id=ui->id_pet->text();
    bool test=tmp_petition.supprimer_petition(id);
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Suppression avec succés");
        ui->tab_petition->setModel(tmp_petition.afficher_petition());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}

void integ_finale::on_modifier_petition_clicked()
{
    QString id_petition=ui->id_pet->text();
    QString titre_petition=ui->titre_pet->text();
    QString auteur_petition=ui->auteur_pet->text();
    QString date_petition=ui->date_pet->text();
    QString description_petition=ui->description_pet->toPlainText();
    QString validite_petition=ui->validite_pet->currentText();
    QString nbr_signatures_requis=ui->nbr_pet->text();

   Petition p(id_petition,titre_petition,auteur_petition,date_petition,description_petition,validite_petition,nbr_signatures_requis);
    bool test=p.modifier_petition(p.getid_petition(),p.gettitre_petition(),p.getauteur_petition(),p.getdate_petition(),p.getdescription_petition(),p.getvalidite_petition(),p.getnbr_signatures_requis());
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Modification avec succés");
       // ui->tab_citoyen->setModel(tmp_citoyen.afficher_citoyen());
          ui->tab_petition->setModel(tmp_petition.afficher_petition());
    }
    else
        msgBox.setText("Echec de modification");
    msgBox.exec();
}

void integ_finale::on_ajouter_image_clicked()
{
    QString fileName=QFileDialog::getOpenFileName( this, tr("Open Document"), QDir::currentPath(), tr("Document files (*.doc *.rtf);;All files (*.*)"),0 );
    QPixmap pixmap;
    if (QFile::exists(fileName))
    {
        fileNameImage=fileName;
        pixmap=fileName;
        ui->label_photo->setPixmap(pixmap);
    }
}
void integ_finale::myfunctionn()
{
    QTime time = QTime::currentTime() ;
    QString time_text=time.toString("hh : mm : ss")  ;

    ui->label_date_time_2->setText(time_text) ;


}

void integ_finale::on_nettoyer_4_clicked()
{
    supprimercitoyen();

}
void integ_finale::supprimercitoyen()
{

    ui->cin_citoyen->clear();
    ui->nom_citoyen->clear();
    ui->prenom_citoyen->clear();
    ui->date_citoyen->clear();
    ui->nationalite_citoyen->clear();
    ui->etat_civil_citoyen->clear();
    ui->tel_citoyen->clear();
    ui->email_citoyen->clear();
    ui->adresse_citoyen->clear();
    ui->label_photo->clear();
    ui->verif_adresse->clear();
    ui->verif_cin_citoyen->clear();
    ui->verif_date_citoyen->clear();
    ui->verif_email->clear();
    ui->verif_nationnalite_citoyen->clear();
    ui->verif_nom_citoyen->clear();
    ui->verif_prenom_citoyen->clear();
    ui->verif_sexe->clear();
    ui->verif_tel->clear();

}


void integ_finale::on_pdf_petition_clicked()
{
    QPainter painter;

    QString str;
        str.append("<html><head></head><body><center>"+QString("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;;<font size=""10"" color =""red""> LISTE DES PETITIONS VALIDES </font><br /> <br /> "));
        str.append("<table border=1><tr>");
        str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">titre</font>&nbsp;&nbsp;"+"</td>");
        str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">auteur</font>&nbsp;&nbsp;"+"</td>");
        str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""20"">date</font>&nbsp;&nbsp;")+"</td>");
        str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">description</font>&nbsp;&nbsp;")+"</td>");
        painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/DELL/Documents/PoliceStation2/Nouveau dossier/5.jpg"));
        QSqlQuery * query=new QSqlQuery();
        query->exec("SELECT  titre_petition,auteur_petition,date_petition, description_petition FROM petition");
        while(query->next())
        {
            str.append("<tr><td>");
            str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(0).toString()+"&nbsp;&nbsp;");
            str.append("</td><td>");
            str.append("&nbsp;&nbsp;<font color =""green""  size=""10"">"+query->value(1).toString()+"&nbsp;&nbsp;");
            str.append("</td><td>");
            str.append("&nbsp;&nbsp;<font color =""green"" size=""10"">"+query->value(2).toString()+"&nbsp;&nbsp;");
             str.append("</td><td>");
            str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(3).toString()+"&nbsp;&nbsp;");
            str.append("</td></tr>");

    }

        str.append("</table></center><body></html>");

        QPrinter printer;
        printer.setOrientation(QPrinter::Portrait);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);

        QString path= QFileDialog::getSaveFileName(NULL,"imprimer","Liste des petitions validées","PDF(*.pdf");
         if(path.isEmpty()) return;
         printer.setOutputFileName(path);
         QTextDocument doc;
         doc.setHtml(str);
         doc.print(&printer);
}

void integ_finale::on_recherche_citoyen_cursorPositionChanged(int arg1, int arg2)
{
    QString cin=ui->recherche_citoyen->text();
    ui->tab_citoyen->setModel(tmp_citoyen.rechercher_id_citoyen(cin));
}

void integ_finale::on_sendBtn_2_clicked()
{
    smtp *s=new smtp("bettaiebyasmine3@gmail.com","kalbalanalana123***","smtp.gmail.com",465);
    s->sendMail("bettaiebyasmine3@gmail.com", ui->rcpt_2->text() , ui->Objet_2->text(), ui->Texte_2->toPlainText(), files );
    QMessageBox::information(nullptr,QObject::tr("Ok"),
                         QObject::tr("Mail envoyé\n"
                                       "Click cancel to exit."),QMessageBox::Cancel);
}
void   integ_finale::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::information(nullptr, tr( "Envoi par mail" ), tr( "L'E-Billet a été envoyé avec succès !\n\n" ) );
    ui->rcpt_2->clear();
    ui->Objet_2->clear();
    ui->file_2->clear();
    ui->Texte_2->clear();

    hide();

    QFile file("C:/Users/DELL/Desktop/yassPDF/Pdf.pdf");
   file.remove();

}
void integ_finale::on_browseBtn_2_clicked()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory("C:/Users/DELL/Desktop/yassPDF");
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file_2->setText(fileListString);
}

void integ_finale::on_pause_clicked()
{
    music->stop() ;

}

void integ_finale::on_recherche_citoyen_editingFinished()
{
    ui->tab_citoyen->setModel(tmp_citoyen.afficher_citoyen());

}

void integ_finale::on_play_2_clicked()
{
    music->play() ;

}

void integ_finale::on_home_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);

}

void integ_finale::on_pushButton_10_clicked()
{
    ui->tab_citoyen->setModel(tmp_citoyen.afficher_citoyen());

}

void integ_finale::on_tab_petition_activated(const QModelIndex &index)
{
    QString val=ui->tab_petition->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select* from petition where id_petition='"+val+"' ");
    if (query.exec())
    { while(query.next())
        {
            ui->id_pet->setText(query.value(0).toString());
            ui->titre_pet->setText(query.value(1).toString());
            ui->auteur_pet->setText(query.value(2).toString());
            ui->date_pet->setDate(query.value(3).toDate());
            ui->description_pet->setPlainText(query.value(4).toString());
            ui->validite_pet->setCurrentText(query.value(5).toString());
            ui->nbr_pet->setText(query.value(6).toString());

           }
    }
}

void integ_finale::on_pushButton_9_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                       tr("Excel Files (*.xls)"));
       if (fileName.isEmpty())
           return;

       ExportExcelObject obj(fileName, "mydata", ui->tab_citoyen);

       //colums to export
       obj.addField(0, "cin_citoyen", "char(20)");
       obj.addField(1, "nom_citoyen", "char(20)");
       obj.addField(2, "prenom_citoyen", "char(20)");
       obj.addField(3, "sexe_citoyen", "char(20)");
       obj.addField(4, "email_citoyen", "char(20)");
       obj.addField(5, "adresse_citoyen", "char(20)");


       int retVal = obj.export2Excel();
       if( retVal > 0)
       {
           QMessageBox::information(this, tr("Done"),
                                    QString(tr("%1 records exported!")).arg(retVal)
                                    );
       }
}



void integ_finale::on_recherche_dynamique_textChanged(const QString &arg1)
{
    ui->tab_petition->setModel(tmp_petition.rechercheDynamic(arg1));

}
void integ_finale::on_pushButton_facebook_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.facebook.com", QUrl::TolerantMode));
}

void integ_finale::on_pushButton_twitter_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.twitter.com", QUrl::TolerantMode));
}
void integ_finale::on_nettoyer_3_clicked()
{
    supprimerpetition();
}
void integ_finale::supprimerpetition()
{


    ui->id_pet->clear();
    ui->titre_pet->clear();
   ui->auteur_pet->clear();
   ui->date_pet->clear();
   ui->description_pet->clear();
   ui->validite_pet->clear();
   ui->nbr_pet->clear();
    ui->label_id_pet->clear();
    ui->label_titre->clear();
    ui->label_auteur->clear();
    ui->label_date->clear();
    ui->label_validite->clear();
    ui->label_nbr->clear();
    ui->label_description->clear();
    ui->recherche_dynamique->clear();

}

void integ_finale::on_email_pet_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);

}

void integ_finale::on_tri_citoyen_clicked()
{
    QString type = ui->comboBox_citoyen_2->currentText();
    if (type == "cin_citoyen")
    {
        ui->tab_citoyen->setModel(tmp_citoyen.tri_cin());
    }else if (type == "date de naissance")
    {
        ui->tab_citoyen->setModel(tmp_citoyen.tri_date());

    }
    else if(type=="nom citoyen")
    {
        ui->tab_citoyen->setModel(tmp_citoyen.tri_nom());
    }
}



void integ_finale::on_pushButton_notepad_clicked()
{


  notePad *app;
       app = new notePad(this);
      // app->setModal(true);
       app->show();
}





void integ_finale::on_pushButton_rech_eq_agent_clicked()
{
    QString nomEquipement = ui->comboBox_eq_agent->currentText();
       if (nomEquipement == "pistolet")
       {
           ui->tableView_agent_equipement->setModel(E.recherche_agent_equipement());
       }else if (nomEquipement == "baton telescopique")
       {
           ui->tableView_agent_equipement->setModel(E.recherche_agent_equipement2());}
}

void integ_finale::on_ajouter_personne_clicked()
{
    int id=ui->id_personne->text().toInt();

        QString nom=ui->nom_personne->text();
        QString prenom=ui->prenom_personne->text();
        QString adresse=ui->adresse_personne->text();
        QString datePersonne=ui->date_personne->text();
        //QString datePer= datePersonne.toString("dd/MM/yyyy");
        QString sexe=ui->comboBox_personne->currentText();



        Personne P(id,nom,prenom,adresse,datePersonne,sexe);
        bool test=P.ajouter();
        QMessageBox msgBox;

           if(test)
               { msgBox.setText("Ajout avec succés");
                ui->tab_personne->setModel(P.afficher());
            }
            else
                msgBox.setText("Echec d'ajout");
            msgBox.exec();
            if(test==1)  //mailing
               {
                   SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

              smtp.setUser("arije.grissiaa@esprit.tn");

         smtp.setPassword("191JFT2575");

            MimeMessage message;

            message.setSender(new EmailAddress("arije.grissiaa@esprit.tn", "ajout"));
            message.addRecipient(new EmailAddress("zraibianour9@gmail.com", "nour"));
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

                              QPrinter printer;
                              printer.setOutputFormat(QPrinter::PdfFormat);
                              printer.setOutputFileName("D:/projetC++/integration_base/file.pdf");
                              QPainter painter;
                              painter.begin(&printer);
                              QImage image("C:/Users/zraib/OneDrive/Bureau/ifinal/Logo.png");
                              painter.drawImage(0,0,image);
                              QFont font;

                              font.setPixelSize(50);
                              painter.setFont(font);
                              painter.setPen(Qt::red);
                              painter.drawText(50,150,"Fiche Des Personne Recherchee: ");
                              font.setPixelSize(35);
                              painter.setFont(font);
                              painter.setPen(Qt::red);
                              painter.drawText(400,300,"Nom: ");
                              painter.drawText(400,500,"Prenom:");
                              painter.drawText(400,650,"Adresse:");
                              painter.drawText(400,800,"Date:");
                              painter.drawText(400,1000,"Sexe:");




                              font.setPixelSize(20);
                              painter.setFont(font);
                              painter.setPen(Qt::black);
                              painter.drawText(400,350,nom);
                              painter.drawText(400,550,prenom);
                              painter.drawText(400,700,adresse);
                              painter.drawText(400,850,datePersonne);
                              painter.drawText(400,1050,sexe);




                              painter.end();



}}}

void integ_finale::on_modifier_personne_clicked()
{     int id=ui->id_personne->text().toInt();

    QString nom=ui->nom_personne->text();
    QString prenom=ui->prenom_personne->text();
    QString adresse=ui->adresse_personne->text();
    QString datePersonne=ui->date_personne->text();
    //QString datePer= datePersonne.toString("dd/MM/yyyy");
    QString sexe=ui->comboBox_personne->currentText();



    Personne P(id,nom,prenom,adresse,datePersonne,sexe);
    bool test=P.update(id,nom,prenom,adresse,datePersonne,sexe);







 QMessageBox msgBox;

            if(test)
               { msgBox.setText("Modification avec succés");
                ui->tab_personne->setModel(P.afficher());
            }
            else
                msgBox.setText("Echec de modification");
            msgBox.exec();
}

void integ_finale::on_tab_personne_activated(const QModelIndex &index)
{
    QString val=ui->tab_personne->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select* from personne where id='"+val+"' ");
        if (query.exec())
        { while(query.next())
            {
                ui->id_personne->setText(query.value(0).toString());
               // ui->le_id_supp->setText(query.value(0).toString());
                ui->nom_personne->setText(query.value(1).toString());
                ui->prenom_personne->setText(query.value(2).toString());
                ui->adresse_personne->setText(query.value(3).toString());
                ui->date_personne->setText(query.value(4).toString());
               // ui->comboBox_personne->currentText(query.value(5).toString());


              }

         }
}

void integ_finale::on_supprimer_personne_clicked()
{

    Personne P;
       P.set_id(ui->id_personne->text().toInt());
        bool test=P.supprimer(P.get_id());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Supprimer avec succés");
        ui->tab_personne->setModel(P.afficher());
        }
        else
            msgBox.setText("Echec de suppression");
        msgBox.exec();
}





void integ_finale::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tab_personne->setModel(P.rechercherPersonne(arg1));
}


void integ_finale::on_recherche_personne_clicked()
{
    QString key = ui->espace_chercher->toPlainText();
        int index = ui->comboBox_ch_personne->currentIndex();


        Personne * s = new Personne();
        QSqlQueryModel * q = s->search(index, key);
        if(q != nullptr){
            ui->tab_personne->setModel(q);
        }else{
            QMessageBox::critical(nullptr, QObject::tr("Warning"),
              QObject::tr("Personne non trouvé."), QMessageBox::Cancel);
        }
}

void integ_finale::on_ajouter_plainte_clicked()
{
    int idp=ui->id_plainte->text().toInt();

      int idpersonne=ui->id_plainte_personne->text().toInt();;
        QString raison=ui->raison_plainte->text();

         QDate dateP=ui->date_plainte->date();
        QString datePl= dateP.toString("dd/MM/yyyy");
        QString type=ui->comboBox_plainte->currentText();



        Plaintes T( idp, raison,datePl, type, idpersonne);
        bool test=T.ajouter();
        QMessageBox msgBox;

           if(test)
               { msgBox.setText("Ajout avec succés");
                ui->tab_plainte->setModel(T.afficher(aff));
            }
            else
                msgBox.setText("Echec d'ajout");
            msgBox.exec();
}

void integ_finale::on_modifier_plainte_clicked()
{
    int idp=ui->id_plainte->text().toInt();

      int idpersonne=ui->id_plainte_personne->text().toInt();;
        QString raison=ui->raison_plainte->text();

         QDate dateP=ui->date_plainte->date();
        QString datePl= dateP.toString("dd/MM/yyyy");
        QString type=ui->comboBox_plainte->currentText();



        Plaintes T(idp, raison,datePl, type, idpersonne);
        bool test=T.update(idp,raison,datePl,type,idpersonne);

      QMessageBox msgBox;

                if(test)
                   { msgBox.setText("Modification avec succés");
                    ui->tab_plainte->setModel(T.afficher(aff));
                }
                else
                    msgBox.setText("Echec de modification");
                msgBox.exec();
    }


void integ_finale::on_tab_plainte_activated(const QModelIndex &index)
{
    QString val=ui->tab_plainte->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select* from plainte where idp='"+val+"' ");
        if (query.exec())
        { while(query.next())
            {
                ui->id_plainte->setText(query.value(0).toString());

                ui->id_plainte_personne->setText(query.value(1).toString());
                ui->raison_plainte->setText(query.value(2).toString());

                  ui->date_plainte->setDate(query.value(3).toDate());
                ui->comboBox_plainte->currentText();


              }

         }
}

void integ_finale::on_supprimer_plainte_clicked()
{
    Plaintes P;
       P.set_id(ui->id_plainte->text().toInt());
        bool test=P.supprimer(P.get_id());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Supprimer avec succés");
        ui->tab_plainte->setModel(P.afficher(aff));
        }
        else
            msgBox.setText("Echec de suppression");
        msgBox.exec();
}

int integ_finale :: getIDFromTableView(QTableView * tv){
    int id =-1;
    if(tv->currentIndex().isValid() == true){
    QModelIndexList indexes = tv->selectionModel()->selection().indexes();
    QVariant qv = indexes.at(0).data();
    QString ss = qv.toString();
    std::string cc = ss.toStdString();
    id = std::atoi (cc.c_str());
    }else{
        id = -1;
    }
    return id;
}

void integ_finale::on_tab_personne_clicked(const QModelIndex &index)
{
    int id = getIDFromTableView(ui->tab_personne);
         Plaintes * s = new Plaintes();
         QSqlQueryModel * model = s->afficher(id) ;
         ui->tableView_plainte->setModel(model);
         ui->tableView_plainte->setColumnHidden(4,true) ;
         delete s;
}
