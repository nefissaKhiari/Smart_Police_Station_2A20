#include "personne.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QString>
#include <QDate>
#include <QObject>
#include <QElapsedTimer>

Personne::Personne()
{
 id=0;
 nom="";
 prenom="";
 adresse="";
 datePersonne="";
 sexe="";
}


Personne::Personne(int id,QString nom,QString prenom,QString adresse,QString datePersonne,QString sexe)
{ this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->adresse=adresse;
  this->datePersonne=datePersonne;
  this->sexe=sexe;

 }

int Personne::get_id(){return id;}
QString Personne::get_nom(){return nom;}
QString Personne::get_prenom(){return prenom;}
QString Personne::get_adresse(){return adresse;}
QString Personne::get_date(){return datePersonne;}
QString Personne::get_sexe(){return sexe;}

void Personne::set_id(int id)
{this->id=id;}

bool Personne::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);



query.prepare("INSERT INTO personne(id,nom,prenom,adresse,datePersonne,sexe) "
                    "VALUES (:id, :nom, :prenom, :adresse, :datePersonne, :sexe)");
query.bindValue(0, res);
query.bindValue(1, nom);
query.bindValue(2, prenom);
query.bindValue(3, adresse);
query.bindValue(4, datePersonne);
query.bindValue(5, sexe);

return    query.exec();



}
QSqlQueryModel* Personne::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


       model->setQuery("select* from personne");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("personne"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("datePersonne"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));
    return model;
}

bool Personne::update(int id,QString nom,QString prenom,QString adresse,QString datePersonne,QString sexe)
{
   QSqlQuery query;
   QString res= QString::number(id);

 //  QDate dateFab=QDate::fromString(dateFabrication,"dd/MM/yyyy");


   query.prepare(" UPDATE personne SET id=:id,nom=:nom,prenom=:prenom, adresse=:adresse, datePersonne=:datePersonne, sexe=:sexe WHERE id=:id");
   /*query.bindValue(":res", res);
   query.bindValue(":nom", nom);
   query.bindValue(":prenom", prenom);
   query.bindValue(":adresse", adresse);
   query.bindValue(":datePersonne", datePersonne);
   query.bindValue(":sexe", sexe);*/
   query.bindValue(0, res);
      query.bindValue(1, nom);
      query.bindValue(2, prenom);
      query.bindValue(3, adresse);
      query.bindValue(4, datePersonne);
      query.bindValue(5, sexe);
    return query.exec();
}
bool Personne::supprimer(int id)
{
   QSqlQuery query;
   query.prepare("Delete from personne where id= :id");//preparer la req

   query.bindValue(0, id);


   return ((query.exec()));
}
QSqlQueryModel * Personne::rechercherPersonne(QString rech)
{
   QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select* from personne where id like '%"+rech+"%'");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("personne"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("datePersonne"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));


       return model;
}

QSqlQueryModel * Personne :: search (int type, QString key){
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    int k ;
    switch(type){
        case 0:

            k = key.toInt();
            query.prepare("Select * from PERSONNE where ID = :id");
            query.bindValue(":id", k);
           query.exec();
           model->setQuery(query);
           if(model->record(0).isEmpty() == true){ return model = nullptr;}
        break;
    case 1:

        query.prepare("Select * from PERSONNE where NOM = :modele");
        query.bindValue(":modele", key);
       query.exec();
       model->setQuery(query);
       if(model->record(0).isEmpty() == true){ return model = nullptr;}
        break;
    case 2:

        query.prepare("Select * from PERSONNE where ADRESSE = :achat");
        query.bindValue(":achat", key);
       query.exec();
       model->setQuery(query);
       if((model->record(0)).isEmpty() == true){return model = nullptr;}
        break;
    default:
        model = nullptr;
        break;
    }
    return model;
}


