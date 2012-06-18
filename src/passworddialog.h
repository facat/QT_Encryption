#ifndef PASSWORDDIALOG_H
#define PASSWORDDIALOG_H

#include "ui_passworddialog.h"
#include <QMessageBox>
class PasswordDialog : public QDialog, private Ui::PasswordDialog
{
    Q_OBJECT
    
public:
    explicit PasswordDialog(QString *pw,QWidget *parent = 0);
private slots:
    void on_pushButtonOK_clicked();
private:
    QString *m_pw;
};

#endif // PASSWORDDIALOG_H
