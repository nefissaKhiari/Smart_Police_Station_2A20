#ifndef CITOYEN_H
#define CITOYEN_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
class Citoyen
{
public:
    Citoyen();
     Citoyen(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);
     QString getcin_citoyen();
     QString getnom_citoyen();
     QString getprenom_citoyen();
     QString getsexe_citoyen();
     QString getdate_naissance_citoyen();
     QString getadresse_citoyen();
     QString gettelephone_citoyen();
     QString getnationalite_citoyen();
     QString getetat_civil_citoyen();
     QString getemail_citoyen();

     void setcin_citoyen(QString);
     void setnom_citoyen(QString);
     void setprenom_citoyen(QString);
     void setsexe_citoyen(QString);
     void setdate_de_naissance_citoyen(QString);
     void setadresse_citoyen(QString);
     void settelephone_citoyen(QString);
     void setnationalite_citoyen(QString);
     void setetat_civil_citoyen(QString);
     void setemail_citoyen(QString);
    QSqlQueryModel* tri_cin() ;
    QSqlQueryModel *tri_date();
     QSqlQueryModel *tri_nom();
    QSqlQueryModel * rechercher_nom_citoyen(QString);
     QSqlQueryModel *rechercher_id_citoyen(QString nom);
     bool ajouter_citoyen();
     QSqlQueryModel* afficher_citoyen();
     bool supprimer_citoyen(QString);
     bool modifier_citoyen(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);
     QByteArray  GetImage() ;
    void  AjoutImage(QString );
private slots:

private:
        QString cin_citoyen,nom_citoyen,prenom_citoyen,sexe_citoyen,date_de_naissance_citoyen,adresse_citoyen,telephone_citoyen,
        nationalite_citoyen,etat_civil_citoyen,email_citoyen;
        QByteArray image;


};




#endif // CITOYEN_H
