#include "cellule.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Cellule::Cellule()
{
    id_cellule=0; type_cellule=""; nb_lits=0; superficie_cellule=0; nb_detenus=0;
}
Cellule::Cellule(int id_cellule,QString type_cellule,int nb_lits,int superficie_cellule , int nb_detenus )
{ this->id_cellule=id_cellule;
  this->type_cellule=type_cellule ;
  this->nb_lits=nb_lits;
  this->superficie_cellule=superficie_cellule ;
  this->nb_detenus=nb_detenus ;
}

int Cellule::getid_cellule(){return id_cellule;}
QString Cellule::gettype_cellule(){return type_cellule;}
int Cellule::getnb_lits(){return nb_lits;}
int Cellule::getsuperficie_cellule(){return superficie_cellule;}
int Cellule::getnb_detenus(){return nb_detenus;}

void Cellule::setid_cellule(int id_cellule){this->id_cellule=id_cellule;}
void Cellule::settype_cellule(QString type_cellule){this->type_cellule=type_cellule;}
void Cellule::setsuperficie_cellule(int superficie_cellule){this->superficie_cellule=superficie_cellule;}
void Cellule::setnb_lits(int nb_lits){this->nb_lits=nb_lits;}
void Cellule::setnb_detenus(int nb_detenus){this->nb_detenus=nb_detenus;}


bool Cellule::ajouter2()
{
    QSqlQuery query;
  QString id_cellule_string=QString::number(id_cellule);
  QString nb_lits_string=QString::number(nb_lits);
  QString sup_cellule=QString::number(superficie_cellule);
  QString nb_detenus_string=QString::number(nb_detenus);

    query.prepare("INSERT INTO cellule (id_cellule, type_cellule,nb_lits,superficie_cellule,nb_detenus) "
                  "VALUES (:id_cellule, :type_cellule,:nb_lits,:superficie_cellule,:nb_detenus)");
    query.bindValue(":id_cellule", id_cellule_string);
    query.bindValue(":type_cellule", type_cellule);
    query.bindValue(":nb_lits", nb_lits_string);
    query.bindValue(":superficie_cellule", sup_cellule);
    query.bindValue(":nb_detenus", nb_detenus_string);

    return query.exec();

}

bool Cellule::supprimer2(int id_cellule)
{
    QSqlQuery query;
    query.prepare("Delete from Cellule where id_cellule= :id_cellule");
    query.bindValue(id_cellule, id_cellule);
    return query.exec();
}
QSqlQueryModel* Cellule::afficher2()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM cellule");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id cellule"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type cellule"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nb lits"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Superficie cellule"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nb detenus"));
    return model;
}
bool Cellule::modifier_cellule(int id_cellule,QString type_cellule,int nb_lits , int superficie_cellule,int nb_detenus )
{
    QSqlQuery query;
    QString id_cellule_string=QString::number(id_cellule) ;
    QString nb_lits_string=QString::number(nb_lits) ;
    QString sup_cellule=QString::number(superficie_cellule);
    QString nb_detenus_string=QString::number(nb_detenus);


    query.prepare("update cellule set id_cellule='"+id_cellule_string+"', type_cellule='"+type_cellule+"',nb_lits='"+nb_lits_string+"',superficie_cellule='"+sup_cellule+"',nb_detenus='"+nb_detenus_string+"' where id_cellule=:id_cellule");
    query.bindValue(0, id_cellule_string);
    query.bindValue(1, type_cellule);
    query.bindValue(2, nb_lits_string);
    query.bindValue(3,sup_cellule );
    query.bindValue(4, nb_detenus_string);

    return query.exec();
}

QSqlQueryModel* Cellule::tri_nb_detenus()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from cellule order by nb_detenus asc") ;
    query->exec() ;
    model->setQuery(*query) ;



    return model;

}
QSqlQueryModel* Cellule::tri_id_cellule()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from cellule order by id_cellule asc") ;
    query->exec() ;
    model->setQuery(*query) ;



    return model;

}
QSqlQueryModel* Cellule::tri_nb_lits()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from cellule order by nb_lits asc") ;
    query->exec() ;
    model->setQuery(*query) ;



    return model;

}
/*
QSqlQueryModel * Cellule::tri_cellule()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from cellule order by nb_detenus asc;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id cellule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type cellule"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nb lits"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Superficie cellule"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nb detenus"));
        return model;
}*/

/*QSqlQueryModel * Cellule::rechercher_cellule(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from cellule where id_cellule='"+rech+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id cellule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type cellule"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nb lits"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Superficie cellule"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nb detenus"));
        return model;
}*/

bool Cellule::recherche_id_cellule(QString valeur)
{
    QSqlQuery query;

    query.prepare("Select * from cellule id_cellule=:id_cellule");
    query.bindValue(":id_cellule",valeur);
    if (query.exec())
    {
        while (query.next()){

            //            qDebug()<<"find";
            this -> id_cellule = (query.value(0).toInt());
            this -> type_cellule = (query.value(1).toString());
            this -> nb_lits =(query.value(2).toInt());
            this -> superficie_cellule = (query.value(3).toInt());
            this -> nb_detenus = (query.value(4).toInt());

        }

    }
    return query.exec();
}

bool Cellule::recherche_type_cellule(QString valeur)
{
    QSqlQuery query;

    query.prepare("Select * from cellule where type_cellule=:type_cellule");
    query.bindValue(":type_cellule",valeur);
    if (query.exec())
    {
        while (query.next()){

            //            qDebug()<<"find";
            this -> id_cellule = (query.value(0).toInt());
            this -> type_cellule = (query.value(1).toString());
            this -> nb_lits =(query.value(2).toInt());
            this -> superficie_cellule = (query.value(3).toInt());
            this -> nb_detenus = (query.value(4).toInt());
        }
    }

    return query.exec();
}

bool Cellule::recherche_nb_detenus(QString valeur)
{
    QSqlQuery query;

    query.prepare("Select * from cellule where nb_detenus=:nb_detenus");
    query.bindValue(":nb_detenus",valeur);
    if (query.exec())
    {
        while (query.next()){

            //            qDebug()<<"find";
            this -> id_cellule = (query.value(0).toInt());
            this -> type_cellule = (query.value(1).toString());
            this -> nb_lits =(query.value(2).toInt());
            this -> superficie_cellule = (query.value(3).toInt());
            this -> nb_detenus = (query.value(4).toInt());
        }
    }
    return query.exec();

}

