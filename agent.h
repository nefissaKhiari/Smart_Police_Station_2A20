#ifndef agent_H
#define agent_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
class agent
{
public:
    agent();
     agent(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);
     QString getcin_agent();
     QString getnom_agent();
     QString getprenom_agent();
     QString getsexe_agent();
     QString getdate_naissance_agent();
     QString getadresse_agent();
     QString gettelephone_agent();
     QString getnationalite_agent();
     QString getetat_civil_agent();
     QString getemail_agent();

     void setcin_agent(QString);
     void setnom_agent(QString);
     void setprenom_agent(QString);
     void setsexe_agent(QString);
     void setdate_de_naissance_agent(QString);
     void setadresse_agent(QString);
     void settelephone_agent(QString);
     void setnationalite_agent(QString);
     void setetat_civil_agent(QString);
     void setemail_agent(QString);
    QSqlQueryModel* tri_cin() ;
    QSqlQueryModel *tri_date();
    QSqlQueryModel * rechercher_nom_agent(QString);
     QSqlQueryModel *rechercher_id_agent(QString nom);
     bool ajouter_agent();
     QSqlQueryModel* afficher_agent();
     bool supprimer_agent(QString);
     bool modifier_agent(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);
     QByteArray  GetImage() ;
    void  AjoutImage(QString );
private slots:

private:
        QString cin_agent,nom_agent,prenom_agent,sexe_agent,date_de_naissance_agent,adresse_agent,telephone_agent,nationalite_agent,etat_civil_agent,email_agent;
        QByteArray image;


};




#endif // agent_H
