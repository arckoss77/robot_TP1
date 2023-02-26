#include "robot.hpp"
#include "mbed.h"

ROBOT::ROBOT(PinName EN_12,PinName A_1,PinName A_2, PinName EN_34,PinName A_3,PinName A_4) : EN12(EN_12), A1(A_1), A2(A_2), EN34(EN_34), A3(A_3), A4(A_4) {}


void ROBOT::enableMotor()
{
    EN12=1;
    EN34=1;
}

void ROBOT::disableMotor()
{
    EN12=0;
    EN34=0;
}

void ROBOT::setSpeed(int speed)
{

    if (speed >= 0 && speed <= 100)
    {
        wheelSpeed = 0.60f + ((static_cast<float>(speed))/100.00f) * 0.40f;
    }
    else wheelSpeed = 1.0f;
}
void ROBOT::forward()
{
    enableMotor();
    A1.write(wheelSpeed);
    A2.write(0);
    A3.write(wheelSpeed);
    A4.write(0);
}

void ROBOT::backward()
{
    enableMotor();
    A1.write(0);
    A2.write(wheelSpeed);
    A3.write(0);
    A4.write(wheelSpeed);
}
void ROBOT::turnRight()
{
    enableMotor();
    A1.write(0);
    A2.write(wheelSpeed);
    A3.write(wheelSpeed);
    A4.write(0);
}
void ROBOT::turnLeft()
{
    enableMotor();
    A1.write(wheelSpeed);
    A2.write(0);
    A3.write(0);
    A4.write(wheelSpeed);
}

void ROBOT::init()
{
    A1.period(1.0f / 2000);
    A2.period(1.0f / 2000);
    A3.period(1.0f / 2000);
    A4.period(1.0f / 2000);
    setSpeed(0);
}

void ROBOT::stop()
{
    disableMotor();
    A1.write(0);
    A2.write(0);
    A3.write(0);
    A4.write(0);
}
