#include "agent.h"
#include "stats.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
agent::agent()
{
id_agent=0;
nom_agent="";
prenom_agent="";
date_naissance_agent="";
nationalite_agent="";sexe_agent="";periode_agent="";dossier_agent="";
taille_agent=0;
poids_agent=0;
}

agent::agent(int id_agent,QString nom_agent,QString prenom_agent,QString date_naissance_agent,QString nationalite_agent ,QString sexe_agent ,int taille_agent,int poids_agent,QString periode_agent,QString dossier_agent)
{ this->id_agent=id_agent;
this->nom_agent=nom_agent ;
this->prenom_agent=prenom_agent;
this->date_naissance_agent=date_naissance_agent  ;
this->nationalite_agent=nationalite_agent ;
this->sexe_agent=sexe_agent ;
this->taille_agent=taille_agent;
this-> poids_agent= poids_agent;
this->periode_agent=periode_agent ;
this->dossier_agent=dossier_agent ;
}

int agent::getid_agent(){return id_agent;};
QString agent::getnom_agent(){return nom_agent;};
QString agent::getprenom_agent(){return prenom_agent;};
QString agent::getdate_naissance_agent(){return date_naissance_agent;};
QString agent::getnationalite_agent(){return nationalite_agent;};
QString agent::getsexe_agent(){return sexe_agent;};
int agent::gettaille_agent(){return taille_agent;};
int agent::getpoids_agent(){return poids_agent;};
QString agent::getperiode_agent(){return periode_agent ;};
QString agent::getdossier_agent(){return dossier_agent ;};

void agent::setid_agent(int id_agent){this->id_agent=id_agent;}
void agent::setnom_agent(QString nom_agent){this->nom_agent=nom_agent;}
void agent::setprenom_agent(QString prenom_agent){this->prenom_agent=prenom_agent;}
void agent::setdate_naissance_agent(QString date_naissance_agent){this->date_naissance_agent=date_naissance_agent;}
void agent::setnationalite_agent(QString nationalite_agent){this->nationalite_agent=nationalite_agent;}
void agent::setsexe_agent(QString sexe_agent){this->sexe_agent=sexe_agent;}
void agent::settaille_agent(int taille_agent){this->taille_agent=taille_agent;}
void agent::setpoids_agent(int poids_agent){this->poids_agent=poids_agent;}
void agent::setperiode_agent(QString periode_agent){this->periode_agent=periode_agent;}
void agent::setdossier_agent(QString dossier_agent){this->nom_agent=dossier_agent;}



bool agent::ajouter_agent()
{
    QSqlQuery query;
  QString id_agent_string=QString::number(id_agent);
  QString taille_agent_string=QString::number(taille_agent);
  QString poids_agent_string=QString::number(poids_agent);
    query.prepare("INSERT INTO agent (id_agent, nom_agent, prenom_agent,date_naissance_agent,nationalite_agent,sexe_agent,taille_agent,poids_agent,periode_agent,dossier_agent) "
                  "VALUES (:id_agent, :nom_agent, :prenom_agent,:date_naissance_agent,:nationalite_agent,:sexe_agent,:taille_agent,:poids_agent,:periode_agent,:dossier_agent)");
    query.bindValue(":id_agent", id_agent_string);
    query.bindValue(":nom_agent", nom_agent);
    query.bindValue(":prenom_agent", prenom_agent);
    query.bindValue(":date_naissance_agent", date_naissance_agent);
    query.bindValue(":nationalite_agent",nationalite_agent);
    query.bindValue(":sexe_agent",sexe_agent);
    query.bindValue(":taille_agent",taille_agent_string);
    query.bindValue(":poids_agent",poids_agent_string);
    query.bindValue(":periode_agent",periode_agent);
    query.bindValue(":dossier_agent",dossier_agent);

    return query.exec();

}

bool agent::modifier_agent(int id_agent,QString nom_agent,QString prenom_agent,QString date_naissance_agent,QString nationalite_agent ,QString sexe_agent,int taille_agent,int poids_agent,QString periode_agent,QString dossier_agent )
{
    QSqlQuery query;
    QString id_agent_string=QString::number(id_agent);
    QString taille_agent_string=QString::number(taille_agent);
    QString poids_agent_string=QString::number(poids_agent);


    query.prepare("update agent set id_agent='"+id_agent_string+"', nom_agent='"+nom_agent+"',prenom_agent='"+prenom_agent+"',date_naissance_agent='"+date_naissance_agent+"',nationalite_agent='"+nationalite_agent+"',sexe_agent='"+sexe_agent+"',taille_agent='"+taille_agent_string+"',poids_agent='"+poids_agent_string+"',periode_agent='"+periode_agent+"',dossier_agent='"+dossier_agent+"' where id_agent=:id_agent");
    query.bindValue(0, id_agent_string);
    query.bindValue(1, nom_agent);
    query.bindValue(2, prenom_agent);
    query.bindValue(3,date_naissance_agent );
    query.bindValue(4, nationalite_agent);
    query.bindValue(5, sexe_agent);
    query.bindValue(6, taille_agent_string);
    query.bindValue(7, poids_agent_string);
    query.bindValue(8, periode_agent);
    query.bindValue(9, dossier_agent);
    return query.exec();
}
bool agent::supprimer_agent(int id_agent)
{
    QSqlQuery query;
    query.prepare("Delete from agent where id_agent= :id_agent");
    query.bindValue(":id_agent", id_agent);

    return query.exec();
}

QSqlQueryModel* agent::afficher_agent()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM agent");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id agent"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom agent"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom agent"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date naissance agent"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nationalite agent"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe agent"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Taille agent"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("Poids agent"));
         model->setHeaderData(8, Qt::Horizontal, QObject::tr("Periode agent"));
         model->setHeaderData(9, Qt::Horizontal, QObject::tr("Dossier agent"));


    return model;
}


