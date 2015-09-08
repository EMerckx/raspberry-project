#ifndef RASPBERRYPI_PROJECT_PORT_H
#define RASPBERRYPI_PROJECT_PORT_H

#include "abstractport.h"

enum PortType { INPUT, OUTPUT, PWM_OUTPUT};

template <PortType T>
class Port : public AbstractPort {
public:
    Port(unsigned int port_number, unsigned int state = 0);

    // writes the state (0 or 1) to the port
    void Write(unsigned int state);

    // reads the state (0 or 1) from the port
    virtual unsigned int Read() const;

};

template <PortType T>
Port<T>::Port(unsigned int port_number, unsigned int state) : AbstractPort(port_number, state) { }

#endif //RASPBERRYPI_PROJECT_PORT_H
