#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vehicule.h"
#include "mission.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_ajouter_clicked();


    void on_pb_supprimer_clicked();
     void on_modifier_vehicule_clicked();
    void on_tab_vehicule_activated(const QModelIndex &index);
    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();
void on_tab_mission_activated(const QModelIndex &index);
     void on_modifier_mission_clicked();
   // void on_tab_detenu_activated(const QModelIndex &index);

    //void on_tab_cellule_activated(const QModelIndex &index);


     void on_tri_mission_clicked();

     void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    vehicule v;
     mission C;

};

#endif // MAINWINDOW_H
