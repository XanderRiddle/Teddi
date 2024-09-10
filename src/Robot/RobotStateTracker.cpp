#include "Robot/RobotStateTracker.h"

int RobotStateTracker::calculateState(int deltaTime, int previousState) {

    const int BRAKE_DURATION = 1;

    int currentPosition = worldState.getCurrentPosition();
    int enemyPosition = worldState.getEnemyPosition();
    int lastEnemyPosition = worldState.getLastEnemyPosition();

    enum RobotState { ON_LINE, FIND, TRACK };
    RobotState state;

    if (previousState == ON_LINE && deltaTime - on_line_timer < 250) {
        state = (RobotState) previousState;
    } else if (currentPosition != 0) {
        state = ON_LINE;
    } else {
        if (lastEnemyPosition == 0) {
            state = FIND;
        }
        if (lastEnemyPosition != 0) {
            state = TRACK;
        }
    }

    /**
     * if has never seen robot spin left and right
     * 
     * if has seen robot, pursue
     * 
     * if on line, turn until not on line
    */
    switch (state) {
        case ON_LINE:
            robotActions.moveBackward();
            if (currentPosition !=0 ) {
                on_line_timer = deltaTime;
            }  
            if (currentPosition == 1) {
                robotActions.moveSoftRightBackward();
            }
            if (currentPosition == 3) {
                robotActions.moveSoftLeftBackward();
            }
            break;
        case FIND:
            //if (0 < (deltaTime % 1500) && (deltaTime % 1500) < 500) {
            //    robotActions.spinLeft();
            //}
            //if (500 <= (deltaTime % 1500) && (deltaTime % 1500) < 1500) {
            //    robotActions.spinRight();
            //}
            //robotActions.moveForwardSlow();
            break;
        case TRACK:
            if (enemyPosition == 0) {
                if (lastEnemyPosition == 1) {
                    robotActions.moveSharpLeft();
                }
                if (lastEnemyPosition == 3) {
                    robotActions.moveSharpRight();
                }
                if (lastEnemyPosition == 2) {
                    robotActions.moveForward(); // this would be very strange
                }
            } else {
                if (enemyPosition == 1) {
                    robotActions.moveSoftLeft();
                }
                if (enemyPosition == 3) {
                    robotActions.moveSoftRight();
                }
                if (enemyPosition == 2) {
                    robotActions.moveForward();
                }
            }
            break;
        }

    if (robotActions.getIsReversingA() == true) {
        if (isFirstTimeReversingA) {
            brakeStartTimeA = deltaTime;
            isFirstTimeReversingA = false;
        }
        if ((deltaTime - brakeStartTimeA) < BRAKE_DURATION) {
            robotActions.brakeA();
        } else {
            robotActions.setIsReversingA(false);
            isFirstTimeReversingA = true;
        }
    }

    if (robotActions.getIsReversingB() == true) {
        if (isFirstTimeReversingB) {
            brakeStartTimeB = deltaTime;
            isFirstTimeReversingB = false;
        }
        if ((deltaTime - brakeStartTimeB) < BRAKE_DURATION) {
            robotActions.brakeB();
        } else {
            robotActions.setIsReversingB(false);
            isFirstTimeReversingB = true;
        }
    }
    
    
    return state;
}