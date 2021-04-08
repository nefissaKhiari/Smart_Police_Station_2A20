#include "service.h"
#include<QString>
service::service()
{
poste ="";
prix_h =0;
id_service=0;
}
service::service(QString poste,int prix_h,int id_service)
{

    this->poste=poste;
    this->prix_h=prix_h;
    this->id_service=id_service;


}
QString service::get_poste(){return poste;}
int   service::get_prix_h(){return prix_h;}
int service::get_id_service(){return id_service;}
bool service::ajouter_service(QString poste,int prix_h,int id_service)
{
    {
    QSqlQuery query;
    query.prepare("INSERT INTO service (poste,prix_h,id_service) "
                        "VALUES (:poste,:prix_h,:id_service)");
    query.bindValue(":poste", poste);
    query.bindValue(":prix_h",prix_h);
    query.bindValue(":id_service",id_service);

    return    query.exec();
    }
}
QSqlQueryModel * service::afficher_service()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from service");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("poste"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix_h"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_service"));
    return model;
}
bool service::supprimer_service(int id_service)
{


    QSqlQuery query;
        query.prepare("Delete from service where id_service=:id_service");
        query.bindValue(":id_service",id_service);
        return query.exec();

}
bool service::modifier(int id_service,int prix_h,QString poste)
{
    QSqlQuery query ;


                    query.prepare("update service set POSTE=:poste,PRIX_H=:prix_h where ID_service=:id_service");
                    query.bindValue (":poste",poste);
                    query.bindValue (":prix_h",prix_h);
                    query.bindValue(":id_service",id_service);
            return  query.exec();

    }
QSqlQueryModel * service::tri(int index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
        if(index == 0)
        {
            model->setQuery("select *FROM service ORDER BY ref ASC");
        }
        else
        {
            model->setQuery("select *FROM  service ORDER BY ref DESC ");
        }

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("poste"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix_h"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_service"));
            return model;
}


