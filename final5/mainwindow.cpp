
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QPrinter>
#include<QPrintDialog>
#include<QPdfWriter>
#include<QPainter>
#include <QStaticText>
#include<QDesktopservices>
#include<QUrl>
#include <QtWidgets>
#include "smtp.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

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
    QString service=ui->service->text() ;
    QString tel=ui->tel_agent->text() ;
    QString email=ui->email_agent->text() ;
    QString adresse=ui->adresse_agent->text();


    agent c(cin_agent, nom_agent, prenom_agent,sexe_agent,date_naissance_agent,adresse, tel,nationalite_agent, service,email);

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
    QString service=ui->service->text() ;
    QString tel=ui->tel_agent->text() ;
    QString email=ui->email_agent->text() ;
    QString adresse=ui->adresse_agent->text();


    agent C(cin_agent, nom_agent, prenom_agent,sexe_agent,date_naissance_agent,adresse, tel,nationalite_agent, service,email);
    bool test=C.modifier_agent(C.getcin_agent(),C.getnom_agent(),C.getprenom_agent(),C.getsexe_agent(),C.getdate_naissance_agent(),C.getadresse_agent(),C.gettelephone_agent(),C.getnationalite_agent(),C.getservice_agent(),C.getemail_agent());
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
    query.prepare("select* from agents where cin_agent='"+val+"' ");
    if (query.exec())
    { while(query.next())
        {
            ui->cin_agent->setText(query.value(0).toString());
            ui->nom_agent->setText(query.value(1).toString());
            ui->prenom_agent->setText(query.value(2).toString());
            ui->dateEdit_4->setDate(query.value(3).toDate());
            ui->nationalite_agent->setText(query.value(4).toString());
            ui->comboBox_agent->setCurrentText(query.value(5).toString());
            ui->service->setText(query.value(6).toString());
            ui->tel_agent->setText(query.value(7).toString());
            ui->email_agent->setText(query.value(8).toString());
            ui->adresse_agent->setText(query.value(9).toString());
            array = query.value(10).toByteArray();
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
    QString titre_service=ui->titre_serv->text();
    QString auteur_service=ui->auteur_serv->text();
    QString date_service=ui->dateEdit->text();
    QString description_service=ui->description_serv->toPlainText();
    QString validite_service=ui->validite_serv->currentText();
    QString nbr_signatures_requis=ui->nbr_serv->text();

    service p(id_service,titre_service,auteur_service,date_service,description_service,validite_service,nbr_signatures_requis);
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
    QString titre_service=ui->titre_serv->text();
    QString auteur_service=ui->auteur_serv->text();
    QString date_service=ui->dateEdit->text();
    QString description_service=ui->description_serv->toPlainText();
    QString validite_service=ui->validite_serv->currentText();
    QString nbr_signatures_requis=ui->nbr_serv->text();

   service p(id_service,titre_service,auteur_service,date_service,description_service,validite_service,nbr_signatures_requis);
    bool test=p.modifier_service(p.getid_service(),p.gettitre_service(),p.getauteur_service(),p.getdate_service(),p.getdescription_service(),p.getvalidite_service(),p.getnbr_signatures_requis());
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
    ui->tab_agent->setModel(tmp_agent.afficher_agent());

}
void MainWindow::supprimeragent()
{

    ui->cin_agent->clear();
    ui->nom_agent->clear();
    ui->prenom_agent->clear();
    ui->dateEdit_4->clear();
    ui->nationalite_agent->clear();
    //ui->service->clear();
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

    //QDateTime datecreation = date.currentDateTime();
    //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
    QPdfWriter pdf("C:/Users/DELL/Desktop/yassPDF/Pdf.pdf");
    QPainter painter(&pdf);
    int i = 4000;
   // painter.setPen(Qt::red);
    //painter.setFont(QFont("Arial Black", 30));
    painter.drawText(3900,1200,"*: ");
    painter.setPen(Qt::black);
  //  painter.setFont(QFont("Arial", 50));
    // painter.drawText(1100,2000,afficheDC);
   // painter.drawRect(100,100,7300,2600);
    //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
   // painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(1000,3300,"-");
   // painter.drawText(6000,6000,"auteur:");
   // painter.drawText(1000,6000,"date:");



   QSqlQuery query;
    query.prepare("select * from service");
    query.exec();
    while (query.next())

    {
        painter.setPen(Qt::red);
        painter.setFont(QFont("Arial Black", 30));
      //  painter.drawText(1200,i,query.value(1).toString());
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 10));
       // painter.drawText(6000,i,query.value(2).toString());
       // painter.drawText(6000,i,query.value(3).toString());
        painter.drawText(6000,i,query.value(4).toString());
        //  painter.drawStaticText(6000,3000,i,query.value(4).m_staticText);



    }
    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
       // QDesktopservices::openUrl(QUrl::fromLocalFile("C:/Users/DELL/Desktop/yassPDF/Pdf.pdf"));
        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }

}




void MainWindow::on_recherche_agent_cursorPositionChanged()
{
    QString cin=ui->recherche_agent->text();
    ui->tab_agent->setModel(tmp_agent.rechercher_id_agent(cin));
}




void   MainWindow::on_sendBtn_clicked()
{
    smtp *s=new smtp("bettaiebyasmine3@gmail.com","kalbalanalana123***","smtp.gmail.com",465);
    s->sendMail("bettaiebyasmine3@gmail.com", ui->rcpt->text() , ui->Objet->text(), ui->Texte->toPlainText(), files );
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

    QFile file("C:/Users/DELL/Desktop/yassPDF/Pdf.pdf");
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
    dialog.setDirectory("C:/Users/DELL/Desktop/yassPDF");
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText(fileListString);
}

void MainWindow::on_nettoyer_2_clicked()
{

    QString id_service=ui->id_serv->text();
    QString titre_service=ui->titre_serv->text();
    QString auteur_service=ui->auteur_serv->text();
    QString date_service=ui->dateEdit->text();
    QString description_service=ui->description_serv->toPlainText();
    QString validite_service=ui->validite_serv->currentText();
    QString nbr_signatures_requis=ui->nbr_serv->text();
    service E;
    bool test=E.modifier2( id_service, titre_service, auteur_service, date_service,
                           description_service, validite_service,nbr_signatures_requis);
    if(test)
  {ui->tab_service->setModel(tmp_service.afficher_service());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                    QObject::tr("employe modiié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un employé"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
}
