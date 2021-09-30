#include <QDebug>
#include "serverWebSocket.h"
#include "bddserver.h"

QtserverWebSocket::QtserverWebSocket(bddserver *bdd, uint16_t port)
	: websocketServer(new QWebSocketServer(QStringLiteral("Server WebSocket"), QWebSocketServer::NonSecureMode))
{
	this->bdd = bdd;
	if (this->websocketServer->listen(QHostAddress::AnyIPv4, port)) {
		qInfo() << "Server WebSocket: Nouvelle connexion";
		QObject::connect(websocketServer.get(), SIGNAL(newConnection()), this, SLOT(onNewConnection()));
	}
	else{
		qInfo() << "Server WebSocket: Erreur d'ecoute IP ou Port";
	}
}

void QtserverWebSocket::onNewConnection(){
	QWebSocket * socket = this->websocketServer->nextPendingConnection();
	QObject::connect(socket, SIGNAL(textMessageReceived(const QString&)), this, SLOT(processTextMessage(const QString&)));
	QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));

	this->clients.push_back(socket);
}

void QtserverWebSocket::processTextMessage(const QString& message){
	QWebSocket * obj = qobject_cast<QWebSocket*>(sender());
	if (message.startsWith("Auth") == true) {
		QString data = QStringRef(&message, 4, message.length() - 4).toString();
		QString login = data.section(";", 0, 0);
		QString mdp = data.section(";", 1, 1);
		QString pseudo = bdd->connexion(login, mdp, obj);
		if (pseudo.size() > 0)
		{
			wsocketToUsername[obj] = pseudo;

		}
	}
	if (message.startsWith("Salt") == true) {
		QString data = QStringRef(&message, 4, message.length() - 4).toString();
		QString login = data.section(";", 0, 0);
		QString mdp = data.section(";", 1, 1);
		bdd->inscription(login, mdp, obj);
	}
	if (message.startsWith("Bdd") == true) {
		QString data = QStringRef(&message, 3, message.length() - 3).toString();
		QString pseudo = wsocketToUsername[obj];
		bdd->insertMessage(pseudo, data, obj);
		
		QString sentence = pseudo + " : " + data;
		for(QList<QWebSocket*>::iterator it = clients.begin(); it != clients.end(); it++) {
			(*it)->sendTextMessage(sentence);
		}
	}
}

void QtserverWebSocket::socketDisconnected(){
	QWebSocket * obj = qobject_cast<QWebSocket*>(sender());
	qInfo() << "Server WebSocket: Deconnexion";
	this->clients.removeAll(obj);
}