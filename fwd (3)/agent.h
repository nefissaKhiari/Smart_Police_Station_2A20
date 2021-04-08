#ifndef AGENT_H
#define AGENT_H
#include <QString>
#include <QTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
class agent
{public:
    agent();
    agent(int ref,QString prenom,QString nom,QString email,QString poste,QString sexe);
    int get_ref();
    QString get_nom();
    QString get_prenom();
    QString get_email();
    QString get_poste();
    int get_salaire();
    QString get_sexe();
    void set_reference(int reference);
    void set_nom(QString nom1 ){nom=nom1;}
    void set_prenom(QString prenom1){prenom=prenom1;}
    void set_email(QString email1){email=email1;}
    void set_poste(QString p){poste=p;}
    void set_sext(QString sexe1){sexe=sexe1;}
    void chercher();
    bool ajouter(int ref, QString nom, QString prenom,QString email,QString poste,QString sexe);
    bool supprimer(int id_ch);
    bool modifier(int ref,QString prenom,QString nom,QString email,QString poste,QString sexe);
    QSqlQueryModel * afficher_liste();
    QSqlQueryModel * afficher2(QString nom);
    QSqlQueryModel *  recherche_agent(QString valeur);
    QSqlQueryModel * recherche_agenttd(QString valeur);
    QSqlQueryModel * recherche_e(int valeur);
    QSqlQueryModel *tri(int index);
    QSqlQueryModel * afficher();





private:
    QString nom,prenom,poste,email;
    QString sexe;
    int ref;

};


#endif // AGENT_H
