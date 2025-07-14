#ifndef RACINGGAME_H
#define RACINGGAME_H

#include "ui_racinggame.h"
#include <QMainWindow>
#include <QMap>
#include <QLabel>
#include <QPushButton>
#include <QFrame>
#include <QVBoxLayout>
#include <QMutex>
#include "car.h"
#include "carthread.h"
#include "racetrack.h"


namespace Ui { class RacingGame; }

class RacingGame : public QMainWindow {
    Q_OBJECT

public:
    explicit RacingGame(QWidget* parent = nullptr);
    ~RacingGame();

private slots:
    void startRace();
    void updateCarPosition(QString name, int pos);
    void countdownTick();

private:
    Ui::RacingGame* ui;
    RaceTrack* m_track;
    QVector<Car*> m_cars;
    QVector<CarThread*> m_threads;
    QMap<QString, QLabel*> m_labels;
    QMutex m_mutex;
    QTimer* m_countdownTimer;
    int m_countdownValue;
    QLabel* m_countdownLabel;
    QString m_user1Name;
    QString m_user2Name;
    bool m_raceFinished = false;
};



#endif // RACINGGAME_H
