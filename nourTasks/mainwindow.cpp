 #include "mainwindow.h"
#include "equipement.h"
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

 MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_equipement->setModel(E.afficher());
   // ui->tab_equipement->setModel(E.afficher());
    QPieSeries *series = new QPieSeries();

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


    series->append("endommage",count);
    series->append("bien",count1);

    QChart * chart =new QChart();
    chart-> addSeries(series);
    chart->setTitle("Statistiques des équipements");

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
    int etatEquipement=ui->le_etat->text().toInt();
    QString nomEquipement=ui->le_nom->text();
    QString typeEquipement=ui->le_type->text();
    QString dateFabrication=ui->la_date->text();

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
       E1.setIdEquipement(ui->le_id_supp->text().toInt());
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
    int etatEquipement=ui->le_etat->text().toInt();
    QString nomEquipement=ui->le_nom->text();
    QString typeEquipement=ui->le_type->text();
    QString dateFabrication=ui->la_date->text();


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

   QString dureeMaintenance=ui->duree_maintenance->text();
   QString dateEntreeM=ui->date_entree_maintenance->text();
   QString dateSortieM=ui->date_sortie_maintenance->text();

        Maintenance M(idMaintenance,dureeMaintenance,dateEntreeM,dateSortieM,frais);
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
            ui->le_id_supp->setText(query.value(0).toString());
            ui->le_nom->setText(query.value(1).toString());
            ui->le_type->setText(query.value(2).toString());
            ui->la_quantite->setText(query.value(3).toString());
            ui->le_etat->setText(query.value(4).toString());
            ui->la_date->setText(query.value(5).toString());
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
