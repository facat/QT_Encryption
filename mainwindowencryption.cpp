#include "mainwindowencryption.h"
#include "src/encryption.h"
MainWindowEncryption::MainWindowEncryption(QWidget *parent) :
	QMainWindow(parent),
	backupLocation("c:/backuplocation/")
{

	setupUi(this);
	this->tableWidgetDetail->horizontalHeader()->setStretchLastSection(true);
	this->ReadAllBackups();

}



void MainWindowEncryption::on_pushButtonAdd_clicked()
{
	QFileDialog dialog;
	QString dir=dialog.getExistingDirectory(this,"ѡ���ļ���");
	if(""==dir) return;//����ȡ��
	qDebug()<<dir;
	QList<QListWidgetItem *> findItem(this->listWidgetDirList->findItems(dir,Qt::MatchFixedString));
	if(findItem.isEmpty())//��û��
	{
		this->listWidgetDirList->addItem(dir);
	}
	this->AddNewDir(this->listWidgetDirList->item(this->listWidgetDirList->count()-1)->text());//��øող����Ŀ¼·��


}

void MainWindowEncryption::on_pushButtonRemove_clicked()
{
	if(this->listWidgetDirList->currentItem()==NULL)
	{
		QMessageBox::information(this,"��ʾ","δѡ��");
		return;
	}
	if(QMessageBox::question(this,"��ʾ","��ɾ�����ݣ��Ƿ������",QMessageBox::Yes|QMessageBox::No)==QMessageBox::No) return;
	this->RemoveDir(this->listWidgetDirList->currentItem()->text());
	qDebug()<<this->listWidgetDirList->currentItem()->text();
	delete this->listWidgetDirList->takeItem(this->listWidgetDirList->currentRow());
    this->tableWidgetDetail->clear();





}

void MainWindowEncryption::AddNewDir(QDir dir)
{
	QDir newDir(this->backupLocation);
	QString newDirName=this->HashDirName(dir.path().toAscii()) ;
	qDebug()<<"newDirName "<<newDirName;
	if(this->IsDirExist(this->backupLocation.path()+"/"+newDirName))
	{

		QMessageBox::information(this,"��ʾ","�����Ѵ���");
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
	QStringList fileList(opDir.entryList());//���Ŀ¼�������ļ�
	foreach(QString i,fileList)
	{
		opDir.remove(i);//���Ŀ¼
	}
	if(!opDir.rmdir(opDir.path()))
	{
		QMessageBox::critical(this,"ע��","Ŀ¼ɾ��ʧ�ܣ�");
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
    ency->encryption(this->listWidgetDirList->currentItem()->text(),"123",this->backupLocation.path()+"/"+this->HashDirName(this->listWidgetDirList->currentItem()->text().replace('\\','/')));
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

        qDebug()<<i.fileName();
        this->tableWidgetDetail->setItem(ind,0,new QTableWidgetItem(i.fileName()));
        this->tableWidgetDetail->setItem(ind,1,new QTableWidgetItem(i.lastModified().toString()));

        ind++;
    }
    //this->tableWidgetDetail->show();
}
