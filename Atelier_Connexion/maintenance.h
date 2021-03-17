#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QString>
#include <qsqlquerymodel.h>

class maintenance
{
public:
    maintenance();
     maintenance(int,QString,QString,QString,int);
     int getIdMaintenance();
     QString getDureeMaintenance();
     QString getDateEntreeM();
     QString getDateSortieM();
     int getFraisMaintenance();

     void setIdMaintenance(int);
     void setDureeMaintenance(QString);
     void setDateEntreeM(QString);
     void setDateSortieM(QString);
     void setFraisMaintenance(int);

     bool ajouterMaintenance();
     QSqlQueryModel* afficherMaintenance();
     bool supprimerMaintenance(int);

private:
     int idMaintenance,frais;
     QString dureeMaintenance,dateEntreeM,dateSortieM;

};

#endif // MAINTENANCE_H
