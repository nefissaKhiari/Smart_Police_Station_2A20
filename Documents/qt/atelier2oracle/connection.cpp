#include "connection.h"
//#include "QSqlDatabase"

Connection::Connection()
{

}
bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_c");//inserer le nom de la source de données ODBC
db.setUserName("arije");//inserer nom de l'utilisateur
db.setPassword("arije");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
        return test;
}




