#ifndef MAINTENANCE_H
#define MAINTENANCE_H
 #include <QSqlDatabase>
 #include <QSqlError>
#include <QSqlQuery>
#include<QString>
#include <qsqlquerymodel.h>

class Maintenance
{
public:
    Maintenance();
    Maintenance(int,QString,QString,QString,int,int);
     int getIdMaintenance();
     QString getDureeMaintenance();
     QString getDateEntreeM();
     QString getDateSortieM();
     int getFraisMaintenance();
     int getFkEquipement();

     void setIdMaintenance(int);
     void setDureeMaintenance(QString);
     void setDateEntreeM(QString);
     void setDateSortieM(QString);
     void setFraisMaintenance(int);
     void setFkEquipement(int);


     bool ajouterMaintenance();
     QSqlQueryModel* afficherMaintenance();
     bool supprimerMaintenance(int);
     bool modifierMaintenance(int,QString,QString,QString,int,int);

private:
     int idMaintenance,frais,fk_equipement;
     QString dureeMaintenance,dateEntreeM,dateSortieM;

};

#endif // MAINTENANCE_H

