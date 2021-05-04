#include "citoyen.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QBuffer>
#include <cstdlib>
#include <QImage>

Citoyen::Citoyen()
{

    cin_citoyen="";
    nom_citoyen="";
    prenom_citoyen="";
    sexe_citoyen="";
    date_de_naissance_citoyen="";
    adresse_citoyen="";
    telephone_citoyen="";
    nationalite_citoyen="";
    etat_civil_citoyen="";
    email_citoyen="";
}

Citoyen::Citoyen(QString cin_citoyen,QString nom_citoyen,QString prenom_citoyen,QString sexe_citoyen,QString date_de_naissance_citoyen,
                 QString adresse_citoyen,QString telephone_citoyen,QString nationalite_citoyen,QString etat_civil_citoyen,QString email_citoyen)
{ this->cin_citoyen=cin_citoyen;
    this->nom_citoyen=nom_citoyen ;
    this->prenom_citoyen=prenom_citoyen;
    this->sexe_citoyen=sexe_citoyen  ;
    this->date_de_naissance_citoyen=date_de_naissance_citoyen ;
    this->adresse_citoyen=adresse_citoyen ;
    this->telephone_citoyen=telephone_citoyen;
    this-> nationalite_citoyen= nationalite_citoyen;
    this->etat_civil_citoyen=etat_civil_citoyen;
    this->email_citoyen=email_citoyen;
}

QString Citoyen::getcin_citoyen(){return cin_citoyen;}
QString Citoyen::getnom_citoyen(){return nom_citoyen;}
QString Citoyen::getprenom_citoyen(){return prenom_citoyen;}
QString Citoyen::getdate_naissance_citoyen(){return date_de_naissance_citoyen;}
QString Citoyen::getnationalite_citoyen(){return nationalite_citoyen;}
QString Citoyen::getsexe_citoyen(){return sexe_citoyen;}
QString Citoyen::getadresse_citoyen(){return adresse_citoyen ;}
QString Citoyen::getemail_citoyen(){return email_citoyen ;}
QString Citoyen::getetat_civil_citoyen(){return etat_civil_citoyen ;}
QString Citoyen::gettelephone_citoyen(){return telephone_citoyen ;}

void Citoyen::setcin_citoyen(QString cin_citoyen){this->cin_citoyen=cin_citoyen;}
void Citoyen::setnom_citoyen(QString nom_citoyen){this->nom_citoyen=nom_citoyen;}
void Citoyen::setprenom_citoyen(QString prenom_citoyen){this->prenom_citoyen=prenom_citoyen;}
void Citoyen::setdate_de_naissance_citoyen(QString date_de_naissance_citoyen){this->date_de_naissance_citoyen=date_de_naissance_citoyen;}
void Citoyen::setnationalite_citoyen(QString nationalite_citoyen){this->nationalite_citoyen=nationalite_citoyen;}
void Citoyen::setsexe_citoyen(QString sexe_citoyen){this->sexe_citoyen=sexe_citoyen;}
void Citoyen::setadresse_citoyen(QString adresse_citoyen){this->adresse_citoyen=adresse_citoyen;}
void Citoyen::setemail_citoyen(QString email_citoyen){this->email_citoyen=email_citoyen;}
void Citoyen::setetat_civil_citoyen(QString etat_civil_citoyen){this->etat_civil_citoyen=etat_civil_citoyen;}
void Citoyen::settelephone_citoyen(QString telephone_citoyen){this->nom_citoyen=telephone_citoyen;}




bool Citoyen::ajouter_citoyen()
{
    QSqlQuery query;
    query.prepare("INSERT INTO citoyens (cin_citoyen, nom_citoyen, prenom_citoyen,sexe_citoyen,date_de_naissance_citoyen,adresse,telephone,nationnalite_citoyen,etat_civil_citoyen,email_citoyen,image) "
                  "VALUES (:cin_citoyen,:nom_citoyen,:prenom_citoyen,:sexe_citoyen,:date_de_naissance_citoyen,:adresse,:telephone,:nationnalite_citoyen,:etat_civil_citoyen,:email_citoyen,:image)");

    query.bindValue(":cin_citoyen", cin_citoyen);
    query.bindValue(":nom_citoyen", nom_citoyen);
    query.bindValue(":prenom_citoyen", prenom_citoyen);
    query.bindValue(":sexe_citoyen", sexe_citoyen);
    query.bindValue(":date_de_naissance_citoyen",date_de_naissance_citoyen);
    query.bindValue(":adresse",adresse_citoyen);
    query.bindValue(":telephone",telephone_citoyen);
    query.bindValue(":nationnalite_citoyen",nationalite_citoyen);
    query.bindValue(":etat_civil_citoyen",etat_civil_citoyen);
    query.bindValue(":email_citoyen",email_citoyen);
    query.bindValue(":image", image, QSql::Binary);

    return query.exec();

}



bool Citoyen::supprimer_citoyen(QString cin_citoyen)
{
    QSqlQuery query;
    query.prepare("Delete from citoyens where cin_citoyen= :cin_citoyen");
    query.bindValue(":cin_citoyen", cin_citoyen);

    return query.exec();
}

QSqlQueryModel* Citoyen::afficher_citoyen()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM citoyens");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin Citoyen"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Citoyen"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom Citoyen"));
    //  model->setHeaderData(3, Qt::Horizontal, QObject::tr("comboBox_citoyen"));

    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date naissance Citoyen"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse citoyen"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("telephone citoyen"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nationalite Citoyen"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("etat civil"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("email"));




    return model;
}
bool Citoyen::modifier_citoyen(QString cin_citoyen,QString nom_citoyen,QString prenom_citoyen,QString sexe_citoyen,QString date_de_naissance_citoyen,QString adresse_citoyen,QString telephone_citoyen,QString nationalite_citoyen,QString etat_civil_citoyen,QString email_citoyen)
{  QSqlQuery query;



    query.prepare("update citoyens set cin_citoyen='"+cin_citoyen+"', nom_citoyen='"+nom_citoyen+"',prenom_citoyen='"+prenom_citoyen+"',sexe_citoyen='"+sexe_citoyen+"',date_de_naissance_citoyen='"+date_de_naissance_citoyen+"',adresse='"+adresse_citoyen+"',telephone='"+telephone_citoyen+"',nationnalite_citoyen='"+nationalite_citoyen+"',etat_civil_citoyen='"+etat_civil_citoyen+"',email_citoyen='"+email_citoyen+"' where cin_citoyen=:cin_citoyen");
    query.bindValue(0, cin_citoyen);
    query.bindValue(1, nom_citoyen);
    query.bindValue(2, prenom_citoyen);
    query.bindValue(3,sexe_citoyen );
    query.bindValue(4, date_de_naissance_citoyen);
    query.bindValue(5, adresse_citoyen);
    query.bindValue(6, telephone_citoyen);
    query.bindValue(7, nationalite_citoyen);
    query.bindValue(8, etat_civil_citoyen);
    query.bindValue(9, email_citoyen);

    return query.exec();
}

QSqlQueryModel* Citoyen::tri_cin()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from citoyens ORDER BY cin_citoyen") ;
    query->exec() ;
    model->setQuery(*query) ;



    return model;

}
QSqlQueryModel* Citoyen::tri_date()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from citoyens ORDER BY date_de_naissance_citoyen") ;
    query->exec() ;
    model->setQuery(*query) ;



    return model;

}
QSqlQueryModel* Citoyen::tri_nom()// triii
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    QSqlQuery *query=new QSqlQuery;
    query->prepare("select * from citoyens ORDER BY nom_citoyen") ;
    query->exec() ;
    model->setQuery(*query) ;



    return model;

}
QByteArray Citoyen:: GetImage()
{
    return this->image;
}
void  Citoyen::AjoutImage(QString fileName){


    if (fileName.isEmpty())
    {
        qDebug()<<"EMPTY EMPTY !!!!!";

        fileName="Citoyen-image_standard.png";

    }
    QImage imageTMP(fileName);

    QByteArray byteArray;

    QBuffer buffer(&byteArray);

    imageTMP.save(&buffer, "PNG");

    image=byteArray;
}
/*QSqlQueryModel * Citoyen::rechercher_nom_citoyen(QString valeur)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from CITOYENS where nom_citoyen='"+valeur+"' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin Citoyen"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Citoyen"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom Citoyen"));
    //  model->setHeaderData(3, Qt::Horizontal, QObject::tr("comboBox_citoyen"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date naissance Citoyen"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse citoyen"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("telephone citoyen"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nationalite Citoyen"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("etat civil"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("email"));
        return model;
}*/
QSqlQueryModel * Citoyen::rechercher_id_citoyen(QString valeur)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from CITOYENS where cin_citoyen='"+valeur+"' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin Citoyen"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Citoyen"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom Citoyen"));
    //  model->setHeaderData(3, Qt::Horizontal, QObject::tr("comboBox_citoyen"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date naissance Citoyen"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse citoyen"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("telephone citoyen"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nationalite Citoyen"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("etat civil"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("email"));
        return model;
}

