#pragma once
#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <qstring.h>

class bddserver {
private :
	bddserver *bdd;
public :
	void bddInit(QString type, QString host, QString name, QString login, QString mdp);
	void bddConnect(QSqlDatabase bdd);
	QString getID();
	QString connexion(QString login, QString mdp);
	QString inscription(QString login, QString mdp);
	void insertMessage(QString login, QString message);
};