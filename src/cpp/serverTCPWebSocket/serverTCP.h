#define MYSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>

class QtserverTCP : public QObject {
	Q_OBJECT
public:
	QtserverTCP(QObject *parent, uint16_t port);

public slots:
	void SocketConnected();

private:
	QTcpSocket * socket;
	QTcpServer * serverTCP;

};
#pragma once
