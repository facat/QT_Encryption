/********************************************************************************
** Form generated from reading UI file 'mainwindowencryption.ui'
**
** Created: Tue Jun 19 15:38:08 2012
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
    QPushButton *pushButtonOpenDir;
    QPushButton *pushButtonCheckOut;
    QPushButton *pushButtonCheckIn;
    QPushButton *pushButtonRemoveBackup;
    QPushButton *pushButtonRemoveDir;
    QPushButton *pushButtonFresh;
    QPushButton *pushButton;
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
        if (tableWidgetDetail->columnCount() < 4)
            tableWidgetDetail->setColumnCount(4);
        tableWidgetDetail->setObjectName(QString::fromUtf8("tableWidgetDetail"));
        tableWidgetDetail->setGeometry(QRect(290, 10, 531, 481));
        tableWidgetDetail->setSortingEnabled(true);
        tableWidgetDetail->setCornerButtonEnabled(false);
        tableWidgetDetail->setColumnCount(4);
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

        pushButtonOpenDir = new QPushButton(horizontalLayoutWidget);
        pushButtonOpenDir->setObjectName(QString::fromUtf8("pushButtonOpenDir"));

        horizontalLayout->addWidget(pushButtonOpenDir);

        pushButtonCheckOut = new QPushButton(horizontalLayoutWidget);
        pushButtonCheckOut->setObjectName(QString::fromUtf8("pushButtonCheckOut"));

        horizontalLayout->addWidget(pushButtonCheckOut);

        pushButtonCheckIn = new QPushButton(horizontalLayoutWidget);
        pushButtonCheckIn->setObjectName(QString::fromUtf8("pushButtonCheckIn"));

        horizontalLayout->addWidget(pushButtonCheckIn);

        pushButtonRemoveBackup = new QPushButton(horizontalLayoutWidget);
        pushButtonRemoveBackup->setObjectName(QString::fromUtf8("pushButtonRemoveBackup"));

        horizontalLayout->addWidget(pushButtonRemoveBackup);

        pushButtonRemoveDir = new QPushButton(horizontalLayoutWidget);
        pushButtonRemoveDir->setObjectName(QString::fromUtf8("pushButtonRemoveDir"));

        horizontalLayout->addWidget(pushButtonRemoveDir);

        pushButtonFresh = new QPushButton(horizontalLayoutWidget);
        pushButtonFresh->setObjectName(QString::fromUtf8("pushButtonFresh"));

        horizontalLayout->addWidget(pushButtonFresh);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 510, 75, 23));
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
        pushButtonOpenDir->setText(QApplication::translate("MainWindowEncryption", "OpenDir", 0, QApplication::UnicodeUTF8));
        pushButtonCheckOut->setText(QApplication::translate("MainWindowEncryption", "CheckOut", 0, QApplication::UnicodeUTF8));
        pushButtonCheckIn->setText(QApplication::translate("MainWindowEncryption", "CheckIn", 0, QApplication::UnicodeUTF8));
        pushButtonRemoveBackup->setText(QApplication::translate("MainWindowEncryption", "Remove Backup", 0, QApplication::UnicodeUTF8));
        pushButtonRemoveDir->setText(QApplication::translate("MainWindowEncryption", "Remove Dir", 0, QApplication::UnicodeUTF8));
        pushButtonFresh->setText(QApplication::translate("MainWindowEncryption", "Fresh", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindowEncryption", "debug", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowEncryption: public Ui_MainWindowEncryption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWENCRYPTION_H
