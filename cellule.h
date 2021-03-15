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

    bool ajouter2();
    QSqlQueryModel* afficher2();
    bool supprimer2(int);
    bool modifier2();
private:
        int id_cellule,nb_lits,superficie_cellule,nb_detenus;
        QString type_cellule;
};

#endif // CELLULE_H
