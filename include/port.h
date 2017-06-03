#ifndef RASPBERRYPI_PROJECT_PORT_H
#define RASPBERRYPI_PROJECT_PORT_H

#include <iostream>
#include <string>

#include "abstractport.h"
#include "wiringPi.h"

using std::ostream;
using std::string;

// T stands for INPUT or OUTPUT from wiringPi
template<int T>
class Port : public AbstractPort {
private:
    // writes the state (0 or 1) to the port
    void Write();

    // reads the state (0 or 1) from the port
    unsigned int Read();

public:
    Port(unsigned int port_number, unsigned int state = 0);

    unsigned int state();

    void set_state(unsigned int state);

    //friend ostream& operator<< <>(ostream& os, const Port& port);

    friend ostream& operator<<(ostream& os, const Port<INPUT>& port);

    friend ostream& operator<<(ostream& os, const Port<OUTPUT>& port);

};

#endif //RASPBERRYPI_PROJECT_PORT_H
