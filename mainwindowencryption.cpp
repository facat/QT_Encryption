#include "mainwindowencryption.h"
#include "src/encryption.h"
MainWindowEncryption::MainWindowEncryption(QWidget *parent) :
    QMainWindow(parent),
    backupLocation("c:/backuplocation/")
{

	setupUi(this);
    this->tableWidgetDetail->horizontalHeader()->setStretchLastSection(true);
   // this->tableWidgetDetail->setColumnCount(1);;
    //Encryption *ency=new Encryption(this);
    //ency->encryption("D:/MyPro/QT_Encryption/7z/1","123");
	//connect(this->pushButtonAdd,SIGNAL(clicked()),this,SLOT(on_pushButtonAdd_clicked()));
}



void MainWindowEncryption::on_pushButtonAdd_clicked()
{
	QFileDialog dialog;
    QString dir=dialog.getExistingDirectory(this,"选择文件夹");
    qDebug()<<dir;
    QList<QListWidgetItem *> findItem(this->listWidgetDirList->findItems(dir,Qt::MatchFixedString));
    if(findItem.isEmpty())//还没有
    {
        this->listWidgetDirList->addItem(dir);
    }
    this->AddNewDir(this->listWidgetDirList->item(this->listWidgetDirList->count()-1)->text());//获得刚刚插入的目录路径


}

void MainWindowEncryption::on_pushButtonRemove_clicked()
{
    if(this->listWidgetDirList->currentItem()==NULL)
    {
        QMessageBox::information(this,"提示","未选择");
        return;
    }
    if(QMessageBox::question(this,"提示","将删除备份，是否继续？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::No) return;
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

void MainWindowEncryption::RemoveDir()
{

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
    QDir dir(this->backupLocation.path()+"/"+this->HashDirName(item->text().toAscii()));
    qDebug()<<dir.path();
    QFileInfoList info(dir.entryInfoList(QDir::Files));
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
    this->tableWidgetDetail->show();

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
        QList<QListWidgetItem *> allItem(this->listWidgetDirList->findItems("",Qt::MatchWildcard));
        QTextStream writer(&file);
        foreach(QListWidgetItem *i, allItem)
        {
            writer<<i->text()<<endl;
        }

        file.close();
    }
}

void MainWindowEncryption::on_MainWindowEncryption_destroyed()
{
    qDebug()<<"on_MainWindowEncryption_destroyed";
    this->WriteAllBackups();
}
