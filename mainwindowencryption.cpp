//realName是不包括后缀的MD5码

#include "mainwindowencryption.h"
#include "src/encryption.h"
#include "src/filedescription.h"
#include "src/detaildialog.h"
#include "src/passworddialog.h"
#include "src/waitdialog.h"
MainWindowEncryption::MainWindowEncryption(QWidget *parent) :
	QMainWindow(parent),
	backupLocation("c:/backuplocation/")
{

	setupUi(this);
	this->tableWidgetDetail->horizontalHeader()->setStretchLastSection(true);
	this->ReadAllBackups();
	//FileDescription des("C:/backuplocation/db.s3db");
	//des.SetFileDetail("fsd111","f","sdf");

}



void MainWindowEncryption::on_pushButtonAdd_clicked()
{
	QFileDialog dialog;
	QString dir=dialog.getExistingDirectory(this,"选择文件夹");
	if(""==dir) return;//点了取消
	qDebug()<<dir;
	QList<QListWidgetItem *> findItem(this->listWidgetDirList->findItems(dir,Qt::MatchFixedString));
	if(findItem.isEmpty())//还没有
	{
		this->listWidgetDirList->addItem(dir);
	}
	this->AddNewDir(this->listWidgetDirList->item(this->listWidgetDirList->count()-1)->text());//获得刚刚插入的目录路径


}



void MainWindowEncryption::AddNewDir(QDir dir)
{
	QDir newDir(this->backupLocation);
	QString newDirName=this->HashDirName(dir.path().toAscii()) ;
	qDebug()<<"newDirName "<<newDirName;
	if(this->IsDirExist(this->backupLocation.path()+"/"+newDirName))
	{

		QMessageBox::information(this,"提示","备份已存在");
		return;
	}
	newDir.mkpath(newDirName);
}

void MainWindowEncryption::RemoveDir(QDir dir)
{
	QString QStrDir(dir.path());
	QStrDir.replace('\\','/');
	QDir opDir(this->backupLocation.path()+"/"+this->HashDirName(QStrDir));
	//
	QStringList fileList(opDir.entryList());//获得目录中所有文件
	foreach(QString i,fileList)
	{
		opDir.remove(i);//清空目录
	}
	if(!opDir.rmdir(opDir.path()))
	{
		QMessageBox::critical(this,"注意","目录删除失败！");
	}

}

QString MainWindowEncryption::HashDirName(QString data)
{
	data.replace('\\','/');
	return QString(QCryptographicHash::hash(data.toAscii(),QCryptographicHash::Md5).toHex().constData());
}

bool MainWindowEncryption::IsDirExist(QString dir)
{
	//qDebug()<<dir;
	QFileInfo info(dir);
	//qDebug()<<"info.isDir()"<<info.isDir();
	//qDebug()<<"info.exists()"<<info.exists();
	if(info.isDir() && info.exists()) return true;
	return false;
}

void MainWindowEncryption::on_listWidgetDirList_itemClicked(QListWidgetItem *item)
{
	qDebug()<<"on_listWidgetDirList_itemClicked";
	this->RefreshBackups(item->text());

}

void MainWindowEncryption::ReadAllBackups()
{
	QString savedFile=this->backupLocation.path()+"/backups.txt";
	if(!QFile::exists(savedFile)) return;
	QFile file(savedFile);
	if(file.open(QFile::ReadOnly))
	{
		QTextStream reader(&file);
		while(!reader.atEnd())
		{
			QString line(reader.readLine());
			if(line.trimmed()=="") continue;
			this->listWidgetDirList->addItem(line);
		}
		file.close();
	}

}

void MainWindowEncryption::WriteAllBackups()
{
	QString savedFile=this->backupLocation.path()+"/backups.txt";
	QFile file(savedFile);
	if(file.open(QFile::WriteOnly))
	{
		QList<QListWidgetItem *> allItem(this->listWidgetDirList->findItems("*",Qt::MatchWildcard|Qt::MatchWrap));
		QTextStream writer(&file);
		foreach(QListWidgetItem *i, allItem)
		{
			qDebug()<<i->text();
			writer<<i->text()<<endl;
		}

		file.close();
	}
}

void MainWindowEncryption::closeEvent(QCloseEvent *e)
{
	qDebug()<<"closeEvent";
	this->WriteAllBackups();
}





void MainWindowEncryption::on_pushButtonCheckOut_clicked()
{
	Encryption *ency=new Encryption(this);
	if(NULL==this->listWidgetDirList->currentItem()) return;
	QString pw;
	PasswordDialog pwDialog(&pw,this);
	pwDialog.setModal(true);
	pwDialog.show();
	pwDialog.exec();
	qDebug()<<pw;
    if("CANCEL"==pw) return;
	QString zipFile=ency->encryption(this->listWidgetDirList->currentItem()->text(),
	                                 pw,
	                                 this->backupLocation.path()+"/"+this->HashDirName(this->listWidgetDirList->currentItem()->text().replace('\\','/')),
	                                 this->GetValidZipName(this->listWidgetDirList->currentItem()->text())
	                                );
	//显示等待窗口
	WaitDialog waitDialog(this);
	connect(ency,SIGNAL(IsDone(int)),&waitDialog,SLOT(done(int)));
	waitDialog.setModal(true);
	waitDialog.show();
	waitDialog.exec();
	FileDescription fileDiscrip(this->backupLocation.path()+"/db.s3db");
	QString realName(this->ExtractRealNameFromZipFile(zipFile));
	qDebug()<<"realName "<<realName;
	QString dirName(this->GetDirectoryName(this->listWidgetDirList->currentItem()->text()));
	QString detail;
	DetailDialog detailDialog(&detail,this);
	detailDialog.setModal(true);
	detailDialog.show();
	detailDialog.exec();
	fileDiscrip.SetFileDetail(realName,this->GetDirectoryName(dirName),detail);
	this->RefreshBackups(this->listWidgetDirList->currentItem()->text());
}
void MainWindowEncryption::RefreshBackups(QString dir)
{
	QDir QDdir(this->backupLocation.path()+"/"+this->HashDirName(dir.replace('\\','/')));
	qDebug()<<QDdir.path();
	QFileInfoList info(QDdir.entryInfoList(QDir::Files));
	int ind=0;
	this->tableWidgetDetail->clear();
	this->tableWidgetDetail->setRowCount(info.count());
	foreach(QFileInfo i,info)
	{

		qDebug()<<i.baseName();
		QString realName(this->ExtractRealNameFromZipFile(i.baseName()));
		FileDescription fileDes(this->backupLocation.path()+"/"+"db.s3db");
		QString fileName=fileDes.GetFileName(realName);
		this->tableWidgetDetail->setItem(ind,0,new QTableWidgetItem(realName));
		this->tableWidgetDetail->setItem(ind,1,new QTableWidgetItem(fileName));
		this->tableWidgetDetail->setItem(ind,2,new QTableWidgetItem(i.lastModified().toString()));
		QString detail(fileDes.GetFileDetail(realName));
		this->tableWidgetDetail->setItem(ind,3,new QTableWidgetItem(detail));
		this->tableWidgetDetail->hideColumn(0);
		QStringList headLabel;
		headLabel.append("");
		headLabel.append("1");
		headLabel.append("2");
		headLabel.append("3");
		this->tableWidgetDetail->setHorizontalHeaderLabels(headLabel);
		ind++;
	}
	//this->tableWidgetDetail->show();
}

QString MainWindowEncryption::GetValidZipName(QString dir)
{
	dir.replace('\\','/');
	QDir objDir(this->backupLocation.path()+"/"+this->HashDirName(dir));
	int i=0;
	QString zipName=this->HashDirName(dir)+QString::number(i)+".7z";
	while(QFile::exists(objDir.path()+"/"+zipName))
	{
		i++;
		zipName=this->HashDirName(dir)+QString::number(i)+".7z";
	}
	return this->HashDirName(dir)+QString::number(i);
}

void MainWindowEncryption::on_pushButtonCheckIn_clicked()
{
	if(-1==this->tableWidgetDetail->currentRow())
	{
		QMessageBox::information(this,"提示","为选择文件包！");
		return;
	}

    //为回滚做备份
    this->MakeBackupForRollBack(this->listWidgetDirList->currentItem()->text());

	QString zipName;
	zipName=this->tableWidgetDetail->item(this->tableWidgetDetail->currentRow(),0)->text();

	//des=this->backupLocation.path()+"/"+this->HashDirName(this->listWidgetDirList->currentItem()->text().replace('\\','/'));
	QString des;
	if( QMessageBox::question(this,"注意","是否恢复？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::No) return;
	QDir desDir(this->listWidgetDirList->currentItem()->text());
	QStringList fileList(desDir.entryList());
	foreach(QString i,fileList)
	{
		desDir.remove(i);
	}
	desDir.cdUp();
	if(desDir.isRoot())
	{
		des=desDir.path();
		des.remove(des.length()-1,1);

	}
	else
	{
		des=desDir.path();
	}
	qDebug()<<des;
	Encryption *ency=new Encryption(this);
	QString fromFile;
	fromFile=this->backupLocation.path()+"/"+this->HashDirName(this->listWidgetDirList->currentItem()->text().replace('\\','/'))+"/"+zipName+".7z";
	qDebug()<<fromFile;
	QString pw;
	PasswordDialog pwDialog(&pw,this);

	pwDialog.setModal(true);
	pwDialog.show();
	pwDialog.exec();
	qDebug()<<"on_pushButtonCheckIn_clicked"<<pw;
    if("CANCEL"==pw) return;
	ency->decryption(fromFile,pw,des);

	//显示等待窗口
	WaitDialog waitDialog(this);

	connect(ency,SIGNAL(IsDone(int)),&waitDialog,SLOT(done(int)));
	connect(&waitDialog,SIGNAL(Rollback()),this,SLOT(Rollback()));
	waitDialog.setModal(true);
	waitDialog.show();
    waitDialog.exec();
    this->DeleteTempFile();


}

QString MainWindowEncryption::ExtractRealNameFromZipFile(const QString &zipFile)
{
	QFileInfo info(zipFile);
	return info.baseName();

}
QString MainWindowEncryption::GetDirectoryName(QString path)
{
	QDir dir(path);
	return dir.dirName();
}

void MainWindowEncryption::on_pushButtonRemoveDir_clicked()
{
	if(this->listWidgetDirList->currentItem()==NULL)
	{
		QMessageBox::information(this,"提示","未选择");
		return;
	}
	if(QMessageBox::question(this,"提示","将删除备份，是否继续？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::No) return;
	this->RemoveDir(this->listWidgetDirList->currentItem()->text());
	qDebug()<<this->listWidgetDirList->currentItem()->text();
	delete this->listWidgetDirList->takeItem(this->listWidgetDirList->currentRow());
	this->tableWidgetDetail->clearContents();
	this->tableWidgetDetail->setRowCount(0);
}





void MainWindowEncryption::on_tableWidgetDetail_itemClicked(QTableWidgetItem *item)
{
	qDebug()<<"on_tableWidgetDetail_itemClicked";
	this->tableWidgetDetail->selectRow(item->row());
}

void MainWindowEncryption::on_pushButtonRemoveBackup_clicked()
{
	if(QMessageBox::question(this,"提示","是否删除当前备份文件？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::No) return;

	QList<QTableWidgetItem *>  selItem(this->tableWidgetDetail->selectedItems());
	FileDescription fileDes(this->backupLocation.path()+"/db.s3db");
	foreach(QTableWidgetItem *i,selItem)
	{
		qDebug()<<i->column();
		if(i->column()==1)
		{
			qDebug()<<i->text();
			QString realName(this->tableWidgetDetail->item(i->row(),0)->text());
			qDebug()<<realName;
			fileDes.DeleteFileDetail(realName);
			this->DeleteBackupFile(realName);
		}
	}

	this->RefreshBackups(this->listWidgetDirList->currentItem()->text());



}

void MainWindowEncryption::DeleteBackupFile(QString realName)
{
	QString Strdir(this->listWidgetDirList->currentItem()->text().replace('\\','/'));
	QString hashDir(this->HashDirName(Strdir));
	QDir dir(this->backupLocation.path()+"/"+hashDir);
	qDebug()<<"del "+realName+".7z";
	dir.remove(realName+".7z");


}

void MainWindowEncryption::on_tableWidgetDetail_itemChanged(QTableWidgetItem *item)
{
	if(item->column()!=3) return;
	QString realName=this->tableWidgetDetail->item(item->row(),0)->text();
	QString fileName=this->tableWidgetDetail->item(item->row(),1)->text();
	QString detail=item->text();
	FileDescription fileDes(this->backupLocation.path()+"/db.s3db");
	fileDes.SetFileDetail(realName,fileName,detail);
}

void MainWindowEncryption::on_pushButtonOpenDir_clicked()
{
	if(NULL==this->listWidgetDirList->currentItem())
	{
		QMessageBox::information(this,"提示","请先选择文件。");
		return;
	}
	QUrl url("file:///"+this->listWidgetDirList->currentItem()->text());
	qDebug()<<url.toString();
	QDesktopServices::openUrl ( url);
}

void MainWindowEncryption::MakeBackupForRollBack(QString dir)
{
	QTemporaryFile tempFile;
	QString strTempFile;
	if(tempFile.open())
	{
		strTempFile=tempFile.fileName();
		tempFile.close();
	}

	dir.replace('\\','/');
	//QDir qdirDir(this->backupLocation.path()+"/"+dir);
	Encryption *encry=new Encryption(this);
	QFileInfo fileInfo(strTempFile);
	this->m_tempFile=strTempFile+".7z";
	//for(int i=1;i<1000000000;i++);
	encry->encryption(dir,"123",fileInfo.path(),fileInfo.fileName());
    WaitDialog waitDialog(this);
    connect(encry,SIGNAL(IsDone(int)),&waitDialog,SLOT(done(int)));
    waitDialog.setModal(true);
    waitDialog.show();
    waitDialog.exec();
	qDebug()<<"strTempFile"<<strTempFile;






}

void MainWindowEncryption::on_pushButton_clicked()
{
	if(NULL==this->listWidgetDirList->currentItem())
	{
		QMessageBox::information(this,"提示","请先选择文件。");
		return;
	}
	this->MakeBackupForRollBack(this->listWidgetDirList->currentItem()->text());
}

void MainWindowEncryption::Rollback()
{
    //for(int i=1; i<1000000000; i++);
	qDebug()<<"Rollback";
	Encryption *encry=new Encryption(this);
	QDir desDir(this->listWidgetDirList->currentItem()->text());
	desDir.cdUp();
	qDebug()<<"m_tempFile"<<this->m_tempFile;
	encry->decryption(this->m_tempFile,"123",desDir.path());
	//显示等待窗口
	WaitDialog waitDialog(this);
	connect(encry,SIGNAL(IsDone(int)),&waitDialog,SLOT(done(int)));
	waitDialog.setModal(true);
	waitDialog.show();
	waitDialog.exec();
    this->DeleteTempFile();

}

void MainWindowEncryption::DeleteTempFile()
{

    qDebug()<<QFile::remove(this->m_tempFile);
}
