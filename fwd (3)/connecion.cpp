#include "connecion.h"
#include <QSqlError>
connecion::connecion(){}
bool connecion::ouvrirconnexion(){
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet_2A");
    db.setUserName("cyrine");
    db.setPassword("cyrine");
    if(db.open())
    test=true;
    else throw QString ("Erreur Paramétres"+db.lastError().text());
    return test;}

void connecion::fermerconnexion(){
    db.close();
}
