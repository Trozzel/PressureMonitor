#ifndef TIMEUPDATER_HPP
#define TIMEUPDATER_HPP

#include <QObject>
#include <QDateTime>
#include <QDebug>

class TimeUpdater : public QObject
{
    Q_OBJECT

private:
    bool STOP_LOOP = false;
public:
    explicit TimeUpdater(QObject *parent = nullptr);
    void stopTimeLoop(); // Sets STOP_LOOP to true

public slots:
    void startTime();

signals:
    void timeUpdated(const QString& timeString);
};

#endif // TIMEUPDATER_HPP
