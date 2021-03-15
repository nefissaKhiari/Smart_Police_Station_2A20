#include "cellule.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Cellule::Cellule()
{
    id_cellule=0; type_cellule=""; nb_lits=0; superficie_cellule=0; nb_detenus=0;
}
Cellule::Cellule(int id_cellule,QString type_cellule,int nb_lits,int superficie_cellule , int nb_detenus )
{ this->id_cellule=id_cellule;
  this->type_cellule=type_cellule ;
  this->nb_lits=nb_lits;
  this->superficie_cellule=superficie_cellule ;
  this->nb_detenus=nb_detenus ;
}

int Cellule::getid_cellule(){return id_cellule;}
QString Cellule::gettype_cellule(){return type_cellule;}
int Cellule::getnb_lits(){return nb_lits;}
int Cellule::getsuperficie_cellule(){return superficie_cellule;}
int Cellule::getnb_detenus(){return nb_detenus;}

void Cellule::setid_cellule(int id_cellule){this->id_cellule=id_cellule;}
void Cellule::settype_cellule(QString type_cellule){this->type_cellule=type_cellule;}
void Cellule::setsuperficie_cellule(int superficie_cellule){this->superficie_cellule=superficie_cellule;}
void Cellule::setnb_lits(int nb_lits){this->nb_lits=nb_lits;}
void Cellule::setnb_detenus(int nb_detenus){this->nb_detenus=nb_detenus;}

bool Cellule::ajouter2()
{
    QSqlQuery query;
  QString id_cellule_string=QString::number(id_cellule);
    query.prepare("INSERT INTO cellule (id_cellule, type_cellule,nb_lits,superficie_cellule,nb_detenus) "
                  "VALUES (:id_cellule, :type_cellule,:nb_lits,:superficie_cellule,:nb_detenus)");
    query.bindValue(":id_cellule", id_cellule_string);
    query.bindValue(":type_cellule", type_cellule);
    query.bindValue(":nb_lits", nb_lits);
    query.bindValue(":superficie_cellule", superficie_cellule);
    query.bindValue(":nb_detenus", nb_detenus);

    return query.exec();

}

bool Cellule::supprimer2(int id_cellule)
{
    QSqlQuery query;
    query.prepare("Delete from Cellule where id_cellule= :id_cellule");
    query.bindValue(":id_cellule", id_cellule);

    return query.exec();
}
QSqlQueryModel* Cellule::afficher2()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM cellule");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id cellule"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type cellule"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nb lits"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Superficie cellule"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nb detenus"));
    return model;
}

