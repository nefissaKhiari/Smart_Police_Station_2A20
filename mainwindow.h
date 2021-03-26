#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "detenu.h"
#include "cellule.h"
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

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_tab_detenu_activated(const QModelIndex &index);

    void on_tab_cellule_activated(const QModelIndex &index);

    void on_modifier_cellule_clicked();

private:
    Ui::MainWindow *ui;
   Detenu D;
};

#endif // MAINWINDOW_H
