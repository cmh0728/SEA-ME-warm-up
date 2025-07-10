#include "racinggame.h"
#include "ui_racinggame.h"

RacingGame::RacingGame(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::RacingGame), m_track(new RaceTrack(1000, 1000)) {
    ui->setupUi(this);

    m_cars.append(new Car("Car 1", 5));
    m_cars.append(new Car("Car 2", 4));
    m_cars.append(new Car("Car 3", 6));

    for (int i = 0; i < m_cars.size(); ++i) {
        QLabel* label = new QLabel(m_cars[i]->name(), ui->trackFrame);
        label->setStyleSheet("background-color: red; color: white; padding: 4px; border-radius: 4px;");
        label->move(0, i * 40);
        label->show();
        m_labels[m_cars[i]->name()] = label;

        connect(m_cars[i], &Car::positionChanged, this, &RacingGame::updateCarPosition);
    }

    connect(ui->startButton, &QPushButton::clicked, this, &RacingGame::startRace);
}

RacingGame::~RacingGame() {
    delete ui;
    for (CarThread* thread : m_threads) {
        thread->wait();
        delete thread;
    }
    qDeleteAll(m_cars);
    delete m_track;
}

void RacingGame::startRace() {
    for (Car* car : m_cars) {
        CarThread* thread = new CarThread(car, m_track, &m_mutex, this);
        m_threads.append(thread);
        thread->start();
    }
}

void RacingGame::updateCarPosition(QString name, int pos) {
    if (m_labels.contains(name)) {
        QLabel* label = m_labels[name];
        int x = qMin(pos, m_trackFrame->width() - label->width());
        label->move(x, label->y());
    }
}

