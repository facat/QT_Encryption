#include "mainwindowencryption.h"
#include "src/encryption.h"
MainWindowEncryption::MainWindowEncryption(QWidget *parent) :
    QMainWindow(parent)
{

    setupUi(this);
    Encryption *ency=new Encryption(this);
    ency->encryption("D:/MyPro/QT_Encryption/7z/1","123");
}
