#include "connection.h"
#include "QSqlDatabase"
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_2a20");//inserer le nom de la source de données ODBC
db.setUserName("ahmed");//inserer nom de l'utilisateur
db.setPassword("ahmed");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
