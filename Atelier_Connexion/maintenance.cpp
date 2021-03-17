#include "maintenance.h"
#include<QSqlQuery>
#include<QtDebug>
#include <QString>
#include <QObject>

maintenance::maintenance()
{
 idMaintenance=0;frais=0;
}
maintenance::maintenance(int idMaintenance,QString dureeMaintenance ,QString dateEntreeM,QString dateSortieM,int frais)
{ this->idMaintenance=idMaintenance;
  this->dureeMaintenance=dureeMaintenance;
  this->dateEntreeM=dateEntreeM;
  this->dateSortieM=dateSortieM;
  this->frais=frais;
}
int maintenance:: getIdMaintenance()
{return idMaintenance ;}
QString maintenance:: getDureeMaintenance()
{return dureeMaintenance ;}
QString maintenance:: getDateEntreeM()
{return dateEntreeM;}
QString maintenance:: getDateSortieM()
{return dateSortieM ;}
int maintenance:: getFraisMaintenance()
{return frais;}

void maintenance::setIdMaintenance(int idMaintenance)
{this->idMaintenance=idMaintenance;}

void maintenance::setDureeMaintenance(QString dureeMaintenance)
{this->dureeMaintenance=dureeMaintenance ;}

void maintenance::setDateEntreeM(QString dateEntreeM)
{  this->dateEntreeM=dateEntreeM;}

void maintenance::setDateSortieM(QString dateSortieM)
{this->dateSortieM=dateSortieM;}

void maintenance::setFraisMaintenance(int frais)
{this->frais=frais;}


bool maintenance::ajouterMaintenance()
{
   QSqlQuery query;

    QString idMaintenance_string=QString::number(idMaintenance);
    QString frais_string=QString::number(frais);


    query.prepare("INSERT INTO  maintenance(idMaintenance, dureeMaintenance, dateEntreeM,dateSortieM,frais) "
                  "VALUES (:idMaintenance, :dureeMaintenance, :dateEntreeM,:dateSortieM,:frais)");
    query.bindValue(0, idMaintenance_string);
    query.bindValue(1, dureeMaintenance);
    query.bindValue(2, dateEntreeM);
    query.bindValue(3,dateSortieM );
    query.bindValue(4, frais_string);

    return query.exec();

}

QSqlQueryModel* maintenance::afficherMaintenance()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery(" SELECT* FROM maintenance");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("duree"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date entree"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date sortie"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("frais"));




  return model;

}

bool maintenance::supprimerMaintenance(int idMaintenance)
{
    QSqlQuery query;
    query.prepare("Delete from maintenance where idMaintenance= :idMaintenance");//preparer la req
    query.bindValue(0, idMaintenance);

    return ((query.exec()));
}






