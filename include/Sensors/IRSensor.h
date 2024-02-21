#ifndef IRSENSOR_H
#define IRSENSOR_H

class IRSensor {
private:
    int leftIRSensor;
    int middleIRSensor;
    int rightIRSensor;
public:
    IRSensor();
    int getLeftIRSensor();
    int getMiddleIRSensor();
    int getRightIRSensor();
    /**
     * write either 1 or 0 to the sensor value
     * write 1 if the sensor detects an object
     * write 0 if the sensor does not detect an object
    */
    void setLeftIRSensor(int sensorValue);
    void setMiddleIRSensor(int sensorValue);
    void setRightIRSensor(int sensorValue);
};

#endif