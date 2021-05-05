#ifndef mission_H
#define mission_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
#include <QPropertyAnimation>
#include <QMediaPlayer>

//QString lng="fr";
class mission
{
public:
    mission();
    mission(int,int,int,QString);
    int getid();
    int getnbr_vehicule();
    int getnbr_policier();

    QString getdate_mission();
    void setid(int);
    void setnbr_vehicule(int);
    void setnbr_policier(int);
    void setdate_mission(QString) ;
    bool ajouter2();
    QSqlQueryModel* afficher_mission();
    bool supprimer(int);
     bool modifier_mission(int,int,int,QString);
     //  int rechercher(int);
     QSqlQueryModel *tri_id();

     QSqlQueryModel *tri_nbr_veh();
     QSqlQueryModel * rechercher_mission(QString);
private slots:


private:
        int id,nbr_vehicule,nbr_policier;

      QString date_mission;
      QMediaPlayer *click;

};

#endif // mission_H

