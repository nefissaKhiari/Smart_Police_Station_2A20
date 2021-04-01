#include "stats.h"

#include "ui_stats.h"

stats::stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stats)
{
    ui->setupUi(this);
}

stats::~stats()
{
    delete ui;
}


        void stats::Statistique()
      { QPieSeries *series = new QPieSeries();
            QSqlQuery query;
        int count=0 ;
        QSqlQuery requete("select * from agent where sexe_agent='femme'") ;
        while(requete.next())
        {
                count++ ;
        }


        QSqlQuery query1;
          int count1=0 ;
          QSqlQuery requete1("select * from agent where sexe_agent='homme'") ;
          while(requete1.next())
          {
                  count1++ ;
          }
          series->append("femme",count);
          series->append("homme",count1);

          QChart * chart =new QChart();
          chart-> addSeries(series);
          chart->setTitle("Statistiques des agents par Sexe ");

          QChartView *chartview= new QChartView (chart);
          chartview->setParent(ui->frame_charts);
        }




/*int stats::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from agent where sexe='none'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int stats::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from agent where sexe='homme'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int stats::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from agent where sexe='femme'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void stats::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
    cout<<b<<endl ;
    int c=Statistique_partie3();
    cout<<c<<endl ;
    int d=Statistique_partie4();
    cout<<d<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c+d ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z  ;
        z=360-(y+m) ;
    QPainter painter(this);
   // painter.drawPixmap(QRect(0,0,861,481),QPixmap("C:/Users/ASUS/Desktop/mon crud/attachments - Copie/téléchargement.jpg"));

    QRectF size=QRectF(50,50,this->width()-200,this->width()-200);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*y);
   ui->label_2->setText("none") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("homme") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("femme") ;

}
int stats::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from from agent where sexe=''") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int stats::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from agent where sexe='homme'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int stats::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from agent where sexe='femme'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void stats::paintEvent(QPaintEvent *)
{

  // int b=Statistique_partie2();
   //cout<<b<<endl ;
    int c=Statistique_partie3();
    cout<<c<<endl ;
    int d=Statistique_partie4();
    cout<<d<<endl ;

       // float s2= b*100 ;
        float s4=d*100;
        float nb = c+d ;
        float q3 ;
        q3 = s4/nb ;
        float q4;
        q4=s4/nb;
        float y  ;
        y = (q3*360)/100 ;
        float m;
        m= (q4*360)/100;
        float z  ;
        z=360-(y+m) ;
    QPainter painter(this);
    QRectF size=QRectF(50,100,this->width()-200,this->width()-200);

    painter.setBrush(Qt::blue);
   painter.drawPie(size,0,16*y);
   // ui->label_2->setText("none") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("homme") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("femme") ;

}

*/
void stats::on_hide_clicked()
{
    hide();
}


