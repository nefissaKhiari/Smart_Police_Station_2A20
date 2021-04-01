#ifndef agent_H
#define agent_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
class agent
{
public:
    agent();
     agent(int,QString,QString,QString,QString,QString,int,int,QString,QString);
     int getid_agent();
     QString getnom_agent();
     QString getprenom_agent();
     QString getdate_naissance_agent();
     QString getnationalite_agent();
     QString getsexe_agent();
     int gettaille_agent();
     int getpoids_agent();
     QString getperiode_agent();
     QString getdossier_agent();

     void setid_agent(int);
     void setnom_agent(QString);
     void setprenom_agent(QString);
     void setdate_naissance_agent(QString);
     void setnationalite_agent(QString);
     void setsexe_agent(QString);
     void settaille_agent(int);
     void setpoids_agent(int);
     void setperiode_agent(QString);
     void setdossier_agent(QString);

     bool ajouter_agent();
     QSqlQueryModel* afficher_agent();
     bool supprimer_agent(int);
      bool modifier_agent(int,QString,QString,QString,QString,QString,int,int,QString,QString);
private:
        int id_agent;
        QString nom_agent, prenom_agent,date_naissance_agent,nationalite_agent,sexe_agent,periode_agent,dossier_agent;
        int taille_agent,poids_agent;

};

#endif // agent_H
