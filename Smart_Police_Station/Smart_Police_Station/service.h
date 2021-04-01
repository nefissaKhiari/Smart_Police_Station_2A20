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
    service(int,QString,int,int,int);
    int getid_service();
    QString gettype_service();
    int getnb_agentss();
    int getsuperficie_service();
    int getnb_agents();

    void setid_service(int);
    void settype_service(QString);
    void setnb_agentss(int);
    void setsuperficie_service(int);
    void setnb_agents(int);

    bool ajouter_service();
    QSqlQueryModel* afficher_service();
    bool supprimer_service(int);
    bool modifier_service(int,QString,int,int,int);
    QSqlQueryModel * tri_nb_agents() ;
    QSqlQueryModel * tri_id_service() ;
    QSqlQueryModel * tri_nb_agentss() ;
   QSqlQueryModel * rechercher_service(QString);
private:
        int id_service,nb_agentss,superficie_service,nb_agents;
        QString type_service;

};

#endif // service_H
