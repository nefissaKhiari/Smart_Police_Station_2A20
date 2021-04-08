 #include "mainwindow.h"
#include "equipement.h"
#include "stats.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>
#include <QPrinter>
#include<QPrintDialog>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QtWidgets>
#include<QDate>

 MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator( new QIntValidator(0,999,this));

       /*QString etatEquipement= ui->le_etat->text();
       if ( etatEquipement == "0" || etatEquipement =="1" )
        {

        }*/
    ui->tab_equipement->setModel(E.afficher());
    ui->tab_maintenance->setModel(M.afficherMaintenance());
    QSqlQuery query;
      int count=0 ;
      QSqlQuery requete("select * from equipement where etatequipement=0") ;
      while(requete.next())
      {
              count++ ;
      }


      QSqlQuery query1;
        int count1=0 ;
        QSqlQuery requete1("select * from equipement where etatequipement=1") ;
        while(requete1.next())
        {
                count1++ ;
        }
     /* series->append("endommage",count);
      series->append("bien",count1);

      QChart * chart =new QChart();
      chart-> addSeries(series);
      chart->setTitle("STATISTIQUES DES EQUIPEMENTS PAR ETAT ");

      QChartView *chartview= new QChartView (chart);
      chartview->setParent(ui->frame_charts);*/
        QBarSet *set0= new QBarSet(" Nombre des équipements endommagés");
        QBarSet *set1= new QBarSet("Nombre des équipements en bon etat");
       /* QBarSet *set2= new QBarSet("John");
        QBarSet *set3= new QBarSet("Nour");
        QBarSet *set4= new QBarSet("Ahmed");*/

        *set0 <<count ;
         *set1<<count1;
       /* *set2<<80<<100<<70<<13<<60<<20;
        *set3<<30<<10<<80<<70<<60<<45;
        *set4<<100<<40<<70<<30<<16<<42;*/
        QBarSeries *series= new QBarSeries();
          series->append(set0);
            series->append(set1);
             /* series->append(set2);
                series->append(set3);
                  series->append(set4);*/
       QChart * chart =new QChart();
          chart-> addSeries(series);
          chart->setTitle("Statistiques des Equipement Etat ");
          chart->setAnimationOptions(QChart::SeriesAnimations);
        QStringList categories;
        categories <<"Jan"<<"Feb"<<"Mar"<<"Apr"<<"May"<<"Jul";
        QBarCategoryAxis *axis= new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis,series);




        QChartView *chartview= new QChartView (chart);
        chartview->setParent(ui->frame_charts);




}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_ajouter_clicked()
{
    int idEquipement=ui->le_id->text().toInt();
    int quantiteEquipement=ui->la_quantite->text().toInt();
     int etatEquipement = ui->le_etat->text().toInt();

    QString nomEquipement=ui->le_nom->text();
    QString typeEquipement=ui->le_type->text();
    QDate dateFabrication=ui->la_date->date();

    Equipement E(idEquipement,quantiteEquipement,etatEquipement,nomEquipement,typeEquipement,dateFabrication);
    bool test=E.ajouterEquipement();
    QMessageBox msgBox;

        if(test)
           { msgBox.setText("Ajout avec succés");
            ui->tab_equipement->setModel(E.afficher());
        }
        else
            msgBox.setText("Echec d'ajout");
        msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Equipement E1;
       E1.setIdEquipement(ui->le_id->text().toInt());
        bool test=E1.supprimer(E1.getIdEquipement());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Supprimer avec succés");
        ui->tab_equipement->setModel(E1.afficher());
        }
        else
            msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void MainWindow::on_pb_modifier_clicked()
{

    int idEquipement=ui->le_id->text().toInt();
    int quantiteEquipement=ui->la_quantite->text().toInt();
    int etatEquipement = ui->le_etat->text().toInt();
    QString nomEquipement=ui->le_nom->text();
    QString typeEquipement=ui->le_type->text();
  QDate dateFabrication=ui->la_date->date();


  Equipement E(idEquipement,quantiteEquipement,etatEquipement,nomEquipement,typeEquipement,dateFabrication);



      bool test=E.modifier(idEquipement,nomEquipement, typeEquipement ,quantiteEquipement,etatEquipement,dateFabrication );
         QMessageBox msgBox;

         if(test)
            { msgBox.setText("Modification avec succés");
             ui->tab_equipement->setModel(E.afficher());
         }
         else
             msgBox.setText("Echec de modification");
         msgBox.exec();

}

void MainWindow::on_pb_ajouterMaintenance_clicked()
{
    int idMaintenance=ui->id_maintenance->text().toInt();
        int frais=ui->frais_maintenance->text().toInt();
        int fk_equipement=ui->frais_maintenance->text().toInt();

   QString dureeMaintenance=ui->duree_maintenance->text();
   QString dateEntreeM=ui->date_entree_maintenance->text();
   QString dateSortieM=ui->date_sortie_maintenance->text();

        Maintenance M(idMaintenance,dureeMaintenance,dateEntreeM,dateSortieM,frais,fk_equipement);
        bool test=M.ajouterMaintenance();
        QMessageBox msgBox;

            if(test)
               { msgBox.setText("Ajout avec succés");
                ui->tab_maintenance->setModel(M.afficherMaintenance());
            }
            else
                msgBox.setText("Echec d'e suppression'ajout");
            msgBox.exec();
}

void MainWindow::on_tab_equipement_activated(const QModelIndex &index)
{
    QString val=ui->tab_equipement->model()->data(index).toString();

    QSqlQuery query;
    query.prepare("select* from equipement where idEquipement='"+val+"' ");
    if (query.exec())
    { while(query.next())
        {
            ui->le_id->setText(query.value(0).toString());

            ui->le_nom->setText(query.value(1).toString());
            ui->le_type->setText(query.value(2).toString());
            ui->la_quantite->setText(query.value(3).toString());
            ui->le_etat->setText(query.value(4).toString());
          //  ui->la_date->setText(query.value(5).toString());
          }

     }
}



void MainWindow::on_trier_clicked()
{
    QString type = ui->comboBox_equipement->currentText();
    if (type == "etatEquipement")
    {
        ui->tab_equipement->setModel(E.tri_etat());
    }else if (type == "quantiteEquipement")
    {
        ui->tab_equipement->setModel(E.tri_quantite());

}

}






void MainWindow::on_pushButton_rechercher_clicked()
{
    QString res=ui->rech_equipement->text();

           ui->tab_equipement->setModel(E.rechercherEquipement(res));

}

void MainWindow::on_pushButton_pdf_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
                         //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                                QPdfWriter pdf("C:/Users/zraib/OneDrive/Bureau/nourPDF/Pdf.pdf");
                                QPainter painter(&pdf);
                               int i = 4000;
                                    painter.setPen(Qt::red);
                                    painter.setFont(QFont("Arial Black", 30));
                                    painter.drawText(1500,1200,"Tableau des equipements");
                                    painter.setPen(Qt::black);
                                    painter.setFont(QFont("Arial", 50));
                                   // painter.drawText(1100,2000,afficheDC);
                                   //painter.drawRect(100,100,100,100);
                                      painter.drawRect(200,100,7700,2100);
                                    //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                                    painter.drawRect(0,3000,9600,500);
                                    painter.setFont(QFont("Arial", 9));
                                    painter.drawText(250,3300,"Id");
                                    painter.drawText(1000,3300,"Nom equipement");
                                    painter.drawText(2400,3300,"Type equipement");
                                    painter.drawText(3800,3300,"Quantité equipement ");

                                    painter.drawText(5500,3300,"Etat equipement");
                                    painter.drawText(7000,3300,"Date de fabrication");


                                    QSqlQuery query;

                                    query.prepare("select * from equipement");
                                    query.exec();
                                    while (query.next())
                                    {
                                        painter.drawText(250,i,query.value(0).toString());
                                        painter.drawText(1000,i,query.value(1).toString());
                                        painter.drawText(2400,i,query.value(2).toString());
                                        painter.drawText(3800,i,query.value(3).toString());
                                        painter.drawText(5500,i,query.value(4).toString());
                                        painter.drawText(7000,i,query.value(5).toString());

                                      i = i + 500;
                                    }
                                    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                        if (reponse == QMessageBox::Yes)
                                        {
                                            QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/zraib/OneDrive/Bureau/nourPDF/Pdf.pdf"));
                                        }
                                        if (reponse == QMessageBox::No)
                                        {
                                             painter.end();
                                        }
}

void MainWindow::on_actionprint_triggered()
{
   QPrinter printer;
   QPrintDialog dialog(&printer,this);
   dialog.setWindowTitle("Print Document");
   if (ui->tab_equipement->SelectRows)


    dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);
   if (dialog.exec()!=QDialog::Accepted)
    {
        return;
    }
}















void MainWindow::on_actionGenerate_pdf_triggered()
{
    //QDateTime datecreation = date.currentDateTime();
                         //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                                QPdfWriter pdf("C:/Users/zraib/OneDrive/Bureau/nourPDF/Pdf.pdf");
                                QPainter painter(&pdf);
                               int i = 4000;
                                    painter.setPen(Qt::red);
                                    painter.setFont(QFont("Arial Black", 30));
                                    painter.drawText(1500,1200,"Tableau des equipements");
                                    painter.setPen(Qt::black);
                                    painter.setFont(QFont("Arial", 50));
                                   // painter.drawText(1100,2000,afficheDC);
                                   //painter.drawRect(100,100,100,100);
                                      painter.drawRect(200,100,7700,2100);
                                    //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                                    painter.drawRect(0,3000,9600,500);
                                    painter.setFont(QFont("Arial", 9));
                                    painter.drawText(250,3300,"Id");
                                    painter.drawText(1000,3300,"Nom equipement");
                                    painter.drawText(2400,3300,"Type equipement");
                                    painter.drawText(3800,3300,"Quantité equipement ");

                                    painter.drawText(5500,3300,"Etat equipement");
                                    painter.drawText(7000,3300,"Date de fabrication");


                                    QSqlQuery query;

                                    query.prepare("select * from equipement");
                                    query.exec();
                                    while (query.next())
                                    {
                                        painter.drawText(250,i,query.value(0).toString());
                                        painter.drawText(1000,i,query.value(1).toString());
                                        painter.drawText(2400,i,query.value(2).toString());
                                        painter.drawText(3800,i,query.value(3).toString());
                                        painter.drawText(5500,i,query.value(4).toString());
                                        painter.drawText(7000,i,query.value(5).toString());

                                      i = i + 500;
                                    }
                                    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                        if (reponse == QMessageBox::Yes)
                                        {
                                            QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/zraib/OneDrive/Bureau/nourPDF/Pdf.pdf"));
                                        }
                                        if (reponse == QMessageBox::No)
                                        {
                                             painter.end();
                                        }
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}



void MainWindow::on_tab_maintenance_activated(const QModelIndex &index)
{
    QString val=ui->tab_maintenance->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select* from maintenance where idMaintenance='"+val+"' ");
    if (query.exec())
    { while(query.next())
        {
            ui->id_maintenance->setText(query.value(0).toString());
            ui->id_sup->setText(query.value(0).toString());
            ui->duree_maintenance->setText(query.value(1).toString());
            ui->date_entree_maintenance->setText(query.value(2).toString());
            ui->date_sortie_maintenance->setText(query.value(3).toString());
            ui->frais_maintenance->setText(query.value(4).toString());

          }

     }
}

void MainWindow::on_pushButton_supprimer_maintenance_clicked()
{
    Maintenance M;
       M.setIdMaintenance(ui->le_id->text().toInt());
        bool test=M.supprimerMaintenance(M.getIdMaintenance());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Supprimer avec succés");
        ui->tab_maintenance->setModel(M.afficherMaintenance());
        }
        else
            msgBox.setText("Echec de suppression");
        msgBox.exec();

}

void MainWindow::on_pushButton_modifier_maintenance_clicked()
{
    int idMaintenance=ui->id_maintenance->text().toInt();
    int frais=ui->frais_maintenance->text().toInt();
    int fk_equipement=ui->fk_equipement_equipement->text().toInt();

    QString dureeMaintenance=ui->duree_maintenance->text();
    QString dateEntreeM=ui->date_entree_maintenance->text();
    QString dateSortieM=ui->date_sortie_maintenance->text();


  Maintenance M(idMaintenance,dureeMaintenance,dateEntreeM,dateSortieM,frais,fk_equipement);



      bool test=M.modifierMaintenance(idMaintenance,dureeMaintenance,dateEntreeM,dateSortieM,frais,fk_equipement);
         QMessageBox msgBox;

         if(test)
            { msgBox.setText("Modification avec succés");
             ui->tab_maintenance->setModel(M.afficherMaintenance());
         }
         else
             msgBox.setText("Echec de modification");
         msgBox.exec();

}

void MainWindow::on_pushButton_statistique_clicked()
{
    stats stat;
        stat.Statistique();
        stat.setModal(true);
        stat.exec();
}

void MainWindow::on_imprimer_clicked()
{

        QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->tab_equipement->model()->rowCount();
                const int columnCount = ui->tab_equipement->model()->columnCount();
                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    << "<title>ERP - COMmANDE LIST<title>\n "
                    << "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<h1 style=\"text-align: center;\"><strong> ****LISTE DES EQUIPEMENTS **** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tab_equipement->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tab_equipement->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tab_equipement->isColumnHidden(column)) {
                            QString data =ui->tab_equipement->model()->data(ui->tab_equipement->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table>\n"
                    "</body>\n"
                    "</html>\n";

                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);

                QPrinter printer;

                QPrintDialog *baba = new QPrintDialog(&printer, NULL);
                if (baba->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }

                delete document;

}



/*void MainWindow::on_Petition_clicked()
{

}*/

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



void MainWindow::on_pushButton_icon_upload_clicked()
{
     ui->tab_equipement->setModel(E.afficher());
}
