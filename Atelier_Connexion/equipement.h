 #ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QString>
#include <qsqlquerymodel.h>
class Equipement
{
 public:
    Equipement();//constructeur par defaut
    Equipement(int,int,int,QString,QString,QString);//constructeur parametré

    int getIdEquipement();
    int getQuantiteEquipement();
    int getEtatEquipement();
    QString getNomEquipement();
    QString getTypeEquipement();
    QString getDateFabrication();

    void setIdEquipement(int);
    void setQuantiteEquipement(int);
    void setEtatEquipement(int);
    void setNomEquipement(QString);
    void setTypeEquipement(QString);
    void setDateFabrication(QString);

    bool ajouterEquipement();
    QSqlQueryModel* afficher();

   bool supprimer(int);
   bool modifier(int,QString,QString,int,int,QString);
   QSqlQueryModel* tri_etat() ;
   QSqlQueryModel *tri_quantite();

private:
    int idEquipement, quantiteEquipement,etatEquipement;
    QString nomEquipement, typeEquipement, dateFabrication;
};

#endif // EQUIPEMENT_H
