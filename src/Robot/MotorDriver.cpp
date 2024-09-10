#include "Robot/MotorDriver.h"

MotorDriver::MotorDriver(int PMWspeed) {
    in1 = 0;
    in2 = 0;
    in3 = 0;
    in4 = 0;
    enableA = PMWspeed;
    enableB = PMWspeed;
    speed = PMWspeed;
    isReversingA = false;
    isReversingB = false;
}

int MotorDriver::getSpeed() {
    return speed;
}
int MotorDriver::getIn1() {
    return in1;
}
int MotorDriver::getIn2() {
    return in2;
}
int MotorDriver::getIn3() {
    return in3;
}
int MotorDriver::getIn4() {
    return in4;
}
int MotorDriver::getEnableA() {
    return enableA;
}
int MotorDriver::getEnableB(){
    return enableB;
}
bool MotorDriver::getIsReversingA() {
    return isReversingA;
}
bool MotorDriver::getIsReversingB() {
    return isReversingB;
}
bool MotorDriver::checkIsReversingA(int futureIn1, int futureIn2) {
    if (in1 != futureIn1 && in2 != futureIn2) {
        return true;
    }
    return false;
}
bool MotorDriver::checkIsReversingB(int futureIn3, int futureIn4) {
    if (in3 != futureIn3 && in4 != futureIn4) {
        return true;
    }
    return false;
}

void MotorDriver::setSpeed(int speed) {
    speed = speed;
}
void MotorDriver::setIn1(int value) {
    in1 = value;
}
void MotorDriver::setIn2(int value) {
    in2 = value;
}
void MotorDriver::setIn3(int value) {
    in3 = value;
}
void MotorDriver::setIn4(int value) {
    in4 = value;
}
void MotorDriver::setEnableA(int PMWvalue) {
    enableA = PMWvalue;
}
void MotorDriver::setEnableB(int PMWvalue) {
    enableB = PMWvalue;
}
void MotorDriver::setIsReversingA(bool isReversing) {
    isReversingA = isReversing;
}
void MotorDriver::setIsReversingB(bool isReversing) {
    isReversingB = isReversing;
}