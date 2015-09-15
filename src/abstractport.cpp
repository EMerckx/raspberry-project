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
