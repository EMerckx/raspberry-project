#ifndef RASPBERRYPI_PROJECT_ABSTRACTPORT_H
#define RASPBERRYPI_PROJECT_ABSTRACTPORT_H

class AbstractPort {
private:
    unsigned int port_number_;
    unsigned int state_;
public:
    AbstractPort(unsigned int port_number, unsigned int state = 0);

    unsigned int port_number() const;

    void set_port_number(unsigned int port_number);

    unsigned int state() const;

    void set_state(unsigned int state);

    // writes the state (0 or 1) to the port
    virtual void Write(unsigned int state) = 0;

    // reads the state (0 or 1) from the port
    virtual unsigned int Read() const = 0;

};

AbstractPort::AbstractPort(unsigned int port_number, unsigned int state) {
    port_number_ = port_number;
    state_ = state;
}

unsigned int AbstractPort::port_number() const {
    return port_number_;
}

void AbstractPort::set_port_number(unsigned int port_number) {
    port_number_ = port_number;
}

unsigned int AbstractPort::state() const {
    return state_;
}

void AbstractPort::set_state(unsigned int state) {
    state_ = state;
}

#endif //RASPBERRYPI_PROJECT_ABSTRACTPORT_H
