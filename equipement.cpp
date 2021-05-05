#include "equipement.h"
#include "maintenance.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QString>
#include <QDate>
#include <QObject>
#include <QElapsedTimer>
Equipement::Equipement()
{
idEquipement=0;quantiteEquipement=0;etatEquipement=0;
nomEquipement="";typeEquipement="";dateFabrication="";

} //le role de ce constructeur est d'affecter les nouvelles valeurs inserer par l'utilisateur
Equipement::Equipement(int idEquipement,int quantiteEquipement, int etatEquipement,QString nomEquipement,QString typeEquipement,QString dateFabrication)
{ this->idEquipement=idEquipement;
  this->quantiteEquipement=quantiteEquipement;
  this->etatEquipement=etatEquipement;
  this->nomEquipement=nomEquipement;
  this->typeEquipement=typeEquipement;
  this->dateFabrication=dateFabrication;
 }
int Equipement:: getIdEquipement()
{ return idEquipement;}
int Equipement:: getQuantiteEquipement()
{return quantiteEquipement;}
int Equipement:: getEtatEquipement()
{ return etatEquipement; }
QString Equipement:: getNomEquipement()
{return nomEquipement ;}
QString Equipement:: getTypeEquipement()
{return  typeEquipement;}
QString Equipement:: getDateFabrication()
{ return  dateFabrication;}

void Equipement::setIdEquipement(int idEquipement)
{this->idEquipement=idEquipement;}
void Equipement::setQuantiteEquipement(int quantiteEquipement )
{ this->quantiteEquipement=quantiteEquipement;}
void Equipement::setEtatEquipement(int etatEquipement)
{ this->etatEquipement=etatEquipement;}
void Equipement::setNomEquipement(QString nomEquipement)
{ this->nomEquipement=nomEquipement;}
void Equipement::setTypeEquipement(QString typeEquipement)
{ this->typeEquipement=typeEquipement;}
void Equipement::setDateFabrication(QString dateFabrication)
{ this->dateFabrication=dateFabrication;}

bool Equipement::ajouterEquipement()
{
  QSqlQuery query;

   QString idEquipement_string=QString::number(idEquipement);
   QString quantiteEquipement_string=QString::number(quantiteEquipement);
   QString etatEquipement_string=QString::number(etatEquipement);
   QDate dateFab = QDate::fromString(dateFabrication,"dd/MM/yyyy");

   query.prepare("INSERT INTO equipement (idEquipement, nomEquipement, typeEquipement,quantiteEquipement,etatEquipement,dateFabrication) "
                 "VALUES (:idEquipement, :nomEquipement, :typeEquipement,:quantiteEquipement,:etatEquipement,:dateFab)");
   query.bindValue(0, idEquipement_string);
   query.bindValue(1, nomEquipement);
   query.bindValue(2, typeEquipement);
   query.bindValue(3,quantiteEquipement_string );
   query.bindValue(4, etatEquipement_string);
   query.bindValue(5, dateFab);
   return query.exec();

}
QSqlQueryModel* Equipement::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery(" SELECT* FROM equipement");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantité"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("DateFabrication"));



 return model;

}

bool Equipement::supprimer(int idEquipement)
{
   QSqlQuery query;
   query.prepare("Delete from equipement where idEquipement= :idEquipement");//preparer la req

   query.bindValue(0, idEquipement);


   return ((query.exec()));
}

bool Equipement::modifier(int idEquipement,QString nomEquipement,QString typeEquipement,int quantiteEquipement,int etatEquipement,QString dateFabrication )
{
   QSqlQuery query;
   QString idEq=QString::number(idEquipement) ;
   QString qEq=QString::number(quantiteEquipement);
   QString eEq=QString::number(etatEquipement);

   QDate dateFab=QDate::fromString(dateFabrication,"dd/MM/yyyy");


   query.prepare("UPDATE equipement set idEquipement=:idEquipement,nomEquipement=:nomEquipement,typeEquipement=:typeEquipement,quantiteEquipement=:quantiteEquipement , etatEquipement=:etatEquipement,dateFabrication=:dateFabrication WHERE idEquipement=:idEquipement");
   query.bindValue(":idEquipement", idEq);
   query.bindValue(":nomEquipement", nomEquipement);
   query.bindValue(":typeEquipement", typeEquipement);
   query.bindValue(":quantiteEquipement",qEq );
   query.bindValue(":etatEquipement", eEq);
   query.bindValue(":dateFabrication",dateFab);
    return query.exec();
}
QSqlQueryModel* Equipement::tri_quantite()
{
   QSqlQueryModel* model=new QSqlQueryModel() ;
   QSqlQuery *query=new QSqlQuery;
   query->prepare("select * from equipement ORDER BY quantiteEquipement") ;
   query->exec() ;
   model->setQuery(*query);



   return model;

}
QSqlQueryModel* Equipement::tri_etat()// tri
{
   QSqlQueryModel* model=new QSqlQueryModel() ;
   QSqlQuery *query=new QSqlQuery;
   query->prepare("select * from equipement ORDER BY etatEquipement") ;
   query->exec() ;
   model->setQuery(*query) ;



   return model;

}
QSqlQueryModel * Equipement::rechercherEquipement(QString rech)
{
   QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from equipement where idEquipement like '%"+rech+"%' ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantité"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("DateFabrication"));


       return model;
}




