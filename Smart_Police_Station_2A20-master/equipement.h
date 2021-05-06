#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QString>
#include<QDate>
#include <qsqlquerymodel.h>
class Equipement
{
public:
   Equipement();//constructeur par defaut
   Equipement(int,int,int,QString,QString,QString,QString);//constructeur parametré

   int getIdEquipement();
   int getQuantiteEquipement();
   int getEtatEquipement();
   QString getNomEquipement();
   QString getTypeEquipement();
   QString getDateFabrication();
   QString getFkAgentEq();
   void setIdEquipement(int);
   void setQuantiteEquipement(int);
   void setEtatEquipement(int);
   void setNomEquipement(QString);
   void setTypeEquipement(QString);
   void setDateFabrication(QString);
   void setFkAgentEq(QString);

   bool ajouterEquipement();
   QSqlQueryModel* afficher();

  bool supprimer(int);
  bool modifier(int,QString,QString,int,int,QString,QString);
  QSqlQueryModel * tri_etat() ;
  QSqlQueryModel *tri_quantite();
  QSqlQueryModel *recherche_agent_equipement();
  QSqlQueryModel *recherche_agent_equipement2();
  QSqlQueryModel *rechercherEquipement(QString);

private:
   int idEquipement, quantiteEquipement,etatEquipement;
   QString nomEquipement, typeEquipement,dateFabrication,fk_agentEq;
   //QDate dateFabrication;
};

#endif // EQUIPEMENT_H

