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
class MainWindowEncryption : public QMainWindow, private Ui::MainWindowEncryption
{
    Q_OBJECT
    
public:
    explicit MainWindowEncryption(QWidget *parent = 0);
private:
    void AddNewDir(QDir dir);
    void RemoveDir();
    QString HashDirName(QString data);
    bool IsDirExist(QString dir);
    void MakeBackup(QString dir);
    void ReadAllBackups();
    void WriteAllBackups();
private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonRemove_clicked();
    void on_listWidgetDirList_itemClicked(QListWidgetItem *item);

    void on_MainWindowEncryption_destroyed();

private:
    QDir backupLocation;
};

#endif // MAINWINDOWENCRYPTION_H
