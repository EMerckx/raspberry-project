#include "motorcontrollerport.h"

MotorControllerPort::MotorControllerPort(unsigned int port_1, unsigned int port_1_state, unsigned int port_2,
                                         unsigned int port_2_state) :
        port_1_(port_1, port_1_state), port_2_(port_2, port_2_state) { }

Port  <OUTPUT> MotorControllerPort::port_1() const {
    return port_1_;
}

void MotorControllerPort::set_port_1(unsigned int port_number, unsigned int state) {
    port_1_ = Port<OUTPUT>(port_number, state);
}

Port <OUTPUT> MotorControllerPort::port_2() const {
    return port_2_;
}

void MotorControllerPort::set_port_2(unsigned int port_number, unsigned int state) {
    port_2_ = Port<OUTPUT>(port_number, state);
}

void MotorControllerPort::set_states(unsigned int port_1_state, unsigned int port_2_state) {
    port_1_.set_state(port_1_state);
    port_2_.set_state(port_2_state);
}