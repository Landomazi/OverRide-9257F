/*----------------------------------------------------------------------------*/
/*    Module:       autonmousRoutes.cpp                                       */
/*    Author:       Landon.kiely                                              */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "configure.h"
#include "Drive.h"
#include "Turn.h"

//Quals
void AutonomousSkills(){
Lift.resetPosition();
Lift.spinToPosition(360, vex::degrees);
Drive(-24,100,1000);
Lift.spinToPosition(10,vex::degrees);
ClawPiston.set(true);
Drive(20,100,1000);
TurnToHeading(55,100,500);
Drive(-5,100,100);
Drive(40,100,750);
Drive(-20,100,500);
Drive(50,100,1000);
Drive(-60,50,10000);
}

void AWP(){
Lift.resetPosition();
Lift.spinToPosition(360, vex::degrees);
Drive(-24,100,1000);
Lift.spinToPosition(10,vex::degrees);
ClawPiston.set(true);
Drive(20,100,1000);
TurnToHeading(55,100,500);
Drive(-5,100,100);
Drive(40,100,750);
Drive(-20,100,500);
Drive(50,100,1000);
Drive(-20,100,1000);
}

void AutonomousRight(){
Lift.resetPosition();
Lift.spinToPosition(360, vex::degrees);
Drive(-24,100,1000);
ClawPiston.set(true);
Drive(20,100,1000);
TurnToHeading(55,100,500);
Drive(-5,100,100);
Drive(40,100,750);
Drive(-20,100,500);
Drive(50,100,1000);
Drive(-20,100,1000);
}

void AutonomousLeft(){
Lift.resetPosition();
Lift.spinToPosition(360, vex::degrees);
Drive(-24,100,1000);
ClawPiston.set(true);
Drive(20,100,1000);
TurnToHeading(55,100,500);
Drive(-5,100,100);
Drive(40,100,750);
Drive(-20,100,500);
Drive(50,100,1000);
Drive(-20,100,1000);
}

//elims
void ElimsRight(){
Lift.resetPosition();
Lift.spinToPosition(360, vex::degrees);
Drive(-24,100,1000);
ClawPiston.set(true);
Drive(20,100,1000);
TurnToHeading(55,100,500);
Drive(-5,100,100);
Drive(40,100,750);
Drive(-20,100,500);
Drive(50,100,1000);
Drive(-20,100,1000);
}

void ElimsLeft(){
Lift.resetPosition();
Lift.spinToPosition(360, vex::degrees);
Drive(-24,100,1000);
ClawPiston.set(true);
Drive(20,100,1000);
TurnToHeading(55,100,500);
Drive(-5,100,100);
Drive(40,100,750);
Drive(-20,100,500);
Drive(50,100,1000);
Drive(-20,100,1000);
}