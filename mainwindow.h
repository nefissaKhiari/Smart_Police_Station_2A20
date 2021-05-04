#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"petition.h"
#include"citoyen.h"
#include"exportexcelobject.h"
#include "qcustomplot.h"

#include "smtp.h"
#include <QMainWindow>
#include<QTimer>
#include <QStaticText>
#include <QMediaPlayer>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QLineSeries>
#include <QtCharts>
#include <QCategoryAxis>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
QSortFilterProxyModel *proxy_emp,*proxy_co;



public slots:

protected slots:

private slots:
    void on_ajouter_citoyen_clicked();

    void on_modifier_citoyen_clicked();

    void on_supprimer_citoyen_clicked();

    void on_Petition_clicked();
    void on_Materiel_clicked();
    void on_Agent_clicked();
    void on_Crimes_clicked();
    void on_Plaintes_clicked();
    void on_Mission_clicked();
    void on_pushButton_37_clicked();





    void on_tab_citoyen_activated(const QModelIndex &index);



    void on_ajouter_petition_clicked();

    void on_supprimer_petition_clicked();

    void on_modifier_petition_clicked();

    void on_ajouter_image_clicked();

    void myfunctionn();
    void on_nettoyer_clicked();

    void supprimercitoyen();
    bool verifnom();





    //void on_pushButton_9_clicked();


    void on_pdf_petition_clicked();


    //void on_pushButton_36_clicked();

    void on_recherche_citoyen_cursorPositionChanged();







    void on_sendBtn_clicked();
      void mailSent(QString);


        void on_browseBtn_clicked();


        void on_pause_clicked();


        void on_recherche_citoyen_editingFinished();



        void on_play_clicked();

        void on_pushButton_48_clicked();

        void on_home_clicked();

        void on_pushButton_10_clicked();

        bool verifcin();
        bool verifprenom();
        bool veriftel();
        bool verifnationalite();
        bool verifsexe();
        bool verifadresse();
        bool verifemail();
        void on_tab_petition_activated(const QModelIndex &index);


        void on_pushButton_9_clicked();

        void show_tables();
        void on_recherche_dynamique_textChanged(const QString &arg1);

        void on_pushButton_facebook_clicked();
        void on_pushButton_twitter_clicked();
        void on_voir_stats_clicked();
        QVector<double> Statistique_vente();
        void makePlot_vente();
        void on_pushButton_11_clicked();


private:
    Ui::MainWindow *ui;
    Citoyen tmp_citoyen ;
    Petition tmp_petition ;
    QString fileNameImage ;
      QPixmap photo ;
      QByteArray image;
    QPixmap pixmap;
        QByteArray array;
        QTimer * timerr ;
         QStringList files;
            QMediaPlayer * music = new QMediaPlayer();
            QPixmap PixTrueIcon;
            QPixmap PixFalseIcon;
             int selcomemp=0,selcomco=0;

};
#endif // MAINWINDOW_H
