
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QPrinter>
#include<QPrintDialog>
#include<QPdfWriter>
#include<QPainter>
#include <QStaticText>
#include<QDesktopServices>
#include<QUrl>
#include <QtWidgets>
#include "smtp.h"
#include<QMediaPlayer>
#include <QtWidgets>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    son=new QSound("C:/Users/POSTE HP/Desktop/esprit/2eme/ifinal-_5_/ifinal/son/souu.wav");


    ui->tab_agent->setModel(tmp_agent.afficher_agent());

    ui->tab_service->setModel(tmp_service.afficher_service());


    timerr=new QTimer(this) ;
    connect(timerr , SIGNAL(timeout()),this,SLOT(myfunctionn())) ;
    timerr->start(1000) ;



}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_service_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
    ui->service->setGeometry(0,142,151,61);
    ui->Materiel->setGeometry(-40,180,201,81);
    ui->Agent->setGeometry(-14,246,151,51);
    ui->Crimes->setGeometry(0,299,121,51);
    ui->Plaintes->setGeometry(0,350,121,51);
    ui->Mission->setGeometry(9,400,111,41);
}

void MainWindow::on_Materiel_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
    ui->service->setGeometry(-17,142,151,61);
    ui->Materiel->setGeometry(-23,180,201,81);
    ui->Agent->setGeometry(-14,246,151,51);
    ui->Crimes->setGeometry(0,299,121,51);
    ui->Plaintes->setGeometry(0,350,121,51);
    ui->Mission->setGeometry(9,400,111,41);
}

void MainWindow::on_Agent_clicked()
{
    ui->stackedWidget->setCurrentIndex(3) ;
    ui->service->setGeometry(-17,142,151,61);
    ui->Materiel->setGeometry(-40,180,201,81);
    ui->Agent->setGeometry(0,246,151,51);
    ui->Crimes->setGeometry(0,299,121,51);
    ui->Plaintes->setGeometry(0,350,121,51);
    ui->Mission->setGeometry(9,400,111,41);
}

void MainWindow::on_Crimes_clicked()
{
    ui->stackedWidget->setCurrentIndex(4) ;
    ui->service->setGeometry(-17,142,151,61);
    ui->Materiel->setGeometry(-40,180,201,81);
    ui->Agent->setGeometry(-14,246,151,51);
    ui->Crimes->setGeometry(17,299,121,51);
    ui->Plaintes->setGeometry(0,350,121,51);
    ui->Mission->setGeometry(9,400,111,41);
}

void MainWindow::on_Plaintes_clicked()
{
    ui->stackedWidget->setCurrentIndex(5) ;
    ui->service->setGeometry(-17,142,151,61);
    ui->Materiel->setGeometry(-40,180,201,81);
    ui->Agent->setGeometry(-14,246,151,51);
    ui->Crimes->setGeometry(0,299,121,51);
    ui->Plaintes->setGeometry(17,350,121,51);
    ui->Mission->setGeometry(9,400,111,41);
}

void MainWindow::on_Mission_clicked()
{
    ui->stackedWidget->setCurrentIndex(6) ;
    ui->service->setGeometry(-17,142,151,61);
    ui->Materiel->setGeometry(-40,180,201,81);
    ui->Agent->setGeometry(-14,246,151,51);
    ui->Crimes->setGeometry(0,299,121,51);
    ui->Plaintes->setGeometry(0,350,121,51);
    ui->Mission->setGeometry(26,400,111,41);
}
void MainWindow::on_ajouter_agent_clicked()
{
    QString cin_agent=ui->cin_agent->text();
    QString nom_agent=ui->nom_agent->text();
    QString prenom_agent=ui->prenom_agent->text();
    QString date_naissance_agent=ui->dateEdit_4->text();
    QString nationalite_agent=ui->nationalite_agent->text();
    QString sexe_agent=ui->comboBox_agent->currentText();
    QString etat_civil_agent=ui->etat_civil->text() ;
    QString telephone_agent=ui->tel_agent->text() ;
    QString email_agent=ui->email_agent->text() ;
    QString adresse_agent=ui->adresse_agent->text();
    QString image=ui->label_photo->text();


    agent c(cin_agent, nom_agent, prenom_agent,sexe_agent,date_naissance_agent,adresse_agent, telephone_agent,nationalite_agent, etat_civil_agent,email_agent, image);
    c.AjoutImage(fileNameImage);

    fileNameImage="";
    bool test=c.ajouter_agent();
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Ajout avec succés");
        ui->tab_agent->setModel(tmp_agent.afficher_agent());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}


void MainWindow::on_modifier_agent_clicked()
{
    QString cin_agent=ui->cin_agent->text();
    QString nom_agent=ui->nom_agent->text();
    QString prenom_agent=ui->prenom_agent->text();
    QString date_naissance_agent=ui->dateEdit_4->text();
    QString nationalite_agent=ui->nationalite_agent->text();
    QString sexe_agent=ui->comboBox_agent->currentText();
    QString etat_civil=ui->etat_civil->text() ;
    QString tel=ui->tel_agent->text() ;
    QString email=ui->email_agent->text() ;
    QString adresse=ui->adresse_agent->text();
    QString image=ui->label_photo->text();


    agent c (cin_agent, nom_agent, prenom_agent,sexe_agent,date_naissance_agent,adresse, tel,nationalite_agent, etat_civil,email, image);
    bool test=c.modifier_agent(c.getcin_agent(),c.getnom_agent(),c.getprenom_agent(),c.getsexe_agent(),c.getdate_naissance_agent(),c.getadresse_agent(),c.gettelephone_agent(),c.getnationalite_agent(),c.getetat_civil_agent(),c.getemail_agent(),c.getimage());
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Modification avec succés");
        ui->tab_agent->setModel(tmp_agent.afficher_agent());
    }
    else
        msgBox.setText("Echec de modification");
    msgBox.exec();

}



void MainWindow::on_supprimer_agent_clicked()
{
    QString cin=ui->cin_agent->text();
    bool test=tmp_agent.supprimer_agent(cin);
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Supprimer avec succés");
        ui->tab_agent->setModel(tmp_agent.afficher_agent());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}




void MainWindow::on_pushButton_37_clicked()
{
    QString type = ui->comboBox_agent_2->currentText();
    if (type == "cin_agent")
    {
        ui->tab_agent->setModel(tmp_agent.tri_cin());
    }else if (type == "date de naissance")
    {
        ui->tab_agent->setModel(tmp_agent.tri_date());

    }

}





void MainWindow::on_tab_agent_activated(const QModelIndex &index)
{


    QString val=ui->tab_agent->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select* from agent where cin_agent='"+val+"' ");
    if (query.exec())
    { while(query.next())
        {
            ui->cin_agent->setText(query.value(0).toString());
            ui->nom_agent->setText(query.value(1).toString());
            ui->prenom_agent->setText(query.value(2).toString());
            ui->dateEdit_4->setDate(query.value(3).toDate());
            ui->nationalite_agent->setText(query.value(4).toString());
            ui->comboBox_agent->setCurrentText(query.value(5).toString());
            ui->etat_civil->setText(query.value(6).toString());
            ui->tel_agent->setText(query.value(7).toString());
            ui->email_agent->setText(query.value(8).toString());
            ui->adresse_agent->setText(query.value(9).toString());
            ui->label_photo->setText(query.value(10).toString());

            array = query.value(11).toByteArray();
            QBuffer buffer(&array);
            image=(array);
            QPixmap outPixmap = QPixmap();
            outPixmap.loadFromData( image );
            ui->label_photo->setPixmap(outPixmap) ;


        }


    }
}



void MainWindow::on_ajouter_service_clicked()
{
    QString id_service=ui->id_serv->text();
    QString libelle_service=ui->titre_serv->text();
    QString agent_service=ui->auteur_serv->text();
    QString date_service=ui->dateEdit->text();
    QString description_service=ui->description_serv->toPlainText();
    QString genre_service=ui->genre_serv->currentText();
    QString nom_departement=ui->nbr_serv->text();

    service p(id_service,libelle_service,agent_service,date_service,description_service,genre_service,nom_departement);
    bool test=p.ajouter_service();
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Ajout avec succés");
        ui->tab_service->setModel(tmp_service.afficher_service());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void MainWindow::on_supprimer_service_clicked()
{
    QString id=ui->id_serv->text();
    bool test=tmp_service.supprimer_service(id);
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Suppression avec succés");
        ui->tab_service->setModel(tmp_service.afficher_service());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}

void MainWindow::on_modifier_service_clicked()
{
    QString id_service=ui->id_serv->text();
    QString libelle_service=ui->titre_serv->text();
    QString agent_service=ui->auteur_serv->text();
    QString date_service=ui->dateEdit->text();
    QString description_service=ui->description_serv->toPlainText();
    QString genre_service=ui->genre_serv->currentText();
    QString nom_departement=ui->nbr_serv->text();

   service p(id_service,libelle_service,agent_service,date_service,description_service,genre_service,nom_departement);
    bool test=p.modifier_service(p.getid_service(),p.getlibelle_service(),p.getagent_service(),p.getdate_service(),p.getdescription_service(),p.getgenre_service(),p.getnom_departement());
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Modification avec succés");
       // ui->tab_agent->setModel(tmp_agent.afficher_agent());
          ui->tab_service->setModel(tmp_service.afficher_service());
    }
    else
        msgBox.setText("Echec de modification");
    msgBox.exec();
}






void MainWindow::on_ajouter_image_clicked()
{
    QString fileName=QFileDialog::getOpenFileName( this, tr("Open Document"), QDir::currentPath(), tr("Document files (*.doc *.rtf);;All files (*.*)"),0 );
    QPixmap pixmap;
    if (QFile::exists(fileName))
    {
        fileNameImage=fileName;
        pixmap=fileName;
        ui->label_photo->setPixmap(pixmap);
    }
}
void MainWindow::myfunctionn()
{
    QTime time = QTime::currentTime() ;
    QString time_text=time.toString("hh : mm : ss")  ;

    ui->label_date_time->setText(time_text) ;


}

void MainWindow::on_nettoyer_clicked()
{
    supprimeragent();
}
void MainWindow::supprimeragent()
{

    ui->cin_agent->clear();
    ui->nom_agent->clear();
    ui->prenom_agent->clear();
    ui->dateEdit_4->clear();
    ui->nationalite_agent->clear();
    ui->etat_civil->clear();
    ui->tel_agent->clear();
    ui->email_agent->clear();
    ui->adresse_agent->clear();
    ui->label_photo->clear();
}









void MainWindow::on_pushButton_36_clicked()
{

   /* QString valeur=ui->recherche_agent->text();

    if (valeur=="nom_agent")

        ui->tab_agent->setModel(tmp_agent.rechercher_nom_agent(valeur));


    else if (valeur=="cin_agent")

        ui->tab_agent->setModel(tmp_agent.rechercher_id_agent(valeur));*/
//     QString nom=ui->recherche_agent->text();
//     ui->tab_agent->setModel(tmp_agent.rechercher_nom_agent(nom));


   /* QString valeur=ui->recherche_agent->text();

    bool test = false, test1 = false;
    if (valeur == "cin_agent")
        test = tmp_agent.rechercher_id_agent(valeur);
    else if (valeur == "nom_agent")
        test1 = tmp_agent.rechercher_nom_agent(valeur);*/


}

void MainWindow::on_pdf_service_clicked()
{

    QString strStream;
        QTextStream out(&strStream);
        const int rowCount = ui->tab_service->model()->rowCount();
        const int columnCount = ui->tab_service->model()->columnCount();
                        QString TT = QDate::currentDate().toString("yyyy/MM/dd");

                        out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("strTitle")
                            <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"

                           //     "<align='right'> " << datefich << "</align>"
                                "<img src='C:/Users/ASUS/Desktop/Smart_Police_Station_2A20 final2/ifinal/Logo.png' width='300' height='150'>"


                            "<center> <H1>Liste des services "+TT+" </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                        // headers
                        out << "<thead><tr bgcolor=#FF2E01> <th>Numero</th>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tab_service->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tab_service->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";

                        // data table
                        for (int row = 0; row < rowCount; row++) {
                            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                            for (int column = 0; column < columnCount; column++) {
                                if (!ui->tab_service->isColumnHidden(column)) {
                                    QString data = ui->tab_service->model()->data(ui->tab_service->model()->index(row, column)).toString().simplified();
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




void MainWindow::on_recherche_agent_cursorPositionChanged()
{
    QString cin=ui->recherche_agent->text();
    ui->tab_agent->setModel(tmp_agent.rechercher_id_agent(cin));
}





void   MainWindow::on_sendBtn_clicked()
{
    smtp *s=new smtp("chouchanecyrine@gmail.com","Princesseflora1","smtp.gmail.com",465);
    s->sendMail("cyrine.chouchane@esprit.tn", ui->rcpt->text() , ui->Objet->text(), ui->Texte->toPlainText(), files );
    QMessageBox::information(nullptr,QObject::tr("Ok"),
                         QObject::tr("Mail envoyé\n"
                                       "Click cancel to exit."),QMessageBox::Cancel);
}
void   MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::information(nullptr, tr( "Envoi par mail" ), tr( "L'E-Billet a été envoyé avec succès !\n\n" ) );
    ui->rcpt->clear();
    ui->Objet->clear();
    ui->file->clear();
    ui->Texte->clear();
    ui->mail_pass->clear();
    hide();

    QFile file("C:/Users/POSTE HP/Desktop/esprit/2eme/ifinal-_5_/ifinal/PDF/Pdf.pdf");
   file.remove();

}
/*void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory("C:/Users/DELL/Desktop/yassPDF");
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText(fileListString);

}*/

void MainWindow::on_browseBtn_clicked()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory("C:/Users/POSTE HP/Desktop/esprit/2eme/ifinal-_5_/ifinal/PDF/Pdf.pdf");
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText(fileListString);
}

/*void MainWindow::on_label_photo_linkActivated(const QString &link)
{

}*/

void MainWindow::on_pushButton_10_clicked()
{
    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tab_agent->model()->rowCount();
            const int columnCount = ui->tab_agent->model()->columnCount();
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
                if (!ui->tab_agent->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tab_agent->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tab_agent->isColumnHidden(column)) {
                        QString data =ui->tab_agent->model()->data(ui->tab_agent->model()->index(row, column)).toString().simplified();
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




void MainWindow::on_comboBox_agent_3_activated(const QString &arg1)
{

        QString type = ui->comboBox_agent_3->currentText();
        if (type == "id_service")
        {
            ui->tab_service->setModel(tmp_service.tri_id());
        }else if (type == "date")
        {
            ui->tab_service->setModel(tmp_service.tri_date());

        }

    }


void MainWindow::on_play_clicked()
{
    son->play();

}

void MainWindow::on_stop_clicked()
{
    son->stop();

}



/*void MainWindow::on_pushButton_28_clicked()
{

        QString cin=ui->recherche_service->text();
        ui->tab_agent->setModel(tmp_service.rechercher_id_service(cin));


}
*/


