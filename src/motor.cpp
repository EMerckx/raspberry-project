#include "motor.h"

Motor::Motor(unsigned int port_1, unsigned int port_1_state, unsigned int port_2, unsigned int port_2_state, int speed)
        : MotorControllerPort(port_1, port_1_state, port_2, port_2_state),
          AbstractMotor(speed) {
    Off();
}

void Motor::Off() {
    this->set_speed(0);
    this->set_states(0, 0);
}

void Motor::Forward() {
    this->set_states(1, 0);
}

void Motor::Reverse() {
    this->set_states(0, 1);
}

void Motor::Brake() {
    this->set_states(0, 0);
}