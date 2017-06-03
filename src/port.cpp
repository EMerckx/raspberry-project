#include "port.h"

template <>
Port<INPUT>::Port(unsigned int port_number, unsigned int state) : AbstractPort(port_number, state) {
    pinMode(port_number, INPUT);
}

template <>
Port<OUTPUT>::Port(unsigned int port_number, unsigned int state) : AbstractPort(port_number, state) {
    pinMode(port_number, OUTPUT);
}

template<int T>
unsigned int Port<T>::state() {
    if (T == INPUT) {
        state_ = Read();
    }
    return state_;
}

template<int T>
void Port<T>::set_state(unsigned int state) {
    if (T == OUTPUT) {
        state_ = state;
        Write();
    }
}

template<int T>
void Port<T>::Write() {
    if (T == OUTPUT) {
        digitalWrite(port_number_, state_);
    }
}

template<int T>
unsigned int Port<T>::Read() {
    if (T == INPUT) {
        state_ = digitalRead(port_number_);
    }
    return state_;
}

//template <>
ostream& operator<<(ostream& os, const Port<INPUT>& port) {
    os <<  "Port<INPUT> { ";
    os << "port_number = " << port.port_number_ << ", ";
    os << "state = " << port.state_ << " }";
    return os;
}

//template <>
ostream& operator<<(ostream& os, const Port<OUTPUT>& port) {
    os <<  "Port<OUTPUT> { ";
    os << "port_number = " << port.port_number_ << ", ";
    os << "state = " << port.state_ << " }";
    return os;
}

/*template <>
string Port<INPUT>::to_string() const {
    string str = "Port<INPUT> { ";

    str.append("port_number = ");
    str.append(port_number_);
    str.append(", ");
    
    str.append("state = ");
    str.append(state_);
    str.append(" }");

    return str;
}

template <>
string Port<OUTPUT>::to_string() const {
    string str = "Port<OUTPUT> { ";

    str.append("port_number = ");
    str.append(port_number_);
    str.append(", ");
    
    str.append("state = ");
    str.append(state_);
    str.append(" }");

    return str;
}*/