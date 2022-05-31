/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *customPlot;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QWidget *horizontalWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *description_lbl;
    QComboBox *baudRate_cmb;
    QComboBox *serialPortSelector_cmb;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *conectar_btn;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *A0_lbl;
    QLCDNumber *input1_lcd;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLCDNumber *input2_lcd;
    QDial *rangeSize_dial;
    QPlainTextEdit *infoSalida_txt;
    QPlainTextEdit *erroresSalida_txt;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalWidget = new QWidget(centralwidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(horizontalWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        customPlot = new QCustomPlot(groupBox);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));

        verticalLayout_3->addWidget(customPlot);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(horizontalWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(300, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalWidget = new QWidget(groupBox_2);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalWidget1 = new QWidget(verticalWidget);
        horizontalWidget1->setObjectName(QString::fromUtf8("horizontalWidget1"));
        horizontalWidget1->setMinimumSize(QSize(0, 30));
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        description_lbl = new QLabel(horizontalWidget1);
        description_lbl->setObjectName(QString::fromUtf8("description_lbl"));
        description_lbl->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(description_lbl);

        baudRate_cmb = new QComboBox(horizontalWidget1);
        baudRate_cmb->setObjectName(QString::fromUtf8("baudRate_cmb"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(baudRate_cmb->sizePolicy().hasHeightForWidth());
        baudRate_cmb->setSizePolicy(sizePolicy);
        baudRate_cmb->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(baudRate_cmb);

        serialPortSelector_cmb = new QComboBox(horizontalWidget1);
        serialPortSelector_cmb->setObjectName(QString::fromUtf8("serialPortSelector_cmb"));
        sizePolicy.setHeightForWidth(serialPortSelector_cmb->sizePolicy().hasHeightForWidth());
        serialPortSelector_cmb->setSizePolicy(sizePolicy);
        serialPortSelector_cmb->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(serialPortSelector_cmb);


        verticalLayout->addWidget(horizontalWidget1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        conectar_btn = new QPushButton(verticalWidget);
        conectar_btn->setObjectName(QString::fromUtf8("conectar_btn"));

        horizontalLayout_3->addWidget(conectar_btn);

        pushButton_2 = new QPushButton(verticalWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(verticalWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        A0_lbl = new QLabel(groupBox_2);
        A0_lbl->setObjectName(QString::fromUtf8("A0_lbl"));

        horizontalLayout_4->addWidget(A0_lbl);

        input1_lcd = new QLCDNumber(groupBox_2);
        input1_lcd->setObjectName(QString::fromUtf8("input1_lcd"));
        input1_lcd->setMinimumSize(QSize(0, 40));

        horizontalLayout_4->addWidget(input1_lcd);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_6->addWidget(label);

        input2_lcd = new QLCDNumber(groupBox_2);
        input2_lcd->setObjectName(QString::fromUtf8("input2_lcd"));
        input2_lcd->setMinimumSize(QSize(0, 40));

        horizontalLayout_6->addWidget(input2_lcd);


        verticalLayout_2->addLayout(horizontalLayout_6);

        rangeSize_dial = new QDial(groupBox_2);
        rangeSize_dial->setObjectName(QString::fromUtf8("rangeSize_dial"));
        rangeSize_dial->setMinimumSize(QSize(0, 100));
        rangeSize_dial->setMinimum(100);
        rangeSize_dial->setMaximum(8000);
        rangeSize_dial->setSingleStep(100);
        rangeSize_dial->setPageStep(500);
        rangeSize_dial->setValue(1000);
        rangeSize_dial->setTracking(true);

        verticalLayout_2->addWidget(rangeSize_dial);

        infoSalida_txt = new QPlainTextEdit(groupBox_2);
        infoSalida_txt->setObjectName(QString::fromUtf8("infoSalida_txt"));
        infoSalida_txt->setEnabled(false);
        sizePolicy.setHeightForWidth(infoSalida_txt->sizePolicy().hasHeightForWidth());
        infoSalida_txt->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(infoSalida_txt);

        erroresSalida_txt = new QPlainTextEdit(groupBox_2);
        erroresSalida_txt->setObjectName(QString::fromUtf8("erroresSalida_txt"));

        verticalLayout_2->addWidget(erroresSalida_txt);


        horizontalLayout->addWidget(groupBox_2);


        horizontalLayout_5->addWidget(horizontalWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "GroupBox", nullptr));
        description_lbl->setText(QApplication::translate("MainWindow", "Description", nullptr));
        conectar_btn->setText(QApplication::translate("MainWindow", "Conectar", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        A0_lbl->setText(QApplication::translate("MainWindow", "I1 (A0)", nullptr));
        label->setText(QApplication::translate("MainWindow", "I2 (A1)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
