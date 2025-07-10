#include "racinggame.h"
#include "ui_racinggame.h"
#include <QPixmap>
#include <QTimer>
#include <QVBoxLayout>
#include <QMessageBox>

//constructor
RacingGame::RacingGame(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::RacingGame), m_track(new RaceTrack(1000, 1000)), m_countdownTimer(new QTimer(this)), m_countdownValue(3) {
    ui->setupUi(this);

    // 인트로 이미지 세팅
    QPixmap introPixmap(":/images/IntroImage.png");  // 리소스에 등록한 인트로 이미지 경로
    ui->introLabel->setPixmap(introPixmap.scaled(
        ui->introLabel->size(),
        Qt::KeepAspectRatioByExpanding,
        Qt::SmoothTransformation));

    ui->introLabel->setAlignment(Qt::AlignCenter);
    ui->introLabel->lower();

    // 초기 화면 버튼 연결
    connect(ui->startButton, &QPushButton::clicked, this, [this]() {
        //버튼 누르면 숨기기
        ui->startButton->hide();
        ui->howToPlayButton->hide();
        ui->introLabel->hide();  // 인트로 이미지 숨기기

        // 대신 QLabel로 트랙 배경을 생성
        QPixmap track(":/images/track.png");
        QLabel* bgLabel = new QLabel(ui->trackFrame);
        bgLabel->setPixmap(track.scaled(ui->trackFrame->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        bgLabel->setGeometry(ui->trackFrame->rect());
        bgLabel->lower(); // 다른 위젯(자동차들) 뒤에 깔리게 함
        bgLabel->show();   // 반드시 필요

        // 자동차 생성
        m_cars.append(new Car("Car 1", 5));
        m_cars.append(new Car("Car 2", 4));
        m_cars.append(new Car("Car 3", 6));

        for (int i = 0; i < m_cars.size(); ++i) {
            QLabel* label = new QLabel(ui->trackFrame);
            QString carPath = i == 0 ? ":/images/car1.png" : (i == 1 ? ":/images/car2.png" : ":/images/car1.png");
            QPixmap pix(carPath);
            label->setPixmap(pix.scaled(60, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            label->move(0, i * 40);
            label->show();
            m_labels[m_cars[i]->name()] = label;

            connect(m_cars[i], &Car::positionChanged, this, &RacingGame::updateCarPosition);
        }

        // 카운트다운 라벨 생성
        m_countdownLabel = new QLabel("", ui->trackFrame);
        m_countdownLabel->setStyleSheet("font-size: 48px; color: yellow; background: transparent;");
        m_countdownLabel->setAlignment(Qt::AlignCenter);
        m_countdownLabel->setGeometry(ui->trackFrame->rect());
        m_countdownLabel->show();

        // 카운트다운 시작
        connect(m_countdownTimer, &QTimer::timeout, this, &RacingGame::countdownTick);
        m_countdownTimer->start(1000);
    });

    connect(ui->howToPlayButton, &QPushButton::clicked, this, [this]() {
        QMessageBox::information(this, "How to Play", "Click Start to begin the race. The first car to reach the finish line wins!");
    });
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

void RacingGame::countdownTick() {
    if (m_countdownValue > 0) {
        m_countdownLabel->setText(QString::number(m_countdownValue));
        --m_countdownValue;
    } else {
        m_countdownLabel->hide();
        m_countdownTimer->stop();
        startRace();
    }
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
        int x = qMin(pos, ui->trackFrame->width() - label->width());
        label->move(x, label->y());
    }
}
