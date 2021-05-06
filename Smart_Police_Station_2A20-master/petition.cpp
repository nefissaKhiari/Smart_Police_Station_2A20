#include "petition.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>


Petition::Petition()
{

    id_petition="";
    titre_petition="";
    auteur_petition="";
    date_petition="";
    description_petition="";
    validite_petition="";
    nbr_signatures_requis="";

}

Petition::Petition(QString id_petition,QString titre_petition,QString auteur_petition,QString date_petition,
                   QString description_petition,QString validite_petition,QString nbr_signatures_requis)
{
    this->id_petition=id_petition;
    this->titre_petition=titre_petition ;
    this->auteur_petition=auteur_petition  ;
    this->date_petition=date_petition ;
    this->description_petition=description_petition ;
    this->validite_petition=validite_petition;
    this->nbr_signatures_requis=nbr_signatures_requis;

}

QString Petition::getid_petition(){return id_petition;}
QString Petition::gettitre_petition(){return titre_petition;}
QString Petition::getauteur_petition(){return auteur_petition;}
QString Petition::getdate_petition(){return date_petition;}
QString Petition::getdescription_petition(){return description_petition ;}
QString Petition::getvalidite_petition(){return validite_petition;}
QString Petition::getnbr_signatures_requis(){return nbr_signatures_requis;}


void Petition::setid_petition(QString id_petition){this->id_petition=id_petition;}
void Petition::settitre_petition(QString titre_petition){this->titre_petition=titre_petition;}
void Petition::setauteur_petition(QString auteur_petition){this->auteur_petition=auteur_petition;}
void Petition::setdate_petition(QString date_petition){this->date_petition=date_petition;}
void Petition::setdescription_petition(QString description_petition){this->description_petition=description_petition;}
void Petition::setvalidite_petition(QString validite_petition){this->validite_petition=validite_petition;}
void Petition::setnbr_signatures_requis(QString nbr_signatures_requis){this->nbr_signatures_requis=nbr_signatures_requis;}





bool Petition::ajouter_petition()
{
    QSqlQuery query;
    query.prepare("INSERT INTO petition (id_petition, titre_petition,auteur_petition,date_petition,description_petition,validite_petition,nbr_signatures_requis) "
                  "VALUES (:id_petition,:titre_petition,:auteur_petition,:date_petition,:description_petition,:validite_petition,:nbr_signatures_requis)");
    query.bindValue(":id_petition",id_petition);
    query.bindValue(":titre_petition",titre_petition);
    query.bindValue(":auteur_petition",auteur_petition);
    query.bindValue(":date_petition",date_petition);
    query.bindValue(":description_petition",description_petition);
    query.bindValue(":validite_petition",validite_petition);
    query.bindValue(":nbr_signatures_requis",nbr_signatures_requis);


    return query.exec();

}

bool Petition::modifier_petition(QString id_petition,QString titre_petition,QString auteur_petition,QString date_petition,
                                 QString description_petition,QString validite_petition,QString nbr_signatures_requis)
{  QSqlQuery query;



    query.prepare("update PETITION set id_petition='"+id_petition+"', titre_petition='"+titre_petition+"',auteur_petition='"+auteur_petition+"',date_petition='"+date_petition+"',description_petition='"+description_petition+"',validite_petition='"+validite_petition+"',nbr_signatures_requis='"+nbr_signatures_requis+"' where id_petition=:id_petition");
    query.bindValue(0, id_petition);
    query.bindValue(1, titre_petition);
    query.bindValue(2,auteur_petition );
    query.bindValue(3, date_petition);
    query.bindValue(4, description_petition);
    query.bindValue(5, validite_petition);
    query.bindValue(6, nbr_signatures_requis);

    return query.exec();
}


bool Petition::supprimer_petition(QString id_petition)
{
    QSqlQuery query;
    query.prepare("Delete from petition where id_petition= :id_petition");
    query.bindValue(":id_petition", id_petition);

    return query.exec();
}

QSqlQueryModel* Petition::afficher_petition()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM petition");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id petition"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre petition"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("auteur petition"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date petition"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("description petition"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("validite petition"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("nbr_signatures_requis"));





    return model;
}
QSqlQueryModel * Petition::rechercheDynamic(QString SearchName)
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * from PETITION where titre_petition LIKE '"+SearchName+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_petition"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre_petition"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("auteur_petition"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_petition"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("description_petition"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("validite_petition"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("nbr_signatures_requis"));

    return  model;
}



