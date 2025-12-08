#pragma once

#include <QAbstractProxyModel>

class MojProxy : public QAbstractProxyModel
{
	Q_OBJECT

public:
	using QAbstractProxyModel::QAbstractProxyModel;

	int rowCount(const QModelIndex &parent) const override;
	int columnCount(const QModelIndex &parent) const override;

	QModelIndex mapToSource(const QModelIndex &proxyIndex) const override;
	QModelIndex mapFromSource(const QModelIndex &) const override;

	QModelIndex index(int row, int column, const QModelIndex &) const override;
	QModelIndex parent(const QModelIndex &) const override;
};
