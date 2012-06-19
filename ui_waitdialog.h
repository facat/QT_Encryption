/********************************************************************************
** Form generated from reading UI file 'waitdialog.ui'
**
** Created: Tue Jun 19 09:20:48 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITDIALOG_H
#define UI_WAITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WaitDialog
{
public:
    QLabel *label;
    QPlainTextEdit *plainTextEditError;
    QPushButton *pushButtonOK;

    void setupUi(QDialog *WaitDialog)
    {
        if (WaitDialog->objectName().isEmpty())
            WaitDialog->setObjectName(QString::fromUtf8("WaitDialog"));
        WaitDialog->resize(305, 147);
        label = new QLabel(WaitDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 10, 161, 31));
        plainTextEditError = new QPlainTextEdit(WaitDialog);
        plainTextEditError->setObjectName(QString::fromUtf8("plainTextEditError"));
        plainTextEditError->setGeometry(QRect(20, 40, 261, 71));
        pushButtonOK = new QPushButton(WaitDialog);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(110, 120, 75, 23));

        retranslateUi(WaitDialog);

        QMetaObject::connectSlotsByName(WaitDialog);
    } // setupUi

    void retranslateUi(QDialog *WaitDialog)
    {
        WaitDialog->setWindowTitle(QApplication::translate("WaitDialog", "\347\255\211\345\276\205\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WaitDialog", "\346\255\243\345\234\250\346\211\247\350\241\214\345\216\213\347\274\251/\350\247\243\345\216\213\346\223\215\344\275\234", 0, QApplication::UnicodeUTF8));
        pushButtonOK->setText(QApplication::translate("WaitDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WaitDialog: public Ui_WaitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITDIALOG_H
