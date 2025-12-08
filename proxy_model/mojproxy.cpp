#include "mojproxy.h"

int MojProxy::rowCount(const QModelIndex &parent) const
{
	return sourceModel()->columnCount(parent);
}

int MojProxy::columnCount(const QModelIndex &parent) const
{
	return sourceModel()->rowCount(parent);
}

QModelIndex MojProxy::mapToSource(const QModelIndex &proxyIndex) const
{
	// Tutaj szalenstwo do granic
	return createIndex(proxyIndex.column(), proxyIndex.row());
}

// Nieuzywane, dopoki nie obslugujesz Qt::EditRole
QModelIndex MojProxy::mapFromSource(const QModelIndex &) const
{
	return {};
}

QModelIndex MojProxy::index(int row, int column, const QModelIndex &) const
{
	// Tu nic nie kombinujemy, po prostu indeks
	return QAbstractItemModel::createIndex(row, column);
}

QModelIndex MojProxy::parent(const QModelIndex &) const
{
	return {};
}
