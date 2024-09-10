#include <Arduino.h>

#include "Robot/WorldState.h"
#include "Robot/RobotActions.h"
#include "Sensors/IRSensor.h"
#include "Sensors/LineSensor.h"
#include "Robot/MotorDriver.h"
#include "Robot/RobotStateTracker.h"

int currentTime;
int currentState;
int previousState;
int switchA;
int switchB;

const int RIGHT_IR_SENSOR = 2;   //Right IR Sensor
const int MIDDLE_IR_SENSOR = 3; //Middle IR Sensor
const int LEFT_IR_SENSOR = 4;  //Left IR Sensor
const int IN1 = 5;
const int IN2 = 9;
const int IN3 = 7;
const int IN4 = 8;
const int ENA = A10;
const int ENB = A11;
const int LEFT_LINE_SENSOR = A17; //Left Line Sensor
const int BACK_LINE_SENSOR = A0;  //Back Line TODO: move lower
const int RIGHT_LINE_SENSOR = A1;  //Right Line Sensor
const int START = 37; 
const int THRESHOLD = 512; //quick fix for big problem, DONT MAX OUT

const int SPEED = 40;

MotorDriver motorDriver = MotorDriver(SPEED);
IRSensor irSensor = IRSensor();
LineSensor lineSensor = LineSensor();
WorldState worldState = WorldState(lineSensor, irSensor);
RobotActions robotActions = RobotActions(motorDriver);
RobotStateTracker robotStateTracker = RobotStateTracker(worldState, robotActions);

void pollSensors();
void writeMotorDriver();

void setup() {
    pinMode(BACK_LINE_SENSOR, INPUT);
    pinMode(LEFT_LINE_SENSOR, INPUT);
    pinMode(RIGHT_LINE_SENSOR, INPUT);
    pinMode(LEFT_IR_SENSOR, INPUT);
    pinMode(RIGHT_IR_SENSOR, INPUT);
    pinMode(MIDDLE_IR_SENSOR, INPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    //initialize sensors
    worldState.setAll(lineSensor.getLeftLineSensor(), lineSensor.getBackLineSensor(), lineSensor.getRightLineSensor(), irSensor.getLeftIRSensor(), irSensor.getMiddleIRSensor(), irSensor.getRightIRSensor());
}

void loop() {
    currentTime = millis();
    int time = currentTime;
    pollSensors();
    worldState.setAll(lineSensor.getLeftLineSensor(), lineSensor.getBackLineSensor(), lineSensor.getRightLineSensor(), irSensor.getLeftIRSensor(), irSensor.getMiddleIRSensor(), irSensor.getRightIRSensor());
    previousState = currentState;
    currentState = robotStateTracker.calculateState(currentTime, previousState);
    writeMotorDriver();

    // DEBUGGING //
    Serial.print("V1.43:");
    Serial.print(time);
    Serial.print(":");
    Serial.print(robotStateTracker.brakeStartTimeA);
    Serial.print(": ");
    
    Serial.print(previousState);
    
    Serial.print(" ");
    Serial.print(irSensor.getRightIRSensor());
    Serial.print(" ");
    Serial.print(irSensor.getMiddleIRSensor());
    Serial.print(" ");
    Serial.print(irSensor.getLeftIRSensor());
    Serial.print(" ");
    Serial.print(analogRead(LEFT_LINE_SENSOR));
    Serial.print(" ");
    Serial.print(analogRead(BACK_LINE_SENSOR));
    Serial.print(" ");
    Serial.print(analogRead(RIGHT_LINE_SENSOR));
    Serial.print(" ");
    Serial.print(motorDriver.getIn1());
    Serial.print(motorDriver.getIn2());
    Serial.print(motorDriver.getIn3());
    Serial.print(motorDriver.getIn4());
    Serial.print(motorDriver.getEnableA());
    Serial.print(motorDriver.getEnableB());
    Serial.print(motorDriver.getSpeed());
    Serial.print(" ");
    Serial.print(worldState.getLastEnemyPosition());
    Serial.print(" ");
    Serial.print(worldState.getCurrentPosition());
    Serial.print(" ");
    Serial.println(digitalRead(START));
    
}

void pollSensors() {
    irSensor.setLeftIRSensor(digitalRead(LEFT_IR_SENSOR));
    irSensor.setMiddleIRSensor(digitalRead(MIDDLE_IR_SENSOR));
    irSensor.setRightIRSensor(digitalRead(RIGHT_IR_SENSOR));
    if (analogRead(LEFT_LINE_SENSOR) < THRESHOLD) {
        lineSensor.setLeftLineSensor(1);
    } else {
        lineSensor.setLeftLineSensor(0);
    }
    if (analogRead(BACK_LINE_SENSOR) < THRESHOLD) {
        lineSensor.setBackLineSensor(1);
    } else {
        lineSensor.setBackLineSensor(0);
    }
    if (analogRead(RIGHT_LINE_SENSOR) < THRESHOLD) {
        lineSensor.setRightLineSensor(1);
    } else {
        lineSensor.setRightLineSensor(0);
    }
    worldState.setAll(lineSensor.getLeftLineSensor(), lineSensor.getBackLineSensor(), lineSensor.getRightLineSensor(), irSensor.getLeftIRSensor(), irSensor.getMiddleIRSensor(), irSensor.getRightIRSensor());
}

void writeMotorDriver() {
    digitalWrite(IN1, motorDriver.getIn1());
    digitalWrite(IN2, motorDriver.getIn2());
    digitalWrite(IN3, motorDriver.getIn3());
    digitalWrite(IN4, motorDriver.getIn4());
    analogWrite(ENA, motorDriver.getEnableA());
    analogWrite(ENB, motorDriver.getEnableB());
}