#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"service.h"
#include"agent.h"
#include "smtp.h"
#include <QMainWindow>
#include<QTimer>
#include <QStaticText>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




protected slots:

private slots:
    void on_ajouter_agent_clicked();

    void on_modifier_agent_clicked();

    void on_supprimer_agent_clicked();

    void on_service_clicked();
    void on_Materiel_clicked();
    void on_Agent_clicked();
    void on_Crimes_clicked();
    void on_Plaintes_clicked();
    void on_Mission_clicked();
    void on_pushButton_37_clicked();

    void on_tab_agent_activated(const QModelIndex &index);


    void on_ajouter_service_clicked();

    void on_supprimer_service_clicked();

    void on_modifier_service_clicked();

    void on_ajouter_image_clicked();

    void myfunctionn();
    void on_nettoyer_clicked();

    void supprimeragent();




    //void on_pushButton_9_clicked();


    void on_pdf_service_clicked();


    void on_pushButton_36_clicked();

    void on_recherche_agent_cursorPositionChanged();







    void on_sendBtn_clicked();
      void mailSent(QString);


        void on_browseBtn_clicked();

private:
    Ui::MainWindow *ui;
    agent tmp_agent ;
    service tmp_service ;
    QString fileNameImage ;
      QPixmap photo ;
      QByteArray image;
    QPixmap pixmap;
        QByteArray array;
        QTimer * timerr ;
         QStringList files;

};
#endif // MAINWINDOW_H
