#include <QApplication>
#include "mainwindowencryption.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QApplication a(argc, argv);
    MainWindowEncryption w;
    w.show();
    
    return a.exec();
}
