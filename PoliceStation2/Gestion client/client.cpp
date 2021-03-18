#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Client::Client()
{
  id=0;nom="";prenom="";
}

Client::Client(int id,QString nom,QString prenom)
{ this->id=id; this->nom=nom ; this->prenom=prenom;}
int Client::getid(){return id;}
QString Client::getnom(){return nom;}
QString Client::getprenom(){return prenom;}
void Client::setid(int id){this->id=id;}
void Client::setnom(QString nom){this->nom=nom;}
void Client::setprenom(QString prenom){this->prenom=prenom;}
bool Client::ajouter()
{
    QSqlQuery query;
  QString id_string=QString::number(id);
    query.prepare("INSERT INTO client (id, nom, prenom) "
                  "VALUES (:id, :forename, :surname)");
    query.bindValue(":id", id_string);
    query.bindValue(":forename", nom);
    query.bindValue(":surname", prenom);
    return query.exec();

}
bool Client::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from Client where id= :id");
    query.bindValue(":id", id);

    return query.exec();
}
QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM client");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    return model;
}

/*int Client::rechercher(int)
{

}*/




