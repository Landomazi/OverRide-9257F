/*----------------------------------------------------------------------------*/
/*    Module:       autonmousRoutes.cpp                                       */
/*    Author:       Landon.kiely                                              */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "configure.h"
#include "Drive.h"
#include "Turn.h"

// Quals
void AutonomousSkills() {
    Lift.resetPosition();
    Lift.spinToPosition(380,vex::degrees);
    Drive(-17, 30, 1000);
    wait(200,vex::msec);
    Lift.spinToPosition(120,vex::degrees);
    ClawPiston.set(true);
    TurnToHeading(-50,100,500);
    Drive(20,100,1000);
    TurnToHeading(40,100,500);
    Drive(50,80,700);
    wait(200,vex::msec);
    Drive(-20,70,700);
    Drive(50, 100, 700);
    Drive(-20,70,700);
    Drive(50,80,1000);
    Drive(-17,70,1000);
    Drive(-50,60,10000);
}//end autonomousSkills

void AWP() {
Drive(10,10,10);
}//end AWP

void AutonomousRight() {
    Lift.resetPosition();
    Lift.spinToPosition(380,vex::degrees);
    Drive(-17, 30, 1000);
    wait(200,vex::msec);
    Lift.spinToPosition(120,vex::degrees);
    ClawPiston.set(true);
    TurnToHeading(-50,100,500);
    Drive(20,100,1000);
    TurnToHeading(40,100,500);
    Drive(50,80,700);
    wait(200,vex::msec);
    Drive(-20,70,700);
    TurnToHeading(40,100,1000);
    wait(200,vex::msec);
    Drive(50, 100, 700);
    Drive(-25,70,700);
    TurnToHeading(-90,100,300);
    Drive(-30,40,2000);
}//end AutonomousRight

void AutonomousLeft() {
    Lift.resetPosition();
    Lift.spinToPosition(380,vex::degrees);
    Drive(-24, 50, 500);
    wait(100,vex::msec);
    Lift.spinToPosition(120,vex::degrees);
    ClawPiston.set(true);
    TurnToHeading(40,100,500);
    Drive(20,100,1000);
    TurnToHeading(-50,100,500);
    Drive(50,70,700);
    wait(200,vex::msec);
    Drive(-20,70,700);
    Drive(34, 50, 700);
    Drive(-17,70,700);
}//end AutonomousLeft

// elims
void ElimsRight() {
    Lift.resetPosition();
    Lift.spinToPosition(380,vex::degrees);
    Drive(-17, 30, 1000);
    wait(200,vex::msec);
    Lift.spinToPosition(120,vex::degrees);
    ClawPiston.set(true);
    TurnToHeading(-50,100,500);
    Drive(20,100,1000);
    TurnToHeading(40,100,500);
    Drive(50,80,700);
    wait(200,vex::msec);
    Drive(-20,70,700);
    wait(200,vex::msec);
    Drive(50, 100, 700);
    Drive(-25,70,700);
    Drive(50, 100, 700);
    Drive(-25,70,700);
    TurnToHeading(-4,100,500);
    Drive(-40,100,500);
    Drive(-18,30,1000);
    ClawPiston.set(false);
    Lift.spinToPosition(540,vex::degrees);
    TurnToHeading(223,100,1000);
    Drive(-35,50,500);
    ClawPiston.set(true);
}//end ElimsRight

void ElimsLeft() {
    Lift.resetPosition();
    Lift.spinToPosition(380,vex::degrees);
    Drive(-24, 50, 500);
    wait(100,vex::msec);
    Lift.spinToPosition(120,vex::degrees);
    ClawPiston.set(true);
    TurnToHeading(40,100,500);
    Drive(20,100,1000);
    TurnToHeading(-50,100,500);
    Drive(50,70,700);
    wait(200,vex::msec);
    Drive(-20,70,700);
    Drive(34, 50, 700);
    Drive(-17,70,700);
}//end ElimsLeft