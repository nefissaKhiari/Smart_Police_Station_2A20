#ifndef STATS_H
#define STATS_H

#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QSqlQuery>
#include <QtCharts>
#include <QChartView>
#include<QPieSeries>
#include<QBarSet>
#include<QBarSeries>
using namespace std;
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class stats;
}

class stats : public QDialog
{
    Q_OBJECT

public:
    explicit stats(QWidget *parent = nullptr);
    //void Statistique() ;
       /*int Statistique_partie3() ;
       int Statistique_partie4() ;
        void paintEvent(QPaintEvent *) ;*/
    ~stats();

private slots:
  //  void on_hide_clicked();

   // void on_pushButton_clicked();

private:
    Ui::stats *ui;
};

#endif // STATS_H
