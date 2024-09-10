#include "Robot/RobotActions.h"

void RobotActions::moveForward() {
    if (previousAction != MOVE_FORWARD && !isBreaking) {
        motorDriver.setIsReversingA(motorDriver.checkIsReversingA(1 , 0));
        motorDriver.setIsReversingB(motorDriver.checkIsReversingB(1 , 0));
    }
    motorDriver.setIn1(1);
    motorDriver.setIn2(0);
    motorDriver.setIn3(1);
    motorDriver.setIn4(0);
    motorDriver.setEnableA(motorDriver.getSpeed() * 6.375);
    motorDriver.setEnableB(motorDriver.getSpeed() * 6.375);
    isBreaking = false;
    previousAction = MOVE_FORWARD;
}

void RobotActions::moveForwardSlow() {
    if (previousAction != MOVE_FORWARD && !isBreaking) {
        motorDriver.setIsReversingA(motorDriver.checkIsReversingA(1 , 0));
        motorDriver.setIsReversingB(motorDriver.checkIsReversingB(1 , 0));
    }
    motorDriver.setIn1(1);
    motorDriver.setIn2(0);
    motorDriver.setIn3(1);
    motorDriver.setIn4(0);
    motorDriver.setEnableA(motorDriver.getSpeed());
    motorDriver.setEnableB(motorDriver.getSpeed());
    isBreaking = false;
    previousAction = MOVE_FORWARD;
}

void RobotActions::spinLeft() {
    if (previousAction != SPIN_LEFT && !isBreaking) {
        motorDriver.setIsReversingA(motorDriver.checkIsReversingA(0 , 1));
        motorDriver.setIsReversingB(motorDriver.checkIsReversingB(1 , 0));
    }
    motorDriver.setIn1(0);
    motorDriver.setIn2(1);
    motorDriver.setIn3(1);
    motorDriver.setIn4(0);
    motorDriver.setEnableA(motorDriver.getSpeed());
    motorDriver.setEnableB(motorDriver.getSpeed());
    isBreaking = false;
    previousAction = SPIN_LEFT;

}

void RobotActions::spinRight() {
    if (previousAction != SPIN_RIGHT && !isBreaking) {
        motorDriver.setIsReversingA(motorDriver.checkIsReversingA(1 , 0));
        motorDriver.setIsReversingB(motorDriver.checkIsReversingB(0 , 1));
    }
    motorDriver.setIn1(1);
    motorDriver.setIn2(0);
    motorDriver.setIn3(0);
    motorDriver.setIn4(1);
    motorDriver.setEnableA(motorDriver.getSpeed());
    motorDriver.setEnableB(motorDriver.getSpeed());
    isBreaking = false;
    previousAction = SPIN_RIGHT;
}

void RobotActions::moveSharpLeft() {
    if (previousAction != MOVE_SHARP_LEFT && !isBreaking) {
        motorDriver.setIsReversingA(motorDriver.checkIsReversingA(1 , 0));
        motorDriver.setIsReversingB(motorDriver.checkIsReversingB(1 , 0));
    }
    motorDriver.setIn1(1);
    motorDriver.setIn2(0);
    motorDriver.setIn3(1);
    motorDriver.setIn4(0);
    motorDriver.setEnableA(motorDriver.getSpeed() / 2);
    motorDriver.setEnableB(motorDriver.getSpeed());
    isBreaking = false;
    previousAction = MOVE_SHARP_LEFT;
}

void RobotActions::moveSharpRight() {
    if (previousAction != MOVE_SHARP_RIGHT && !isBreaking) {
        motorDriver.setIsReversingA(motorDriver.checkIsReversingA(1 , 0));
        motorDriver.setIsReversingB(motorDriver.checkIsReversingB(1 , 0));
    }
    motorDriver.setIn1(1);
    motorDriver.setIn2(0);
    motorDriver.setIn3(1);
    motorDriver.setIn4(0);
    motorDriver.setEnableA(motorDriver.getSpeed());
    motorDriver.setEnableB(motorDriver.getSpeed() / 2);
    isBreaking = false;
    previousAction = MOVE_SHARP_RIGHT;
}

void RobotActions::moveSoftLeft() {
    if (previousAction != MOVE_SOFT_LEFT && !isBreaking) {
        motorDriver.setIsReversingA(motorDriver.checkIsReversingA(1 , 0));
        motorDriver.setIsReversingB(motorDriver.checkIsReversingB(1 , 0));
    }
    motorDriver.setIn1(1);
    motorDriver.setIn2(0);
    motorDriver.setIn3(1);
    motorDriver.setIn4(0);
    motorDriver.setEnableA(motorDriver.getSpeed() * 0.8);
    motorDriver.setEnableB(motorDriver.getSpeed());
    isBreaking = false;
    previousAction = MOVE_SOFT_LEFT;
}

void RobotActions::moveSoftRight() {
    if (previousAction != MOVE_SOFT_RIGHT && !isBreaking) {
        motorDriver.setIsReversingA(motorDriver.checkIsReversingA(1 , 0));
        motorDriver.setIsReversingB(motorDriver.checkIsReversingB(1 , 0));
    }
    motorDriver.setIn1(1);
    motorDriver.setIn2(0);
    motorDriver.setIn3(1);
    motorDriver.setIn4(0);
    motorDriver.setEnableA(motorDriver.getSpeed());
    motorDriver.setEnableB(motorDriver.getSpeed() * 0.8);
    isBreaking = false;
    previousAction = MOVE_SOFT_RIGHT;
}

void RobotActions::moveBackward() {
    if (previousAction != MOVE_BACKWARD && !isBreaking) {
        motorDriver.setIsReversingA(motorDriver.checkIsReversingA(0 , 1));
        motorDriver.setIsReversingB(motorDriver.checkIsReversingB(0 , 1));
    }
    motorDriver.setIn1(0);
    motorDriver.setIn2(1);
    motorDriver.setIn3(0);
    motorDriver.setIn4(1);
    motorDriver.setEnableA(motorDriver.getSpeed() * 3);
    motorDriver.setEnableB(motorDriver.getSpeed() * 3);
    isBreaking = false;
    previousAction = MOVE_BACKWARD;
}

void RobotActions::moveSoftLeftBackward() {
    if (previousAction != MOVE_SOFT_LEFT_BACKWARD && !isBreaking) {
        motorDriver.setIsReversingA(motorDriver.checkIsReversingA(0 , 1));
        motorDriver.setIsReversingB(motorDriver.checkIsReversingB(0 , 1));
    }
    motorDriver.setIn1(0);
    motorDriver.setIn2(1);
    motorDriver.setIn3(0);
    motorDriver.setIn4(1);
    motorDriver.setEnableA(motorDriver.getSpeed() * 4);
    motorDriver.setEnableB(motorDriver.getSpeed() * 2);
    isBreaking = false;
    previousAction = MOVE_SOFT_LEFT_BACKWARD;
}

void RobotActions::moveSoftRightBackward() {
    if (previousAction != MOVE_SOFT_RIGHT_BACKWARD && !isBreaking) {
        motorDriver.setIsReversingA(motorDriver.checkIsReversingA(0 , 1));
        motorDriver.setIsReversingB(motorDriver.checkIsReversingB(0 , 1));
    }
    motorDriver.setIn1(0);
    motorDriver.setIn2(1);
    motorDriver.setIn3(0);
    motorDriver.setIn4(1);
    motorDriver.setEnableA(motorDriver.getSpeed() * 2);
    motorDriver.setEnableB(motorDriver.getSpeed() * 4);
    isBreaking = false;
    previousAction = MOVE_SOFT_RIGHT_BACKWARD;
}

void RobotActions::brake() {
    motorDriver.setIn1(0);
    motorDriver.setIn2(0);
    motorDriver.setIn3(0);
    motorDriver.setIn4(0);
    motorDriver.setEnableA(0);
    motorDriver.setEnableB(0);
    isBreaking = true;
    previousAction = BRAKE;
}

void RobotActions::brakeA() {
    motorDriver.setIn1(0);
    motorDriver.setIn2(0);
    motorDriver.setEnableA(0);
    isBreaking = true;
    previousAction = BRAKE_A;
}

void RobotActions::brakeB() {
    motorDriver.setIn3(0);
    motorDriver.setIn4(0);
    motorDriver.setEnableB(0);
    isBreaking = true;
    previousAction = BRAKE_B;
}

bool RobotActions::getIsReversingA() {
    return motorDriver.getIsReversingA();
}

bool RobotActions::getIsReversingB() {
    return motorDriver.getIsReversingB();
}

void RobotActions::setIsReversingA(bool isReversingA) {
    motorDriver.setIsReversingA(isReversingA);
}

void RobotActions::setIsReversingB(bool isReversingB) {
    motorDriver.setIsReversingB(isReversingB);
}
