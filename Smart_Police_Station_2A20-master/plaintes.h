#ifndef PLAINTES_H
#define PLAINTES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>

class Plaintes
{
public:
    Plaintes();
    Plaintes(int,QString,QString,QString,int);
    int get_id();
    int get_idpersonne();
    QString get_raison();
    QString get_date();
    QString get_type();
       void set_id(int);
    bool ajouter();
    QSqlQueryModel * afficher(int);
    bool supprimer(int);
    bool update(int,QString,QString,QString,int);
    QSqlQueryModel * afficher_tri();
    QSqlQueryModel * chercher(int);
    int rech(int);
    void recherche_id_place(QTableView *, QString);
    QSqlQueryModel * search (int type, QString key) ;
    QSqlQueryModel * sort (int type) ;

private:
    int idp,idpersonne;
    QString raison,datep,type;
};

#endif // PLAINTES_H

