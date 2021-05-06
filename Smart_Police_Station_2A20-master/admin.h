
#ifndef ADMIN_H
#define ADMIN_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>




class admin
{
public:
    admin();
    bool ajouter() ;
    QString get_id() ;

    QString get_mdp() ;
    admin(QString,QString);
    QSqlQueryModel * afficher() ;
    bool supprimer(QString) ;
private:

    QString username,password;
};

#endif // ADMIN_H

