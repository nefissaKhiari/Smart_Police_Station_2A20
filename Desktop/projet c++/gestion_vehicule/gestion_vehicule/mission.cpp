#include "mission.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
mission::mission()
{
  id=0;nbr_vehicule=0;
  nbr_policier=0;
  date_mission="";
}

mission::mission(int id,int nbr_vehicule,int nbr_policier,QString date_mission)
{ this->id=id; this->nbr_vehicule=nbr_vehicule; this->nbr_policier=nbr_policier; this->date_mission=date_mission ;}
int mission::getid(){return id;}
int mission::getnbr_vehicule(){return nbr_vehicule;}
int mission::getnbr_policier(){return nbr_policier;}
QString mission::getdate_mission(){return date_mission;}

void mission::setid(int id){this->id=id;}
void mission::setnbr_vehicule(int nbr_vehicule){this->nbr_vehicule=nbr_vehicule;}
void mission::setnbr_policier(int nbr_policier){this->nbr_policier=nbr_policier;}
void mission::setdate_mission(QString date_mission){this->date_mission=date_mission;}


bool mission::ajouter2()
{
    QSqlQuery query;
  QString id_string=QString::number(id);
   QString forename=QString::number(nbr_vehicule);
   QString surname=QString::number(nbr_policier);




  query.prepare("INSERT INTO mission (id, nbr_vehicule, nbr_policier,date_mission) "
                  "VALUES (:id, :nbr_vehicule, :nbr_policier, :date_mission)");
    query.bindValue(":id", id_string);
    query.bindValue(":nbr_vehicule",forename);
    query.bindValue(":nbr_policier",surname);
    query.bindValue(":date_mission",date_mission);
    return query.exec();

}
bool mission::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from mission where id= :id");
    query.bindValue(":id", id);

    return query.exec();
}
QSqlQueryModel* mission::afficher_mission()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM mission");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbr_vehicule"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("nbr_policier"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_mission"));
    return model;
}

/*int mission::rechercher(int)
{

}*/

bool mission::modifier_mission(int id ,int nbr_vehicule, int nbr_policier,QString date_mission )
{
    QSqlQuery query;
    QString id_string=QString::number(id) ;
    QString forename=QString::number(nbr_vehicule) ;

    QString surname=QString::number(nbr_policier);


    query.prepare("update mission set id='"+id_string+"',nbr_vehicule='"+forename+"',nbr_policier='"+surname+"',date_mission='"+date_mission+"' where id=:id");
    query.bindValue(0, id_string);

    query.bindValue(1, forename);
    query.bindValue(2,surname );
    query.bindValue(3, date_mission);

    return query.exec();
}



QSqlQueryModel* mission::tri_id()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from mission ORDER BY id ASC") ;
    query->exec() ;
    model->setQuery(*query) ;



    return model;

}
QSqlQueryModel* mission::tri_nbr_veh()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from mission ORDER BY  nbr_vehicule ASC ") ;
    query->exec() ;
    model->setQuery(*query) ;



    return model;

}

