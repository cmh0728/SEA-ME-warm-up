#ifndef CARTHREAD_H
#define CARTHREAD_H

#include <QThread>
#include <QMutex>
#include "car.h"
#include "racetrack.h"

class CarThread : public QThread {
    Q_OBJECT
public:
    CarThread(Car* car, RaceTrack* track, QMutex* mutex, QObject* parent = nullptr);
    void run() override;

private:
    Car* m_car; //car object
    RaceTrack* m_track; //track object
    QMutex* m_mutex; //for data protect between thread
};

#endif // CARTHREAD_H
