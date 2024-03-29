#ifndef MAINWINDOWENCRYPTION_H
#define MAINWINDOWENCRYPTION_H

#include "ui_mainwindowencryption.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QString>
#include <QCryptographicHash>
#include <QList>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QDesktopServices>
#include <QTemporaryFile>
class MainWindowEncryption : public QMainWindow, private Ui::MainWindowEncryption
{
    Q_OBJECT
    
public:
    explicit MainWindowEncryption(QWidget *parent = 0);
private:
    void AddNewDir(QDir dir);
    void RemoveDir(QDir dir);
    QString HashDirName(QString data);
    bool IsDirExist(QString dir);
    //void MakeBackup(QString dir);
    void ReadAllBackups();
    void WriteAllBackups();
    void closeEvent(QCloseEvent *);
    void RefreshBackups(QString dir);
    QString GetValidZipName(QString dir);
    QString ExtractRealNameFromZipFile(const QString &zipFile);
    QString GetDirectoryName(QString path);
    void DeleteBackupFile(QString realName);
    void MakeBackupForRollBack(QString dir);
    void DeleteTempFile();
public slots:
    void Rollback();
private slots:
    void on_pushButtonAdd_clicked();
    void on_listWidgetDirList_itemClicked(QListWidgetItem *item);



    void on_pushButtonCheckOut_clicked();

    void on_pushButtonCheckIn_clicked();

    void on_pushButtonRemoveDir_clicked();

    void on_tableWidgetDetail_itemClicked(QTableWidgetItem *item);

    void on_pushButtonRemoveBackup_clicked();

    void on_tableWidgetDetail_itemChanged(QTableWidgetItem *item);

    void on_pushButtonOpenDir_clicked();

    void on_pushButton_clicked();

private:
    QDir backupLocation;
    QString m_tempFile;
};

#endif // MAINWINDOWENCRYPTION_H
