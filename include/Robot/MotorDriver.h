#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

class MotorDriver {
private:
    int in1;
    int in2;
    int in3;
    int in4;
    int enableA;
    int enableB;
    int speed;
    bool isReversingA;
    bool isReversingB;
public:
    MotorDriver(int speed);
    int getSpeed();
    int getIn1();
    int getIn2();
    int getIn3();
    int getIn4();
    int getEnableA();
    int getEnableB();
    bool getIsReversingA();
    bool getIsReversingB();
    bool checkIsReversingA(int futureIn1, int futureIn2);
    bool checkIsReversingB(int futureIn3, int futureIn4);

    void setSpeed(int speed);
    void setIn1(int value);
    void setIn2(int value);
    void setIn3(int value);
    void setIn4(int value);
    void setEnableA(int PMWvalue);
    void setEnableB(int PMWvalue);
    void setIsReversingA(bool isReversing);
    void setIsReversingB(bool isReversing);
};

#endif 
