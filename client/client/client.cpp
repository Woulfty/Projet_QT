#include "client.h"

client::client(QWidget *parent)
    : QMainWindow(parent).
	_socket(this)
	ui(new Ui::MainWindow),
{
    ui.setupUi(this);

}


	

	
{
	ui->setupUi(this);
	_socket.connectToHost(QHostAddress("127.0.0.1"), 4242);
	connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

client::~client()
{
	delete ui;
}

void MainWindow::onReadyRead()
{
	QByteArray datas = _socket.readAll();
	qDebug() << datas;
	_socket.write(QByteArray("ok !\n"));
}

// pour afficher/cacher setvisible 
