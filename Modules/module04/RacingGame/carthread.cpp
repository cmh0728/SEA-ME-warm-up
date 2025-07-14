#include "carthread.h"
#include <QThread>

//constructor
CarThread::CarThread(Car* car, RaceTrack* track, QMutex* mutex, QObject* parent)
    : QThread(parent), m_car(car), m_track(track), m_mutex(mutex) {}

//loop(race)
void CarThread::run() {
    while (!isInterruptionRequested() && m_car->position() < m_track->finishLine()) {
        m_mutex->lock();
        m_car->move();
        m_mutex->unlock();

        emit m_car->positionChanged(m_car->name(), m_car->position());

        msleep(100);
    }

}
