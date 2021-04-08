#ifndef service_H
#define service_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class service
{
public:
    service();
    service(QString,int,int);
    QString get_poste();
    int   get_prix_h();
    int get_id_service();
    bool ajouter_service(QString poste,int prix_h,int id_service);
    QSqlQueryModel * afficher_service();

    bool modifier(int id_service,int prix_h,QString poste);
    bool supprimer_service(int id);
    QSqlQueryModel *tri(int index);



private:
    QString poste;
    int prix_h,id_service;
};

#endif // service_H
