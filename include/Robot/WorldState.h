#include "Sensors/IRSensor.h"
#include "Sensors/LineSensor.h"

#ifndef WORLD_STATE_H
#define WORLD_STATE_H

class WorldState {
    private:
        LineSensor& lineSensor;
        IRSensor& irSensor;
        int lastEnemyPosition;
    public:
        WorldState(LineSensor& lineSensor, IRSensor& irSensor)
            : lineSensor(lineSensor), irSensor(irSensor) {
            this->lastEnemyPosition = 0;
        }
        int getEnemyPosition();
        int getLastEnemyPosition();
        int getCurrentPosition();
        void setAll(int leftLineSensor, int backLineSensor, int rightLineSensor, int leftIRSensor, int middleIRSensor, int rightIRSensor);
};

#endif


