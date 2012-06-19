#include "passworddialog.h"

PasswordDialog::PasswordDialog(QString *pw, QWidget *parent) :
	QDialog(parent),m_pw(pw),m_OKClicked(false)
{
	setupUi(this);
	this->lineEdit->setFocus();

}

void PasswordDialog::on_pushButtonOK_clicked()
{
	QString pw=this->lineEdit->text();
	if(0==pw.length())
	{
		QMessageBox::warning(this,"ע��","������������!");
	}
	else
	{
		*this->m_pw=this->lineEdit->text();
        this->m_OKClicked=true;
		this->close();
	}
}

void PasswordDialog::closeEvent(QCloseEvent *e)
{

//	if(0==this->lineEdit->text().length())
//	{
//        e->ignore();

//	}
//	else
//	{
//        e->accept();
//	}
	if(!m_OKClicked)
	{
        //e->ignore();
        *this->m_pw="CANCEL";
	}
}
