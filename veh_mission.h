#ifndef VEH_MISSION_H
#define VEH_MISSION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
#include <QDialog>

namespace Ui {
class VEH_MISSION;
}


class VEH_MISSION : public QDialog
{
    Q_OBJECT

public:
    explicit VEH_MISSION(QWidget *parent = nullptr);
    ~VEH_MISSION();





    VEH_MISSION();

     VEH_MISSION(int);


    int getnbr_vehicule();

    void setnbr_vehicule(int);

     bool ajouter3();

private slots:
    void on_pb_ajouter_3_clicked();

private:
    Ui::VEH_MISSION *ui;
      //int nbr_vehicule;
};

#endif // VEH_MISSION_H
