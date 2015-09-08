#ifndef RASPBERRYPI_PROJECT_ABSTRACTMOTOR_H
#define RASPBERRYPI_PROJECT_ABSTRACTMOTOR_H

class AbstractMotor {
private:
    int speed_;
public:
    AbstractMotor();
    AbstractMotor(int speed);

    int speed() const;

    void set_speed(int speed);

    virtual void Off() = 0;

    virtual void Forward() = 0;

    virtual void Reverse() = 0;

    virtual void Brake() = 0;
};

AbstractMotor::AbstractMotor() {
    speed_ = 0;
}

AbstractMotor::AbstractMotor(int speed) {
    speed_ = speed;
}

int AbstractMotor::speed() const {
    return speed_;
}

void AbstractMotor::set_speed(int speed) {
    if (speed < 0) {
        speed_ = 0;
    }
    else if (speed > 255) {
        speed_ = 255;
    }
    else {
        speed_ = speed;
    }
}

#endif //RASPBERRYPI_PROJECT_ABSTRACTMOTOR_H
