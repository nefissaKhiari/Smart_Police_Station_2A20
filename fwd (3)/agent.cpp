#include "agent.h"
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

agent::agent()
{

}
agent::agent(int ref,QString prenom,QString nom,QString email,QString poste,QString sexe)
{
  this->ref=ref;
  this->prenom=prenom;
  this->nom=nom;
    this->email=email;
    this->poste=poste;
    this->sexe=sexe;



}
int agent::get_ref(){return  ref;}
QString agent::get_nom(){return nom;}
QString agent::get_prenom(){return prenom;}
QString agent::get_email(){return email;}
QString agent::get_poste(){return poste;}
QString agent::get_sexe(){return sexe;}
void agent::set_reference(int reference){ref=reference;}
void agent::chercher(){
    QSqlQuery query;
    query.prepare("SELECT nom,prenom,email,poste,sexe FROM agent WHERE ref=:ref");
    query.bindValue(":ref",ref);
    query.exec();
    while(query.next())
    {
        nom=query.value(1).toString();
        prenom=query.value(2).toString();
        email=query.value(3).toString();
        poste=query.value(4).toString();
        sexe=query.value(5).toString();
}
}
bool agent::ajouter(int ref,QString prenom,QString nom,QString email,QString poste,QString sexe)
{
QSqlQuery query;
query.prepare("INSERT INTO agent (REF, NOM, PRENOM,EMAIL,POSTE,SEXE) "
                    "VALUES (:ref,:nom,:prenom,:email,:poste,:sexe)");
query.bindValue(":ref",ref);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":email",email);
query.bindValue(":poste",poste);
query.bindValue(":sexe",sexe);
return    query.exec();
}

QSqlQueryModel * agent::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * "
                "from agent");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("poste"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));
return model;
}

bool agent::supprimer(int ref)
{
QSqlQuery query;

query.prepare("Delete from agent where REF=:ref ");
query.bindValue(":ref", ref);
return    query.exec();
}

 QSqlQueryModel * agent::  afficher_liste()
 {
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select ref from agent");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ref"));
    return  model;
 }

bool agent::modifier(int ref,QString prenom,QString nom,QString email,QString poste,QString sexe)
{QSqlQuery edit;
    edit.prepare("Update agent set nom=:nom,prenom=:prenom,email=:email,poste=:poste,sexe=:sexe where REF =:ref");
    edit.bindValue(":ref",ref);
    edit.bindValue(":nom",nom);
    edit.bindValue(":prenom",prenom);
    edit.bindValue(":email",email);
    edit.bindValue(":poste",poste);
    edit.bindValue(":sexe",sexe);


    return       edit.exec()  ;
}
QSqlQueryModel * agent::afficher2(QString nom)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    nom='%'+nom+'%';
    query.prepare("SELECT * from agent where nom like :nom or prenom like :nom or  email like :nom order by ref");
    query.bindValue(":nom",nom);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ref"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("sexe"));
    return model;
}
QSqlQueryModel * agent:: recherche_agent(QString valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;


    query.prepare("SELECT * FROM agent WHERE NOM LIKE :valeur order by NOM");


    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("POSTE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));
    return model;

}
QSqlQueryModel * agent :: recherche_agenttd(QString valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
  query.prepare("SELECT * FROM agent WHERE NOM LIKE :valeur order by NOM desc");
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("POSTE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));
    return model;

}
QSqlQueryModel * agent::recherche_e(int valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM agent WHERE ref LIKE :valeur order by nom ");
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("POSTE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));
    return model;
}
QSqlQueryModel * agent::tri(int index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
        if(index == 0)
        {
            model->setQuery("select *FROM agent ORDER BY ref ASC");
        }
        else
        {
            model->setQuery("select *FROM  agent ORDER BY ref DESC ");
        }


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("POSTE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE"));
        return model;
}











