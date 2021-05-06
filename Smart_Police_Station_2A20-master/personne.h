#ifndef PERSONNE_H
#define PERSONNE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QDebug>
#include <QMessageBox>
#include <QSqlRecord>

class Personne
{
public:
    Personne();
    Personne(int,QString,QString,QString,QString,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
    QString get_date();
    QString get_sexe();
    void set_id(int);
    /*void setQuantiteEquipement(int);
    void setEtatEquipement(int);
    void setNomEquipement(QString);
    void setTypeEquipement(QString);
    void setDateFabrication(QString);
    void setFkAgentEq(QString);*/

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool update(int,QString,QString,QString,QString,QString);
    QSqlQueryModel * afficher_tri();
    QSqlQueryModel * chercher(int);
    int rech(int);
    void recherche_id_place(QTableView *, QString);
    QSqlQueryModel * search (int type, QString key) ;
    QSqlQueryModel * sort (int type) ;
   QSqlQueryModel *rechercherPersonne(QString);

    static int nombre ;
private:
    int id;

    QString nom,prenom,adresse,datePersonne,sexe;
};

#endif // PERSONNE_H
