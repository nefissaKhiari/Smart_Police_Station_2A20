/********************************************************************************
** Form generated from reading UI file 'stats.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATS_H
#define UI_STATS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_stats
{
public:
    QPushButton *hide;
    QFrame *frame_charts;
    QHBoxLayout *horizontalLayout;

    void setupUi(QDialog *stats)
    {
        if (stats->objectName().isEmpty())
            stats->setObjectName(QStringLiteral("stats"));
        stats->resize(754, 533);
        hide = new QPushButton(stats);
        hide->setObjectName(QStringLiteral("hide"));
        hide->setGeometry(QRect(660, 470, 75, 23));
        frame_charts = new QFrame(stats);
        frame_charts->setObjectName(QStringLiteral("frame_charts"));
        frame_charts->setGeometry(QRect(10, 20, 641, 401));
        horizontalLayout = new QHBoxLayout(frame_charts);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        retranslateUi(stats);

        QMetaObject::connectSlotsByName(stats);
    } // setupUi

    void retranslateUi(QDialog *stats)
    {
        stats->setWindowTitle(QApplication::translate("stats", "Dialog", Q_NULLPTR));
        hide->setText(QApplication::translate("stats", "hide", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class stats: public Ui_stats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATS_H
