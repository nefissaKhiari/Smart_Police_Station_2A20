
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
       music->setMedia(QUrl("C:/Users/DELL/Desktop/Qt/ifinal/1.mp3"));
       PixTrueIcon=QPixmap("C:/Users/DELL/Documents/PoliceStation2/Nouveau dossier/2.png");
       PixFalseIcon=QPixmap("C:/Users/DELL/Documents/PoliceStation2/Nouveau dossier/3.png");

    ui->tab_citoyen->setModel(tmp_citoyen.afficher_citoyen());

    ui->tab_petition->setModel(tmp_petition.afficher_petition());
       ui->tab_citoyen->sortByColumn(1,Qt::DescendingOrder);


    timerr=new QTimer(this) ;
    connect(timerr , SIGNAL(timeout()),this,SLOT(myfunctionn())) ;
    timerr->start(1000) ;
    show_tables();



}

MainWindow::~MainWindow()
{
    delete ui;
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
bool MainWindow::verifnom()
{
    if (ui->nom_citoyen->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->nom_citoyen->text().isEmpty())
    {
        ui->nom_citoyen->clear();

        ui->verif_nom_citoyen->setPixmap(PixFalseIcon);
        ui->nom_citoyen->setPlaceholderText("contient que des caracteres") ;
        return false;
    }else
    {
        ui->verif_nom_citoyen->setPixmap(PixTrueIcon);
        return true;
    }
}
bool MainWindow::verifcin()
{
    if ( ui->cin_citoyen->text().isEmpty())
    {
        ui->cin_citoyen->clear();

        ui->verif_cin_citoyen->setPixmap(PixFalseIcon);
        ui->cin_citoyen->setPlaceholderText("Le ID est vide") ;

        return false;
    }else
    {
        ui->verif_cin_citoyen->setPixmap(PixTrueIcon);
        return true;
    }
}
bool MainWindow::verifprenom()
{
    if (ui->prenom_citoyen->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->prenom_citoyen->text().isEmpty())
    {
        ui->prenom_citoyen->clear();

        ui->verif_cin_citoyen->setPixmap(PixFalseIcon);
        ui->prenom_citoyen->setPlaceholderText("contient que des caracteres") ;

        return false;
    }else
    {
        ui->verif_cin_citoyen->setPixmap(PixTrueIcon);
        return true;
    }
}
bool MainWindow::veriftel()
{
    if (ui->tel_citoyen->text().contains(QRegExp("[^0-9]") ) || ui->tel_citoyen->text().isEmpty())
    {
        ui->tel_citoyen->clear();

        ui->verif_tel->setPixmap(PixFalseIcon);
        ui->tel_citoyen->setPlaceholderText("contient que des chiffres") ;

        return false;
    }else
    {
        ui->verif_tel->setPixmap(PixTrueIcon);
        return true;
    }
}

bool MainWindow::verifnationalite()
{
    if (ui->nationalite_citoyen->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->nationalite_citoyen->text().isEmpty())
    {
        ui->nationalite_citoyen->clear();

        ui->verif_nationnalite_citoyen->setPixmap(PixFalseIcon);
        ui->nationalite_citoyen->setPlaceholderText("contient que des caracteres") ;

        return false;
    }else
    {
        ui->verif_nationnalite_citoyen->setPixmap(PixTrueIcon);
        return true;
    }
}

bool MainWindow::verifsexe()
{
    if (ui->comboBox_citoyen->currentIndex()>-1)
    {
        ui->verif_sexe->setPixmap(PixTrueIcon);
        return true;
    }else
    {
        ui->verif_sexe->setPixmap(PixFalseIcon);
        return false;
    }
}

bool MainWindow::verifemail()
{
    if ( ui->email_citoyen->text().isEmpty())
    {
        ui->email_citoyen->clear();
        ui->verif_email->setPixmap(PixFalseIcon);
        ui->email_citoyen->setPlaceholderText("Le email est vide") ;
        return false;
    }else
    {
        ui->verif_email->setPixmap(PixTrueIcon);
        return true;
    }
}

bool MainWindow::verifadresse()
{
    if ( ui->adresse_citoyen->text().isEmpty())
    {
        ui->adresse_citoyen->clear();
        ui->verif_adresse->setPixmap(PixFalseIcon);
        ui->adresse_citoyen->setPlaceholderText("L adresse est vide") ;
        return false;
    }else
    {
        ui->verif_adresse->setPixmap(PixTrueIcon);
        return true;
    }
}
void MainWindow::on_ajouter_citoyen_clicked()
{
    QString cin_citoyen=ui->cin_citoyen->text();
    QString nom_citoyen=ui->nom_citoyen->text();
    QString prenom_citoyen=ui->prenom_citoyen->text();
    QString date_naissance_citoyen=ui->dateEdit_4->text();
    QString nationalite_citoyen=ui->nationalite_citoyen->text();
    QString sexe_citoyen=ui->comboBox_citoyen->currentText();
    QString etat_civil=ui->etat_civil->text() ;
    QString tel=ui->tel_citoyen->text() ;
    QString email=ui->email_citoyen->text() ;
    QString adresse=ui->adresse_citoyen->text();
      QMessageBox msgBox;

if( verifnom() && verifcin() && verifprenom() && veriftel() &&   verifnationalite() && verifsexe() && verifemail() && verifadresse() )
{
    Citoyen c(cin_citoyen, nom_citoyen, prenom_citoyen,sexe_citoyen,date_naissance_citoyen,adresse, tel,nationalite_citoyen, etat_civil,email);
    c.AjoutImage(fileNameImage);

    fileNameImage="";
    bool test=c.ajouter_citoyen();


    if(test)
    { msgBox.setText("Ajout avec succés");
        ui->tab_citoyen->setModel(tmp_citoyen.afficher_citoyen());
    }
}
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}


void MainWindow::on_modifier_citoyen_clicked()
{
    QString cin_citoyen=ui->cin_citoyen->text();
    QString nom_citoyen=ui->nom_citoyen->text();
    QString prenom_citoyen=ui->prenom_citoyen->text();
    QString date_naissance_citoyen=ui->dateEdit_4->text();
    QString nationalite_citoyen=ui->nationalite_citoyen->text();
    QString sexe_citoyen=ui->comboBox_citoyen->currentText();
    QString etat_civil=ui->etat_civil->text() ;
    QString tel=ui->tel_citoyen->text() ;
    QString email=ui->email_citoyen->text() ;
    QString adresse=ui->adresse_citoyen->text();

 QMessageBox msgBox;
    Citoyen C(cin_citoyen, nom_citoyen, prenom_citoyen,sexe_citoyen,date_naissance_citoyen,adresse, tel,nationalite_citoyen, etat_civil,email);
    bool test=C.modifier_citoyen(C.getcin_citoyen(),C.getnom_citoyen(),C.getprenom_citoyen(),C.getsexe_citoyen(),C.getdate_naissance_citoyen(),C.getadresse_citoyen(),C.gettelephone_citoyen(),C.getnationalite_citoyen(),C.getetat_civil_citoyen(),C.getemail_citoyen());
    if( verifnom() && verifcin() && verifprenom() && veriftel() &&   verifnationalite() && verifsexe() && verifemail() && verifadresse() )

   {

    if(test)
    { msgBox.setText("Modification avec succés");
        ui->tab_citoyen->setModel(tmp_citoyen.afficher_citoyen());
    }
    }
    else
        msgBox.setText("Echec de modification");
    msgBox.exec();

}



void MainWindow::on_supprimer_citoyen_clicked()
{
    QString cin=ui->cin_citoyen->text();
    bool test=tmp_citoyen.supprimer_citoyen(cin);
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Supprimer avec succés");
        ui->tab_citoyen->setModel(tmp_citoyen.afficher_citoyen());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}




void MainWindow::on_pushButton_37_clicked()
{
    QString type = ui->comboBox_citoyen_2->currentText();
    if (type == "cin_citoyen")
    {
        ui->tab_citoyen->setModel(tmp_citoyen.tri_cin());
    }else if (type == "date de naissance")
    {
        ui->tab_citoyen->setModel(tmp_citoyen.tri_date());

    }
    else if(type=="nom citoyen")
    {
        ui->tab_citoyen->setModel(tmp_citoyen.tri_nom());
    }

}





void MainWindow::on_tab_citoyen_activated(const QModelIndex &index)
{


    QString val=ui->tab_citoyen->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select* from citoyens where cin_citoyen='"+val+"' ");
    if (query.exec())
    { while(query.next())
        {
            ui->cin_citoyen->setText(query.value(0).toString());
            ui->nom_citoyen->setText(query.value(1).toString());
            ui->prenom_citoyen->setText(query.value(2).toString());
            ui->dateEdit_4->setDate(query.value(3).toDate());
            ui->nationalite_citoyen->setText(query.value(4).toString());
            ui->comboBox_citoyen->setCurrentText(query.value(5).toString());
            ui->etat_civil->setText(query.value(6).toString());
            ui->tel_citoyen->setText(query.value(7).toString());
            ui->email_citoyen->setText(query.value(8).toString());
            ui->adresse_citoyen->setText(query.value(9).toString());
            array = query.value(10).toByteArray();
            QBuffer buffer(&array);
            image=(array);
            QPixmap outPixmap = QPixmap();
            outPixmap.loadFromData( image );
            ui->label_photo->setPixmap(outPixmap) ;


        }


    }
}



void MainWindow::on_ajouter_petition_clicked()
{
    QString id_petition=ui->id_pet->text();
    QString titre_petition=ui->titre_pet->text();
    QString auteur_petition=ui->auteur_pet->text();
    QString date_petition=ui->dateEdit->text();
    QString description_petition=ui->description_pet->toPlainText();
    QString validite_petition=ui->validite_pet->currentText();
    QString nbr_signatures_requis=ui->nbr_pet->text();

    Petition p(id_petition,titre_petition,auteur_petition,date_petition,description_petition,validite_petition,nbr_signatures_requis);
    bool test=p.ajouter_petition();
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Ajout avec succés");
        ui->tab_petition->setModel(tmp_petition.afficher_petition());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void MainWindow::on_supprimer_petition_clicked()
{
    QString id=ui->id_pet->text();
    bool test=tmp_petition.supprimer_petition(id);
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Suppression avec succés");
        ui->tab_petition->setModel(tmp_petition.afficher_petition());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}

void MainWindow::on_modifier_petition_clicked()
{
    QString id_petition=ui->id_pet->text();
    QString titre_petition=ui->titre_pet->text();
    QString auteur_petition=ui->auteur_pet->text();
    QString date_petition=ui->dateEdit->text();
    QString description_petition=ui->description_pet->toPlainText();
    QString validite_petition=ui->validite_pet->currentText();
    QString nbr_signatures_requis=ui->nbr_pet->text();

   Petition p(id_petition,titre_petition,auteur_petition,date_petition,description_petition,validite_petition,nbr_signatures_requis);
    bool test=p.modifier_petition(p.getid_petition(),p.gettitre_petition(),p.getauteur_petition(),p.getdate_petition(),p.getdescription_petition(),p.getvalidite_petition(),p.getnbr_signatures_requis());
    QMessageBox msgBox;

    if(test)
    { msgBox.setText("Modification avec succés");
       // ui->tab_citoyen->setModel(tmp_citoyen.afficher_citoyen());
          ui->tab_petition->setModel(tmp_petition.afficher_petition());
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
    supprimercitoyen();
}
void MainWindow::supprimercitoyen()
{

    ui->cin_citoyen->clear();
    ui->nom_citoyen->clear();
    ui->prenom_citoyen->clear();
    ui->dateEdit_4->clear();
    ui->nationalite_citoyen->clear();
    ui->etat_civil->clear();
    ui->tel_citoyen->clear();
    ui->email_citoyen->clear();
    ui->adresse_citoyen->clear();
    ui->label_photo->clear();
    ui->verif_adresse->clear();
    ui->verif_cin_citoyen->clear();
    ui->verif_date_citoyen->clear();
    ui->verif_email->clear();
    ui->verif_nationnalite_citoyen->clear();
    ui->verif_nom_citoyen->clear();
    ui->verif_prenom_citoyen->clear();
    ui->verif_sexe->clear();
    ui->verif_tel->clear();

}











void MainWindow::on_pdf_petition_clicked()
{
    QPainter painter;

    QString str;
        str.append("<html><head></head><body><center>"+QString("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;;<font size=""10"" color =""red""> LISTE DES PETITIONS VALIDES </font><br /> <br /> "));
        str.append("<table border=1><tr>");
        str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">titre</font>&nbsp;&nbsp;"+"</td>");
        str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">auteur</font>&nbsp;&nbsp;"+"</td>");
        str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""20"">date</font>&nbsp;&nbsp;")+"</td>");
        str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">description</font>&nbsp;&nbsp;")+"</td>");
        painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/DELL/Documents/PoliceStation2/Nouveau dossier/5.jpg"));
        QSqlQuery * query=new QSqlQuery();
        query->exec("SELECT  titre_petition,auteur_petition,date_petition, description_petition FROM petition");
        while(query->next())
        {
            str.append("<tr><td>");
            str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(0).toString()+"&nbsp;&nbsp;");
            str.append("</td><td>");
            str.append("&nbsp;&nbsp;<font color =""green""  size=""10"">"+query->value(1).toString()+"&nbsp;&nbsp;");
            str.append("</td><td>");
            str.append("&nbsp;&nbsp;<font color =""green"" size=""10"">"+query->value(2).toString()+"&nbsp;&nbsp;");
             str.append("</td><td>");
            str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(3).toString()+"&nbsp;&nbsp;");
            str.append("</td></tr>");

    }

        str.append("</table></center><body></html>");

        QPrinter printer;
        printer.setOrientation(QPrinter::Portrait);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);

        QString path= QFileDialog::getSaveFileName(NULL,"imprimer","Liste des petitions validées","PDF(*.pdf");
         if(path.isEmpty()) return;
         printer.setOutputFileName(path);
         QTextDocument doc;
         doc.setHtml(str);
         doc.print(&printer);
}




void MainWindow::on_recherche_citoyen_cursorPositionChanged()
{
    QString cin=ui->recherche_citoyen->text();
    ui->tab_citoyen->setModel(tmp_citoyen.rechercher_id_citoyen(cin));
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




void MainWindow::on_pause_clicked()
{
       music->stop() ;
}



void MainWindow::on_recherche_citoyen_editingFinished()
{
     ui->tab_citoyen->setModel(tmp_citoyen.afficher_citoyen());
}





void MainWindow::on_play_clicked()
{
      music->play() ;
}

void MainWindow::on_pushButton_48_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_home_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_pushButton_10_clicked()
{
     ui->tab_citoyen->setModel(tmp_citoyen.afficher_citoyen());
}

void MainWindow::on_tab_petition_activated(const QModelIndex &index)
{
    QString val=ui->tab_petition->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select* from petition where id_petition='"+val+"' ");
    if (query.exec())
    { while(query.next())
        {
            ui->id_pet->setText(query.value(0).toString());
            ui->titre_pet->setText(query.value(1).toString());
            ui->auteur_pet->setText(query.value(2).toString());
            ui->dateEdit->setDate(query.value(3).toDate());
            ui->description_pet->setPlainText(query.value(4).toString());
            ui->validite_pet->setCurrentText(query.value(5).toString());
            ui->nbr_pet->setText(query.value(6).toString());

           }
    }


}


void MainWindow::on_pushButton_9_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                       tr("Excel Files (*.xls)"));
       if (fileName.isEmpty())
           return;

       ExportExcelObject obj(fileName, "mydata", ui->tab_citoyen);

       //colums to export
       obj.addField(0, "cin_citoyen", "char(20)");
       obj.addField(1, "nom_citoyen", "char(20)");
       obj.addField(2, "prenom_citoyen", "char(20)");
       obj.addField(3, "sexe_citoyen", "char(20)");
       obj.addField(4, "email_citoyen", "char(20)");
       obj.addField(5, "adresse_citoyen", "char(20)");


       int retVal = obj.export2Excel();
       if( retVal > 0)
       {
           QMessageBox::information(this, tr("Done"),
                                    QString(tr("%1 records exported!")).arg(retVal)
                                    );
       }
}
void MainWindow::show_tables(){
    //employe
//creation model (masque du tableau) : permet recherche et tri
    proxy_emp = new QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy_emp->setSourceModel(tmp_citoyen.afficher_citoyen());

 //pour la recherche
    proxy_emp->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
    proxy_emp->setFilterKeyColumn(selcomemp); // chercher dans tout le tableau (-1) ou donner le numero de la colone
   //remplissage tableau avec le masque
    ui->tab_citoyen->setModel(proxy_emp);

    //conge

    //creation model (masque du tableau) : permet recherche et tri
        proxy_co = new QSortFilterProxyModel();

     //definir la source (tableau original)
        proxy_co->setSourceModel(tmp_petition.afficher_petition());

     //pour la recherche
        proxy_co->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
        proxy_co->setFilterKeyColumn(selcomco); // chercher dans tout le tableau (-1) ou donner le numero de la colone
       //remplissage tableau avec le masque
        ui->tab_petition->setModel(proxy_co);

}



void MainWindow::on_recherche_dynamique_textChanged(const QString &arg1)
{
   ui->tab_petition->setModel(tmp_petition.rechercheDynamic(arg1));
}
void MainWindow::on_pushButton_facebook_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.facebook.com", QUrl::TolerantMode));
}

void MainWindow::on_pushButton_twitter_clicked()
{
    QDesktopServices::openUrl(QUrl("http://www.twitter.com", QUrl::TolerantMode));
}
void MainWindow::on_voir_stats_clicked()
{   ui->tabWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(2);
    makePlot_vente();
}

QVector<double> MainWindow::Statistique_vente()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;

    q.prepare("SELECT * FROM petition WHERE nbr_signatures_requis between '100' and '199'");
    q.exec();
    while (q.next())
    {
        stat[0]+=q.value(6).toInt();
    }
    q.prepare("SELECT * FROM petition WHERE nbr_signatures_requis between '200' and '299'");
    q.exec();
    while (q.next())
    {
        stat[1]+=q.value(6).toInt();
    }
    q.prepare("SELECT * FROM petition WHERE nbr_signatures_requis between '300' and '399'");
    q.exec();
    while (q.next())
    {
        stat[2]+=q.value(6).toInt();
    }
    q.prepare("SELECT * FROM petition WHERE nbr_signatures_requis between '400' and '499'");
    q.exec();
    while (q.next())
    {
        stat[3]+=q.value(6).toInt();
    }
    q.prepare("SELECT * FROM petition WHERE nbr_signatures_requis between '500' and '599'");
    q.exec();
    while (q.next())
    {
        stat[4]+=q.value(6).toInt();
    }

    return stat;
}

void MainWindow::makePlot_vente()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
        x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
        y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::Statistique_vente());
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customPlot->replot();

    // move bars above graphs and grid below bars:
    ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
    ui->customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
    ui->customPlot->xAxis->grid()->setLayer("belowmain");
    ui->customPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6;
    QVector<QString> labels;
    labels<<"100-200"<<"200-300"<<"300-400"<<"400-500"<<"500-600%";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0,4);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customPlot->axisRect()->setBackground(axisRectGradient);

    ui->customPlot->rescaleAxes();
    ui->customPlot->xAxis->setRange(0, 7);
    ui->customPlot->yAxis->setRange(0, 100);
}



void MainWindow::on_pushButton_11_clicked()
{
   ui->stackedWidget_2->setCurrentIndex(0);
}

