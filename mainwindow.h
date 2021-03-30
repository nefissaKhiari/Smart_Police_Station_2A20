#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
//#include <QtTextToSpeech/QTextToSpeech>
//#include <QMediaPlayer>
#include <QtCharts>
#include <QChartView>
#include<QPieSeries>
#include "detenu.h"
#include "cellule.h"

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

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_tab_detenu_activated(const QModelIndex &index);

    void on_tab_cellule_activated(const QModelIndex &index);

    void on_modifier_cellule_clicked();

    void on_pushButton_6_clicked();

    void on_pdf_detenu_clicked();

    void on_pb_trier_cellule_clicked();

    void on_pb_rechercher_cellule_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
   Detenu D;
  // QMediaPlayer * erreur = new QMediaPlayer ;
       Cellule tmpcellule;

};

#endif // MAINWINDOW_H
