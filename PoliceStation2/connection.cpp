#include "connection.h"
#include "QSqlDatabase"

connection::connection()
{

}

bool connection::createConnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_2a");//inserer le nom de la source de données ODBC
db.setUserName("yasmine");//inserer nom de l'utilisateur
db.setPassword("SYSTEM");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
