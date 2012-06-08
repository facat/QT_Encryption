#include "encryption.h"
#include <QProcess>
#include <QApplication>
#include <qDebug>
#include <QStringList>
#include <QFileInfo>

Encryption::Encryption(QObject *parent):QObject(parent),encryprocess(NULL),decryprocess(NULL)
{
}

void Encryption::encryption(QString path, QString passwd,QString outPath)
{
	QString z("./7z/7z.exe");
	//QString z("D:/MyPro/QT_Encryption/7z/7z.exe");
	QStringList argList;
	argList.append("a");
	argList.append("-t7z");

    if(""==outPath)
    {
        //qDebug()<<"GetUpDirectory"<<Encryption::GetUpDirectory(path);
        QString out7zFile=Encryption::GetUpDirectory(path)+"/"+Encryption::GetDirectoryName(path)+".7z";
        qDebug()<<out7zFile;
        argList.append(out7zFile);
        //qDebug()<<Encryption::GetUpDirectory(path)+"/"+Encryption::GetDirectoryName(path)+".7z";
        //qDebug()<<"base dir"<<QApplication::applicationDirPath();
        //qDebug()<<"output:"<<path;

        //如果文件已经存在则删除
        QString removedFile(out7zFile);
        qDebug()<<removedFile;
        QFile::remove(removedFile);

    }
    else
    {
        outPath.replace('\\','/');
        QString out7zFile=outPath+"/"+Encryption::GetDirectoryName(path)+".7z";
        qDebug()<<"out7zFile"<<out7zFile;
        argList.append(out7zFile);
        //如果文件已经存在则删除
        QString removedFile(out7zFile);
        qDebug()<<removedFile;
        QFile::remove(removedFile);
    }
	path.replace('\\',"/");
	if(path.at(path.length()-1)=='/')
	{
        argList.append(path);

	}
	else
	{
        argList.append(path+"/");
	}

	argList.append("-p"+passwd);
	argList.append("-mhe=on");


	QProcess *p=new QProcess(this);
	this->encryprocess=p;
	p->setProcessChannelMode(QProcess::MergedChannels);
	connect(p,SIGNAL(readyReadStandardOutput()),this,SLOT(Output()));
	p->start(z,argList);
    qDebug()<<p->nativeArguments();
}

QString Encryption::GetDirectoryName(QString path)
{

	QDir dir(path);
	qDebug()<<dir.current().dirName();
	return dir.current().dirName();

}

QString Encryption::GetUpDirectory(QString path)
{
	QDir dir(path);
    qDebug()<<"in function GetUpDirectory"<<path;

    dir.cdUp();
    qDebug()<<"in function GetUpDirectory"<<dir.path();
    return dir.path();
}

void Encryption::Output() const
{
	if(NULL!=this->encryprocess)
	{
		qDebug()<<this->encryprocess->readAllStandardOutput();
	}
	if(NULL!=this->decryprocess)
	{
		qDebug()<<this->decryprocess->readAllStandardOutput();
	}
}

void Encryption::decryption(QString file,QString passwd,QString outPath)
{
	QString z("./7z/7z.exe");
	//QString z("D:/MyPro/QT_Encryption/7z/7z.exe");
	QStringList argList;
	argList.append("x");
	argList.append(file);
	argList.append("-p"+passwd);

	outPath.replace('\\','/');
	if(""==outPath)
	{
        QFileInfo fileinfo(file);
		//QDir dir(fileinfo.path());
        argList.append("-o"+fileinfo.path());

	}
	else
	{
		//if(outPath.at(outPath.length()-1)=="/")
		argList.append("-o"+outPath);
	}
	QProcess *p=new QProcess(this);
	this->decryprocess=p;
	p->setProcessChannelMode(QProcess::MergedChannels);
	connect(p,SIGNAL(readyReadStandardOutput()),this,SLOT(Output()));
	p->start(z,argList);

}
