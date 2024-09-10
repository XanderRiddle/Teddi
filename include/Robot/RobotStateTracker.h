#include "Robot/WorldState.h"
#include "Robot/RobotActions.h"
#include "Sensors/IRSensor.h"
#include "Sensors/LineSensor.h"
#include "Robot/MotorDriver.h"

#ifndef ROBOT_STATE_TRACKER_H
#define ROBOT_STATE_TRACKER_H

class RobotStateTracker {
    private:
        WorldState& worldState;
        RobotActions& robotActions;
    public:
        RobotStateTracker(WorldState& worldState, RobotActions& robotActions)
            : worldState(worldState), robotActions(robotActions) {
        }
        int brakeStartTimeA;
        int brakeStartTimeB;
        int on_line_timer;
        bool isFirstTimeReversingA;
        bool isFirstTimeReversingB;
        int calculateState(int deltaTime, int previousState);
};


#endif 