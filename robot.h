#ifndef robot_H
#define robot_H
#include "mbed.h"


 
class ROBOT {
    private:
        
        DigitalOut EN12;
        PwmOut A1;
        PwmOut A2;

        DigitalOut EN34;
        PwmOut A3;
        PwmOut A4;
        
        float wheelSpeed;
        void enableMotor();
        void disableMotor();
        
    
    public:
        
        ROBOT(PinName EN_12,PinName A_1,PinName A_2, PinName EN_34,PinName A_3,PinName A_4);
        void init();
        void setSpeed(int speed);
        void forward();
        void backward();
        void turnRight();
        void turnLeft();
        void stop();
    
        
 
};

#endif
