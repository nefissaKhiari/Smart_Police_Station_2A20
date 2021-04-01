/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *mission;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_3;
    QPushButton *pb_ajouter;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pb_supprimer;
    QLineEdit *le_id;
    QLineEdit *le_nom;
    QLineEdit *le_prenom;
    QTableView *tab_vehicule;
    QLabel *label;
    QLineEdit *le_id_supp;
    QPushButton *modifier_vehicule;
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QPushButton *pb_afficher;
    QPushButton *pb_ajouter_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pb_supprimer_2;
    QLineEdit *le_id_2;
    QLineEdit *le_nom_2;
    QLineEdit *le_prenom_2;
    QTableView *tab_mission;
    QLabel *label_2;
    QLineEdit *le_id_supp_2;
    QLabel *label_10;
    QPushButton *modifier_mission;
    QPushButton *tri_mission;
    QComboBox *comboBox_mission;
    QLineEdit *le_nom_3;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(792, 558);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 751, 541));
        mission = new QWidget();
        mission->setObjectName(QStringLiteral("mission"));
        groupBox_2 = new QGroupBox(mission);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 771, 491));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 180, 101, 23));
        pb_ajouter = new QPushButton(groupBox_2);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(90, 180, 101, 23));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 40, 47, 13));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 90, 47, 13));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 140, 47, 13));
        pb_supprimer = new QPushButton(groupBox_2);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(560, 80, 101, 23));
        le_id = new QLineEdit(groupBox_2);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(180, 40, 113, 20));
        le_nom = new QLineEdit(groupBox_2);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(180, 90, 113, 20));
        le_prenom = new QLineEdit(groupBox_2);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(180, 140, 113, 20));
        tab_vehicule = new QTableView(groupBox_2);
        tab_vehicule->setObjectName(QStringLiteral("tab_vehicule"));
        tab_vehicule->setGeometry(QRect(80, 270, 321, 192));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(450, 40, 61, 16));
        le_id_supp = new QLineEdit(groupBox_2);
        le_id_supp->setObjectName(QStringLiteral("le_id_supp"));
        le_id_supp->setGeometry(QRect(520, 40, 113, 20));
        modifier_vehicule = new QPushButton(groupBox_2);
        modifier_vehicule->setObjectName(QStringLiteral("modifier_vehicule"));
        modifier_vehicule->setGeometry(QRect(380, 230, 101, 23));
        tabWidget->addTab(mission, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(-10, 10, 771, 491));
        pb_afficher = new QPushButton(groupBox_3);
        pb_afficher->setObjectName(QStringLiteral("pb_afficher"));
        pb_afficher->setGeometry(QRect(220, 180, 101, 23));
        pb_ajouter_2 = new QPushButton(groupBox_3);
        pb_ajouter_2->setObjectName(QStringLiteral("pb_ajouter_2"));
        pb_ajouter_2->setGeometry(QRect(90, 180, 101, 23));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(120, 60, 47, 13));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(100, 90, 71, 16));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(100, 120, 71, 16));
        pb_supprimer_2 = new QPushButton(groupBox_3);
        pb_supprimer_2->setObjectName(QStringLiteral("pb_supprimer_2"));
        pb_supprimer_2->setGeometry(QRect(560, 80, 101, 23));
        le_id_2 = new QLineEdit(groupBox_3);
        le_id_2->setObjectName(QStringLiteral("le_id_2"));
        le_id_2->setGeometry(QRect(180, 60, 113, 20));
        le_nom_2 = new QLineEdit(groupBox_3);
        le_nom_2->setObjectName(QStringLiteral("le_nom_2"));
        le_nom_2->setGeometry(QRect(180, 90, 113, 20));
        le_prenom_2 = new QLineEdit(groupBox_3);
        le_prenom_2->setObjectName(QStringLiteral("le_prenom_2"));
        le_prenom_2->setGeometry(QRect(180, 120, 113, 20));
        tab_mission = new QTableView(groupBox_3);
        tab_mission->setObjectName(QStringLiteral("tab_mission"));
        tab_mission->setGeometry(QRect(80, 270, 661, 192));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(450, 40, 61, 16));
        le_id_supp_2 = new QLineEdit(groupBox_3);
        le_id_supp_2->setObjectName(QStringLiteral("le_id_supp_2"));
        le_id_supp_2->setGeometry(QRect(520, 40, 113, 20));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(100, 150, 71, 16));
        modifier_mission = new QPushButton(groupBox_3);
        modifier_mission->setObjectName(QStringLiteral("modifier_mission"));
        modifier_mission->setGeometry(QRect(630, 240, 75, 23));
        tri_mission = new QPushButton(groupBox_3);
        tri_mission->setObjectName(QStringLiteral("tri_mission"));
        tri_mission->setGeometry(QRect(430, 240, 41, 23));
        comboBox_mission = new QComboBox(groupBox_3);
        comboBox_mission->setObjectName(QStringLiteral("comboBox_mission"));
        comboBox_mission->setGeometry(QRect(490, 240, 61, 22));
        le_nom_3 = new QLineEdit(groupBox_3);
        le_nom_3->setObjectName(QStringLiteral("le_nom_3"));
        le_nom_3->setGeometry(QRect(180, 150, 113, 20));
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 240, 75, 23));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 792, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Id", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Marque", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Mod\303\251le", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Identifiant", Q_NULLPTR));
        modifier_vehicule->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(mission), QApplication::translate("MainWindow", "VEHICULE", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Gestion Client", Q_NULLPTR));
        pb_afficher->setText(QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        pb_ajouter_2->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Id", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "nbr vehicule", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "nbr policier", Q_NULLPTR));
        pb_supprimer_2->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Identifiant", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Date mission", Q_NULLPTR));
        modifier_mission->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        tri_mission->setText(QApplication::translate("MainWindow", "Tri ", Q_NULLPTR));
        comboBox_mission->clear();
        comboBox_mission->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "id", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nbr de vehicule", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "mission", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
