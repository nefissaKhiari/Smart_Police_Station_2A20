#include "plaintes.h"

Plaintes::Plaintes()
{
  idp=0;
  raison="";
  datep="";
  type="";
  idpersonne=0;
}

Plaintes::Plaintes(int idp,QString raison,QString datep,QString type,int idpersonne)
{
    this->idp=idp;
      this->idpersonne=idpersonne;
      this->raison=raison;
      this->datep=datep;
      this->type=type;



}
//GETTERS
int Plaintes::get_id(){return idp;}
void Plaintes::set_id(int idp)
{this->idp=idp;}
int Plaintes::get_idpersonne(){return idpersonne;}

QString Plaintes::get_raison(){return raison;}

QString Plaintes::get_date(){return datep;}

QString Plaintes::get_type(){return type;}

bool Plaintes::ajouter()
{
QSqlQuery query;
QString res= QString::number(idp);

query.prepare("INSERT INTO PLAINTE (IDP,RAISON,DATEP,TYPE,IDPERSONNE) "
                    "VALUES (:idp, :raison, :datep, :type,:idpersonne )");
query.bindValue(0, res);
query.bindValue(1, raison);
query.bindValue(2, datep);
query.bindValue(3, type);
query.bindValue(4, idpersonne);



return    query.exec();
}

QSqlQueryModel * Plaintes::afficher(int aff)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * from plainte");



           model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_personne"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("raison"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));

        return model;
}

bool Plaintes::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from PLAINTE where IDP = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Plaintes::update(int idp,QString raison, QString dateP, QString type, int idpersonne)
{
    QSqlQuery query;
    QString res= QString::number(idp);

  query.prepare(" UPDATE plainte SET idp=:idp,raison=:raison,dateP=:dateP, type=:type, idpersonne=:idpersonne WHERE idp=:idp");

    query.bindValue(":idp", res);
       query.bindValue(":raison", raison);
       query.bindValue(":dateP", dateP);
       query.bindValue(":type", type);
       query.bindValue(":idpersonne", idpersonne);
       return query.exec();

}

QSqlQueryModel * Plaintes::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PLAINTE order by IDP asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDP"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("RAISON "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEP"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
    return model;
}

QSqlQueryModel * Plaintes::chercher(int id)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from PLAINTE WHERE IDP=:id"));

     query.bindValue(":id",id);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDP"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("RAISON "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEP"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));

return model;
 }
int Plaintes::rech(int id)
{

    QSqlQuery query;
        int count=0;
        bool test=0;
        QString num_string=QString::number(id);
        if(query.exec("select ID_R from PLAINTE where  IDP='" +num_string +"'"))
        {
        while(query.next())
            count++;
        if(count>=1)
            test=1;

        }
        return test;
}


