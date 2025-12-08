#include "mojmodel.h"

QModelIndex MojModel::index(int row, int column, const QModelIndex &parent) const
{
	return QAbstractItemModel::createIndex(row, column);
}

QModelIndex MojModel::parent(const QModelIndex &child) const
{
	return {};
}

int MojModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid())
	{
		return 0;
	}
	return 10;
}

int MojModel::columnCount(const QModelIndex &parent) const
{
	if (parent.isValid())
	{
		return 0;
	}
	return 3;
}

QVariant MojModel::data(const QModelIndex &index, int role) const
{
	if (role == Qt::DisplayRole)
	{
		return QStringLiteral("w: %1 k: %2").arg(index.row()).arg(index.column());
	}
	return {};
}
