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
        QPixmap track(":/images/track2.png");
        QLabel* bgLabel = new QLabel(ui->trackFrame);
        bgLabel->setPixmap(track.scaled(ui->trackFrame->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        bgLabel->setGeometry(ui->trackFrame->rect());
        bgLabel->lower(); // 다른 위젯(자동차들) 뒤에 깔리게 함
        bgLabel->show();   // 반드시 필요

        delete m_track;
        m_track = new RaceTrack(0, ui->trackFrame->height());  // 트랙의 길이(세로)

        // 자동차 생성
        m_cars.append(new Car("Car 1", 5));
        m_cars.append(new Car("Car 2", 4));

        for (int i = 0; i < m_cars.size(); ++i) {
            QLabel* label = new QLabel(ui->trackFrame);
            QString carPath = i == 0 ? ":/images/car1.png" : (i == 1 ? ":/images/car2.png" : ":/images/car1.png");

            // 크기 조정 (기존 60x100 → 약간 키움)
            QPixmap pix(carPath);
            label->setPixmap(pix.scaled(80, 120, Qt::KeepAspectRatio, Qt::SmoothTransformation));

            // 트랙 중앙 기준 x 위치 계산 (벌어지게)
            int baseX = ui->trackFrame->width() / 2 + 90;
            int spacing = 250;  // 차 간격 늘림
            int x = baseX - (spacing * m_cars.size() / 2) + (i * spacing);

            // y 위치: 아래쪽 (스타트선 위)
            int y = ui->trackFrame->height() - 130;

            label->move(x, y);
            label->show();
            m_labels[m_cars[i]->name()] = label;

            connect(m_cars[i], &Car::positionChanged, this, &RacingGame::updateCarPosition);
        }




        // 카운트다운 라벨 생성
        m_countdownLabel = new QLabel("", ui->trackFrame);
        m_countdownLabel->setStyleSheet(
            "font-size: 156px; "
            "color: red; "
            "font-weight:bold;"
            "background: transparent;");
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

        // Finish를 위쪽으로 가정 → 높이에서 pos를 빼서 위로 이동
        int maxY = ui->trackFrame->height() - label->height();
        int y = qMax(0, maxY - pos);

        label->move(label->x(), y);  // Y축 이동
    }
}

