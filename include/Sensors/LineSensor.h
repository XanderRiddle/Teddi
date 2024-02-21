#ifndef LINESENSOR_H
#define LINESENSOR_H

class LineSensor {
private:
    int leftLineSensor;
    int rightLineSensor;
    int backLineSensor;  
public:
    LineSensor();
    int getLeftLineSensor();
    int getRightLineSensor();
    int getBackLineSensor();
    /**
     * write either 1 or 0 to the sensor value
     * write 1 if the robot is on the line
     * write 0 if the robot is not on the line
    */
    void setLeftLineSensor(int sensorValue);
    void setRightLineSensor(int sensorValue);
    void setBackLineSensor(int sensorsValue);
};

#endif