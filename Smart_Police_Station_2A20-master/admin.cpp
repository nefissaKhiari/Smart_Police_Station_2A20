#include "admin.h"


admin::admin()
{
    username="" ;
    password="" ;

}

admin::admin(QString username,QString password)
{
    this->username=username ;
    this->password=password ;


}

QString admin::get_id(){return username ; }

QString admin:: get_mdp() {return password ; }

bool admin::ajouter()
{
    QSqlQuery query ;
    query.prepare("INSERT INTO stpsadmin (username,password)"
                  "VALUES (:username,:password)")  ;
    query.bindValue(":username",username) ;

    query.bindValue(":password",password) ;


    return query.exec() ;


}

bool admin::supprimer(QString username)
{
    QSqlQuery query ;
    QString res=username ;
    query.prepare("Delete from stpsadmin where username =:username") ;
    query.bindValue(":username",res) ;

    return query.exec() ;

}
