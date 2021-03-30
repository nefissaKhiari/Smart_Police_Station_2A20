#ifndef CELLULE_H
#define CELLULE_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>

class Cellule
{
public:
    Cellule();
    Cellule(int,QString,int,int,int);
    int getid_cellule();
    QString gettype_cellule();
    int getnb_lits();
    int getsuperficie_cellule();
    int getnb_detenus();

    void setid_cellule(int);
    void settype_cellule(QString);
    void setnb_lits(int);
    void setsuperficie_cellule(int);
    void setnb_detenus(int);

    bool ajouter_cellule();
    QSqlQueryModel* afficher_cellule();
    bool supprimer_cellule(int);
    bool modifier_cellule(int,QString,int,int,int);
    QSqlQueryModel * tri_nb_detenus() ;
    QSqlQueryModel * tri_id_cellule() ;
    QSqlQueryModel * tri_nb_lits() ;
   QSqlQueryModel * rechercher_cellule(QString);
private:
        int id_cellule,nb_lits,superficie_cellule,nb_detenus;
        QString type_cellule;

};

#endif // CELLULE_H
