 #ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include<QString>
#include<QDate>
#include <qsqlquerymodel.h>
class Equipement
{
 public:
    Equipement();//constructeur par defaut
    Equipement(int,int,int,QString,QString,QDate);//constructeur parametré

    int getIdEquipement();
    int getQuantiteEquipement();
    int getEtatEquipement();
    QString getNomEquipement();
    QString getTypeEquipement();
    QDate getDateFabrication();

    void setIdEquipement(int);
    void setQuantiteEquipement(int);
    void setEtatEquipement(int);
    void setNomEquipement(QString);
    void setTypeEquipement(QString);
    void setDateFabrication(QDate);

    bool ajouterEquipement();
    QSqlQueryModel* afficher();

   bool supprimer(int);
   bool modifier(int,QString,QString,int,int,QDate);
   QSqlQueryModel * tri_etat() ;
   QSqlQueryModel *tri_quantite();
   QSqlQueryModel *rechercherEquipement(QString);

private:
    int idEquipement, quantiteEquipement,etatEquipement;
    QString nomEquipement, typeEquipement;
    QDate dateFabrication;
};

#endif // EQUIPEMENT_H
