#ifndef RASPBERRYPI_PROJECT_MOTORCONTROLLERPORT_H
#define RASPBERRYPI_PROJECT_MOTORCONTROLLERPORT_H

#include "port.h"

class MotorControllerPort {
private:
    Port enable_port_;
    Port port_1_;
    Port port_2_;
public:
    MotorControllerPort(unsigned int enable_port, unsigned int enable_port_state, unsigned int port_1,
                        unsigned int port_1_state, unsigned int port_2, unsigned int port_2_state);

    Port enable_port() const;

    void set_enable_port(unsigned int port_number, unsigned int state);

    Port port_1() const;

    void set_port_1(unsigned int port_number, unsigned int state);

    Port port_2() const;

    void set_port_2(unsigned int port_number, unsigned int state);

    void set_states(unsigned int enable_port_state, unsigned int port_1_state, unsigned int port_2_state);
};

MotorControllerPort::MotorControllerPort(unsigned int enable_port, unsigned int enable_port_state, unsigned int port_1,
                                         unsigned int port_1_state, unsigned int port_2, unsigned int port_2_state) :
        enable_port_(enable_port, enable_port_state), port_1_(port_1, port_1_state), port_2_(port_2, port_2_state) { }

Port MotorControllerPort::enable_port() const {
    return enable_port_;
}

void MotorControllerPort::set_enable_port(unsigned int port_number, unsigned int state) {
    enable_port_ = Port(port_number, state);
}

Port MotorControllerPort::port_1() const {
    return port_1_;
}

void MotorControllerPort::set_port_1(unsigned int port_number, unsigned int state) {
    port_1_ = Port(port_number, state);
}

Port MotorControllerPort::port_2() const {
    return port_2_;
}

void MotorControllerPort::set_port_2(unsigned int port_number, unsigned int state) {
    port_2_ = Port(port_number, state);
}

void MotorControllerPort::set_states(unsigned int enable_port_state, unsigned int port_1_state,
                                     unsigned int port_2_state) {
    enable_port_.set_state(enable_port_state);
    port_1_.set_state(port_1_state);
    port_2_.set_state(port_2_state);
}

#endif //RASPBERRYPI_PROJECT_MOTORCONTROLLERPORT_H
