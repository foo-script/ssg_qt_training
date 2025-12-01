#pragma once

class QObject;

namespace InstanceFactory
{
QObject* createInstance(QObject* parent = nullptr);
}
