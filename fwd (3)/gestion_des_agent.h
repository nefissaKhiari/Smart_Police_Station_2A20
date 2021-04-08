#ifndef GESTION_DES_AGENT_H
#define GESTION_DES_AGENT_H

#include <QDialog>
#include "agent.h"
#include"service.h"
#include"smtp.h"

namespace Ui {
class gestion_des_agent;
}

class gestion_des_agent : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_des_agent(QWidget *parent = nullptr);
    ~gestion_des_agent();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();



    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);



    void on_modifier_agent_clicked();


    void on_supprimer_service_clicked();

    void on_pushButton_4_clicked();


    void on_modifier_agent_e2_clicked();

    void on_imprimer_service_clicked();

    void on_chercher_agent_clicked();


    void on_statistiques_clicked();
    void sendMail();

    void mailSent(QString status);


    void on_sendBtn_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_trier_agent_2_clicked();

    void on_pushButton_3_clicked();

    void on_trier_agent_3_clicked();

    void on_label_linkActivated(const QString &link);

private:
    Ui::gestion_des_agent *ui;
    agent tmpagent;
    service tmpservice;

};

#endif // GESTION_DES_AGENT_H
