#include "racinggame.h"
#include "ui_racinggame.h"
#include <QPixmap>
#include <QTimer>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QInputDialog>


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

        // 사용자 이름 입력
        m_user1Name = QInputDialog::getText(this, "Player 1", "Enter Player 1's name : ");
        m_user2Name = QInputDialog::getText(this, "Player 2", "Enter Player 2's name : ");

        if (m_user1Name.isEmpty()) m_user1Name = "Player 1";
        if (m_user2Name.isEmpty()) m_user2Name = "Player 2";

        // 대신 QLabel로 트랙 배경을 생성
        QPixmap track(":/images/track2.png");
        QLabel* bgLabel = new QLabel(ui->trackFrame);
        bgLabel->setPixmap(track.scaled(ui->trackFrame->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        bgLabel->setGeometry(ui->trackFrame->rect());
        bgLabel->lower(); // 다른 위젯(자동차들) 뒤에 깔리게 함
        bgLabel->show();   // 반드시 필요

        delete m_track;
        m_track = new RaceTrack(0, ui->trackFrame->height());  // 트랙의 길이(세로)


        // 기존 객체들 정리
        for (CarThread* thread : m_threads) {
            thread->wait();
            delete thread;
        }
        m_threads.clear();

        qDeleteAll(m_cars);
        m_cars.clear();
        m_labels.clear();


        // 자동차 생성
        QStringList carNames = {"Car 1", "Car 2"};
        for (int i = 0; i < carNames.size(); ++i) {
            int randomSpeed = QRandomGenerator::global()->bounded(4, 7);  // 4~6
            Car* car = new Car(carNames[i], randomSpeed);
            m_cars.append(car);
        }



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
    if (m_labels.contains(name) && !m_raceFinished) {
        QLabel* label = m_labels[name];

        int maxY = ui->trackFrame->height() - label->height();
        int y = qMax(0, maxY - pos);
        label->move(label->x(), y);

        // 도착선 도달 확인
        if (y <= 0) {
            m_raceFinished = true;

            QString winner = (name == "Car 1") ? m_user1Name : m_user2Name;
            QMessageBox::information(this, "Race Finished", winner + " wins the race!");

            // 모든 쓰레드 종료
            for (CarThread* thread : m_threads) {
                thread->requestInterruption();  // CarThread 내에서 중단 체크 필요
            }

            QTimer::singleShot(1000, qApp, &QApplication::quit);  // 1초 후 앱 종료
        }
    }
}


