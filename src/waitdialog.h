#ifndef WAITDIALOG_H
#define WAITDIALOG_H

#include "ui_waitdialog.h"

class WaitDialog : public QDialog, private Ui::WaitDialog
{
	Q_OBJECT

public:
	explicit WaitDialog(QWidget *parent = 0);
	virtual void	done ( int r );

private slots:
    void on_pushButtonOK_clicked();
};

#endif // WAITDIALOG_H
