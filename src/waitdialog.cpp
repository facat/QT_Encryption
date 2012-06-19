#include "waitdialog.h"
#include <qdialog>
WaitDialog::WaitDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

void	WaitDialog::done ( int r )
{
    if(0==r)
    {
        this->plainTextEditError->setPlainText("��ѹ����");
    }
    else
    {
        QDialog::done(r);
    }
}

void WaitDialog::on_pushButtonOK_clicked()
{
    QDialog::accept ();
}
