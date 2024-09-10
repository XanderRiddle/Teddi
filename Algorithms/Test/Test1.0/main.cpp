//TEST CODE

#include <Arduino.h>
#include "Robot/MotorDriver.h"
#include "Robot/RobotActions.h"

// LOOKING FROM THE BACK

const int LEFT_IR_SENSOR = 2;   //Right IR Sensor
const int MIDDLE_IR_SENSOR = 3; //Middle IR Sensor
const int RIGHT_IR_SENSOR = 4;  //Left IR Sensor
const int IN1 = 5;
const int IN2 = 9;
const int IN3 = 7;
const int IN4 = 8;
const int ENA = A10;
const int ENB = A11;
const int LINE1 = A17; //Left Line Sensor
const int LINE2 = A0;  //Back Line TODO: move lower
const int LINE3 = A1;  //Right Line Sensor
const int START = 28; 

const int SPEED = 40;

//const int BACK_LINE_SENSOR = A9;
//const int LEFT_MOTOR;
MotorDriver motorDriver = MotorDriver(SPEED);
RobotActions robotActions = RobotActions(motorDriver);

void writeMotorDriver();

void setup() {
    
    pinMode(MIDDLE_IR_SENSOR, INPUT);
    pinMode(LINE1, INPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    /*
    pinMode(BACK_LINE_SENSOR, INPUT);
    pinMode(LEFT_MOTOR, OUTPUT);
    */
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int time = millis();
    //int middleIRSensor = analogRead(MIDDLE_IR_SENSOR);
    //int backLineSensor = digitalRead(BACK_LINE_SENSOR);
    //Serial.print("IRSensor: ");
    //Serial.println(middleIRSensor);
    
    //Serial.print(" LineSensor: ");
    //Serial.println(backLineSensor);
    //Serial.println("Hello World");
    //Serial.println(analogRead(MIDDLE_IR_SENSOR));

    
    Serial.print("V1.21:");
    Serial.print(time);
    Serial.print(": ");
    /*
    Serial.print(digitalRead(LEFT_IR_SENSOR));
    Serial.print(" ");
    Serial.print(digitalRead(MIDDLE_IR_SENSOR));
    Serial.print(" ");
    Serial.print(digitalRead(RIGHT_IR_SENSOR));
    Serial.print(" ");
    Serial.print(analogRead(LINE1));
    Serial.print(" ");
    Serial.print(analogRead(LINE2));
    Serial.print(" ");
    Serial.print(analogRead(LINE3));
    Serial.print(" ");
    Serial.println(digitalRead(START));
    */
    
    robotActions.moveForward();
    writeMotorDriver();
    delay(250);
    robotActions.moveBackward();
    writeMotorDriver();
    delay(250);

    Serial.print(motorDriver.getIn1());
    Serial.print(motorDriver.getIn2());
    Serial.print(motorDriver.getIn3());
    Serial.print(motorDriver.getIn4());
    Serial.print(motorDriver.getEnableA());
    Serial.print(motorDriver.getEnableB());
    Serial.println(motorDriver.getSpeed());
    /*
    digitalWrite(IN1, 1);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 1);
    digitalWrite(IN4, 0);
    analogWrite(ENB, 40);
    analogWrite(ENA, 40);
    */

    //Serial.println("Hello World");
    //delay(1);
    /*
    digitalWrite(LEFT_MOTOR, HIGH);
    */

}

void writeMotorDriver() {
    digitalWrite(IN1, motorDriver.getIn1());
    digitalWrite(IN2, motorDriver.getIn2());
    digitalWrite(IN3, motorDriver.getIn3());
    digitalWrite(IN4, motorDriver.getIn4());
    analogWrite(ENB, motorDriver.getEnableA());
    analogWrite(ENA, motorDriver.getEnableB());
}