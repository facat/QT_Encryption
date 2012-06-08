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
	void encryption(QString path, QString passwd, QString outPath="");
private:
	QString GetDirectoryName(QString path);
	QString GetUpDirectory(QString path);
	QProcess *encryprocess;
	QProcess *decryprocess;

private slots:
	void Output() const;

};

#endif // ENCRYPTION_H
