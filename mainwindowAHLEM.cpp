#include "mainwindow.h"
#include "detenu.h"
#include "cellule.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QIntValidator>
#include <QMessageBox>
#include<QPrinter>
#include<QPrintDialog>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QtWidgets>
#include <QMediaPlayer>
#include <QVideoWidget>
#include "exportexcelobject.h"
#include <QPropertyAnimation>
#include <QDateTime>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   ui->le_id->setValidator( new QIntValidator(0, 99, this));
   ui->le_id_2->setValidator( new QIntValidator(0, 99, this));
   ui->tab_detenu->setModel(D.afficher_detenu());
   ui->tab_cellule->setModel(C.afficher_cellule());

   animation = new QPropertyAnimation (ui ->frame,"geometry" );
                  // animation = new QPropertyAnimation (ui ->text_2,"geometry" );
                   animation->setDuration(3000) ;
                   animation->setStartValue(ui->frame->geometry());
                   animation->setEndValue(QRect(1,5,200,140)) ;
                   animation->start() ;

                   /***************/
                             QTimer *timer=new QTimer(this);
                           connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));
                           timer->start();
                           /*************************date*****************/
                           QDate date = QDate ::currentDate();
                           QString datee=date.toString();

                           ui->Date_2->setText(datee) ;


   QSqlQuery query;
int count=0 ;
QSqlQuery requete("select * from detenu where sexe_detenu='femme'") ;
while(requete.next())
{
       count++ ;
}


QSqlQuery query1;
 int count1=0 ;
 QSqlQuery requete1("select * from detenu where sexe_detenu='homme'") ;
 while(requete1.next())
 {
         count1++ ;
 }
 QBarSet *set0= new QBarSet(" Nombre des femmes");
 QBarSet *set1= new QBarSet("Nombre des hommes");


             *set0 <<count ;
             *set1<<count1;

             QBarSeries *series= new QBarSeries();
               series->append(set0);
                 series->append(set1);


            QChart * chart =new QChart();
               chart-> addSeries(series);
               chart->setTitle("Statistiques des detenus par rapport au sexe ");
               chart->setAnimationOptions(QChart::SeriesAnimations);
             QStringList categories;
             categories <<"Jan"<<"Feb"<<"Mar"<<"Apr"<<"May"<<"Jul";
             QBarCategoryAxis *axis= new QBarCategoryAxis();
             axis->append(categories);
             chart->createDefaultAxes();
             chart->setAxisX(axis,series);




             QChartView *chartview= new QChartView (chart);
              chartview->setParent(ui->frame_charts);
//Arduino***************
/* int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
*/
}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_ajouter_clicked()
{
    int id_detenu=ui->le_id->text().toInt();
    QString nom_detenu=ui->le_nom->text();
    QString prenom_detenu=ui->le_prenom->text();
    QString date_naissance_detenu=ui->la_date->text();
    QString nationalite_detenu=ui->la_nationalite->text();
    QString sexe_detenu=ui->le_sexe->text();
    int taille_detenu=ui->la_taille->text().toInt();
    int poids_detenu=ui->le_poids->text().toInt();
    QString periode_detenu=ui->la_periode->text();
    QString dossier_detenu=ui->le_dossier->text();
   // QString id_cellule=ui->comboBox->currentText();
    //int id_cellule=ui->le_id_cellule->text().toInt();

    Detenu D(id_detenu, nom_detenu, prenom_detenu,date_naissance_detenu,nationalite_detenu,sexe_detenu,taille_detenu,poids_detenu,periode_detenu,dossier_detenu);
    bool test=D.ajouter_detenu();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succés");
        ui->tab_detenu->setModel(D.afficher_detenu());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Detenu D1; D1.setid_detenu(ui->le_id->text().toInt());
    bool test=D1.supprimer_detenu(D1.getid_detenu());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprimer avec succés");
     ui->tab_detenu->setModel(D.afficher_detenu());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();

}

void MainWindow::on_pb_modifier_clicked()
{
    int id_detenu=ui->le_id->text().toInt();
    QString nom_detenu=ui->le_nom->text();
    QString prenom_detenu=ui->le_prenom->text();
    QString date_naissance_detenu=ui->la_date->text();
    QString nationalite_detenu=ui->la_nationalite->text();
    QString sexe_detenu=ui->le_sexe->text();
    int taille_detenu=ui->la_taille->text().toInt();;
    int poids_detenu=ui->le_poids->text().toInt();;
    QString periode_detenu=ui->la_periode->text();
    QString dossier_detenu=ui->le_dossier->text();
   // int id_cellule=ui->le_id_cellule->text().toInt();

    Detenu Det(id_detenu, nom_detenu, prenom_detenu,date_naissance_detenu,nationalite_detenu,sexe_detenu,taille_detenu,poids_detenu,periode_detenu,dossier_detenu/*id_cellule*/);
     bool test=Det.modifier_detenu(Det.getid_detenu(),Det.getnom_detenu(),Det.getprenom_detenu(),Det.getdate_naissance_detenu(),Det.getnationalite_detenu(),Det.getsexe_detenu(),Det.gettaille_detenu(),Det.getpoids_detenu(),Det.getperiode_detenu(),Det.getdossier_detenu()/*,Det.getid_cellule()*/);
     QMessageBox msgBox;

     if(test)
        { msgBox.setText("Modification avec succés");
         ui->tab_detenu->setModel(Det.afficher_detenu());
     }
     else
         msgBox.setText("Echec de modification");
     msgBox.exec();
}

void MainWindow::on_tab_detenu_activated(const QModelIndex &index)
{
    QString val=ui->tab_detenu->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select* from detenu where id_detenu='"+val+"' ");
        if (query.exec())
        { while(query.next())
            {
                ui->le_id->setText(query.value(0).toString());
                ui->le_id->setText(query.value(0).toString());//suppression
                ui->le_nom->setText(query.value(1).toString());
                ui->le_prenom->setText(query.value(2).toString());
                ui->la_date->setText(query.value(3).toString());
                ui->la_nationalite->setText(query.value(4).toString());
                ui->le_sexe->setText(query.value(5).toString());
                ui->la_taille->setText(query.value(6).toString());
                ui->le_poids->setText(query.value(7).toString());
                ui->la_periode->setText(query.value(8).toString());
                ui->le_dossier->setText(query.value(9).toString());
              //  ui->le_id_cellule->setText(query.value(10).toString());

              }
}
}

void MainWindow::on_pb_ajouter_cellule_clicked()
{
    int id_cellule=ui->le_id_2->text().toInt();
    QString type_cellule=ui->le_type_cellule->text();
    int nb_lits=ui->le_nb_lits->text().toInt();
    int superficie_cellule=ui->la_superficie->text().toInt();
    int nb_detenus=ui->le_nb_detenus->text().toInt();
   Cellule C(id_cellule, type_cellule, nb_lits, superficie_cellule ,  nb_detenus );
    bool test=C.ajouter_cellule();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succés");
        ui->tab_cellule->setModel(C.afficher_cellule());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}




void MainWindow::on_pb_supprimer_cellule_clicked()
{
    Cellule C1; C1.setid_cellule(ui->le_id_2->text().toInt());
    bool test=C1.supprimer_cellule(C1.getid_cellule());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprimer avec succés");
     ui->tab_cellule->setModel(C1.afficher_cellule());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}




void MainWindow::on_tab_cellule_activated(const QModelIndex &index)
{
    QString val=ui->tab_cellule->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select* from cellule where id_cellule='"+val+"' ");
        if (query.exec())
        { while(query.next())
            {
                ui->le_id_2->setText(query.value(0).toString());
                ui->le_id_2->setText(query.value(0).toString());//suppression
                ui->le_type_cellule->setText(query.value(1).toString());
                ui->le_nb_lits->setText(query.value(2).toString());
                ui->la_superficie->setText(query.value(3).toString());
                ui->le_nb_detenus->setText(query.value(4).toString());

              }
}
}



void MainWindow::on_modifier_cellule_clicked()
{
    int id_cellule=ui->le_id_2->text().toInt();
    QString type_cellule=ui->le_type_cellule->text();
    int nb_lits=ui->le_nb_lits->text().toInt();
    int superficie_cellule=ui->la_superficie->text().toInt();
    int nb_detenus=ui->le_nb_detenus->text().toInt();

    Cellule C(id_cellule, type_cellule, nb_lits, superficie_cellule ,  nb_detenus );
     bool test=C.modifier_cellule(C.getid_cellule(),C.gettype_cellule(),C.getnb_lits(),C.getsuperficie_cellule(),C.getnb_detenus());
     QMessageBox msgBox;

     if(test)
        { msgBox.setText("Modification avec succés");
         ui->tab_cellule->setModel(C.afficher_cellule());
     }
     else
         msgBox.setText("Echec de modification");
     msgBox.exec();



}


/*
void MainWindow::on_pdf_detenu_clicked()
{

    //QDateTime datecreation = date.currentDateTime();
                       //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                              QPdfWriter pdf("C:/Users/ASUS/Desktop/pdf detenu.pdf");
                              QPainter painter(&pdf);
                             int i = 4000;
                                  painter.setPen(Qt::red);
                                  painter.setFont(QFont("Arial Black", 30));
                                  painter.drawText(1500,1200," Tableau de Detenu");
                                  painter.setPen(Qt::black);
                                  painter.setFont(QFont("Arial", 50));
                                 // painter.drawText(1100,2000,afficheDC);
                                 //painter.drawRect(100,100,100,100);
                                    painter.drawRect(200,100,7700,2100);
                                  //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                                  painter.drawRect(0,3000,9600,500);
                                  painter.setFont(QFont("Arial", 9));
                                  painter.drawText(200,3300,"Id");
                                  painter.drawText(1200,3300,"Nom");
                                  painter.drawText(2400,3300,"Prenom");
                                  painter.drawText(3400,3300,"Date naissance");
                                  painter.drawText(4600,3300,"Nationalite");
                                  painter.drawText(5600,3300,"Sexe");
                                  painter.drawText(6200,3300,"Taille");
                                  painter.drawText(7100,3300,"Poids");
                                  painter.drawText(8000,3300,"Periode");
                                  painter.drawText(9000,3300,"Dossier");

                                  QSqlQuery query;
                                  query.prepare("select * from detenu");
                                  query.exec();
                                  while (query.next())
                                  {
                                      painter.drawText(200,i,query.value(0).toString());
                                      painter.drawText(1200,i,query.value(1).toString());
                                      painter.drawText(2400,i,query.value(2).toString());
                                      painter.drawText(3400,i,query.value(3).toString());
                                      painter.drawText(4600,i,query.value(4).toString());
                                     painter.drawText(5600,i,query.value(5).toString());
                                      painter.drawText(6200,i,query.value(6).toString());
                                      painter.drawText(7100,i,query.value(7).toString());
                                      painter.drawText(8000,i,query.value(8).toString());
                                      painter.drawText(9000,i,query.value(8).toString());

                                    i = i + 500;
                                  }
                                  int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                      if (reponse == QMessageBox::Yes)
                                      {
                                          QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/pdf detenu.pdf"));
                                      }
                                      if (reponse == QMessageBox::No)
                                      {
                                           painter.end();
                                      }
}*/

void MainWindow::on_pb_trier_cellule_clicked()
{
    QString type = ui->comboBox_cellule->currentText();
        if (type == "nb_detenus")
        {
            ui->tab_cellule->setModel(tmpcellule.tri_nb_detenus());
        }else if (type == "id_cellule")
        {
            ui->tab_cellule->setModel(tmpcellule.tri_id_cellule());
}else if (type == "nb_lits")
        {
            ui->tab_cellule->setModel(tmpcellule.tri_nb_lits());
}
}



void MainWindow::on_pb_rechercher_cellule_clicked()
{
    QString res=ui->recher_cellule->text();

        ui->tab_cellule->setModel(tmpcellule.rechercher_cellule(res));
}




void MainWindow::on_imprimer_clicked()
{

    QString strStream;
     QTextStream out(&strStream);
     const int rowCount = ui->tab_detenu->model()->rowCount();
     const int columnCount = ui->tab_detenu->model()->columnCount();
                     QString TT = QDate::currentDate().toString("yyyy/MM/dd");

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                             "<img src='C:/Users/ASUS/Desktop/Smart_Police_Station_2A20 final2/ifinal/Logo.png' width='300' height='150'>"


                         "<center> <H1>Liste des detenus "+TT+" </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#FF2E01> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tab_detenu->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tab_detenu->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tab_detenu->isColumnHidden(column)) {
                                 QString data = ui->tab_detenu->model()->data(ui->tab_detenu->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));


                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n";
out << "<tr>\n"

                         "</body>\n"
                         "</html>\n";

                     QTextDocument *document = new QTextDocument();
                     document->setHtml(strStream);
                     QPrinter printer;

                     QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                     if (dialog->exec() == QDialog::Accepted) {
                         document->print(&printer);
                     }

                     delete document;
}




void MainWindow::on_Petition_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
        ui->Petition->setGeometry(0,142,151,61);
        ui->Materiel->setGeometry(-40,180,201,81);
        ui->Agent->setGeometry(-14,246,151,51);
        ui->Crimes->setGeometry(0,299,121,51);
       ui->Plaintes->setGeometry(0,350,121,51);
        ui->Mission->setGeometry(9,400,111,41);
}



void MainWindow::on_Materiel_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
       ui->Petition->setGeometry(-17,142,151,61);
       ui->Materiel->setGeometry(-23,180,201,81);
       ui->Agent->setGeometry(-14,246,151,51);
       ui->Crimes->setGeometry(0,299,121,51);
       ui->Plaintes->setGeometry(0,350,121,51);
       ui->Mission->setGeometry(9,400,111,41);
}

void MainWindow::on_Agent_clicked()
{
    ui->stackedWidget->setCurrentIndex(3) ;
       ui->Petition->setGeometry(-17,142,151,61);
       ui->Materiel->setGeometry(-40,180,201,81);
       ui->Agent->setGeometry(0,246,151,51);
       ui->Crimes->setGeometry(0,299,121,51);
      ui->Plaintes->setGeometry(0,350,121,51);
       ui->Mission->setGeometry(9,400,111,41);
}

void MainWindow::on_Crimes_clicked()
{
    ui->stackedWidget->setCurrentIndex(4) ;
      ui->Petition->setGeometry(-17,142,151,61);
      ui->Materiel->setGeometry(-40,180,201,81);
      ui->Agent->setGeometry(-14,246,151,51);
      ui->Crimes->setGeometry(17,299,121,51);
      ui->Plaintes->setGeometry(0,350,121,51);
      ui->Mission->setGeometry(9,400,111,41);
}

void MainWindow::on_Plaintes_clicked()
{
    ui->stackedWidget->setCurrentIndex(5) ;
        ui->Petition->setGeometry(-17,142,151,61);
        ui->Materiel->setGeometry(-40,180,201,81);
        ui->Agent->setGeometry(-14,246,151,51);
        ui->Crimes->setGeometry(0,299,121,51);
        ui->Plaintes->setGeometry(17,350,121,51);
        ui->Mission->setGeometry(9,400,111,41);
}



/*
void MainWindow::on_Statistique_clicked()
{
    stats stat;
    stat.Statistique();
    stat.setModal(true);
    stat.exec();
}
*/
void MainWindow::on_Mission_clicked()
{
    ui->stackedWidget->setCurrentIndex(6) ;
      ui->Petition->setGeometry(-17,142,151,61);
      ui->Materiel->setGeometry(-40,180,201,81);
      ui->Agent->setGeometry(-14,246,151,51);
      ui->Crimes->setGeometry(0,299,121,51);
      ui->Plaintes->setGeometry(0,350,121,51);
      ui->Mission->setGeometry(26,400,111,41);
}

void MainWindow::on_pushButton_clicked()
{


    ui->tab_cellule->setModel(C.afficher_cellule());
}


/*
void MainWindow::on_Load_clicked()
{
    Connection c;
    QSqlQueryModel  * modal= new QSqlQueryModel();
    c.createconnect();

    QSqlQuery * query=new QSqlQuery (c.db);


     query->prepare("select id_cellule from cellule");
     query->exec();
     modal->setQuery(*query);

      ui->comboBox->setModel(modal);
qDebug() <<(modal->rowCount());
}

*/

void MainWindow::on_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                           tr("Excel Files (*.xls)"));
           if (fileName.isEmpty())
               return;

           ExportExcelObject obj(fileName, "mydata", ui->tab_cellule);

           //colums to export
           obj.addField(0, "IdCellule", "char(20)");
           obj.addField(1, "TypeCellule", "char(20)");
           obj.addField(2, "Nblits", "char(20)");
           obj.addField(3, "Superficie", "char(20)");
           obj.addField(4, "Nbdetenus", "char(50)");






           int retVal = obj.export2Excel();
           if( retVal > 0)
           {
               QMessageBox::information(this, tr("Done"),
                                        QString(tr("%1 records exported!")).arg(retVal)
                                        );
           }
}

/*void MainWindow::on_Video_clicked()
{
    QMediaPlayer* player=new QMediaPlayer;
    QVideoWidget* Vw=new QVideoWidget;
    player->setVideoOutput(Vw);
    player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Downloads/spot_pubicitaire_1.mp4"));
    Vw->setGeometry(100,100,600,400);
    Vw->show();
    player->play();
    qDebug()<<player->state();
}*/

void MainWindow::showtime ()
{
    QTime time = QTime::currentTime();

           QString time_text=time.toString("hh : mm : ss");
           if((time.second() % 2) == 0 )
           {
               time_text[3] = ' ';
               time_text[8] = ' ';
           }
           ui->digitalclock_2->setText(time_text) ;
}






void MainWindow::on_VIDEO_clicked()
{
    QMediaPlayer* player=new QMediaPlayer;
    QVideoWidget* Vw=new QVideoWidget;
    player->setVideoOutput(Vw);
    QString filename=QFileDialog::getOpenFileName((this));
        if(filename.isEmpty())
        return;
    player->setMedia(QUrl::fromLocalFile(filename));;
   // player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/Videoo.mpg"));
    Vw->setGeometry(100,100,600,400);
    Vw->show();
    player->play();
    qDebug()<<player->state();
}
