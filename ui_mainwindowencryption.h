/********************************************************************************
** Form generated from reading UI file 'mainwindowencryption.ui'
**
** Created: Sun Jun 10 22:20:54 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWENCRYPTION_H
#define UI_MAINWINDOWENCRYPTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowEncryption
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidgetDetail;
    QListWidget *listWidgetDirList;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonCheckOut;
    QPushButton *pushButtonCheckIn;
    QPushButton *pushButtonRemove;
    QPushButton *pushButtonFresh;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowEncryption)
    {
        if (MainWindowEncryption->objectName().isEmpty())
            MainWindowEncryption->setObjectName(QString::fromUtf8("MainWindowEncryption"));
        MainWindowEncryption->resize(863, 721);
        centralWidget = new QWidget(MainWindowEncryption);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableWidgetDetail = new QTableWidget(centralWidget);
        if (tableWidgetDetail->columnCount() < 3)
            tableWidgetDetail->setColumnCount(3);
        tableWidgetDetail->setObjectName(QString::fromUtf8("tableWidgetDetail"));
        tableWidgetDetail->setGeometry(QRect(290, 10, 531, 481));
        tableWidgetDetail->setSortingEnabled(true);
        tableWidgetDetail->setCornerButtonEnabled(false);
        tableWidgetDetail->setColumnCount(3);
        listWidgetDirList = new QListWidget(centralWidget);
        listWidgetDirList->setObjectName(QString::fromUtf8("listWidgetDirList"));
        listWidgetDirList->setGeometry(QRect(20, 10, 241, 479));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 540, 641, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonAdd = new QPushButton(horizontalLayoutWidget);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));

        horizontalLayout->addWidget(pushButtonAdd);

        pushButtonCheckOut = new QPushButton(horizontalLayoutWidget);
        pushButtonCheckOut->setObjectName(QString::fromUtf8("pushButtonCheckOut"));

        horizontalLayout->addWidget(pushButtonCheckOut);

        pushButtonCheckIn = new QPushButton(horizontalLayoutWidget);
        pushButtonCheckIn->setObjectName(QString::fromUtf8("pushButtonCheckIn"));

        horizontalLayout->addWidget(pushButtonCheckIn);

        pushButtonRemove = new QPushButton(horizontalLayoutWidget);
        pushButtonRemove->setObjectName(QString::fromUtf8("pushButtonRemove"));

        horizontalLayout->addWidget(pushButtonRemove);

        pushButtonFresh = new QPushButton(horizontalLayoutWidget);
        pushButtonFresh->setObjectName(QString::fromUtf8("pushButtonFresh"));

        horizontalLayout->addWidget(pushButtonFresh);

        MainWindowEncryption->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowEncryption);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 863, 23));
        MainWindowEncryption->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowEncryption);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindowEncryption->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowEncryption);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowEncryption->setStatusBar(statusBar);

        retranslateUi(MainWindowEncryption);

        QMetaObject::connectSlotsByName(MainWindowEncryption);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowEncryption)
    {
        MainWindowEncryption->setWindowTitle(QApplication::translate("MainWindowEncryption", "MainWindowEncryption", 0, QApplication::UnicodeUTF8));
        pushButtonAdd->setText(QApplication::translate("MainWindowEncryption", "Add", 0, QApplication::UnicodeUTF8));
        pushButtonCheckOut->setText(QApplication::translate("MainWindowEncryption", "CheckOut", 0, QApplication::UnicodeUTF8));
        pushButtonCheckIn->setText(QApplication::translate("MainWindowEncryption", "CheckIn", 0, QApplication::UnicodeUTF8));
        pushButtonRemove->setText(QApplication::translate("MainWindowEncryption", "Remove", 0, QApplication::UnicodeUTF8));
        pushButtonFresh->setText(QApplication::translate("MainWindowEncryption", "Fresh", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowEncryption: public Ui_MainWindowEncryption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWENCRYPTION_H
