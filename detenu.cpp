#include "detenu.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
Detenu::Detenu()
{
id_detenu=0;
nom_detenu="";
prenom_detenu="";
date_naissance_detenu="";
nationalite_detenu="";sexe_detenu="";periode_detenu="";dossier_detenu="";
taille_detenu=0;
poids_detenu=0;
//id_cellule=0;

}

Detenu::Detenu(int id_detenu,QString nom_detenu,QString prenom_detenu,QString date_naissance_detenu,QString nationalite_detenu ,QString sexe_detenu ,int taille_detenu,int poids_detenu,QString periode_detenu,QString dossier_detenu/*int id_cellule*/)
{ this->id_detenu=id_detenu;
this->nom_detenu=nom_detenu ;
this->prenom_detenu=prenom_detenu;
this->date_naissance_detenu=date_naissance_detenu  ;
this->nationalite_detenu=nationalite_detenu ;
this->sexe_detenu=sexe_detenu ;
this->taille_detenu=taille_detenu;
this-> poids_detenu= poids_detenu;
this->periode_detenu=periode_detenu ;
this->dossier_detenu=dossier_detenu ;
//this->id_cellule=id_cellule ;
}

int Detenu::getid_detenu(){return id_detenu;};
QString Detenu::getnom_detenu(){return nom_detenu;};
QString Detenu::getprenom_detenu(){return prenom_detenu;};
QString Detenu::getdate_naissance_detenu(){return date_naissance_detenu;};
QString Detenu::getnationalite_detenu(){return nationalite_detenu;};
QString Detenu::getsexe_detenu(){return sexe_detenu;};
int Detenu::gettaille_detenu(){return taille_detenu;};
int Detenu::getpoids_detenu(){return poids_detenu;};
QString Detenu::getperiode_detenu(){return periode_detenu ;};
QString Detenu::getdossier_detenu(){return dossier_detenu ;};
//int Detenu::getid_cellule(){return id_cellule;};

void Detenu::setid_detenu(int id_detenu){this->id_detenu=id_detenu;}
void Detenu::setnom_detenu(QString nom_detenu){this->nom_detenu=nom_detenu;}
void Detenu::setprenom_detenu(QString prenom_detenu){this->prenom_detenu=prenom_detenu;}
void Detenu::setdate_naissance_detenu(QString date_naissance_detenu){this->date_naissance_detenu=date_naissance_detenu;}
void Detenu::setnationalite_detenu(QString nationalite_detenu){this->nationalite_detenu=nationalite_detenu;}
void Detenu::setsexe_detenu(QString sexe_detenu){this->sexe_detenu=sexe_detenu;}
void Detenu::settaille_detenu(int taille_detenu){this->taille_detenu=taille_detenu;}
void Detenu::setpoids_detenu(int poids_detenu){this->poids_detenu=poids_detenu;}
void Detenu::setperiode_detenu(QString periode_detenu){this->periode_detenu=periode_detenu;}
void Detenu::setdossier_detenu(QString dossier_detenu){this->nom_detenu=dossier_detenu;}
//void Detenu::setid_cellule(int id_cellule){this->id_cellule=id_cellule;}


bool Detenu::ajouter_detenu()
{
    QSqlQuery query;
  QString id_detenu_string=QString::number(id_detenu);
  QString taille_detenu_string=QString::number(taille_detenu);
  QString poids_detenu_string=QString::number(poids_detenu);
 // QString id_cellule_string=QString::number(id_cellule);
    query.prepare("INSERT INTO detenu (id_detenu, nom_detenu, prenom_detenu,date_naissance_detenu,nationalite_detenu,sexe_detenu,taille_detenu,poids_detenu,periode_detenu,dossier_detenu) "
                  "VALUES (:id_detenu, :nom_detenu, :prenom_detenu,:date_naissance_detenu,:nationalite_detenu,:sexe_detenu,:taille_detenu,:poids_detenu,:periode_detenu,:dossier_detenu)");
    query.bindValue(":id_detenu", id_detenu_string);
    query.bindValue(":nom_detenu", nom_detenu);
    query.bindValue(":prenom_detenu", prenom_detenu);
    query.bindValue(":date_naissance_detenu", date_naissance_detenu);
    query.bindValue(":nationalite_detenu",nationalite_detenu);
    query.bindValue(":sexe_detenu",sexe_detenu);
    query.bindValue(":taille_detenu",taille_detenu_string);
    query.bindValue(":poids_detenu",poids_detenu_string);
    query.bindValue(":periode_detenu",periode_detenu);
    query.bindValue(":dossier_detenu",dossier_detenu);

    return query.exec();

}

bool Detenu::modifier_detenu(int id_detenu,QString nom_detenu,QString prenom_detenu,QString date_naissance_detenu,QString nationalite_detenu ,QString sexe_detenu,int taille_detenu,int poids_detenu,QString periode_detenu,QString dossier_detenu )
{
    QSqlQuery query;
    QString id_detenu_string=QString::number(id_detenu);
    QString taille_detenu_string=QString::number(taille_detenu);
    QString poids_detenu_string=QString::number(poids_detenu);
   // QString id_cellule_string=QString::number(id_cellule);

    query.prepare("update detenu set id_detenu='"+id_detenu_string+"', nom_detenu='"+nom_detenu+"',prenom_detenu='"+prenom_detenu+"',date_naissance_detenu='"+date_naissance_detenu+"',nationalite_detenu='"+nationalite_detenu+"',sexe_detenu='"+sexe_detenu+"',taille_detenu='"+taille_detenu_string+"',poids_detenu='"+poids_detenu_string+"',periode_detenu='"+periode_detenu+"',dossier_detenu='"+dossier_detenu+"' where id_detenu=:id_detenu");
    query.bindValue(0, id_detenu_string);
    query.bindValue(1, nom_detenu);
    query.bindValue(2, prenom_detenu);
    query.bindValue(3,date_naissance_detenu );
    query.bindValue(4, nationalite_detenu);
    query.bindValue(5, sexe_detenu);
    query.bindValue(6, taille_detenu_string);
    query.bindValue(7, poids_detenu_string);
    query.bindValue(8, periode_detenu);
    query.bindValue(9, dossier_detenu);
   // query.bindValue(10, id_cellule_string);
    return query.exec();
}
bool Detenu::supprimer_detenu(int id_detenu)
{
    QSqlQuery query;
    query.prepare("Delete from Detenu where id_detenu= :id_detenu");
    query.bindValue(":id_detenu", id_detenu);

    return query.exec();
}

QSqlQueryModel* Detenu::afficher_detenu()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM detenu");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id detenu"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom detenu"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom detenu"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance detenu"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nationalite detenu"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe detenu"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Taille detenu"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("Poids detenu"));
         model->setHeaderData(8, Qt::Horizontal, QObject::tr("Periode detenu"));
         model->setHeaderData(9, Qt::Horizontal, QObject::tr("Dossier detenu"));
         //model->setHeaderData(10, Qt::Horizontal, QObject::tr("Id Cellule"));


    return model;
}


