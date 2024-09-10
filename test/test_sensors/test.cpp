#include "unity.h"
#include "Sensors/IRSensor.h"
#include "Sensors/LineSensor.h"
#include "Robot/MotorDriver.h"
#include "Robot/RobotActions.h"
#include "Robot/WorldState.h"
#include "Robot/RobotStateTracker.h"
#include <stdbool.h>
#include <stdio.h>

//IRSensor irSensor = IRSensor();


LineSensor lineSensor = LineSensor();
void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_should_doBlahAndBlah(void) {
    TEST_ASSERT_TRUE(true);
}

void test_IRSensor_set(void) {
    IRSensor irSensor = IRSensor();
    irSensor.setLeftIRSensor(0);
    TEST_ASSERT_EQUAL_INT(0, irSensor.getLeftIRSensor());
    irSensor.setRightIRSensor(100);
    TEST_ASSERT_EQUAL_INT(100, irSensor.getRightIRSensor());
    irSensor.setMiddleIRSensor(1000);
    TEST_ASSERT_EQUAL_INT(1000, irSensor.getMiddleIRSensor());
}

void test_LineSensor_set(void) {
    LineSensor lineSensor = LineSensor();
    lineSensor.setLeftLineSensor(0);
    TEST_ASSERT_EQUAL_INT(0, lineSensor.getLeftLineSensor());
    lineSensor.setRightLineSensor(100);
    TEST_ASSERT_EQUAL_INT(100, lineSensor.getRightLineSensor());
    lineSensor.setBackLineSensor(1000);
    TEST_ASSERT_EQUAL_INT(1000, lineSensor.getBackLineSensor());
}

void test_WorldState(void) {
    LineSensor lineSensor = LineSensor();
    IRSensor irSensor = IRSensor();
    WorldState worldState = WorldState(lineSensor, irSensor);
    //testing enemy position
    TEST_ASSERT_EQUAL_INT(0, worldState.getEnemyPosition());
    TEST_ASSERT_EQUAL_INT(0, worldState.getLastEnemyPosition());
    TEST_ASSERT_EQUAL_INT(0, worldState.getCurrentPosition());
    irSensor.setMiddleIRSensor(1);
    TEST_ASSERT_EQUAL_INT(2, worldState.getEnemyPosition());
    TEST_ASSERT_EQUAL_INT(2, worldState.getLastEnemyPosition());
    irSensor.setMiddleIRSensor(0);
    irSensor.setLeftIRSensor(1);
    TEST_ASSERT_EQUAL_INT(1, worldState.getEnemyPosition());
    TEST_ASSERT_EQUAL_INT(1, worldState.getLastEnemyPosition());
    irSensor.setLeftIRSensor(0);
    irSensor.setRightIRSensor(1);
    TEST_ASSERT_EQUAL_INT(3, worldState.getEnemyPosition());
    TEST_ASSERT_EQUAL_INT(3, worldState.getLastEnemyPosition());
    irSensor.setRightIRSensor(0);
    TEST_ASSERT_EQUAL_INT(3, worldState.getLastEnemyPosition());
    //testing current position
    lineSensor.setLeftLineSensor(1);
    TEST_ASSERT_EQUAL_INT(1, worldState.getCurrentPosition());
    lineSensor.setLeftLineSensor(0);
    lineSensor.setRightLineSensor(1);
    TEST_ASSERT_EQUAL_INT(3, worldState.getCurrentPosition());
    lineSensor.setRightLineSensor(0);
    lineSensor.setBackLineSensor(1);
    TEST_ASSERT_EQUAL_INT(2, worldState.getCurrentPosition());
    lineSensor.setBackLineSensor(0);
    worldState.setAll(1, 1, 1, 1, 1, 1);
    TEST_ASSERT_EQUAL_INT(2, worldState.getCurrentPosition());
    TEST_ASSERT_EQUAL_INT(2, worldState.getEnemyPosition());
    worldState.setAll(0, 0, 0, 0, 0, 0);
}

void test_IsReverseing(void) {
    MotorDriver motorDriver = MotorDriver(255);
    RobotActions robotActions = RobotActions(motorDriver);
    robotActions.spinLeft();
    robotActions.spinRight();
    TEST_ASSERT_TRUE(robotActions.getIsReversingA());
    TEST_ASSERT_TRUE(robotActions.getIsReversingB());
    robotActions.setIsReversingA(false);
    robotActions.setIsReversingB(false);
    TEST_ASSERT_FALSE(robotActions.getIsReversingA());
    TEST_ASSERT_FALSE(robotActions.getIsReversingB());
    robotActions.setIsReversingA(true);
    robotActions.setIsReversingB(true);
    TEST_ASSERT_TRUE(robotActions.getIsReversingA());
    TEST_ASSERT_TRUE(robotActions.getIsReversingB());
    TEST_ASSERT_TRUE(motorDriver.getIsReversingA());
    TEST_ASSERT_TRUE(motorDriver.getIsReversingB());


}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_IRSensor_set);
    RUN_TEST(test_LineSensor_set);
    RUN_TEST(test_WorldState);
    RUN_TEST(test_IsReverseing);
    return UNITY_END();
}