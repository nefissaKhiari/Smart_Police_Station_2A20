#ifndef DETENU_H
#define DETENU_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
class Detenu
{
public:
    Detenu();
     Detenu(int,QString,QString,QString,QString,QString,int,int,QString,QString);
     int getid_detenu();
     QString getnom_detenu();
     QString getprenom_detenu();
     QString getdate_naissance_detenu();
     QString getnationalite_detenu();
     QString getsexe_detenu();
     int gettaille_detenu();
     int getpoids_detenu();
     QString getperiode_detenu();
     QString getdossier_detenu();
    // int getid_cellule();

     void setid_detenu(int);
     void setnom_detenu(QString);
     void setprenom_detenu(QString);
     void setdate_naissance_detenu(QString);
     void setnationalite_detenu(QString);
     void setsexe_detenu(QString);
     void settaille_detenu(int);
     void setpoids_detenu(int);
     void setperiode_detenu(QString);
     void setdossier_detenu(QString);
  //  void setid_cellule(int);

     bool ajouter_detenu();
     QSqlQueryModel* afficher_detenu();//lecture les ensembles des resultats SQl
     bool supprimer_detenu(int);
      bool modifier_detenu(int,QString,QString,QString,QString,QString,int,int,QString,QString);

private:
        int id_detenu/*,id_cellule*/;
        QString nom_detenu, prenom_detenu,date_naissance_detenu,nationalite_detenu,sexe_detenu,periode_detenu,dossier_detenu;
        int taille_detenu,poids_detenu;

};

#endif // DETENU_H
