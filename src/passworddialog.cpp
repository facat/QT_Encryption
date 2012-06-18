#include "passworddialog.h"

PasswordDialog::PasswordDialog(QString *pw, QWidget *parent) :
    QDialog(parent),m_pw(pw)
{
    setupUi(this);
    this->lineEdit->setFocus();
}

void PasswordDialog::on_pushButtonOK_clicked()
{
    QString pw=this->lineEdit->text();
    if(0==pw.length())
    {
        QMessageBox::warning(this,"×¢Òâ","±ØÐëÊäÈëÃÜÂë!");
    }
    else
    {
        *this->m_pw=this->lineEdit->text();
        this->close();
    }
}
