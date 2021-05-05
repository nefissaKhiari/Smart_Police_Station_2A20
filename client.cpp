#include "vehicule.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
vehicule::vehicule()
{
  id_vehicule=0;marque_vehicule="";model_vehicule="";
}

vehicule::vehicule(int id_vehicule,QString marque_vehicule,QString model_vehicule)
{ this->id_vehicule=id_vehicule; this->marque_vehicule=marque_vehicule ; this->model_vehicule=model_vehicule;}
int vehicule::getid_vehicule(){return id_vehicule;}
QString vehicule::getmarque_vehicule(){return marque_vehicule;}
QString vehicule::getmodel_vehicule(){return model_vehicule;}
void vehicule::setid_vehicule(int id_vehicule){this->id_vehicule=id_vehicule;}
void vehicule::setmarque_vehicule(QString marque_vehicule){this->marque_vehicule=marque_vehicule;}
void vehicule::setmodel_vehicule(QString model_vehicule){this->model_vehicule=model_vehicule;}
bool vehicule::ajouter()
{
    QSqlQuery query;
  QString id_string=QString::number(id_vehicule);
    query.prepare("INSERT INTO vehicule (id_vehicule, marque_vehicule, model_vehicule) "
                  "VALUES (:id, :forename, :surname)");
    query.bindValue(":id_vehicule", id_string);
    query.bindValue(":forename", marque_vehicule);
    query.bindValue(":surname", model_vehicule);
    return query.exec();

}
bool vehicule::supprimer(int id_vehicule)
{
    QSqlQuery query;
    query.prepare("Delete from vehicule where id_vehicule= :id_vehicule");
    query.bindValue(":id_vehicule", id_vehicule);

    return query.exec();
}
QSqlQueryModel* vehicule::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM vehicule");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque_vehicule"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("model_vehicule"));
    return model;
}

/*int vehicule::rechercher(int)
{

}*/




