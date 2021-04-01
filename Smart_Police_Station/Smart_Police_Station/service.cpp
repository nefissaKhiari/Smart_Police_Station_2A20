#include "service.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
service::service()
{
    id_service=0; type_service=""; nb_agentss=0; superficie_service=0; nb_agents=0;
}
service::service(int id_service,QString type_service,int nb_agentss,int superficie_service , int nb_agents )
{ this->id_service=id_service;
  this->type_service=type_service ;
  this->nb_agentss=nb_agentss;
  this->superficie_service=superficie_service ;
  this->nb_agents=nb_agents ;
}

int service::getid_service(){return id_service;}
QString service::gettype_service(){return type_service;}
int service::getnb_agentss(){return nb_agentss;}
int service::getsuperficie_service(){return superficie_service;}
int service::getnb_agents(){return nb_agents;}

void service::setid_service(int id_service){this->id_service=id_service;}
void service::settype_service(QString type_service){this->type_service=type_service;}
void service::setsuperficie_service(int superficie_service){this->superficie_service=superficie_service;}
void service::setnb_agentss(int nb_agentss){this->nb_agentss=nb_agentss;}
void service::setnb_agents(int nb_agents){this->nb_agents=nb_agents;}


bool service::ajouter_service()
{
    QSqlQuery query;
  QString id_service_string=QString::number(id_service);
  QString nb_agentss_string=QString::number(nb_agentss);
  QString sup_service=QString::number(superficie_service);
  QString nb_agents_string=QString::number(nb_agents);

    query.prepare("INSERT INTO service (id_service, type_service,nb_agentss,superficie_service,nb_agents) "
                  "VALUES (:id_service, :type_service,:nb_agentss,:superficie_service,:nb_agents)");
    query.bindValue(":id_service", id_service_string);
    query.bindValue(":type_service", type_service);
    query.bindValue(":nb_agentss", nb_agentss_string);
    query.bindValue(":superficie_service", sup_service);
    query.bindValue(":nb_agents", nb_agents_string);

    return query.exec();

}

bool service::supprimer_service(int id_service)
{
    QSqlQuery query;
    query.prepare("Delete from service where id_service= :id_service");
    query.bindValue(":id_service", id_service);
    return query.exec();
}
QSqlQueryModel* service::afficher_service()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM service");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id service"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type service"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nb agentss"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Superficie service"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nb agents"));
    return model;
}
bool service::modifier_service(int id_service,QString type_service,int nb_agentss , int superficie_service,int nb_agents )
{
    QSqlQuery query;
    QString id_service_string=QString::number(id_service) ;
    QString nb_agentss_string=QString::number(nb_agentss) ;
    QString sup_service=QString::number(superficie_service);
    QString nb_agents_string=QString::number(nb_agents);


    query.prepare("update service set id_service='"+id_service_string+"', type_service='"+type_service+"',nb_agentss='"+nb_agentss_string+"',superficie_service='"+sup_service+"',nb_agents='"+nb_agents_string+"' where id_service=:id_service");
    query.bindValue(0, id_service_string);
    query.bindValue(1, type_service);
    query.bindValue(2, nb_agentss_string);
    query.bindValue(3,sup_service );
    query.bindValue(4, nb_agents_string);

    return query.exec();
}

QSqlQueryModel* service::tri_nb_agents()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from service order by nb_agents asc") ;
    query->exec() ;
    model->setQuery(*query) ;



    return model;

}
QSqlQueryModel* service::tri_id_service()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from service order by id_service asc") ;
    query->exec() ;
    model->setQuery(*query) ;



    return model;

}
QSqlQueryModel* service::tri_nb_agentss()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from service order by nb_agentss asc") ;
    query->exec() ;
    model->setQuery(*query) ;



    return model;

}
/*
QSqlQueryModel * service::tri_service()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from service order by nb_agents asc;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id service"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type service"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nb agentss"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Superficie service"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nb agents"));
        return model;
}*/

QSqlQueryModel * service::rechercher_service(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from service where id_service='"+rech+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id service"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type service"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nb agentss"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Superficie service"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nb agents"));
        return model;
}

/*bool service::recherche_id_service(QString valeur)
{
    QSqlQuery query;

    query.prepare("Select * from service id_service=:id_service");
    query.bindValue(":id_service",valeur);
    if (query.exec())
    {
        while (query.next()){

            //            qDebug()<<"find";
            this -> id_service = (query.value(0).toInt());
            this -> type_service = (query.value(1).toString());
            this -> nb_agentss =(query.value(2).toInt());
            this -> superficie_service = (query.value(3).toInt());
            this -> nb_agents = (query.value(4).toInt());

        }

    }
    return query.exec();
}

bool service::recherche_type_service(QString valeur)
{
    QSqlQuery query;

    query.prepare("Select * from service where type_service=:type_service");
    query.bindValue(":type_service",valeur);
    if (query.exec())
    {
        while (query.next()){

            //            qDebug()<<"find";
            this -> id_service = (query.value(0).toInt());
            this -> type_service = (query.value(1).toString());
            this -> nb_agentss =(query.value(2).toInt());
            this -> superficie_service = (query.value(3).toInt());
            this -> nb_agents = (query.value(4).toInt());
        }
    }

    return query.exec();
}

bool service::recherche_nb_agents(QString valeur)
{
    QSqlQuery query;

    query.prepare("Select * from service where nb_agents=:nb_agents");
    query.bindValue(":nb_agents",valeur);
    if (query.exec())
    {
        while (query.next()){

            //            qDebug()<<"find";
            this -> id_service = (query.value(0).toInt());
            this -> type_service = (query.value(1).toString());
            this -> nb_agentss =(query.value(2).toInt());
            this -> superficie_service = (query.value(3).toInt());
            this -> nb_agents = (query.value(4).toInt());
        }
    }
    return query.exec();

}*/

