#include "service.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>


service::service()
{

    id_service="";
    titre_service="";
    auteur_service="";
    date_service="";
    description_service="";
    validite_service="";
    nbr_signatures_requis="";

}

service::service(QString id_service,QString titre_service,QString auteur_service,QString date_service,
                   QString description_service,QString validite_service,QString nbr_signatures_requis)
{
    this->id_service=id_service;
    this->titre_service=titre_service ;
    this->auteur_service=auteur_service  ;
    this->date_service=date_service ;
    this->description_service=description_service ;
    this->validite_service=validite_service;
    this->nbr_signatures_requis=nbr_signatures_requis;

}

QString service::getid_service(){return id_service;}
QString service::gettitre_service(){return titre_service;}
QString service::getauteur_service(){return auteur_service;}
QString service::getdate_service(){return date_service;}
QString service::getdescription_service(){return description_service ;}
QString service::getvalidite_service(){return validite_service;}
QString service::getnbr_signatures_requis(){return nbr_signatures_requis;}


void service::setid_service(QString id_service){this->id_service=id_service;}
void service::settitre_service(QString titre_service){this->titre_service=titre_service;}
void service::setauteur_service(QString auteur_service){this->auteur_service=auteur_service;}
void service::setdate_service(QString date_service){this->date_service=date_service;}
void service::setdescription_service(QString description_service){this->description_service=description_service;}
void service::setvalidite_service(QString validite_service){this->validite_service=validite_service;}
void service::setnbr_signatures_requis(QString nbr_signatures_requis){this->nbr_signatures_requis=nbr_signatures_requis;}





bool service::ajouter_service()
{
    QSqlQuery query;
    query.prepare("INSERT INTO service (id_service, titre_service,auteur_service,date_service,description_service,validite_service) ""VALUES (:id_service,:titre_service,:auteur_service,:date_service,:description_service,:validite_service)");
    query.bindValue(":id_service",id_service);
    query.bindValue(":titre_service",titre_service);
    query.bindValue(":auteur_service",auteur_service);
    query.bindValue(":date_service",date_service);
    query.bindValue(":description_service",description_service);
    query.bindValue(":validite_service",validite_service);
    query.bindValue(":nbr_signatures_requis",nbr_signatures_requis);


    return query.exec();

}

bool service::modifier_service(QString id_service,QString titre_service,QString auteur_service,QString date_service, QString description_service,QString validite_service,QString nbr_signatures_requis)
{  QSqlQuery query;



    query.prepare("update service set id_service='"+id_service+"', titre_service='"+titre_service+"',auteur_service='"+auteur_service+"',date_service='"+date_service+"',description_service='"+description_service+"',validite_service='"+validite_service+"',nbr_signatures_requis='"+nbr_signatures_requis+"' where id_service=:id_service");
    query.bindValue(0, id_service);
    query.bindValue(1, titre_service);
    query.bindValue(2,auteur_service );
    query.bindValue(3, date_service);
    query.bindValue(4, description_service);
    query.bindValue(5, validite_service);
    query.bindValue(6, nbr_signatures_requis);

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
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre service"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("auteur service"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date service"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("description service"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("validite service"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("nbr_signatures_requis"));





    return model;
}


