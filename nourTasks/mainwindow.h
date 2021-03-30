 #ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "equipement.h"
#include "maintenance.h"
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include<QPieSeries>

//test git
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

    void on_pb_modifier_clicked();

    void on_pb_ajouterMaintenance_clicked();

    void on_tab_maintenance_activated(const QModelIndex &index);

    void on_tab_equipement_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_trier_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_pdf_clicked();

private:
    Ui::MainWindow *ui;
    Equipement E,E1;
    Maintenance M;
};

#endif // MAINWINDOW_H
