#include <Arduino.h>

// implementation of Tracker

#include "Robot/WorldState.h"
#include "Robot/RobotActions.h"
#include "Sensors/IRSensor.h"
#include "Sensors/LineSensor.h"
#include "Robot/MotorDriver.h"

long myTime;
long timeSinceLastAction;

const int BACK_LINE_SENSOR = A4;
const int LEFT_LINE_SENSOR = A5;
const int RIGHT_LINE_SENSOR = A6;
const int LEFT_IR_SENSOR = A7;
const int RIGHT_IR_SENSOR = A8;
const int MIDDLE_IR_SENSOR = A9;

MotorDriver motorDriver = MotorDriver();
IRSensor irSensor = IRSensor();
LineSensor lineSensor = LineSensor();
WorldState worldState = WorldState(lineSensor, irSensor);
RobotActions robotActions = RobotActions(motorDriver);

void moveForward();
void moveBackLeft();
void moveBackRight();

void pollSensors();
void robotState();
void findEnemy();

void setup() {
    pinMode(BACK_LINE_SENSOR, INPUT);
    pinMode(LEFT_LINE_SENSOR, INPUT);
    pinMode(RIGHT_LINE_SENSOR, INPUT);
    pinMode(LEFT_IR_SENSOR, INPUT);
    pinMode(RIGHT_IR_SENSOR, INPUT);
    pinMode(MIDDLE_IR_SENSOR, INPUT);
    attachInterrupt(digitalPinToInterrupt(BACK_LINE_SENSOR), moveForward, CHANGE);
    attachInterrupt(digitalPinToInterrupt(LEFT_LINE_SENSOR), moveBackRight, CHANGE);
    attachInterrupt(digitalPinToInterrupt(RIGHT_LINE_SENSOR), moveBackLeft, CHANGE);

    //initialize sensors
    worldState.setAll(lineSensor.getLeftLineSensor(), lineSensor.getBackLineSensor(), lineSensor.getRightLineSensor(), irSensor.getLeftIRSensor(), irSensor.getMiddleIRSensor(), irSensor.getRightIRSensor());
}

void loop() {
    pollSensors();
    robotState();
    myTime = millis();
}

void moveForward() {
    robotActions.moveForward();
}

void moveBackLeft() {
    robotActions.moveSoftLeftBackward();
}

void moveBackRight() {
    robotActions.moveSoftRightBackward();
}

void pollSensors() {
    if (analogRead(LEFT_IR_SENSOR) > 100) {
        irSensor.setLeftIRSensor(1);
    }
    if (analogRead(MIDDLE_IR_SENSOR) > 100) {
        irSensor.setMiddleIRSensor(1);
    }
    if (analogRead(RIGHT_IR_SENSOR) > 100) {
        irSensor.setRightIRSensor(1);
    }
    if (analogRead(LEFT_LINE_SENSOR) > 100) {
        lineSensor.setLeftLineSensor(1);
    }
    if (analogRead(BACK_LINE_SENSOR) > 100) {
        lineSensor.setBackLineSensor(1);
    }
    if (analogRead(RIGHT_LINE_SENSOR) > 100) {
        lineSensor.setRightLineSensor(1);
    }
    worldState.setAll(lineSensor.getLeftLineSensor(), lineSensor.getBackLineSensor(), lineSensor.getRightLineSensor(), irSensor.getLeftIRSensor(), irSensor.getMiddleIRSensor(), irSensor.getRightIRSensor());
}

void robotState() {
    if (worldState.getLastEnemyPosition() == 2) {
        robotActions.moveForward();
    } else if (worldState.getLastEnemyPosition() == 1) {
        robotActions.moveSharpLeft();
    } else if (worldState.getLastEnemyPosition() == 3) {
        robotActions.moveSharpRight();
    } else {
        findEnemy();
    }
}
//tempory scuff
void findEnemy() {
    int i = 0;
    while(true) {
        while (i < 2000) {
            robotActions.spinLeft();
            delay(1);
            i++;
            if (worldState.getLastEnemyPosition() != 0) {
                break;
            }
        }
        if (worldState.getLastEnemyPosition() != 0) {
            break;
        }
        i = 0;
        while (i < 2000) {
            robotActions.spinRight();
            delay(1);
            i++;
            if (worldState.getLastEnemyPosition() != 0) {
                break;
            }
        }
        if (worldState.getLastEnemyPosition() != 0) {
            break;
        }
        i = 0;
    }
}