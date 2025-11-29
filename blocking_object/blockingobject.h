#pragma once

#include <QObject>

#include <memory>

class BlockingObject : public QObject
{
    Q_OBJECT

public:
    BlockingObject(QObject* parent=nullptr);

    ~BlockingObject();

    //! Blocks execution for an unpredictable period of time. Requires network access.
    Q_SLOT void block();
    Q_SLOT void stop();

signals:
    void finished();

private:
    // PIMPL
    struct Private;
    std::unique_ptr<Private> m_d;
};
