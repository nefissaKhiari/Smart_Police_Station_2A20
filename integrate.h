#ifndef INTEGRATE_H
#define INTEGRATE_H
#include <QMainWindow>
#include <QSystemTrayIcon>
#include "bus.h"
#include "entretien.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include "statistique_etat.h"
#include "plaintes.h"
#include "personne.h"
#include <QDialog>
#include "equipement.h"
#include "maintenance.h"
#include "detenu.h"
#include "service.h"
#include "cellule.h"
#include <QPropertyAnimation>
#include <QLabel>
#include <QWidget>
//#include"service.h"
#include"agent.h"
//#include "smtp.h"
#include <QMainWindow>
#include<QTimer>
#include <QStaticText>
#include <QSound>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include<QPrintDialog>
#include <QVariant>


QT_BEGIN_NAMESPACE
namespace Ui { class integrate; }
QT_END_NAMESPACE

class QSystemTrayIcon;

class integrate : public QMainWindow
{
    Q_OBJECT

public:
    integrate(QWidget *parent = nullptr);
    ~integrate();

private slots:

    void on_ajouter_p6_clicked();

    void on_supprimer_p6_clicked();

    void on_modifier_p6_clicked();

    void on_search_button6_clicked();

    void on_refresh6_clicked();

    void on_espace_chercher6_textChanged();

    void on_annulerA6_clicked();

    void on_annuler_M6_clicked();

    void on_annuler_S6_clicked();

    void on_confirmer_A_R6_clicked();

    void on_confirmerM_R6_clicked();

    void on_confimerS_R6_clicked();

    void on_ajouter_S6_clicked();

    void on_modifier_S6_clicked();

    void on_supprimer_S6_clicked();

    void on_annulerAS6_clicked();

    void on_annuler_SS6_clicked();

    void on_annnulerMS6_clicked();

    void on_confirmerSS6_clicked();
    void on_pushButton_166_clicked();
    void on_table_personne6_clicked();




    void on_confirmerAS6_clicked();
    void modifierr6(int index) ;
    void update_label6();   // slot permettant la mise à jour du label état de la lampe 1,
        // ce slot est lancé à chaque réception d'un message de Arduino

        void on_pushButton6_clicked();   // bouton ON

        void on_pushButton_26_clicked(); // bouton OFF

        void on_pushButton_36_clicked(); // bouton +

        void on_pushButton_46_clicked(); // bouton -

        void on_return_26_clicked();

        void on_onreturn6_clicked();

        void on_confirmerMS66_clicked();

private:
    int getIDFromTableView6(QTableView * tv);
    Ui::integrate *ui;
    QSystemTrayIcon *mysystem;
     statistique_etat *stat ;
     Plaintes tmpp;
     Personne *trier1,*p;
     Personne tmppers;
};
#endif // INTEGRATE_H
