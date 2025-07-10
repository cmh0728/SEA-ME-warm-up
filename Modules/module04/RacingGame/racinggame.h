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

namespace Ui {
class RacingGame;
}

class RacingGame : public QMainWindow {
    Q_OBJECT

public:
    RacingGame(QWidget* parent = nullptr);
    ~RacingGame();

private slots:
    void startRace();
    void updateCarPosition(QString name, int pos);

private:
    Ui::RacingGame* ui;

    RaceTrack* m_track;
    QVector<Car*> m_cars;
    QVector<CarThread*> m_threads;
    QMap<QString, QLabel*> m_labels;
    QMutex m_mutex;
    QFrame* m_trackFrame;
    QPushButton* m_startButton;
};


#endif // RACINGGAME_H
