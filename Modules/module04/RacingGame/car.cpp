#include "car.h"

//constructor
Car::Car(QString name, int speed, QObject* parent)
    : QObject(parent), m_name(name), m_position(0), m_speed(speed) {} //initioal position = 0


//get position
int Car::position() const { return m_position; }

//get name
QString Car::name() const { return m_name; }

//move car
void Car::move() {
    m_position += m_speed;
    emit positionChanged(m_name, m_position);
}


//가속도 공식 적용해서 움직인 시간에 비례한 가속도 적용?
