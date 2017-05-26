#ifndef RASPBERRYPI_PROJECT_MOTOR_H
#define RASPBERRYPI_PROJECT_MOTOR_H

#include "abstractmotor.h"
#include "motorcontrollerport.h"

class Motor : public AbstractMotor, public MotorControllerPort {
public:
    Motor(unsigned int port_1, unsigned int port_1_state, unsigned int port_2, unsigned int port_2_state,
          int speed = 0);

    virtual void Off();

    virtual void Forward();

    virtual void Reverse();

    virtual void Brake();

};

#endif //RASPBERRYPI_PROJECT_MOTOR_H
