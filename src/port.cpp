#include "port.h"

/***************************/

template <>
Port<INPUT>::Port(unsigned int port_number, unsigned int state) : AbstractPort(port_number, state) {
    pinMode(port_number, INPUT);
}

template <>
Port<OUTPUT>::Port(unsigned int port_number, unsigned int state) : AbstractPort(port_number, state) {
    pinMode(port_number, OUTPUT);
}

/***************************/

template <>
unsigned int Port<INPUT>::state() {
    state_ = Read();
    return state_;
}

template <>
unsigned int Port<OUTPUT>::state() {
    return state_;
}

/***************************/

template <>
void Port<INPUT>::set_state(unsigned int state) {
    // do nothing
}

template <>
void Port<OUTPUT>::set_state(unsigned int state) {
    state_ = state;
    Write();
}

/***************************/

template<>
void Port<INPUT>::Write() {
    // do nothing
}

template<>
void Port<OUTPUT>::Write() {
    digitalWrite(port_number_, state_);
}

/***************************/

template<>
unsigned int Port<INPUT>::Read() {
    state_ = digitalRead(port_number_);
    return state_;
}

template<>
unsigned int Port<OUTPUT>::Read() {
    return state_;
}

/***************************/

ostream& operator<<(ostream& os, const Port<INPUT>& port) {
    os <<  "Port<INPUT> { ";
    os << "port_number = " << port.port_number_ << ", ";
    os << "state = " << port.state_ << " }";
    return os;
}

ostream& operator<<(ostream& os, const Port<OUTPUT>& port) {
    os <<  "Port<OUTPUT> { ";
    os << "port_number = " << port.port_number_ << ", ";
    os << "state = " << port.state_ << " }";
    return os;
}

/***************************/
