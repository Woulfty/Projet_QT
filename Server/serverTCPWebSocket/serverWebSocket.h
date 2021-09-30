#pragma once
#ifndef __INSPECTION_SERVER_HPP__
#define __INSPECTION_SERVER_HPP__

#include <QObject>
#include <QList>
#include <QWebSocket>
#include <QWebSocketServer>
#include "bddserver.h"
#include <iostream>
#include <memory>

class QtserverWebSocket;

typedef std::shared_ptr<QWebSocketServer> QWebSocketServerPtr;
typedef std::shared_ptr<QWebSocket> QWebSocketPtr;
typedef std::shared_ptr<QtserverWebSocket> QtserverWebSocketPtr;

class QtserverWebSocket : public QObject
{
	Q_OBJECT

	QWebSocketServerPtr websocketServer;
	QList<QWebSocket*> clients;
	QMap<QWebSocket*, QString> wsocketToUsername;
	bddserver *bdd;

public:
	QtserverWebSocket(bddserver *bdd, uint16_t port);

signals:
	void closed();

private slots:
	void onNewConnection();
	void processTextMessage(const QString& message);
	void socketDisconnected();

};

#endif#pragma once
