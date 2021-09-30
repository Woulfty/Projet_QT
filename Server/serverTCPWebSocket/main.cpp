#include <QtCore/QCoreApplication>
#include "serverTCP.h"
#include "serverWebSocket.h"
#include "bddserver.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	bddserver *bdd = new bddserver();
	bdd->bddInit("QMYSQL", "127.0.0.1", "servertcpwebsocket", "root", "");
	QtserverWebSocket serverWebSocket(bdd, 1234);
	QtserverTCP serverTCP(Q_NULLPTR, 4321);

	return a.exec();
}
