#include "Robot/WorldState.h"

/**
 * @brief Get the position of the enemy robot
 * @returns 2 if the enemy robot is in the middle,
 *          1 if the enemy robot is on the left,
 *          3 if the enemy robot is on the right,
 *          0 if the enemy robot is not detected
*/
int WorldState::getEnemyPosition() {
    if (irSensor.getMiddleIRSensor() == 1) {
        lastEnemyPosition = 2;
        return 2;
    } else if (irSensor.getLeftIRSensor() == 1) {
        lastEnemyPosition = 1;
        return 1;
    } else if (irSensor.getRightIRSensor() == 1) {
        lastEnemyPosition = 3;
        return 3;
    } else {
        return 0;
    }
}

int WorldState::getLastEnemyPosition() {
    return lastEnemyPosition;
}

/**
 * @brief Get the current position of the robot
 * @returns 2 if the back line sensor is on the line,
 *          1 if the left line sensor is on the line,
 *          3 if the right line sensor is on the line,
 *          0 if the robot is not on the line
*/
int WorldState::getCurrentPosition() {
    if (lineSensor.getBackLineSensor() == 1) {
        return 2;
    } else if (lineSensor.getLeftLineSensor() == 1) {
        return 1;
    } else if (lineSensor.getRightLineSensor() == 1) {
        return 3;
    } else {
        return 0;
    }
}
