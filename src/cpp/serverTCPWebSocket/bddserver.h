#pragma once
#include <QObject>
#include <QWebSocket>
#include <QWebSocketServer>
#include <QtSql>
#include <QSqlDatabase>
#include <qstring.h>

class bddserver {
	QString id;
	bddserver *bdd;
public :
	void bddInit(QString type, QString host, QString name, QString login, QString mdp);
	void bddConnect(QSqlDatabase bdd);
	QString getID();
	QString connexion(QString login, QString mdp, QWebSocket *obj);
	void inscription(QString login, QString mdp, QWebSocket *obj);
	void selectMessage(QSqlQuery query, QWebSocket *obj);
	void insertMessage(QString id, QString message, QWebSocket *obj);
};