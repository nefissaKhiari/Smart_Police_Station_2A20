#include "personne.h"


Personne::Personne()
{
 id=0;
 nom="";
 prenom="";
 adresse="";
 date="";
 sexe="";
}

Personne::Personne(int idp,QString nomp,QString prenomp,QString adressep,QString datep,QString sexep)
{
  id=idp;
  nom=nomp;
  prenom=prenomp;
  adresse=adressep;
  date=datep;
  sexe=sexep;
}

//GETTERS
int Personne::get_id(){return id;}
QString Personne::get_nom(){return nom;}
QString Personne::get_prenom(){return prenom;}
QString Personne::get_adresse(){return adresse;}
QString Personne::get_date(){return date;}
QString Personne::get_sexe(){return sexe;}



bool Personne::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
Personne s;
if (s.rech(id)==0)
{
query.prepare("INSERT INTO PERSONNE (ID,NOM,PRENOM,ADRESSE,DATEPERSONNE,SEXE) "
                    "VALUES (:id, :nom, :prenom, :adresse, :date, :sexe)");
query.bindValue(":id", id);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":date", date);
query.bindValue(":sexe", sexe);

}

return    query.exec();
}

QSqlQueryModel * Personne::afficher()
{
    QSqlQuery query;
     query.prepare("Select * from PERSONNE");
    QSqlQueryModel *model = new QSqlQueryModel();
    query.exec();
    model->setQuery(query);
    return model;
}

bool Personne::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from PERSONNE where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Personne::update()
{

    QSqlQuery query;
    int first=0 ;
        QString res1=QString::number(id);
         QString editer="Update PERSONNE set" ;
        query.bindValue(":nom",nom);
        if(nom!="")
        {
            editer+=" NOM = :nom" ;
            first=1 ;
        }

        query.bindValue(":prenom",prenom);
        if(prenom!=""&& first!=0)
            editer+=" ,PRENOM= :prenom" ;
        else if (prenom!=""&&first==0)
          {
            editer+=" PRENOM= :prenom" ;
            first=1 ;
          }
             query.bindValue(":adresse",adresse);
             if(adresse!=""&& first!=0)
                 editer+=" ,ADRESSE = :adresse" ;
             else if (adresse!="" && first==0)
             {
                editer+=" ADRESSE = :adresse" ;
                first=1 ;
             }

               query.bindValue(":date",date);
               if(date!=""&& first!=0)
                   editer+=" ,DATEPERSONNE = :date" ;
               else if (date!=""&&first==0)
               {
                 editer+=" DATEPERSONNE = :date" ;
                 first=1 ;
               }

               query.bindValue(":sexe",sexe);
               if(sexe!=""&& first!=0)
                   editer+=" ,SEXE = :sexe" ;
               else if (sexe!=""&&first==0)
               {
                 editer+=" SEXE = :sexe" ;
                 first=1 ;
               }



               editer+=" where ID = :id" ;



               QByteArray chaine = editer.toLocal8Bit();
               const char *final = chaine.data();

            query.prepare(final);


         query.bindValue(":id",QVariant(res1).toInt());
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":adresse", adresse);
         query.bindValue(":date", date);
         query.bindValue(":sexe", sexe);


         return query.exec();
}


QSqlQueryModel * Personne::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PERSONNE order by ID asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEN "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE "));

    return model;
}

QSqlQueryModel * Personne::chercher(int id)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from PERSONNE WHERE ID=:id"));

     query.bindValue(":id",id);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEN "));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE "));

return model;
 }


int Personne::rech(int id)
{

    QSqlQuery query;
        int count=0;
        bool test=0;
        QString num_string=QString::number(id);
        if(query.exec("select ID from PERSONNE where  ID='" +num_string +"'"))
        {
        while(query.next())
            count++;
        if(count>=1)
            test=1;

        }
        return test;
}

QSqlQueryModel * Personne :: search (int type, QString key){
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();
    int k ;
    switch(type){
        case 0:

            k = key.toInt();
            query.prepare("Select * from PERSONNE where ID = :id");
            query.bindValue(":id", k);
           query.exec();
           model->setQuery(query);
           if(model->record(0).isEmpty() == true){ return model = nullptr;}
        break;
    case 1:

        query.prepare("Select * from PERSONNE where NOM = :modele");
        query.bindValue(":modele", key);
       query.exec();
       model->setQuery(query);
       if(model->record(0).isEmpty() == true){ return model = nullptr;}
        break;
    case 2:

        query.prepare("Select * from PERSONNE where ADRESSE = :achat");
        query.bindValue(":achat", key);
       query.exec();
       model->setQuery(query);
       if((model->record(0)).isEmpty() == true){return model = nullptr;}
        break;
    default:
        model = nullptr;
        break;
    }
    return model;
}
 int Personne::nombre=20;
QSqlQueryModel * Personne :: sort (int type){

    QSqlQueryModel * model= new QSqlQueryModel();
    switch (type) {

    case 0:
        if(Personne::nombre!=0)
        {
        model->setQuery("select * from PERSONNE order by ID asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEN "));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE "));
        Personne::nombre=0;
        }
        else if(Personne::nombre==0)
        {
            model->setQuery("select * from PERSONNE");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEN "));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE "));
            Personne::nombre=20;
        }
        break ;
      case 1 :
        if(Personne::nombre!=1)
        {
        model->setQuery("select * from PERSONNE order by NOM asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEN "));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE "));
        Personne::nombre=1;
        }
        else if(Personne::nombre==1)
        {
            model->setQuery("select * from PERSONNE");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEN "));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE "));
            Personne::nombre=20;
        }
        break;
      case 2 :
        if(Personne::nombre!=2)
        {
        model->setQuery("select * from PERSONNE order by PRENOM asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEN "));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE "));
        Personne::nombre=2;
        }
        else if(Personne::nombre==2)
        {
            model->setQuery("select * from PERSONNE");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEN "));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE "));
            Personne::nombre=20;
        }
        break;

      case 3 :
        if(Personne::nombre!=3)
        {
        model->setQuery("select * from PERSONNE order by ADRESSE asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEN "));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE "));
        Personne::nombre=3;
        }
        else if(Personne::nombre==3)
        {
            model->setQuery("select * from PERSONNE");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEN "));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE "));
            Personne::nombre=20;
        }
        break;

      case 4 :
        if(Personne::nombre!=4)
        {
        model->setQuery("select * from PERSONNE order by DATEN asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEN "));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE "));
        Personne::nombre=4;
        }
        else if(Personne::nombre==4)
        {
            model->setQuery("select * from PERSONNE");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEN "));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE "));
            Personne::nombre=20;
        }
        break ;
      case 5 :
        if(Personne::nombre!=5)
        {
        model->setQuery("select * from PERSONNE order by SEXE asc");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEN "));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE "));
        Personne::nombre=5;
        }
        else if(Personne::nombre==5)
        {
            model->setQuery("select * from PERSONNE");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEN "));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("SEXE "));
            Personne::nombre=20;
        }
        break;


    }


        return model;
}

void Personne::recherche_id_place(QTableView *table, QString res)
{

QSqlQueryModel *model=new QSqlQueryModel() ;
QSqlQuery qry ;
if(res !="")
{
qry.prepare("Select * from PERSONNE where (regexp_like(ID,:id))");
qry.bindValue(":id",res);
}
else {
    qry.prepare("Select * from PERSONNE ");
}
qry.exec() ;
model->setQuery(qry) ;
table->setModel(model) ;
table->show() ;
}
