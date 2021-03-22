#include "mainwindow.h"
#include "detenu.h"
#include "cellule.h"
#include "ui_mainwindow.h"
//#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QFileDialog>
#include <QTextDocument>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->le_id->setValidator( new QIntValidator(0, 9999999, this));
   ui->tab_detenu->setModel(D.afficher());
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


    Detenu D(id_detenu, nom_detenu, prenom_detenu,date_naissance_detenu,nationalite_detenu,sexe_detenu,taille_detenu,poids_detenu,periode_detenu,dossier_detenu);
    bool test=D.ajouter();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succés");
        ui->tab_detenu->setModel(D.afficher());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Detenu D1; D1.setid_detenu(ui->le_id_supp->text().toInt());
    bool test=D1.supprimer(D1.getid_detenu());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprimer avec succés");
     ui->tab_detenu->setModel(D.afficher());
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


    Detenu Det(id_detenu, nom_detenu, prenom_detenu,date_naissance_detenu,nationalite_detenu,sexe_detenu,taille_detenu,poids_detenu,periode_detenu,dossier_detenu);
     bool test=Det.modifier(Det.getid_detenu(),Det.getnom_detenu(),Det.getprenom_detenu(),Det.getdate_naissance_detenu(),Det.getnationalite_detenu(),Det.getsexe_detenu(),Det.gettaille_detenu(),Det.getpoids_detenu(),Det.getperiode_detenu(),Det.getdossier_detenu());
     QMessageBox msgBox;

     if(test)
        { msgBox.setText("Modification avec succés");
         ui->tab_detenu->setModel(Det.afficher());
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
                ui->le_id_supp->setText(query.value(0).toString());
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

void MainWindow::on_pb_ajouter_2_clicked()
{
    int id_cellule=ui->le_id_2->text().toInt();
    QString type_cellule=ui->le_type_cellule->text();
    int nb_lits=ui->le_nb_lits->text().toInt();
    int superficie_cellule=ui->la_superficie->text().toInt();
    int nb_detenus=ui->le_nb_detenus->text().toInt();
   Cellule C(id_cellule, type_cellule, nb_lits, superficie_cellule ,  nb_detenus );
    bool test=C.ajouter2();
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Ajout avec succés");
        ui->tab_cellule->setModel(C.afficher2());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}




void MainWindow::on_pb_supprimer_2_clicked()
{
    Cellule C1; C1.setid_cellule(ui->le_id_supp_2->text().toInt());
    bool test=C1.supprimer2(C1.getid_cellule());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Supprimer avec succés");
     ui->tab_cellule->setModel(C1.afficher2());
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
                ui->le_id_supp_2->setText(query.value(0).toString());
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
    QString type_cellule=ui->le_nom->text();
    int nb_lits=ui->le_nb_lits->text().toInt();
    int superficie_cellule=ui->la_superficie->text().toInt();
    int nb_detenus=ui->le_nb_detenus->text().toInt();

    Cellule C(id_cellule, type_cellule, nb_lits, superficie_cellule ,  nb_detenus );
     bool test=C.modifier_cellule(C.getid_cellule(),C.gettype_cellule(),C.getnb_lits(),C.getsuperficie_cellule(),C.getnb_detenus());
     QMessageBox msgBox;

     if(test)
        { msgBox.setText("Modification avec succés");
         ui->tab_cellule->setModel(C.afficher2());
     }
     else
         msgBox.setText("Echec de modification");
     msgBox.exec();



}

/*void MainWindow::on_pushButton_6_clicked()
{
    ui->tab_cellule->setModel(tmpcellule.tri_cellule());
    ui->tab_cellule->setModel(tmpcellule.tri_cellule());//refresh
}*/

/*void MainWindow::on_pdf_detenu_clicked()
{
    QString str;
        str.append("<html><head></head><body><center>"+QString("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;;<font size=""10"" color =""red""> GESTION DES PRODUITS </font><br /> <br /> "));
        str.append("<table border=1><tr>");
        str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">IDP</font>&nbsp;&nbsp;"+"</td>");
        str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">Nom </font>&nbsp;&nbsp;")+"</td>");
        str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">Quantité</font>&nbsp;&nbsp;")+"</td>");


        QSqlQuery * query=new QSqlQuery();
        query->exec("SELECT * FROM detenu");
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
            str.append("</td><td>");
            str.append("&nbsp;&nbsp;<font color =""green""  size=""10"">"+query->value(4).toString()+"&nbsp;&nbsp;");
            str.append("</td><td>");
            str.append("&nbsp;&nbsp;<font color =""green"" size=""10"">"+query->value(5).toString()+"&nbsp;&nbsp;");
            str.append("</td></tr>");

    }

        str.append("</table></center><body></html>");

        QPrinter printer;
        printer.setOrientation(QPrinter::Portrait);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);

        QString path= QFileDialog::getSaveFileName(NULL,"imprimer","gestion des detenus","PDF(*.pdf");
         if(path.isEmpty()) return;
         printer.setOutputFileName(path);
         QTextDocument doc;
         doc.setHtml(str);
         doc.print(&printer);
}*/

void MainWindow::on_pb_trier_cellule_clicked()
{
      ui->tab_cellule->setModel(tmpcellule.tri_cellule());
       ui->tab_cellule->setModel(tmpcellule.tri_cellule());//refresh
}

void MainWindow::on_pb_rechercher_cellule_clicked()
{
    QString res=ui->recher_cellule->text();

        ui->tab_cellule->setModel(tmpcellule.rechercher_cellule(res));
}
