#include "timeupdater.hpp"
#include <iostream>

TimeUpdater::TimeUpdater(QObject *parent) : QObject(parent)
{
}

void TimeUpdater::startTime()
{
    while (!STOP_LOOP)
    {
        QTime now = QTime::currentTime();
        emit timeUpdated(now.toString());
    }
}

void TimeUpdater::stopTimeLoop()
{
    STOP_LOOP = true;
}
