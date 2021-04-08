#ifndef service_H
#define service_

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
     QString gettitre_service();
     QString getauteur_service();
     QString getdate_service();
     QString getdescription_service();
     QString getvalidite_service();
     QString getnbr_signatures_requis();


     void setid_service(QString);
     void settitre_service(QString);
     void setauteur_service(QString);
     void setdate_service(QString);
     void setdescription_service(QString);
     void setvalidite_service(QString);
     void setnbr_signatures_requis(QString);

     bool ajouter_service();
     QSqlQueryModel* afficher_service();
     bool supprimer_service(QString);
     bool modifier_service(QString,QString,QString,QString,QString,QString,QString);
     bool modifier2(QString ,QString ,QString ,QString ,
                             QString ,QString ,QString );
private slots:
private: QString id_service,titre_service,auteur_service,date_service,description_service,validite_service,nbr_signatures_requis;


};



#endif // service_H

