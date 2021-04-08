#include "gestion_des_agent.h"
#include "ui_gestion_des_agent.h"
#include <QPixmap>
#include "agent.h"
#include"service.h"
#include <QMessageBox>
#include <QTextDocument>
#include <QTextStream>
#include <QPrintDialog>
#include <QPrinter>
#include"QDate"
#include "statistiques.h"
#include "smtp.h"

gestion_des_agent::gestion_des_agent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_des_agent)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Ben Moussa/Desktop/Projet 2A/CRUD_YaCine/affiche.jpg");
    ui->tabagent_2->setModel(tmpagent.afficher());
    ui->tab_service->setModel(tmpservice.afficher_service());
   // ui->comboBox->setModel(tmpagent.afficher_liste());
}

gestion_des_agent::~gestion_des_agent()
{
    delete ui;
}





void gestion_des_agent::on_ajouter_clicked()
{
    int ref = ui->ref_e->text().toInt();
    QString nom= ui->nom_e->text();
    QString prenom= ui->prenom_e->text();
    QString email=ui->email_e->text();
    QString poste =ui->poste_e->text();
    QString sexe =ui->sex_e->text();
  agent E;
  bool test=false;
  int i;
  for(i=0;i<email.size();i++)
  { if((email[i]=="@")&&((sexe=="homme")||(sexe=="femme")))
          test=true;}
   if(test)E.ajouter(ref,nom,prenom,email,poste,sexe);
  if(test)
{ui->tabagent_2->setModel(tmpagent.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un agent"),
                  QObject::tr("agent ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

  else
  {
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employé"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
}
void gestion_des_agent::on_supprimer_clicked()
{
    int id_ch = ui->reference_sup_e->text().toInt();
    bool test=tmpagent.supprimer(id_ch);
    if(test)
    {ui->tabagent_2->setModel(tmpagent.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un agent"),
                    QObject::tr("Employé supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un agent"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}


void gestion_des_agent::on_pushButton_clicked()
{
    int prix_h  = ui->prix_h_e->text().toInt();
        QString  poste= ui->poste1_e->text();
        int id_service = ui->id_service->text().toInt();
      service E;

      bool test=E.ajouter_service(poste,prix_h,id_service);
      if(test)
    {ui->tab_service->setModel(tmpservice.afficher_service());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter service"),
                      QObject::tr("service ajoutée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter une service"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestion_des_agent::on_comboBox_activated(const QString &arg1)
{

}


/*void gestion_des_agent::on_modifier_agent_clicked()
{
    tmpagent.set_nom(ui->nom_e3->text());
    tmpagent.set_prenom(ui->prenom_e3->text());
    tmpagent.set_email(ui->email_e3->text());
    tmpagent.set_poste(ui->poste_e3->text());
    tmpagent.set_sext(ui->modifier_sex->text());
    tmpagent.set_reference(ui->comboBox->currentText().toInt());
    bool test=tmpagent.modifier();
    if (test){  ui->setupUi(this);
        ui->tabagent_2->setModel(tmpagent.afficher());
        ui->comboBox->setModel(tmpagent.afficher_liste());}
}*/

void gestion_des_agent::on_supprimer_service_clicked()
{
    int id_ch = ui->id_service_e->text().toInt();
    bool test=tmpservice.supprimer_service(id_ch);
    if(test)
    {ui->tab_service->setModel(tmpservice.afficher_service());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un agent"),
                    QObject::tr("service supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un agent"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}


void gestion_des_agent::on_pushButton_4_clicked()
{
    int id_service = ui->poste1_e_2->text().toInt();
                int prix_h= ui->prix_h_e_2->text().toInt();
                QString poste = ui->id_service_2->text();
                service e ( poste, prix_h,id_service);
                bool l=e.modifier(id_service,prix_h,poste);
                if(l)
                {ui->tab_service->setModel(tmpservice.afficher_service());//refresh
                    QMessageBox::information(nullptr, QObject::tr("Supprimer un Achat"),
                                QObject::tr("Achat Modifié.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}


void gestion_des_agent::on_modifier_agent_e2_clicked()
{
    int ref = ui->ref_e->text().toInt();
    QString nom= ui->nom_e->text();
    QString prenom= ui->prenom_e->text();
    QString email=ui->email_e->text();
    QString poste =ui->poste_e->text();
    QString sexe =ui->sex_e->text();
  agent E;
  bool test=E.modifier(ref,nom,prenom,email,poste,sexe);
  if(test)
{ui->tabagent_2->setModel(tmpagent.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un agent"),
                  QObject::tr("agent modiié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

  else
  {
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employé"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

}

void gestion_des_agent::on_imprimer_service_clicked()
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

void gestion_des_agent::on_chercher_agent_clicked()
{
    int id = ui->chercher_e->text().toInt();
            ui->afficher_trie->setModel(tmpagent.recherche_e(id));

}




void gestion_des_agent::on_statistiques_clicked()
{


        statistiques *a=new statistiques();
        a->show();


}
/*void gestion_des_agent::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void gestion_des_agent::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


*/

void gestion_des_agent::on_sendBtn_clicked()
{
    smtp *s=new smtp("chouchanecyrine@gmail.com","princesseflora***","smtp.gmail.com",465);
    s->sendMail("chouchanecyrine@gmail.com", ui->label->text() , ui->label_2->text(), ui->label_3->text());
    QMessageBox::information(nullptr,QObject::tr("Ok"),
                         QObject::tr("Mail envoyé\n"
                                       "Click cancel to exit."),QMessageBox::Cancel);
}

void gestion_des_agent::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::information(nullptr, tr( "Envoi par mail" ), tr( "L'E-Billet a été envoyé avec succès !\n\n" ) );
    ui->label->clear();
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label_4->clear();
    ui->label_5->clear();
    ui->label_6->clear();
    ui->label_7->clear();


    hide();

    QFile file("C:/Users/DELL/Desktop/yassPDF/Pdf.pdf");
   file.remove();

}


void gestion_des_agent::on_pushButton_2_clicked()
{
    ui->tab_service->setModel(tmpservice.tri(0));
}

void gestion_des_agent::on_pushButton_9_clicked()
{
     ui->tab_service->setModel(tmpservice.tri(1));

}

void gestion_des_agent::on_pushButton_10_clicked()
{
     ui->tabagent_2->setModel(tmpagent.tri(0));
}

void gestion_des_agent::on_trier_agent_2_clicked()
{
    ui->tabagent_2->setModel(tmpagent.tri(1));

}

void gestion_des_agent::on_pushButton_3_clicked()
{
    ui->tab_service->setModel(tmpservice.tri(1));


}

void gestion_des_agent::on_trier_agent_3_clicked()
{
    ui->tabagent_2->setModel(tmpagent.tri(0));

}

void gestion_des_agent::on_label_linkActivated(const QString &link)
{

}
