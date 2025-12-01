#include "instancefactory.h"

#define DISABLE_LOGGING 1

#include <QRandomGenerator>

#include <QAction>
#include <QBuffer>
#include <QDir>
#include <QEventLoop>
#include <QFile>
#include <QObject>
#include <QTimer>
#include <QDebug>

template <typename T, typename... Args>
QObject* createQObject(QObject* parent, Args... args)
{
	return new T{args..., parent};
}

namespace
{
auto byteArray = QByteArrayLiteral("FooBar");

} // end of anonymous namespace

QObject *InstanceFactory::createInstance(QObject *parent)
{
#ifdef DISABLE_LOGGING
	auto logger = QMessageLogger().noDebug();
#else
	auto logger = qInfo();
#endif

	switch(QRandomGenerator::global()->bounded(0, 5))
	{
	case 0:
		logger << "QFile";
		return createQObject<QFile>(parent, QDir::currentPath());
	case 1:
		logger << "QBuffer";
		return createQObject<QBuffer>(parent, &byteArray);
	case 2:
		logger << "QEventLoop";
		return createQObject<QEventLoop>(parent);
	case 3:
		logger << "QTimer";
		return createQObject<QTimer>(parent);
	case 4:
		logger << "QAction";
		return createQObject<QAction>(parent, QStringLiteral("BarFoo"));
	case 5:
		logger << "QObject";
		return createQObject<QObject>(parent);
	}

	Q_UNREACHABLE();
	return nullptr;
}
