#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
//#include <QtTextToSpeech/QTextToSpeech>
//#include <QMediaPlayer>
/*#include <QtCharts>
#include <QChartView>
#include<QPieSeries>*/
#include "agent.h"
#include "service.h"

//QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
//QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_ajouter_service_clicked();

    void on_pb_supprimer_service_clicked();

    void on_tab_agent_activated(const QModelIndex &index);

    void on_tab_service_activated(const QModelIndex &index);

    void on_modifier_service_clicked();

   // void on_pushButton_6_clicked();

    void on_pdf_agent_clicked();

    void on_pb_trier_service_clicked();

    void on_pb_rechercher_service_clicked();

    void on_pushButton_clicked();



    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
   agent D;
  // QMediaPlayer * erreur = new QMediaPlayer ;
       service tmpservice , C;

};

#endif // MAINWINDOW_H
