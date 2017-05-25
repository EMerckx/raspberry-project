#ifndef RASPBERRYPI_PROJECT_PORT_H
#define RASPBERRYPI_PROJECT_PORT_H

#include "abstractport.h"
#include "wiringPi.h"

class Port : public AbstractPort {
private:
	int mode_;
private:
    // writes the state (0 or 1) to the port
    void Write();

    // reads the state (0 or 1) from the port
    unsigned int Read() const;

public:
	// mode stands for INPUT or OUTPUT from wiringPi
    Port(int mode, unsigned int port_number, unsigned int state = 0);

    int mode() const;

    unsigned int state() const;

    void set_state(unsigned int state);

};

#endif //RASPBERRYPI_PROJECT_PORT_H
