#ifndef WAITDIALOG_H
#define WAITDIALOG_H

#include "ui_waitdialog.h"

class WaitDialog : public QDialog, private Ui::WaitDialog
{
	Q_OBJECT

public:
	explicit WaitDialog(QWidget *parent = 0);

signals:
    void Rollback();


private slots:
	void on_pushButtonOK_clicked();
	virtual void	done ( int r );
};

#endif // WAITDIALOG_H
