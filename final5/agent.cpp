#include "agent.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QBuffer>
#include <cstdlib>
#include <QImage>

agent::agent()
{

    cin_agent="";
    nom_agent="";
    prenom_agent="";
    sexe_agent="";
    date_de_naissance_agent="";
    adresse_agent="";
    telephone_agent="";
    nationalite_agent="";
    service_agent="";
    email_agent="";
}

agent::agent(QString cin_agent,QString nom_agent,QString prenom_agent,QString sexe_agent,QString date_de_naissance_agent,
                 QString adresse_agent,QString telephone_agent,QString nationalite_agent,QString service_agent,QString email_agent)
{ this->cin_agent=cin_agent;
    this->nom_agent=nom_agent ;
    this->prenom_agent=prenom_agent;
    this->sexe_agent=sexe_agent  ;
    this->date_de_naissance_agent=date_de_naissance_agent ;
    this->adresse_agent=adresse_agent ;
    this->telephone_agent=telephone_agent;
    this-> nationalite_agent= nationalite_agent;
    this->service_agent=service_agent;
    this->email_agent=email_agent;
}

QString agent::getcin_agent(){return cin_agent;}
QString agent::getnom_agent(){return nom_agent;}
QString agent::getprenom_agent(){return prenom_agent;}
QString agent::getdate_naissance_agent(){return date_de_naissance_agent;}
QString agent::getnationalite_agent(){return nationalite_agent;}
QString agent::getsexe_agent(){return sexe_agent;}
QString agent::getadresse_agent(){return adresse_agent ;}
QString agent::getemail_agent(){return email_agent ;}
QString agent::getservice_agent(){return service_agent ;}
QString agent::gettelephone_agent(){return telephone_agent ;}

void agent::setcin_agent(QString cin_agent){this->cin_agent=cin_agent;}
void agent::setnom_agent(QString nom_agent){this->nom_agent=nom_agent;}
void agent::setprenom_agent(QString prenom_agent){this->prenom_agent=prenom_agent;}
void agent::setdate_de_naissance_agent(QString date_de_naissance_agent){this->date_de_naissance_agent=date_de_naissance_agent;}
void agent::setnationalite_agent(QString nationalite_agent){this->nationalite_agent=nationalite_agent;}
void agent::setsexe_agent(QString sexe_agent){this->sexe_agent=sexe_agent;}
void agent::setadresse_agent(QString adresse_agent){this->adresse_agent=adresse_agent;}
void agent::setemail_agent(QString email_agent){this->email_agent=email_agent;}
void agent::setservice_agent(QString service_agent){this->service_agent=service_agent;}
void agent::settelephone_agent(QString telephone_agent){this->nom_agent=telephone_agent;}




bool agent::ajouter_agent()
{
    QSqlQuery query;
    query.prepare("INSERT INTO agent (cin_agent, nom_agent, prenom_agent,sexe_agent,date_de_naissance_agent,adresse,telephone,nationnalite_agent,service_agent,email_agent) "
                  "VALUES (:cin_agent,:nom_agent,:prenom_agent,:sexe_agent,:date_de_naissance_agent,:adresse,:telephone,:nationnalite_agent,:service_agent,:email_agent)");

    query.bindValue(":cin_agent", cin_agent);
    query.bindValue(":nom_agent", nom_agent);
    query.bindValue(":prenom_agent", prenom_agent);
    query.bindValue(":sexe_agent", sexe_agent);
    query.bindValue(":date_de_naissance_agent",date_de_naissance_agent);
    query.bindValue(":adresse",adresse_agent);
    query.bindValue(":telephone",telephone_agent);
    query.bindValue(":nationnalite_agent",nationalite_agent);
    query.bindValue(":service_agent",service_agent);
    query.bindValue(":email_agent",email_agent);

    return query.exec();

}



bool agent::supprimer_agent(QString cin_agent)
{
    QSqlQuery query;
    query.prepare("Delete from agents where cin_agent= :cin_agent");
    query.bindValue(":cin_agent", cin_agent);

    return query.exec();
}

QSqlQueryModel* agent::afficher_agent()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM agent");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin agent"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom agent"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom agent"));
    //  model->setHeaderData(3, Qt::Horizontal, QObject::tr("comboBox_agent"));

    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date naissance agent"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse agent"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("telephone agent"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nationalite agent"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("etat civil"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("email"));




    return model;
}
bool agent::modifier_agent(QString cin_agent,QString nom_agent,QString prenom_agent,QString sexe_agent,QString date_de_naissance_agent,QString adresse_agent,QString telephone_agent,QString nationalite_agent,QString service_agent,QString email_agent)
{  QSqlQuery query;



    query.prepare("update agents set cin_agent='"+cin_agent+"', nom_agent='"+nom_agent+"',prenom_agent='"+prenom_agent+"',sexe_agent='"+sexe_agent+"',date_de_naissance_agent='"+date_de_naissance_agent+"',adresse='"+adresse_agent+"',telephone='"+telephone_agent+"',nationnalite_agent='"+nationalite_agent+"',service_agent='"+service_agent+"',email_agent='"+email_agent+"' where cin_agent=:cin_agent");
    query.bindValue(0, cin_agent);
    query.bindValue(1, nom_agent);
    query.bindValue(2, prenom_agent);
    query.bindValue(3,sexe_agent );
    query.bindValue(4, date_de_naissance_agent);
    query.bindValue(5, adresse_agent);
    query.bindValue(6, telephone_agent);
    query.bindValue(7, nationalite_agent);
    query.bindValue(8, service_agent);
    query.bindValue(9, email_agent);
    return query.exec();
}

QSqlQueryModel* agent::tri_cin()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from agents ORDER BY cin_agent") ;
    query->exec() ;
    model->setQuery(*query) ;



    return model;

}
QSqlQueryModel* agent::tri_date()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from agents ORDER BY date_de_naissance_agent") ;
    query->exec() ;
    model->setQuery(*query) ;



    return model;

}
QByteArray agent:: GetImage()
{
    return this->image;
}
void  agent::AjoutImage(QString fileName){


    if (fileName.isEmpty())
    {
        qDebug()<<"EMPTY EMPTY !!!!!";

        fileName="agent-image_standard.png";

    }
    QImage imageTMP(fileName);

    QByteArray byteArray;

    QBuffer buffer(&byteArray);

    imageTMP.save(&buffer, "PNG");

    image=byteArray;
}
/*QSqlQueryModel * agent::rechercher_nom_agent(QString valeur)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from agentS where nom_agent='"+valeur+"' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin agent"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom agent"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom agent"));
    //  model->setHeaderData(3, Qt::Horizontal, QObject::tr("comboBox_agent"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date naissance agent"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse agent"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("telephone agent"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nationalite agent"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("etat civil"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("email"));
        return model;
}*/
QSqlQueryModel * agent::rechercher_id_agent(QString valeur)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from agentS where cin_agent='"+valeur+"' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin agent"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom agent"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom agent"));
    //  model->setHeaderData(3, Qt::Horizontal, QObject::tr("comboBox_agent"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date naissance agent"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse agent"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("telephone agent"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nationalite agent"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("etat civil"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("email"));
        return model;
}

