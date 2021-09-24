#include "client.h"
#include "main.h"
#include <QtWidgets/QApplication>



MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::client),
	_socket(this)
{
	ui->setupUi(this);
	_socket.connectToHost(QHostAddress(""), 4242);
	connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::onReadyRead()
{
	QByteArray datas = _socket.readAll();
	qDebug() << datas;
	_socket.write(QByteArray("ok !\n"));
}