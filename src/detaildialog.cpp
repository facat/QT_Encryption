#include "detaildialog.h"

DetailDialog::DetailDialog(QString *detail, QWidget *parent) :
    QDialog(parent),m_detail(detail)
{
    setupUi(this);
    this->plainTextEditDetail->setFocus();
}

void DetailDialog::on_pushButtonOK_clicked()
{
    *this->m_detail=this->plainTextEditDetail->toPlainText();
    this->close();
}
