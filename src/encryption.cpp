#include "encryption.h"
#include <QProcess>
#include <QApplication>
#include <qDebug>
#include <QStringList>
Encryption::Encryption(QObject *parent):QObject(parent)
{
}

void Encryption::encryption(QString path, QString passwd,QString outPath)
{
    QString z("./7z/7z.exe");
    //QString z("D:/MyPro/QT_Encryption/7z/7z.exe");
    QStringList argList;
    argList.append("a");
    argList.append("-t7z");
    argList.append(Encryption::GetDirectoryName(path));//Ñ¹Ëõ°üÃû³Æ
    path.replace('\\',"/");
    if(path.at(path.length()-1)=='/')
    {
        argList.append(path+"");

    }
    else
    {
         argList.append(path+"/*");
    }
    if(""==outPath)
    {
    argList.append("-o"+Encryption::GetUpDirectory(path));
    }
    else
    {
        outPath.replace('\\','/');
        argList.append("-o"+outPath);
    }
    argList.append("-p"+passwd);
    argList.append("-mhe=on");
    //argList.append("-mmt=on");

    //qDebug()
    QProcess *p=new QProcess(this);
    this->process=p;
    p->setProcessChannelMode(QProcess::MergedChannels);
    connect(p,SIGNAL(readyReadStandardOutput()),this,SLOT(Output()));
//    foreach(QString i, argList)
//    {
//        qDebug()<<i;
//    }
    p->start(z,argList);

    //p->waitForFinished();
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
    dir.cdUp();
    return dir.currentPath();
}

void Encryption::Output() const
{
    qDebug()<<this->process->readAllStandardOutput();
}
