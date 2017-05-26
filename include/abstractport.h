#ifndef RASPBERRYPI_PROJECT_ABSTRACTPORT_H
#define RASPBERRYPI_PROJECT_ABSTRACTPORT_H

class AbstractPort {
protected:
    unsigned int port_number_;
    unsigned int state_;

private:
    // writes the state (0 or 1) to the port
    virtual void Write() = 0;

    // reads the state (0 or 1) from the port
    virtual unsigned int Read() const = 0;

public:
    AbstractPort(unsigned int port_number, unsigned int state = 0);

    unsigned int port_number() const;

    void set_port_number(unsigned int port_number);

    unsigned int state() const;

    void set_state(unsigned int state);
};

#endif //RASPBERRYPI_PROJECT_ABSTRACTPORT_H
