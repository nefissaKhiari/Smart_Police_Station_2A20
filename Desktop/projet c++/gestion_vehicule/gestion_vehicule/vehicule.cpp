#include "vehicule.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
vehicule::vehicule()
{
  id=0;marque="";model="";
}

vehicule::vehicule(int id,QString marque,QString model)
{ this->id=id; this->marque=marque ; this->model=model;}
int vehicule::getid(){return id;}
QString vehicule::getmarque(){return marque;}
QString vehicule::getmodel(){return model;}
void vehicule::setid(int id){this->id=id;}
void vehicule::setmarque(QString marque){this->marque=marque;}
void vehicule::setmodel(QString model){this->model=model;}



bool vehicule::ajouter()
{
    QSqlQuery query;
  QString id_string=QString::number(id);
    query.prepare("INSERT INTO vehicule (id, marque, model) "
                  "VALUES (:id, :forename, :surname)");
    query.bindValue(":id", id_string);
    query.bindValue(":forename", marque);
    query.bindValue(":surname", model);
    return query.exec();

}



bool vehicule::modifier_vehicule(int id,QString marque, QString model)
{
    QSqlQuery query;
    QString id_string=QString::number(id);


    query.prepare("update vehicule set id='"+id_string+"', marque='"+marque+"', model='"+model+"' where id=:id");
    query.bindValue(0, id_string);
    query.bindValue(1, marque);
    query.bindValue(2, model);

    return query.exec();
}

QSqlQueryModel* vehicule::afficher_vehicule()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM vehicule");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("model"));

    return model;
}




bool vehicule::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from vehicule where id= :id");
    query.bindValue(":id", id);

    return query.exec();
}


/*int vehicule::rechercher(int)
{

}*/


