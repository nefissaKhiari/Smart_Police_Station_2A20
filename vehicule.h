#ifndef vehicule_H
#define vehicule_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
class vehicule
{
public:
    vehicule();
    vehicule(int,QString,QString);
    int getid();
    QString getmarque();
    QString getmodel();



    void setid(int);
    void setmarque(QString);
    void setmodel(QString);


    bool ajouter();
    QSqlQueryModel* afficher_vehicule();
    bool supprimer(int);
     bool modifier_vehicule(int,QString,QString);
  //  int rechercher(int);
private:
        int id;
        QString marque, model;


};

#endif // vehicule_H

