#include "service.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>


service::service()
{

    id_service="";
    libelle_service="";
    agent_service="";
    date_service="";
    description_service="";
    genre_service="";
    nom_departement="";

}

service::service(QString id_service,QString libelle_service,QString agent_service,QString date_service,
                   QString description_service,QString genre_service,QString nom_departement)
{
    this->id_service=id_service;
    this->libelle_service=libelle_service ;
    this->agent_service=agent_service  ;
    this->date_service=date_service ;
    this->description_service=description_service ;
    this->genre_service=genre_service;
    this->nom_departement=nom_departement;

}

QString service::getid_service(){return id_service;}
QString service::getlibelle_service(){return libelle_service;}
QString service::getagent_service(){return agent_service;}
QString service::getdate_service(){return date_service;}
QString service::getdescription_service(){return description_service ;}
QString service::getgenre_service(){return genre_service;}
QString service::getnom_departement(){return nom_departement;}


void service::setid_service(QString id_service){this->id_service=id_service;}
void service::setlibelle_service(QString libelle_service){this->libelle_service=libelle_service;}
void service::setagent_service(QString agent_service){this->agent_service=agent_service;}
void service::setdate_service(QString date_service){this->date_service=date_service;}
void service::setdescription_service(QString description_service){this->description_service=description_service;}
void service::setgenre_service(QString genre_service){this->genre_service=genre_service;}
void service::setnom_departement(QString nom_departement){this->nom_departement=nom_departement;}





bool service::ajouter_service()
{
    QSqlQuery query;
    query.prepare("INSERT INTO service (id_service, libelle_service,agent_service,date_service,description_service,genre_service,nom_departement) ""VALUES (:id_service,:libelle_service,:agent_service,:date_service,:description_service,:genre_service, :nom_departement)");
    query.bindValue(":id_service",id_service);
    query.bindValue(":libelle_service",libelle_service);
    query.bindValue(":agent_service",agent_service);
    query.bindValue(":date_service",date_service);
    query.bindValue(":description_service",description_service);
    query.bindValue(":genre_service",genre_service);
    query.bindValue(":nom_departement",nom_departement);


    return query.exec();

}

bool service::modifier_service(QString id_service,QString libelle_service,QString agent_service,QString date_service, QString description_service,QString genre_service,QString nom_departement)
{  QSqlQuery query;



    query.prepare("update service set id_service='"+id_service+"', libelle_service='"+libelle_service+"',agent_service='"+agent_service+"',date_service='"+date_service+"',description_service='"+description_service+"',genre_service='"+genre_service+"',nom_departement='"+nom_departement+"' where id_service=:id_service");
    query.bindValue(0, id_service);
    query.bindValue(1, libelle_service);
    query.bindValue(2,agent_service );
    query.bindValue(3, date_service);
    query.bindValue(4, description_service);
    query.bindValue(5, genre_service);
    query.bindValue(6, nom_departement);

    return query.exec();
}


bool service::supprimer_service(QString id_service)
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
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id service"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle service"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("agent service"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date service"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("description service"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("genre service"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("nom_departement"));





    return model;
}

QSqlQueryModel* service::tri_id()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from service ORDER BY id_service") ;
    query->exec() ;
    model->setQuery(*query) ;



    return model;

}
QSqlQueryModel* service::tri_date()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from service ORDER BY date_service") ;
    query->exec() ;
    model->setQuery(*query) ;



    return model;

}

QSqlQueryModel * service::rechercher_id_service(QString valeur)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from service where id_service='"+valeur+"' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_service"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle_service"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("agent_service"));
    //  model->setHeaderData(3, Qt::Horizontal, QObject::tr("comboBox_agent"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_service"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("description_service"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("genre_service"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("nom_departement"));
        return model;
}


