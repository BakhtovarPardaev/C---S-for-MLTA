#include "mytcpserver.h"
#include "serverfunction.h"


MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent) {
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if (!mTcpServer->listen(QHostAddress::Any, 33333)) {
        qDebug() << "server is not started";
    } else {
        server_status = 1;
        qDebug() << "server is started";

    }
}

void MyTcpServer::slotNewConnection(){
    if (server_status == 1){
        QTcpSocket *tempSocket;
        tempSocket = mTcpServer->nextPendingConnection();
        tempSocket->write("Hello I`m Luka`s server!!!\r\n");
        connect(tempSocket, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
        connect(tempSocket, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
        TcpSocketList.push_front(tempSocket);
    }
}

void MyTcpServer::slotServerRead() {
    QString res = "";
    QTcpSocket* tempSocket = (QTcpSocket*)sender();
    QByteArray request;
    while (tempSocket->bytesAvailable() > 0) {

        request.append(tempSocket->readAll());
        res.append(request);
        qDebug()<<res.mid(0, res.length()-2)<<"\n";
    }
    QByteArray response = parse(request) + "\r\n";
    tempSocket->write(response);

}

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    server_status = 0;
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* tempSocket = (QTcpSocket*) sender();
    tempSocket->close();
}



