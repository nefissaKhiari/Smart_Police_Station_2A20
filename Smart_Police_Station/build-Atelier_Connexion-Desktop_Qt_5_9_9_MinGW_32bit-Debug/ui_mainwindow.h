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
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *le_id;
    QLineEdit *le_nom;
    QLineEdit *le_prenom;
    QLineEdit *la_date;
    QLineEdit *la_nationalite;
    QLineEdit *le_sexe;
    QPushButton *pb_ajouter;
    QPushButton *pb_supprimer;
    QTableView *tab_agent;
    QLineEdit *la_taille;
    QLineEdit *le_poids;
    QLineEdit *la_periode;
    QLineEdit *le_dossier;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pb_modifier;
    QPushButton *pdf_agent;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QLabel *label_18;
    QLineEdit *le_nb_lits;
    QLabel *label_19;
    QLineEdit *la_superficie;
    QTableView *tab_service;
    QLineEdit *le_type_service;
    QLineEdit *le_nb_agents;
    QPushButton *pb_supprimer_service;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *le_id_2;
    QPushButton *pb_ajouter_service;
    QPushButton *modifier_service;
    QPushButton *pb_trier_service;
    QPushButton *pb_rechercher_service;
    QLineEdit *recher_service;
    QComboBox *comboBox_service;
    QLabel *label_6;
    QWidget *tab_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1011, 837);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1001, 691));
        tabWidget->setDocumentMode(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 991, 691));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 40, 101, 21));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(610, 40, 111, 20));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(610, 80, 121, 21));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(14, 80, 131, 20));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 120, 111, 16));
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(610, 120, 71, 16));
        le_id = new QLineEdit(groupBox);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(150, 40, 113, 22));
        le_nom = new QLineEdit(groupBox);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(750, 40, 113, 22));
        le_prenom = new QLineEdit(groupBox);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(750, 80, 113, 22));
        la_date = new QLineEdit(groupBox);
        la_date->setObjectName(QStringLiteral("la_date"));
        la_date->setGeometry(QRect(150, 80, 113, 22));
        la_nationalite = new QLineEdit(groupBox);
        la_nationalite->setObjectName(QStringLiteral("la_nationalite"));
        la_nationalite->setGeometry(QRect(150, 120, 113, 22));
        le_sexe = new QLineEdit(groupBox);
        le_sexe->setObjectName(QStringLiteral("le_sexe"));
        le_sexe->setGeometry(QRect(750, 120, 113, 22));
        pb_ajouter = new QPushButton(groupBox);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(240, 320, 81, 23));
        pb_supprimer = new QPushButton(groupBox);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(490, 320, 81, 23));
        tab_agent = new QTableView(groupBox);
        tab_agent->setObjectName(QStringLiteral("tab_agent"));
        tab_agent->setGeometry(QRect(0, 390, 981, 192));
        la_taille = new QLineEdit(groupBox);
        la_taille->setObjectName(QStringLiteral("la_taille"));
        la_taille->setGeometry(QRect(150, 160, 113, 20));
        le_poids = new QLineEdit(groupBox);
        le_poids->setObjectName(QStringLiteral("le_poids"));
        le_poids->setGeometry(QRect(150, 200, 113, 20));
        la_periode = new QLineEdit(groupBox);
        la_periode->setObjectName(QStringLiteral("la_periode"));
        la_periode->setGeometry(QRect(750, 160, 113, 20));
        le_dossier = new QLineEdit(groupBox);
        le_dossier->setObjectName(QStringLiteral("le_dossier"));
        le_dossier->setGeometry(QRect(750, 200, 113, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 160, 91, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 200, 81, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(610, 160, 141, 21));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(610, 200, 141, 16));
        pb_modifier = new QPushButton(groupBox);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(670, 320, 81, 23));
        pdf_agent = new QPushButton(groupBox);
        pdf_agent->setObjectName(QStringLiteral("pdf_agent"));
        pdf_agent->setGeometry(QRect(890, 320, 75, 23));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 320, 81, 23));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 150, 251, 41));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(890, 350, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 40, 81, 20));
        le_nb_lits = new QLineEdit(tab_2);
        le_nb_lits->setObjectName(QStringLiteral("le_nb_lits"));
        le_nb_lits->setGeometry(QRect(710, 40, 113, 22));
        label_19 = new QLabel(tab_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(590, 70, 111, 20));
        la_superficie = new QLineEdit(tab_2);
        la_superficie->setObjectName(QStringLiteral("la_superficie"));
        la_superficie->setGeometry(QRect(710, 70, 113, 22));
        tab_service = new QTableView(tab_2);
        tab_service->setObjectName(QStringLiteral("tab_service"));
        tab_service->setGeometry(QRect(20, 320, 521, 291));
        le_type_service = new QLineEdit(tab_2);
        le_type_service->setObjectName(QStringLiteral("le_type_service"));
        le_type_service->setGeometry(QRect(130, 70, 113, 22));
        le_nb_agents = new QLineEdit(tab_2);
        le_nb_agents->setObjectName(QStringLiteral("le_nb_agents"));
        le_nb_agents->setGeometry(QRect(710, 100, 113, 22));
        pb_supprimer_service = new QPushButton(tab_2);
        pb_supprimer_service->setObjectName(QStringLiteral("pb_supprimer_service"));
        pb_supprimer_service->setGeometry(QRect(350, 240, 81, 23));
        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(10, 70, 101, 20));
        label_21 = new QLabel(tab_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(590, 40, 91, 21));
        label_22 = new QLabel(tab_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(590, 100, 101, 20));
        le_id_2 = new QLineEdit(tab_2);
        le_id_2->setObjectName(QStringLiteral("le_id_2"));
        le_id_2->setGeometry(QRect(130, 40, 113, 22));
        pb_ajouter_service = new QPushButton(tab_2);
        pb_ajouter_service->setObjectName(QStringLiteral("pb_ajouter_service"));
        pb_ajouter_service->setGeometry(QRect(140, 240, 81, 23));
        modifier_service = new QPushButton(tab_2);
        modifier_service->setObjectName(QStringLiteral("modifier_service"));
        modifier_service->setGeometry(QRect(620, 240, 75, 23));
        pb_trier_service = new QPushButton(tab_2);
        pb_trier_service->setObjectName(QStringLiteral("pb_trier_service"));
        pb_trier_service->setGeometry(QRect(140, 290, 75, 23));
        pb_rechercher_service = new QPushButton(tab_2);
        pb_rechercher_service->setObjectName(QStringLiteral("pb_rechercher_service"));
        pb_rechercher_service->setGeometry(QRect(740, 340, 75, 23));
        recher_service = new QLineEdit(tab_2);
        recher_service->setObjectName(QStringLiteral("recher_service"));
        recher_service->setGeometry(QRect(610, 340, 113, 20));
        comboBox_service = new QComboBox(tab_2);
        comboBox_service->setObjectName(QStringLiteral("comboBox_service"));
        comboBox_service->setGeometry(QRect(20, 290, 101, 22));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(200, 140, 391, 51));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1011, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Manipuleragent", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">id_Agent</span></p></body></html>", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">nom Agent</span></p></body></html>", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">prenom Agent</span></p></body></html>", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">date_naissance</span></p></body></html>", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">nationalite</span></p></body></html>", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Sexe</span></p></body></html>", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Taille</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Poids</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Periode travail</span></p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Dossier m\303\251dical</span></p></body></html>", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pdf_agent->setText(QApplication::translate("MainWindow", "G\303\251nerer pdf", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; font-style:italic; text-decoration: underline;\">SMART POLICE STATION</span></p></body></html>", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Imprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Detenu", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">id Service</span></p></body></html>", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">dur\303\251e</span></p></body></html>", Q_NULLPTR));
        pb_supprimer_service->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">type service</span></p></body></html>", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">nb agents</span></p></body></html>", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">nb presents</span></p></body></html>", Q_NULLPTR));
        pb_ajouter_service->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        modifier_service->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pb_trier_service->setText(QApplication::translate("MainWindow", "trier", Q_NULLPTR));
        pb_rechercher_service->setText(QApplication::translate("MainWindow", "rechercher", Q_NULLPTR));
        comboBox_service->clear();
        comboBox_service->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "id_cellule", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nb_detenus", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nb_lits", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600; font-style:italic; text-decoration: underline;\">SMART POLICE STATION</span></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Cellule", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Statistique Detenu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
