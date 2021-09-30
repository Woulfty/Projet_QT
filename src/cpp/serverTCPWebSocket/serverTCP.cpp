#include "serverTCP.h"

QtserverTCP::QtserverTCP(QObject *parent, uint16_t port) : QObject(parent) {

	serverTCP = new QTcpServer(this);

	if (serverTCP->listen(QHostAddress::AnyIPv4, port)) {
		QObject::connect(serverTCP, SIGNAL(newConnection()), this, SLOT(SocketConnected()));
		qInfo() << "Serveur TCP: Nouvelle connexion";
	}
	else {
		qInfo() << "Serveur TCP: Erreur d'ecoute IP ou Port";
	}
}

void QtserverTCP::SocketConnected() {
	QTcpSocket * socket = serverTCP->nextPendingConnection();
	socket->write("Hello world\r\n");
	socket->flush();
	socket->waitForBytesWritten(5000);
	socket->close();
}