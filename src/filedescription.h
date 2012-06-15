#ifndef FILEDESCRIPTION_H
#define FILEDESCRIPTION_H
#include "sqlite3.h"
#include <QDebug>
#include <QtCore>
#include <QByteArray>
class FileDescription
{
public:
    FileDescription(QString dbFile);
    ~FileDescription();
    QString GetFileDetail(QString realName);
    QString GetFileName(QString realName);
    void SetFileDetail(QString realName, QString fileName, QString detail);
    bool IsFileDetailExist(QString realName);
    void DeleteFileDetail(QString realName);
private:
    sqlite3 *dbHandle;
    sqlite3_stmt *pState;

};

#endif // FILEDESCRIPTION_H
