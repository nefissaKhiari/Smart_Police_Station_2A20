#ifndef PETITION_H
#define PETITION_

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>

class Petition
{
public:
    Petition();
     Petition(QString,QString,QString,QString,QString,QString,QString);
     QString getid_petition();
     QString gettitre_petition();
     QString getauteur_petition();
     QString getdate_petition();
     QString getdescription_petition();
     QString getvalidite_petition();
     QString getnbr_signatures_requis();


     void setid_petition(QString);
     void settitre_petition(QString);
     void setauteur_petition(QString);
     void setdate_petition(QString);
     void setdescription_petition(QString);
     void setvalidite_petition(QString);
     void setnbr_signatures_requis(QString);

     bool ajouter_petition();
     QSqlQueryModel* afficher_petition();

     QSqlQueryModel * rechercheDynamic(QString);
     bool supprimer_petition(QString);
     bool modifier_petition(QString,QString,QString,QString,QString,QString,QString);
private slots:
private: QString id_petition,titre_petition,auteur_petition,date_petition,description_petition,validite_petition,nbr_signatures_requis;


};



#endif // PETITION_H

