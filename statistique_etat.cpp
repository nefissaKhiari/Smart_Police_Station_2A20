#include "statistique_etat.h"
#include "ui_statistique_etat.h"

statistique_etat::statistique_etat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::statistique_etat)
{
    ui->setupUi(this);
}

statistique_etat::~statistique_etat()
{
    delete ui;
}
