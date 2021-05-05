#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
   
    void on_Petition_clicked();
    void on_Materiel_clicked();
    void on_Agent_clicked();
    void on_Crimes_clicked();
    void on_Plaintes_clicked();
    void on_Mission_clicked();
 





private:
    Ui::MainWindow *ui;
 
};
#endif // MAINWINDOW_H
