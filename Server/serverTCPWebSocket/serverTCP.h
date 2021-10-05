#include <iostream>
#include <memory>

#include <QDebug>
#include <QObject>
#include <QList>
#include <QTcpSocket>
#include <QTcpServer>
#include "bddserver.h"

class QtserverWebSocket;

class QtserverTCP : public QObject {
	Q_OBJECT
		QList<QTcpSocket*> tcpclients;
		QMap<QTcpSocket*, QString> tcpsocketToUsername;
		bddserver *bdd;
private:
	QTcpSocket * tcpSocket;
	QTcpServer * tcpServer;
	QtserverWebSocket * wsServer;

public:
	QtserverTCP(bddserver *bdd, uint16_t port);
	void setWSServer(QtserverWebSocket * server);
	QMap<QTcpSocket*, QString> & getSockets() {
		return tcpsocketToUsername;
	}

public slots:
	void onNewConnection();
	void processTextMessage();
	void selectMessageTCP(QSqlQuery query, QTcpSocket *tcp);
	void socketDisconnected();

signals:
	void closed();
};
