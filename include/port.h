#ifndef RASPBERRYPI_PROJECT_PORT_H
#define RASPBERRYPI_PROJECT_PORT_H

#include <string>

#include "abstractport.h"
#include "wiringPi.h"

// T stands for INPUT or OUTPUT from wiringPi
template<int T>
class Port : public AbstractPort {
private:
    // writes the state (0 or 1) to the port
    void Write();

    // reads the state (0 or 1) from the port
    unsigned int Read() const;

public:
    Port(unsigned int port_number, unsigned int state = 0);

    unsigned int state() const;

    void set_state(unsigned int state);

    string to_string() const;

};

#endif //RASPBERRYPI_PROJECT_PORT_H
