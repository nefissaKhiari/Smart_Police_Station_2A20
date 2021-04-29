#ifndef service_H
#define service_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>

class service
{
public:
    service();
     service(QString,QString,QString,QString,QString,QString,QString);
     QString getid_service();
     QString getlibelle_service();
     QString getagent_service();
     QString getdate_service();
     QString getdescription_service();
     QString getgenre_service();
     QString getnom_departement();


     void setid_service(QString);
     void setlibelle_service(QString);
     void setagent_service(QString);
     void setdate_service(QString);
     void setdescription_service(QString);
     void setgenre_service(QString);
     void setnom_departement(QString);
     QSqlQueryModel* tri_id() ;
     QSqlQueryModel *tri_date();

     QSqlQueryModel * rechercher_id_service(QString);
      QSqlQueryModel *rechercher_genre_service(QString genre);
     bool ajouter_service();

     QSqlQueryModel* afficher_service();
     bool supprimer_service(QString);
     bool modifier_service(QString,QString,QString,QString,QString,QString,QString);
private slots:
private: QString id_service,libelle_service,agent_service,date_service,description_service,genre_service,nom_departement;


};



#endif // service_H

