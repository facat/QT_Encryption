#include "filedescription.h"

FileDescription::FileDescription(QString dbFile)
{
    sqlite3_open(dbFile.toAscii().data(),&(this->dbHandle));

}

QString FileDescription::GetFileDetail(QString realName)
{
    QString selState;
    selState=QString("select * from Description where RealName='%1' ").arg(realName);
    //selState=QString("select * from Description where RealName='45' ").arg(realName);
    qDebug()<<selState;
    int error=sqlite3_prepare(this->dbHandle,selState.toAscii().data(),selState.toAscii().length(),&(this->pState),NULL);
    qDebug()<<error;
    error=sqlite3_step(this->pState);
    if(SQLITE_ROW !=error)
    {
        sqlite3_finalize(this->pState);
        return QString("");
    }
    //qDebug()<<"sqlite3_column_count"<<sqlite3_column_count(this->pState);
    QByteArray data((char *)sqlite3_column_blob(this->pState,2),sqlite3_column_bytes(this->pState, 2));
    qDebug()<<"data"<<data;
    sqlite3_finalize(this->pState);
    return QString(data);
}
QString FileDescription::GetFileName(QString realName)
{
    QString selState;
    selState=QString("select * from Description where RealName='%1' ").arg(realName);
    //selState=QString("select * from Description where RealName='45' ").arg(realName);
    qDebug()<<selState;
    int error=sqlite3_prepare(this->dbHandle,selState.toAscii().data(),selState.toAscii().length(),&(this->pState),NULL);
    qDebug()<<error;
    error=sqlite3_step(this->pState);
    if(SQLITE_ROW !=error)
    {
        sqlite3_finalize(this->pState);
        return QString("");
    }
    //qDebug()<<"sqlite3_column_count"<<sqlite3_column_count(this->pState);
    QByteArray data((char *)sqlite3_column_blob(this->pState,1),sqlite3_column_bytes(this->pState, 1));
    qDebug()<<"data"<<data;
    sqlite3_finalize(this->pState);
    return QString(data);
}

FileDescription::~FileDescription()
{
    //sqlite3_finalize(this->pState);
    sqlite3_close(this->dbHandle);
}

void FileDescription::SetFileDetail(QString realName,QString fileName,QString detail)
{
    QString sqlState;
    if(this->IsFileDetailExist(realName))//已经有记录了
    {
        sqlState=QString("update Description set Detail='%1' where RealName='%2' ").arg(detail).arg(realName);
    }
    else
    {
        sqlState=QString("insert into Description values('%1','%2','%3')").arg(realName).arg(fileName).arg(detail);
    }
    qDebug()<<sqlState;
    int error=sqlite3_prepare(this->dbHandle,sqlState.toAscii().data(),sqlState.toAscii().length(),&(this->pState),NULL);
    error=sqlite3_step(this->pState);
    qDebug()<<error;
    sqlite3_finalize(this->pState);
}

bool FileDescription::IsFileDetailExist(QString realName)
{
    if(this->GetFileDetail(realName)=="") return false;
    return true;
}

void FileDescription::DeleteFileDetail(QString realName)
{
    QString selState;
    selState=QString("delete  from Description where RealName='%1' ").arg(realName);
    qDebug()<<selState;
    int error=sqlite3_prepare(this->dbHandle,selState.toAscii().data(),selState.toAscii().length(),&(this->pState),NULL);
    qDebug()<<error;
    error=sqlite3_step(this->pState);
    qDebug()<<error;
    sqlite3_finalize(this->pState);

}
