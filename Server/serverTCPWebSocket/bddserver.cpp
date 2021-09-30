#include <QDebug>
#include "bddserver.h"

void bddserver::bddInit(QString type, QString host, QString name, QString login, QString mdp) {
	QSqlDatabase bdd = QSqlDatabase::addDatabase(type);
	bdd.setHostName(host);
	bdd.setDatabaseName(name);
	bdd.setUserName(login);
	bdd.setPassword(mdp);

	bddConnect(bdd);
}

void bddserver::bddConnect(QSqlDatabase bdd) {
	bool ok = bdd.open();
	if (ok == true) {
		qInfo() << "BDD: Nouvelle connexion";
	}
	else {
		qInfo() << "BDD: Erreur de connexion";
	}
}

QString bddserver::getID() {
	return this->id;
}


QString bddserver::connexion(QString login, QString mdp, QWebSocket *obj) {
	QSqlQuery query;
	QString pseudo = "";
	//QMap
	query.exec("SELECT * FROM `user` WHERE `login`='"+login+"' AND `mdp`='"+mdp+"'");
	if (query.next()) {
		QString id = query.value(0).toString();
		QString loglogin = query.value(1).toString();
		QString logmdp = query.value(2).toString();
		if (loglogin == login && logmdp == mdp) {
			obj->sendTextMessage("Authtrue");
			this->id = id;
			qInfo() << login+" s'est connecte";
			pseudo = login;
			selectMessage(query, obj);
		}
	}
	return pseudo;
}

void bddserver::inscription(QString login, QString mdp, QWebSocket *obj) {
	QSqlQuery query;
	query.exec("INSERT INTO `user`(`login`, `mdp`) VALUES('"+login+"', '"+mdp+"')");
	query.next();
	qInfo() << login + " s'est creer un compte";
	query.exec("SELECT * FROM `user` WHERE `login`='"+login+"' AND `mdp`='"+mdp+"'");
	if (query.next()) {
		QString id = query.value(0).toString();
	}
	obj->sendTextMessage("Salttrue");
	this->id = id;
	qInfo() << login + " s'est connecte";
	selectMessage(query, obj);
}

void bddserver::insertMessage(QString login, QString message, QWebSocket *obj) {
	QSqlQuery query;
	query.prepare("INSERT INTO message(`iduser`,`message`) SELECT id, :message FROM user WHERE user.login = :username");
	query.bindValue(":username", login);
	query.bindValue(":message", message);
	query.exec();
}

void bddserver::selectMessage(QSqlQuery query, QWebSocket *obj) {
	query.exec("SELECT `login`,`message` FROM `user`, `message` WHERE id=iduser ORDER BY `date` LIMIT 100");
	while (query.next()) {
		QString login = query.value(0).toString();
		QString message = query.value(1).toString();
		obj->sendTextMessage(login+": "+message);
	}
}
