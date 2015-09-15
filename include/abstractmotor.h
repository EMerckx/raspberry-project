#ifndef RASPBERRYPI_PROJECT_ABSTRACTMOTOR_H
#define RASPBERRYPI_PROJECT_ABSTRACTMOTOR_H

class AbstractMotor {
private:
    int speed_;
public:
    AbstractMotor();

    AbstractMotor(int speed);

    int speed() const;

    void set_speed(int speed);

    virtual void Off() = 0;

    virtual void Forward() = 0;

    virtual void Reverse() = 0;

    virtual void Brake() = 0;
};

#endif //RASPBERRYPI_PROJECT_ABSTRACTMOTOR_H
