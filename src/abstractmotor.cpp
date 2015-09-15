#include "abstractmotor.h"

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