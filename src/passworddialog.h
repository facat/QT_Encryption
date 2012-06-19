#ifndef PASSWORDDIALOG_H
#define PASSWORDDIALOG_H
#include <QCloseEvent>
#include "ui_passworddialog.h"
#include <QMessageBox>
class PasswordDialog : public QDialog, private Ui::PasswordDialog
{
    Q_OBJECT
    
public:
    explicit PasswordDialog(QString *pw,QWidget *parent = 0);
protected:
    void closeEvent(QCloseEvent *);
private slots:
    void on_pushButtonOK_clicked();
private:
    QString *m_pw;
    bool m_OKClicked;
};

#endif // PASSWORDDIALOG_H
