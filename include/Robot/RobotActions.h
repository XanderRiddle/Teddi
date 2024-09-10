#include "MotorDriver.h"

#ifndef ROBOT_ACTIONS_H
#define ROBOT_ACTIONS_H

class RobotActions {
    private:
        MotorDriver& motorDriver;
    public:
        enum Action {MOVE_FORWARD, SPIN_LEFT, SPIN_RIGHT, MOVE_SHARP_LEFT, MOVE_SHARP_RIGHT, MOVE_SOFT_LEFT, MOVE_SOFT_RIGHT, MOVE_BACKWARD, MOVE_SOFT_LEFT_BACKWARD, MOVE_SOFT_RIGHT_BACKWARD, BRAKE, BRAKE_A, BRAKE_B};
        RobotActions(MotorDriver& motorDriver)
            : motorDriver(motorDriver) {
        }
        Action previousAction;
        bool isBreaking;
        void moveForward();
        void moveForwardSlow();
        void spinLeft();
        void spinRight();
        void moveSharpLeft();   
        void moveSharpRight();  
        void moveSoftLeft();    //both wheel still moving in the same direction but still a pretty sharp turn
        void moveSoftRight();
        void moveBackward();
        void moveSoftLeftBackward();    //less sharp turn because its only used to back up from the edge
        void moveSoftRightBackward();
        void brake();
        void brakeA();
        void brakeB();
        bool getIsReversingA();
        bool getIsReversingB();
        void setIsReversingA(bool isReversingA);
        void setIsReversingB(bool isReversingB);
};
#endif
