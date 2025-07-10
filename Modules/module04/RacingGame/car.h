#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <Qstring>

//Qobject inherience for use signal-slot
class Car : public QObject {
    Q_OBJECT

public:
    Car(QString name, int speed, QObject* parent = nullptr); //(QObject* parent = nullptr) for memory
    int position() const;
    QString name() const;
    void move();

signals:
    void positionChanged(QString name, int newPosition);

private:
    QString m_name;
    int m_position;
    int m_speed;
    QString m_direction;
};

#endif // CAR_H
