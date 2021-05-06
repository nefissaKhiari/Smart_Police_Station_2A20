#ifndef INTEG_FINALE_H
#define INTEG_FINALE_H

#include <QDialog>
#include "equipement.h"
#include "maintenance.h"
#include "detenu.h"
#include "service.h"
#include "cellule.h"
#include <QPropertyAnimation>
#include <QLabel>
#include <QWidget>
//#include"service.h"
#include"agent.h"
//#include "smtp.h"
#include <QMainWindow>
#include<QTimer>
#include <QStaticText>
#include <QSound>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include<QPrintDialog>
#include <QVariant>
#include "vehicule.h"
#include "mission.h"
#include "arduino.h"
#include "QrCode.hpp"
#include"petition.h"
#include"citoyen.h"
#include "smtp.h"
#include "notepad.h"
#include "personne.h"
#include "plaintes.h"



namespace Ui {
class integ_finale;
}

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;

class integ_finale : public QDialog
{
    Q_OBJECT

public:
    explicit integ_finale(QWidget *parent = nullptr);
    ~integ_finale();

private slots:
   // void on_pushButton_clicked();

    void on_Petition_clicked();

    void on_Materiel_clicked();

    void on_Agent_clicked();

    void on_Crimes_clicked();

    void on_Plaintes_clicked();

    void on_Mission_clicked();

    void on_pb_ajouter_clicked();

    void on_quit_clicked();

    void on_pb_modifier_detenu_clicked();

    void on_tab_detenu_2_activated(const QModelIndex &index);

    void on_modifier_cellule_clicked();

    void on_tab_cellule_activated(const QModelIndex &index);

    void on_pb_supprimer_detenu_clicked();

    void on_pb_supprimer_cellule_clicked();

    void on_pb_ajouter_detenu_clicked();

    void on_pb_ajouter_cellule_clicked();

    void on_pb_trier_cellule_clicked();

    void on_pb_rechercher_cellule_clicked();

    void on_pb_modifier_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouterMaintenance_clicked();

    void on_pushButton_modifier_maintenance_clicked();

    void on_pushButton_supprimer_maintenance_clicked();

    void on_tab_equipement_activated(const QModelIndex &index);

    void on_tab_maintenance_activated(const QModelIndex &index);

    void on_trier_clicked();

    void on_imprimer_clicked();

    void on_rech_equipement_textChanged(const QString &arg1);

    void on_imprimer_detenu_clicked();

      void showtime () ;
      void on_Video_clicked();

      void on_excel_clicked();



      void on_ajouter_agent_clicked();

      void on_ajouter_image_2_clicked();

      void on_modifier_agent_clicked();

      void on_supprimer_agent_clicked();

      void on_tab_agent_activated(const QModelIndex &index);

      void on_ajouter_service_clicked();

      void on_modifier_service_clicked();

      void on_supprimer_service_clicked();

//void on_pb_ajouter_2_clicked();







      void on_pushButton_36_clicked();

      void on_pushButton_37_clicked();

      void on_pdf_service_clicked();

      void on_map_clicked();

      void on_refresh_c_clicked();
      //***Ahmed
      void on_pb_ajouter_2_clicked();

           void on_pb_supprimer_2_clicked();

           void on_modifier_vehicule_clicked();

           void on_tab_vehicule_activated(const QModelIndex &index);


           void on_pb_ajouter_3_clicked();

                void on_modifier_mission_clicked();

                void on_pb_supprimer_3_clicked();

                void on_tab_mission_activated(const QModelIndex &index);

             void on_tri_mission_clicked();

                void on_pushButton_clicked();

                void on_pb_rechercher_mission_clicked();

                void on_pushButton_6_clicked();

                void on_pushButton_5_clicked();


                void on_pushButton_4_clicked();


                void update_label();

                void on_pushButton_on_clicked();

                void on_pushButton_off_clicked();

                void on_qrpushbutton_clicked();
                bool verifnom();

                                bool verifcin();
                                bool verifprenom();
                                bool veriftel();
                                bool verifnationalite();
                                bool verifsexe();
                                bool verifadresse();
                                bool verifemail();
                                void on_ajouter_citoyen_clicked();

                                void on_modifier_citoyen_clicked();

                                void on_supprimer_citoyen_clicked();


                                void on_tab_citoyen_activated(const QModelIndex &index);

                                void on_ajouter_petition_clicked();

                                void on_supprimer_petition_clicked();

                                void on_modifier_petition_clicked();

                                void on_ajouter_image_clicked();

                                void myfunctionn();
                                void on_nettoyer_4_clicked();

                                void supprimercitoyen();
                                void on_pdf_petition_clicked();

                                void on_recherche_citoyen_cursorPositionChanged(int arg1, int arg2);

                                void on_sendBtn_2_clicked();

                                void mailSent(QString status);
                                void on_browseBtn_2_clicked();

                                void on_pause_clicked();

                                void on_recherche_citoyen_editingFinished();

                                void on_play_2_clicked();



                                void on_home_clicked();

                                void on_pushButton_10_clicked();

                                void on_tab_petition_activated(const QModelIndex &index);

                                void on_pushButton_9_clicked();


                                void on_recherche_dynamique_textChanged(const QString &arg1);

                                void on_pushButton_facebook_clicked();
                                void on_pushButton_twitter_clicked();
                                void on_nettoyer_3_clicked();

                                void supprimerpetition();
                                bool veriftitre();
                                bool verifid();
                                bool verifauteur();
                                bool verifnbr();
                                bool verifvalidite();
                                bool verifdesc();
                                void on_email_pet_clicked();

                                void on_tri_citoyen_clicked();



                                void on_pushButton_notepad_clicked();





                                void on_pushButton_rech_eq_agent_clicked();

                                void on_ajouter_personne_clicked();

                                void on_modifier_personne_clicked();

                                void on_tab_personne_activated(const QModelIndex &index);

                                void on_supprimer_personne_clicked();






                                void on_lineEdit_textChanged(const QString &arg1);

                                void on_recherche_personne_clicked();

                                void on_ajouter_plainte_clicked();

                                void on_modifier_plainte_clicked();

                                void on_tab_plainte_activated(const QModelIndex &index);

                                void on_supprimer_plainte_clicked();

                                void on_tab_personne_clicked(const QModelIndex &index);

private:
                                int getIDFromTableView(QTableView * tv);
    Ui::integ_finale *ui;
    notePad *app;

    int b,aff;
    Equipement E;
    Plaintes T;
    Maintenance M;
    Detenu D;
    Cellule C;
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOpcionesMenu;
    QAction *mEncenderAction;
    QAction *mApagarAction;
    QAction *mCapturarAction;

    vehicule v;
    mission m;
    QString lng="fr";
    QMediaPlayer *click;
    QPropertyAnimation *animation;

    Cellule tmpcellule ;
    agent tmp_agent ;
    service tmp_service ;
    QString fileNameImage ;
    QPixmap photo ;
    QByteArray image;
    QPixmap pixmap;
    QByteArray array;
    QTimer * timerr ;
    QStringList files;
    QSound *son;
    QString currentFile="";
    QByteArray data; // variable contenant les données reçues
    Arduino A; // objet temporaire
    Personne P,p;
    Citoyen tmp_citoyen ;
        Petition tmp_petition ;

                QMediaPlayer * music = new QMediaPlayer();
                QPixmap PixTrueIcon;
                QPixmap PixFalseIcon;
                 int selcomemp=0,selcomco=0;
signals:
    void setCenter(QVariant,QVariant);


};
#endif // INTEG_FINALE_H
