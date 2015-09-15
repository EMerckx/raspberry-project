#ifndef RASPBERRYPI_PROJECT_PORT_H
#define RASPBERRYPI_PROJECT_PORT_H

#include "abstractport.h"
#include "wiringPi.h"

// wiringPi supports the PortTypes: INPUT, OUTPUT, PWM_OUTPUT
// we need only INPUT and OUTPUT
enum PortType {
    INPUT, OUTPUT
};

template<PortType T>
class Port : public AbstractPort {
private:
    // writes the state (0 or 1) to the port
    void Write();

    // reads the state (0 or 1) from the port
    virtual unsigned int Read() const;

public:
    Port(unsigned int port_number, unsigned int state = 0);

    unsigned int state() const;

    void set_state(unsigned int state);

};

template<PortType T>
Port<T>::Port(unsigned int port_number, unsigned int state) : AbstractPort(port_number, state) {
    if (T == INPUT) {
        pinMode(port_number, INPUT);
    }
    else {
        pinMode(port_number, OUTPUT);
    }
}

template<PortType T>
unsigned int Port<T>::state() const {
    if (T == INPUT) {
        state_ = Read();
    }
    return state_;
}

template<PortType T>
void Port<T>::set_state(unsigned int state) {
    if (T == OUTPUT) {
        state_ = state;
        Write(state);
    }
}

template<PortType T>
void Port<T>::Write() {
    if (T == OUTPUT) {
        digitalWrite(port_number_, state_);
    }
}

template<PortType T>
unsigned int Port<T>::Read() const {
    if (T == INPUT) {
        digitalRead(port_number_, state_);
    }
}

#endif //RASPBERRYPI_PROJECT_PORT_H
