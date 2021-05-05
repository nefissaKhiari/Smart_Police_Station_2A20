#ifndef CLIENT_H
#define CLIENT_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
class Client
{
public:
    Client();
    Client(int,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
  //  int rechercher(int);
private:
        int id;
        QString nom, prenom;


};

#endif // CLIENT_H
