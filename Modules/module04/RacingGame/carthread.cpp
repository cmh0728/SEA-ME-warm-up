#include "carthread.h"
#include <QThread>

//constructor
CarThread::CarThread(Car* car, RaceTrack* track, QMutex* mutex, QObject* parent)
    : QThread(parent), m_car(car), m_track(track), m_mutex(mutex) {}

//loop(race)
void CarThread::run() {
    while (m_car->position() < m_track->finishLine()) {
        m_mutex->lock();
        m_car->move(); // car move
        m_mutex->unlock();
        msleep(100); //0.1s delay(100ms)
    }
}
