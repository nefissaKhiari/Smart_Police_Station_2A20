#include "mainwindow.h"
#include "agent.h"
#include "service.h"
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

//#include <QUrDesktopServices>
#include "stats.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->le_id->setValidator( new QIntValidator(0, 999, this));
   ui->tab_agent->setModel(D.afficher_agent());
   ui->tab_service->setModel(C.afficher_service());

   /*QPieSeries *series = new QPieSeries();

         QSqlQuery query;
           int count=0 ;
           QSqlQuery requete("select * from agent where sexe_agent='femme'") ;
           while(requete.next())
           {
                   count++ ;
           }

           QSqlQuery query1;
             int count1=0 ;
             QSqlQuery requete1("select * from agent where sexe_agent='homme'") ;
             while(requete1.next())
             {
                     count1++ ;
             }


       series->append("femme",count);
       series->append("homme",count1);

       QChart * chart =new QChart();
       chart-> addSeries(series);
       chart->setTitle("Statistiques des agent par Sexe ");

       QChartView *chartview= new QChartView (chart);
       chartview->setParent(ui->frame_charts);*/
}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_ajouter_clicked()
{
    int id_agent=ui->le_id->text().toInt();
    QString nom_agent=ui->le_nom->text();
    QString prenom_agent=ui->le_prenom->text();
    QString date_naissance_agent=ui->la_date->text();
    QString nationalite_agent=ui->la_nationalite->text();
    QString sexe_agent=ui->le_sexe->text();
    int taille_agent=ui->la_taille->text().toInt();
    int poids_agent=ui->le_poids->text().toInt();
    QString periode_agent=ui->la_periode->text();
    QString dossier_agent=ui->le_dossier->text();


    agent D(id_agent, nom_agent, prenom_agent,date_naissance_agent,nationalite_agent,sexe_agent,taille_agent,poids_agent,periode_agent,dossier_agent);
    bool test=D.ajouter_agent();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succés");
        ui->tab_agent->setModel(D.afficher_agent());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    agent D1; D1.setid_agent(ui->le_id->text().toInt());
    bool test=D1.supprimer_agent(D1.getid_agent());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprimer avec succés");
     ui->tab_agent->setModel(D.afficher_agent());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();

}

void MainWindow::on_pb_modifier_clicked()
{
    int id_agent=ui->le_id->text().toInt();
    QString nom_agent=ui->le_nom->text();
    QString prenom_agent=ui->le_prenom->text();
    QString date_naissance_agent=ui->la_date->text();
    QString nationalite_agent=ui->la_nationalite->text();
    QString sexe_agent=ui->le_sexe->text();
    int taille_agent=ui->la_taille->text().toInt();;
    int poids_agent=ui->le_poids->text().toInt();;
    QString periode_agent=ui->la_periode->text();
    QString dossier_agent=ui->le_dossier->text();


    agent Det(id_agent, nom_agent, prenom_agent,date_naissance_agent,nationalite_agent,sexe_agent,taille_agent,poids_agent,periode_agent,dossier_agent);
     bool test=Det.modifier_agent(Det.getid_agent(),Det.getnom_agent(),Det.getprenom_agent(),Det.getdate_naissance_agent(),Det.getnationalite_agent(),Det.getsexe_agent(),Det.gettaille_agent(),Det.getpoids_agent(),Det.getperiode_agent(),Det.getdossier_agent());
     QMessageBox msgBox;

     if(test)
        { msgBox.setText("Modification avec succés");
         ui->tab_agent->setModel(Det.afficher_agent());
     }
     else
         msgBox.setText("Echec de modification");
     msgBox.exec();
}

void MainWindow::on_tab_agent_activated(const QModelIndex &index)
{
    QString val=ui->tab_agent->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select* from agent where id_agent='"+val+"' ");
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

              }
}
}

void MainWindow::on_pb_ajouter_service_clicked()
{
    int id_service=ui->le_id_2->text().toInt();
    QString type_service=ui->le_type_service->text();
    int nb_agentss=ui->le_nb_agentss->text().toInt();
    int superficie_service=ui->la_superficie->text().toInt();
    int nb_agents=ui->le_nb_agents->text().toInt();
   service C(id_service, type_service, nb_agentss, superficie_service ,  nb_agents );
    bool test=C.ajouter_service();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succés");
        ui->tab_service->setModel(C.afficher_service());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}




void MainWindow::on_pb_supprimer_service_clicked()
{
    service C1; C1.setid_service(ui->le_id_2->text().toInt());
    bool test=C1.supprimer_service(C1.getid_service());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprimer avec succés");
     ui->tab_service->setModel(C1.afficher_service());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}




void MainWindow::on_tab_service_activated(const QModelIndex &index)
{
    QString val=ui->tab_service->model()->data(index).toString();
        QSqlQuery query;
        query.prepare("select* from service where id_service='"+val+"' ");
        if (query.exec())
        { while(query.next())
            {
                ui->le_id_2->setText(query.value(0).toString());
                ui->le_id_2->setText(query.value(0).toString());//suppression
                ui->le_type_service->setText(query.value(1).toString());
                ui->le_nb_agentss->setText(query.value(2).toString());
                ui->la_superficie->setText(query.value(3).toString());
                ui->le_nb_agents->setText(query.value(4).toString());

              }
}
}



void MainWindow::on_modifier_service_clicked()
{
    int id_service=ui->le_id_2->text().toInt();
    QString type_service=ui->le_type_service->text();
    int nb_agentss=ui->le_nb_agentss->text().toInt();
    int superficie_service=ui->la_superficie->text().toInt();
    int nb_agents=ui->le_nb_agents->text().toInt();

    service C(id_service, type_service, nb_agentss, superficie_service ,  nb_agents );
     bool test=C.modifier_service(C.getid_service(),C.gettype_service(),C.getnb_agentss(),C.getsuperficie_service(),C.getnb_agents());
     QMessageBox msgBox;

     if(test)
        { msgBox.setText("Modification avec succés");
         ui->tab_service->setModel(C.afficher_service());
     }
     else
         msgBox.setText("Echec de modification");
     msgBox.exec();



}

/*void MainWindow::on_pushButton_6_clicked()
{
    ui->tab_service->setModel(tmpservice.tri_service());
    ui->tab_service->setModel(tmpservice.tri_service());//refresh
}*/

void MainWindow::on_pdf_agent_clicked()
{

    //QDateTime datecreation = date.currentDateTime();
                       //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                              QPdfWriter pdf("C:/Users/POSTE HP/Desktop/PDF/Pdf.pdf");
                              QPainter painter(&pdf);
                             int i = 4000;
                                  painter.setPen(Qt::red);
                                  painter.setFont(QFont("Arial Black", 30));
                                  painter.drawText(1500,1200," Tableau de agent");
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
                                  query.prepare("select * from agent");
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
                                          QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/POSTE HP/Desktop/PDF/Pdf.pdf"));
                                      }
                                      if (reponse == QMessageBox::No)
                                      {
                                           painter.end();
                                      }
}

void MainWindow::on_pb_trier_service_clicked()
{
    QString type = ui->comboBox_service->currentText();
        if (type == "nb_agents")
        {
            ui->tab_service->setModel(tmpservice.tri_nb_agents());
        }else if (type == "id_service")
        {
            ui->tab_service->setModel(tmpservice.tri_id_service());
}else if (type == "nb_agentss")
        {
            ui->tab_service->setModel(tmpservice.tri_nb_agentss());
}
}
/*void MainWindow::on_pb_rechercher_service_clicked()
{
    QString type = ui->comboBox_recherche->currentText();
        QString valeur = ui->recher_service->currentText();
        bool test = false, test1 = false, test2 = false;
        if (type == "id_service")
            test = tmpservice.recherche_id_service(valeur);
        else if (type == "type_service")
            test1 = tmpservice.recherche_type_service(valeur);
        else if (type == "nb_agents")
            test2 = tmpservice.recherche_nb_agents(valeur);

        if (test || test1 || test2)
        {
            int id_service = tmpservice.getid_service();
            QString type_service = tmpservice.gettype_service();
            int nb_agentss = tmpservice.getnb_agents();
            int superficie_service = tmpservice.getsuperficie_service();
            int nb_agents = tmpservice.getnb_agents();

            ui->recher_service->setCurrentText(id_service);
            ui->comboBox_mail_4->setCurrentText(email);
            ui->comboBox_film_3->setCurrentText(film);
            ui->spinBox_quantite_4->setValue(quantite);
            ui->spinBox_remise_3->setValue(remise);
            ui->comboBox_salle_3->setCurrentText(salle);
            ui->sieges_3->setText(siege);
            ui->spinBox_prix_3->setValue(prix);
            ui->dateEdit_billet->setDate(QDate::fromString(date,"MM/dd/yyyy"));
            ui->timeEdit_billet->setTime(QTime::fromString(heure,"hh:mm"));
            ui->comboBox_tarif_3->setCurrentText(tarif);
        }
    }
*/

void MainWindow::on_pushButton_clicked()
{
    stats stat;
    stat.Statistique();
    stat.setModal(true);
    stat.exec();
}
void MainWindow::on_pb_rechercher_service_clicked()
{
    QString res=ui->recher_service->text();

        ui->tab_service->setModel(tmpservice.rechercher_service(res));
}



void MainWindow::on_pushButton_2_clicked()
{

        QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->tab_service->model()->rowCount();
                const int columnCount = ui->tab_service->model()->columnCount();
                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    << "<title>ERP - COMmANDE LIST<title>\n "
                    << "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<h1 style=\"text-align: center;\"><strong> *****LISTE DES Factures ***** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tab_service->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tab_service->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tab_service->isColumnHidden(column)) {
                            QString data =ui->tab_service->model()->data(ui->tab_service->model()->index(row, column)).toString().simplified();
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



