#ifndef ENCRYPTION_H
#define ENCRYPTION_H

class QProcess;
#include <QtCore>

class Encryption:public QObject
{

	Q_OBJECT
public:
	explicit Encryption(QObject *parent);
	void decryption(QString file, QString passwd, QString outPath="");
    QString encryption(QString path, QString passwd, QString outPath="",QString zipName="");
private:
	QString GetDirectoryName(QString path);
	QString GetUpDirectory(QString path);
	QProcess *encryprocess;
	QProcess *decryprocess;

private slots:
	void Output() const;
signals:
    void IsDone(int );

};

#endif // ENCRYPTION_H
