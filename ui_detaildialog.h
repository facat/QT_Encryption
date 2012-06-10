/********************************************************************************
** Form generated from reading UI file 'detaildialog.ui'
**
** Created: Sun Jun 10 22:07:56 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILDIALOG_H
#define UI_DETAILDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DetailDialog
{
public:
    QPushButton *pushButtonOK;
    QPlainTextEdit *plainTextEditDetail;

    void setupUi(QDialog *DetailDialog)
    {
        if (DetailDialog->objectName().isEmpty())
            DetailDialog->setObjectName(QString::fromUtf8("DetailDialog"));
        DetailDialog->resize(458, 158);
        pushButtonOK = new QPushButton(DetailDialog);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(150, 120, 161, 31));
        plainTextEditDetail = new QPlainTextEdit(DetailDialog);
        plainTextEditDetail->setObjectName(QString::fromUtf8("plainTextEditDetail"));
        plainTextEditDetail->setGeometry(QRect(50, 10, 371, 101));

        retranslateUi(DetailDialog);

        QMetaObject::connectSlotsByName(DetailDialog);
    } // setupUi

    void retranslateUi(QDialog *DetailDialog)
    {
        DetailDialog->setWindowTitle(QApplication::translate("DetailDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButtonOK->setText(QApplication::translate("DetailDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DetailDialog: public Ui_DetailDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILDIALOG_H
