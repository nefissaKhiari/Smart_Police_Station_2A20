#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    void on_pb_ajouter_cellule_clicked();

    void on_pb_supprimer_cellule_clicked();

    void on_tab_detenu_activated(const QModelIndex &index);

    void on_tab_cellule_activated(const QModelIndex &index);

    void on_modifier_cellule_clicked();

  //  void on_pdf_detenu_clicked();

    void on_pb_trier_cellule_clicked();

    void on_pb_rechercher_cellule_clicked();



    void on_imprimer_clicked();



    void on_Petition_clicked();

    void on_Materiel_clicked();

    void on_Agent_clicked();

    void on_Crimes_clicked();

    void on_Plaintes_clicked();



  //  void on_Statistique_clicked();

    void on_Mission_clicked();

    void on_pushButton_clicked();

   // void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
   Detenu D;

       Cellule tmpcellule , C;

};

#endif // MAINWINDOW_H
