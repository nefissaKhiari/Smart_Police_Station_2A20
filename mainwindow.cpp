#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include"integ_finale.h"
#include "smtp.h"

#include<QLineEdit>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_Password->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_login_clicked()
{

    QString username= ui->lineEdit_username->text();
    QString password= ui->lineEdit_Password->text();

    QSqlQuery qry;
    qry.prepare("Select * from stpsadmin where username=:username");
    qry.bindValue(":username",username);
    qry.exec();


            //                hide();//La fenetre d'authentification se ferme automatiquement
            integ_finale a;
            a.exec() ;





}

void MainWindow::on_mail_clicked()
{
    QString code = generer_code();
    QString text = "Bonjour Monsieur/Madame, \n\nVous avez demandé à changer le mot de passe de votre compte smart police station \n\n"
                   "Voici votre code récupération: " + code +" \n\n Si ce n'est pas vous, veuillez contacter votre responsable au plus vite.\n\n"
                                                             " Cordialement,\nsmart police station ";

    smtp *s=new smtp("bettaiebyasmine3@gmail.com","kalbalanalana123***","smtp.gmail.com",465);
    connect(s, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    s->sendMail("bettaiebyasmine3@gmail.com", ui->email->text(),"Reinitialisation mot de passe  smart police station",text );
    set_code(code);
}
QString MainWindow::get_code(){return code;}
void MainWindow::set_code(QString code){this->code = code;};

QString MainWindow:: generer_code()
{
    int cpt = 0;
    QString chaine ="";
    srand(time(NULL));
    while (cpt != 4)
    {
        int lettre = (rand() % ('Z' - 'A'+ 1)) + 'A';
        chaine += lettre;
        int nbr = (rand() % 9) + 1;
        //        chaine += " "+QString::number(nbr);
        cpt++;
    }
    return chaine;
}

void MainWindow::on_valider_mdp_clicked()
{
    QSqlQuery query;
    QByteArray array;

    QString mail = ui->email->text();
    QString username= ui->lineEdit_username->text();
    QString password= ui->lineEdit_Password->text();
    QString  mdp ;
    query.prepare("select * from stpsadmin username='"+username+"' and password='"+password+"'");
    if (query.exec())
    {
        while(query.next())
        {
            username = query.value(0).toString();
            mdp = query.value(1).toString();
        }
    }

    mdp = ui->nouveau_mdp->text();
    if ((ui->nouveau_mdp->text() == ui->confirmation->text()) && (ui->code_recuperation_2->text()==get_code()))
    {
        QSqlQuery query;
        query.prepare("Update stpsadmin set password=:mdp where username=:username");

        query.bindValue(":username", username);
        query.bindValue(":password", mdp);



        QMessageBox::information(nullptr, QObject::tr("Réinitialiser mdp"),
                                 QObject::tr("Mot De Passe modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->stackedWidget->setCurrentIndex(0);
        ui->code_recuperation_2->clear();
        ui->confirmation->clear();
        ui->nouveau_mdp->clear();
        ui->email->clear();
    }
    else
        QMessageBox::information(nullptr, QObject::tr("Réinitialiser mdp"),
                                 QObject::tr("Erreur ! Le code de récupération est incorrect \nou "
                                             "les mots de passe sont différents. \n"), QMessageBox::Cancel);
}

void MainWindow::on_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_mdp_oublie_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}
