#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	socket = new QTcpSocket(this);

	connect(this, &MainWindow::newMessage, this, &MainWindow::displayMessage);
	connect(socket, &QTcpSocket::readyRead, this, &MainWindow::readSocket);
	connect(socket, &QTcpSocket::disconnected, this, &MainWindow::discardSocket);
	

	socket->connectToHost(QHostAddress::LocalHost, 8080);

	
}

MainWindow::~MainWindow()
{
	if (socket->isOpen())
		socket->close();
	delete ui;
}

void MainWindow::readSocket()
{
	QByteArray buffer;

	



	

	QString header = buffer.mid(0, 128);
	QString fileType = header.split(",")[0].split(":")[1];

	buffer = buffer.mid(128);

	if (fileType == "attachment") {
		QString fileName = header.split(",")[1].split(":")[1];
		QString ext = fileName.split(".")[1];
		QString size = header.split(",")[2].split(":")[1].split(";")[0];

		if (QMessageBox::Yes == QMessageBox::question(this, "QTCPServer", QString("voulez vous envoyez la socket?").arg(socket->socketDescriptor()).arg(size).arg(fileName)))
		{
			QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/" + fileName, QString("File (*.%1)").arg(ext));

			QFile file(filePath);
			if (file.open(QIODevice::WriteOnly)) {
				file.write(buffer);
				QString message = QString("INFO :: Attachment from sd:%1 successfully stored on disk under the path %2").arg(socket->socketDescriptor()).arg(QString(filePath));
				emit newMessage(message);
			}
			else
				QMessageBox::critical(this, "QTCPServer", "An error occurred while trying to write the attachment.");
		}
		else {
			QString message = QString("INFO :: Attachment from sd:%1 discarded").arg(socket->socketDescriptor());
			emit newMessage(message);
		}
	}
	else if (fileType == "message") {
		QString message = QString("%1 :: %2").arg(socket->socketDescriptor()).arg(QString::fromStdString(buffer.toStdString()));
		emit newMessage(message);
	}
}

void MainWindow::discardSocket()
{
	socket->deleteLater();
	socket = nullptr;

	
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
	switch (socketError) {
	case QAbstractSocket::RemoteHostClosedError:
		break;
	case QAbstractSocket::HostNotFoundError:
		QMessageBox::information(this, "QTCPClient", "The host was not found. Please check the host name and port settings.");
		break;
	case QAbstractSocket::ConnectionRefusedError:
		QMessageBox::information(this, "QTCPClient", "The connection was refused by the peer. Make sure QTCPServer is running, and check that the host name and port settings are correct.");
		break;
	default:
		QMessageBox::information(this, "QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
		break;
	}
}

void MainWindow::on_pushButton_sendMessage_clicked()
{
	if (socket)
	{
		if (socket->isOpen())
		{
			QString str = ui->lineEdit_message->text();

			QDataStream socketStream(socket);
	

			QByteArray header;
			header.prepend(QString("fileType:message,fileName:null,fileSize:%1;").arg(str.size()).toUtf8());
			header.resize(128);

			QByteArray byteArray = str.toUtf8();
			byteArray.prepend(header);

			socketStream << byteArray;

			ui->lineEdit_message->clear();
		}
		else
			QMessageBox::critical(this, "QTCPClient", "Socket ne pas souvrir");
	}
	else
		QMessageBox::critical(this, "QTCPClient", "non connecter");
}

void MainWindow::on_pushButton_sendAttachment_clicked()
{
	if (socket)
	{
		if (socket->isOpen())
		{
			QString filePath = QFileDialog::getOpenFileName(this, ("Select an attachment"), QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), ("File (*.json *.txt *.png *.jpg *.jpeg)"));

			if (filePath.isEmpty()) {
				QMessageBox::critical(this, "QTCPClient", "??a marche!");
				return;
			}

			QFile m_file(filePath);
			if (m_file.open(QIODevice::ReadOnly)) {

				QFileInfo fileInfo(m_file.fileName());
				QString fileName(fileInfo.fileName());

				QDataStream socketStream(socket);
				

				QByteArray header;
				header.prepend(QString("fileType:attachment,fileName:%1,fileSize:%2;").arg(fileName).arg(m_file.size()).toUtf8());
				header.resize(128);

				QByteArray byteArray = m_file.readAll();
				byteArray.prepend(header);

				
				socketStream << byteArray;
			}
			else
				QMessageBox::critical(this, "QTCPClient", "Attachment is not readable!");
		}
		else
			QMessageBox::critical(this, "QTCPClient", "Socket doesn't seem to be opened");
	}
	else
		QMessageBox::critical(this, "QTCPClient", "Not connected");
}

