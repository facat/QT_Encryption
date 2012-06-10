#ifndef DETAILDIALOG_H
#define DETAILDIALOG_H

#include "ui_detaildialog.h"

class DetailDialog : public QDialog, private Ui::DetailDialog
{
    Q_OBJECT
    
public:
    explicit DetailDialog(QString *detail,QWidget *parent = 0);
private slots:
    void on_pushButtonOK_clicked();

private:
    QString *m_detail;
};

#endif // DETAILDIALOG_H
