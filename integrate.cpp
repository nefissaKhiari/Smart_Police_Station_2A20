
#include "plaintes.h"
#include "personne.h"
#include "ui_integrate.h"
#include "integrate.h"
#include "ui_mainwindow.h"
#include <QHeaderView>
#include "mailing/mailing/SmtpMime"
#include "QtPrintSupport/QPrinter"
#include "QImage"
#include "QPainter"
#include "iostream"



QT_CHARTS_USE_NAMESPACE


void integrate::on_ajouter_p6_clicked()
{
    ui->stackedWidget6->setCurrentIndex(1) ;
    p = new Personne();
   QSqlQueryModel *model = p->afficher();
   ui->tableView_66->setModel(model);
   delete p ;
}


void integrate::on_supprimer_p6_clicked()
{
    ui->stackedWidget6->setCurrentIndex(3) ;
    p= new Personne();
   QSqlQueryModel *model = p->afficher();
   ui->tableView_86->setModel(model);
   delete p ;
}

void integrate::on_modifier_p6_clicked()
{
    ui->stackedWidget6->setCurrentIndex(2) ;
    p = new Personne();
   QSqlQueryModel *model = p->afficher();
   ui->tableView_76->setModel(model);
   delete p ;
}

void integrate::on_search_button6_clicked()
{
    QString key = ui->espace_chercher6->toPlainText();
    int index = ui->comboBox6->currentIndex();


    Personne * s = new Personne();
    QSqlQueryModel * q = s->search(index, key);
    if(q != nullptr){
        ui->table_personne6->setModel(q);
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Warning"),
          QObject::tr("Personne non trouvé."), QMessageBox::Cancel);
    }
}

void integrate::on_refresh6_clicked()
{
    p = new Personne();
   QSqlQueryModel *model = p->afficher();
   ui->table_personne6->setModel(model);
   delete p ;
}

void integrate::on_espace_chercher6_textChanged()
{
    Personne b;
  QString index=ui->espace_chercher6->toPlainText() ;
   b.recherche_id_place(ui->table_personne6,index) ;
}


void integrate::on_annulerA6_clicked()
{
    ui->stackedWidget6->setCurrentIndex(0);
    on_refresh6_clicked() ;
}

void integrate::on_annuler_M6_clicked()
{
    ui->stackedWidget6->setCurrentIndex(0);
    on_refresh6_clicked() ;
}

void integrate::on_annuler_S6_clicked()
{
 ui->stackedWidget6->setCurrentIndex(0);
 on_refresh6_clicked() ;
}

void integrate::on_confirmer_A_R6_clicked()
{


QRegExp re("\\d*");
int id=0 ;
int control=1;
if (re.exactMatch(ui->id_line6->text()))
{
         id = ui->id_line6->text().toInt();
}
else {
    QMessageBox::critical(nullptr, QObject::tr("Warning"),
      QObject::tr("écrivez un nombre dans le champ ID"), QMessageBox::Cancel);
    control=0;
}

    QString nom= ui->name_line6->text();
    QString prenom= ui->prenom_line6->text();
    QString adresse= ui->adress_line6->text();
     QString date= ui->dateEdit_dateA6->text();
     QString sexe= ui->comboBox_26->currentText();

     if (  nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() )
     {
         QMessageBox::critical(nullptr, QObject::tr("Warning"),
           QObject::tr(" veuillez remplier tous les champs."), QMessageBox::Cancel);
         control=0;
     }



   if(control==1)
   {
       SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);





              smtp.setUser("ForminiTN@gmail.com");

              smtp.setPassword("538886282A1");







              MimeMessage message;



              message.setSender(new EmailAddress("ForminiTN@gmail.com", "formini"));

              message.addRecipient(new EmailAddress("arije.grissiaa@esprit.tn", "arije"));

              message.setSubject("SmtpClient for Qt - Demo");







              MimeText text;



              text.setText("Hi,\n une personne est ajouter\n");







              message.addPart(&text);






              smtp.connectToHost();

              smtp.login();

              if(smtp.sendMail(message))
              {
                  QMessageBox::information(nullptr, QObject::tr("mailing"),
                                  QObject::tr("mailing.\n"
                                              "Click Ok to exit."), QMessageBox::Accepted);
              }

              smtp.quit();



       QPrinter printer;
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setOutputFileName("C:/Users/ARIJ/Downloads/Arij_projet (2)/Arij_projet/file.pdf");
       QPainter painter;
       painter.begin(&printer);
       QImage image("C:/Users/ARIJ/Downloads/Arij_projet (2)/Arij_projet/abcd.jpg");
       painter.drawImage(0,0,image);
       QFont font;

       font.setPixelSize(50);
       painter.setFont(font);
       painter.setPen(Qt::red);
       painter.drawText(50,150,"Fiche Des Personne Recherchee: ");
       font.setPixelSize(35);
       painter.setFont(font);
       painter.setPen(Qt::red);
       painter.drawText(400,300,"Nom: ");
       painter.drawText(400,500,"Prenom:");
       painter.drawText(400,650,"Adresse:");
       painter.drawText(400,800,"Date:");
       painter.drawText(400,1000,"Sexe:");




       font.setPixelSize(20);
       painter.setFont(font);
       painter.setPen(Qt::black);
       painter.drawText(400,350,nom);
       painter.drawText(400,550,prenom);
       painter.drawText(400,700,adresse);
       painter.drawText(400,850,date);
       painter.drawText(400,1050,sexe);




       painter.end();






     mysystem->show();
     mysystem->showMessage(tr("notification"),tr("ajout avec succes"));
       Personne b(id,nom,prenom,adresse,date,sexe);
       bool test=b.ajouter();
       if(test)
       {

       QMessageBox::information(nullptr, QObject::tr("Ajouter une Personne"),
                       QObject::tr("Personne ajouté.\n"
                                   "Click Ok to exit."), QMessageBox::Accepted);
       ui->stackedWidget6->setCurrentIndex(0) ;
       on_refresh6_clicked() ;

       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Ajouter un Personne"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);



   }






}

void integrate::on_confirmerM_R6_clicked()
{
    QRegExp re("\\d*");
    int id=0 ;
    int control=1;
    if (re.exactMatch(ui->id_line_26->text()))
    {
             id = ui->id_line_26->text().toInt();
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Warning"),
          QObject::tr("écrivez un nombre dans le champ ID"), QMessageBox::Cancel);
        control=0;
    }


    QString nom= ui->name_line_26->text();
    QString prenom= ui->prenom_line_26->text();
    QString adresse= ui->lineEdit_idA_76->text();

     QString date= ui->dateEdit_dateA_26->text();
     QString sexe= ui->comboBox_36->currentText();

     if (  nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() )
     {
         QMessageBox::critical(nullptr, QObject::tr("Warning"),
           QObject::tr(" veuillez remplier tous les champs."), QMessageBox::Cancel);
         control=0;
     }
     if(control==1)
     {
   mysystem->show();
   mysystem->showMessage(tr("notification"),tr("modifcation avec succes"));
  Personne b(id,nom,prenom,adresse,date,sexe);
  bool test=b.update();
  if(test)
  {

  QMessageBox::information(nullptr, QObject::tr("Modifer une Personne"),
                  QObject::tr("Personne modifié.\n"
                              "Click Ok to exit."), QMessageBox::Accepted);
   ui->stackedWidget6->setCurrentIndex(0) ;
   on_refresh6_clicked() ;
  }
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier une Personne"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  }
}


void integrate::on_confimerS_R6_clicked()
{
    int id = ui->lineEdit_S->text().toInt();
    bool test=tmppers.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer personne"),
                    QObject::tr("Personne supprimé.\n"
                                "Click Ok to exit."), QMessageBox::Accepted);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Personne"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->stackedWidget6->setCurrentIndex(0) ;
    on_refresh6_clicked() ;
}

void integrate::on_ajouter_S6_clicked()
{
  ui->stackedWidget_26->setCurrentIndex(1);
}

void integrate::on_modifier_S6_clicked()
{
  ui->stackedWidget_26->setCurrentIndex(3);
}

void integrate::on_supprimer_S6_clicked()
{
    ui->stackedWidget_26->setCurrentIndex(2);
}

void integrate::on_annulerAS6_clicked()
{
    ui->stackedWidget_26->setCurrentIndex(0);
  // ui->tableView_2->setModel(tmpp.afficher());
    on_refresh6_clicked() ;
}

void integrate::on_annuler_SS6_clicked()
{
    ui->stackedWidget_26->setCurrentIndex(0);
   // ui->tableView_2->setModel(tmpp.afficher());
    on_refresh6_clicked() ;
}

void integrate::on_annnulerMS6_clicked()
{
    ui->stackedWidget_26->setCurrentIndex(0);
   // ui->tableView_2->setModel(tmpp.afficher());
    on_refresh6_clicked() ;
}

void integrate::on_confirmerSS6_clicked()
{
    int id=ui->lineEdit_idSE6->text().toInt();

    bool test=tmpp.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer une Plainte"),
                    QObject::tr("Plainte supprimé.\n"
                                "Click Ok to exit."), QMessageBox::Accepted);
        ui->stackedWidget_26->setCurrentIndex(0);
      // ui->tableView_2->setModel(tmpp.afficher());
        on_refresh6_clicked() ;

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une Plainte"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->stackedWidget_26->setCurrentIndex(0);
  // ui->tableView_2->setModel(tmpp.afficher());
    on_refresh6_clicked() ;
}





void integrate::on_confirmerMS66_clicked()
{

    QRegExp re("\\d*");
    int id=0 ;
    int control=1;
    if (re.exactMatch(ui->lineEdit_idMS6->text())  )
    {
             id = ui->lineEdit_idMS6->text().toInt();

    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Warning"),
          QObject::tr("écrivez un nombre dans le champ ID et IDP"), QMessageBox::Cancel);
        control=0;
    }

    QString raison= ui->lineEdit_nomMS6->text();
    QString date= ui->dateEdit_dateMS6->text();
    QString type= ui->comboBox_serviceMS6->currentText();

    if (  raison.isEmpty() )
    {
        QMessageBox::critical(nullptr, QObject::tr("Warning"),
          QObject::tr(" veuillez remplier tous les champs."), QMessageBox::Cancel);
        control=0;
    }
    if(control==1)
    {
 Plaintes e(id,raison,date,type,0);
  bool test=e.update();
  if(test)
{
QMessageBox::information(nullptr, QObject::tr("Modifier une Plainte"),
                  QObject::tr("Plainte modifié.\n"
                              "Click Ok to exit."), QMessageBox::Accepted);
ui->stackedWidget_26->setCurrentIndex(0);
//ui->tableView_2->setModel(tmpp.afficher());
on_refresh6_clicked() ;

}
  else
      QMessageBox::critical(nullptr, QObject::tr("echec "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
}
void integrate::on_confirmerAS6_clicked()
{

    QRegExp re("\\d*");
    int id=0,idp=0 ;
    int control=1;
    if (re.exactMatch(ui->lineEdit_idAS6->text()) &&  re.exactMatch(ui->lineEdit_idpersonneAS6->text()))
    {
             id = ui->lineEdit_idAS6->text().toInt();
             idp= ui->lineEdit_idpersonneAS6->text().toInt();
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Warning"),
          QObject::tr("écrivez un nombre dans le champ ID"), QMessageBox::Cancel);
        control=0;
    }

    QString raison= ui->lineEdit_raisonAS6->text();
    QString type= ui->comboBox_serviceAS6->currentText();
    QString date= ui->dateEdit_dateAS6->text();
    if (  raison.isEmpty() )
    {
        QMessageBox::critical(nullptr, QObject::tr("Warning"),
          QObject::tr(" veuillez remplier tous les champs."), QMessageBox::Cancel);
        control=0;
    }
    if(control==1)
    {
 Plaintes e(id,raison,date,type,idp);
  bool test=e.ajouter();
  ui->dateEdit_dateAS6->clear() ;
 ui->lineEdit_idAS6->clear() ;
 ui->lineEdit_raisonAS6->clear() ;
  if(test)
{
QMessageBox::information(nullptr, QObject::tr("Ajouter une Plainte"),
                  QObject::tr("Plainte ajouté.\n"
                              "Click Ok to exit."), QMessageBox::Accepted);
 ui->stackedWidget_26->setCurrentIndex(0);
 //ui->tableView_2->setModel(tmpp.afficher());
 on_refresh6_clicked() ;

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une Plainte"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
}
void integrate:: modifierr6(int index)
{




    QSqlQueryModel * model = trier1->sort(index);
     ui->table_personne6->setModel(model);



}
int integrate :: getIDFromTableView6(QTableView * tv){
    int id =-1;
    if(tv->currentIndex().isValid() == true){
    QModelIndexList indexes = tv->selectionModel()->selection().indexes();
    QVariant qv = indexes.at(0).data();
    QString ss = qv.toString();
    std::string cc = ss.toStdString();
    id = std::atoi (cc.c_str());
    }else{
        id = -1;
    }
    return id;
}
 void integrate::on_table_personne6_clicked()
{
     int id = getIDFromTableView6(ui->table_personne6);
     Plaintes * s = new Plaintes();
     QSqlQueryModel * model = s->afficher(id) ;
     ui->tableView_26->setModel(model);
     ui->tableView_26->setColumnHidden(4,true) ;
     delete s;
}
void integrate::on_pushButton_166_clicked()
{
    stat = new statistique_etat(this) ;
    //![1]
        QBarSet *set0 = new QBarSet("Femmes");
        QBarSet *set1 = new QBarSet("Hommes");

        int nb0=0;
        QSqlQuery query0("select * from PERSONNE  where SEXE = 'Femme'");
        while(query0.next())
        {
            nb0++;
        }
        int nb1=0;
        QSqlQuery query1("select * from  PERSONNE  where SEXE = 'Homme'");
        while(query1.next())
        {
            nb1++;
        }
       // int nb2=0;


        *set0 << nb0 ;
        *set1 << nb1 ;

    //![1]

    //![2]
        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);

    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Etat");
        chart->setAnimationOptions(QChart::SeriesAnimations);
    //![3]

    //![4]
        QStringList categories;
        categories << "Statistique des Personnes";

        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);
   int nb=0;
   QSqlQuery query("select * from PERSONNE ");
   while(query.next())
   {
       nb++;
   }

        QValueAxis *axisY = new QValueAxis();
        axisY->setRange(0,nb);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);
    //![4]

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        stat->setCentralWidget(chartView);
        stat->show();
}




void integrate::on_pushButton6_clicked()
{
    hide();

}

