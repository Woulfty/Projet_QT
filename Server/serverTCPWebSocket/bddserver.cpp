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

QString bddserver::connexion(QString login, QString mdp) {
	QSqlQuery query;
	QString pseudo = "";
	query.exec("SELECT * FROM `user` WHERE `login`='"+login+"' AND `mdp`='"+mdp+"'");
	if (query.next()) {
		QString logid = query.value(0).toString();
		QString loglogin = query.value(1).toString();
		QString logmdp = query.value(2).toString();

		if (loglogin == login && logmdp == mdp) {
			qInfo() << login+" s'est connecte";
			pseudo = login;
		}
	}
	return pseudo;
}

QString bddserver::inscription(QString login, QString mdp) {
	QSqlQuery query;
	QString pseudo = login;
	query.exec("INSERT INTO `user`(`login`, `mdp`) VALUES('"+login+"', '"+mdp+"')");
	query.next();
	qInfo() << login + " s'est creer un compte";
	qInfo() << login + " s'est connecte";
	return pseudo;
}

void bddserver::insertMessage(QString login, QString message) {
	QSqlQuery query;
	query.prepare("INSERT INTO message(`iduser`,`message`) SELECT id, :message FROM user WHERE user.login = :username");
	query.bindValue(":username", login);
	query.bindValue(":message", message);
	query.exec();
}
