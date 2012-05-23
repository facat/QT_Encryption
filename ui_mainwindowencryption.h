/********************************************************************************
** Form generated from reading UI file 'mainwindowencryption.ui'
**
** Created: Wed May 23 18:27:00 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWENCRYPTION_H
#define UI_MAINWINDOWENCRYPTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowEncryption
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonFresh;
    QPushButton *pushButtonRemove;
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
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(40, 70, 751, 391));
        pushButtonAdd = new QPushButton(centralWidget);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(330, 530, 75, 23));
        pushButtonFresh = new QPushButton(centralWidget);
        pushButtonFresh->setObjectName(QString::fromUtf8("pushButtonFresh"));
        pushButtonFresh->setGeometry(QRect(160, 530, 75, 23));
        pushButtonRemove = new QPushButton(centralWidget);
        pushButtonRemove->setObjectName(QString::fromUtf8("pushButtonRemove"));
        pushButtonRemove->setGeometry(QRect(480, 530, 75, 23));
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
        pushButtonAdd->setText(QApplication::translate("MainWindowEncryption", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButtonFresh->setText(QApplication::translate("MainWindowEncryption", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButtonRemove->setText(QApplication::translate("MainWindowEncryption", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowEncryption: public Ui_MainWindowEncryption {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWENCRYPTION_H
