#include <iostream>
#include <memory>

#include <QDebug>
#include <QObject>
#include <QList>
#include <QWebSocket>
#include <QWebSocketServer>
#include "bddserver.h"

class QtserverTCP;

class QtserverWebSocket;

typedef std::shared_ptr<QWebSocketServer> QWebSocketServerPtr;
typedef std::shared_ptr<QWebSocket> QWebSocketPtr;
typedef std::shared_ptr<QtserverWebSocket> QtserverWebSocketPtr;

class QtserverWebSocket : public QObject
{
	Q_OBJECT
		QWebSocketServerPtr websocketServer;
		QList<QWebSocket*> wsclients;
		QMap<QWebSocket*, QString> wsocketToUsername;
		bddserver *bdd;

private:
	QWebSocket * socket;
	QtserverTCP * tcpServer;

public:
	QtserverWebSocket(bddserver *bdd, uint16_t port);
	void setTcpServer(QtserverTCP * server);
	QMap<QWebSocket*, QString> & getSockets() {
		return wsocketToUsername;
	}

public slots:
	void onNewConnection();
	void processTextMessage(const QString& message);
	void selectMessageWS(QSqlQuery query, QWebSocket *ws);
	void socketDisconnected();

signals:
	void closed();
};
