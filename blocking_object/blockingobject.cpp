#include "blockingobject.h"

#include <QDebug>
#include <QTcpSocket>

#include <QDebug>

struct BlockingObject::Private
{
    QTcpSocket socket;
};

BlockingObject::BlockingObject(QObject *parent) : m_d(new Private)
{
}

// ----

BlockingObject::~BlockingObject() = default; // PIMPL

void BlockingObject::block()
{
    QTcpSocket socket;
    socket.connectToHost(QByteArrayLiteral("libsbrasserie.com"), static_cast<quint16>(80U));

    if (!socket.waitForConnected())
    {
        qWarning() << "Could not connect";
        emit finished();
        return;
    }
    socket.write("GET /img/downloaded/1.jpg HTTP/1.0\r\n");
    socket.write("Host: libsbrasserie.com\r\n");
    socket.write("User-Agent: custom/1.0.0\r\n");
    socket.write("Accept: text/html\r\n");
    //socket.write("\r\n"); // Deliberate bug

    if (!socket.waitForReadyRead())
    {
        qWarning() << "Not ready for read";
        emit finished();
        return;
    }

    qInfo() << "Finished successfuly";

    emit finished();
}

void BlockingObject::stop()
{
    qInfo() << "BlockingObject: stopping";
    m_d->socket.disconnectFromHost();
}
