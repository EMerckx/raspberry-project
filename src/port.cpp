#include "port.h"

Port::Port(int mode, unsigned int port_number, unsigned int state) : AbstractPort(port_number, state) {
    mode_ = mode;
    if (mode_ == INPUT) {
        pinMode(port_number, INPUT);
    }
    else {
        pinMode(port_number, OUTPUT);
    }
}

int Port::mode() const {
    return mode_;
}

unsigned int Port::state() const {
    if (mode_ == INPUT) {
        state_ = Read();
    }
    return state_;
}

void Port::set_state(unsigned int state) {
    if (mode_ == OUTPUT) {
        state_ = state;
        Write();
    }
}

void Port::Write() {
    if (mode_ == OUTPUT) {
        digitalWrite(port_number_, state_);
    }
}

unsigned int Port::Read() const {
    if (mode_ == INPUT) {
        state_ = digitalRead(port_number_);
    }
    return state_;
}