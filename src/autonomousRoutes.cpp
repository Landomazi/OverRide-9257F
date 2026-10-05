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
DriveStraight(-24,100,1000);
Lift.spinToPosition(10,vex::degrees);
ClawPiston.set(true);
DriveStraight(20,100,1000);
TurnToHeading(55,100,500);
DriveStraight(-5,100,100);
DriveStraight(40,100,750);
DriveStraight(-20,100,500);
DriveStraight(50,100,1000);
DriveStraight(-60,50,10000);
}
void AWP(){
Lift.resetPosition();
Lift.spinToPosition(360, vex::degrees);
DriveStraight(-24,100,1000);
Lift.spinToPosition(10,vex::degrees);
ClawPiston.set(true);
DriveStraight(20,100,1000);
TurnToHeading(55,100,500);
DriveStraight(-5,100,100);
DriveStraight(40,100,750);
DriveStraight(-20,100,500);
DriveStraight(50,100,1000);
DriveStraight(-20,100,1000);
}
void AutonomousRedRight(){
Lift.resetPosition();
Lift.spinToPosition(360, vex::degrees);
DriveStraight(-24,100,1000);
ClawPiston.set(true);
DriveStraight(20,100,1000);
TurnToHeading(55,100,500);
DriveStraight(-5,100,100);
DriveStraight(40,100,750);
DriveStraight(-20,100,500);
DriveStraight(50,100,1000);
DriveStraight(-20,100,1000);
}
void AutonomousRedLeft(){
Lift.resetPosition();
Lift.spinToPosition(360, vex::degrees);
DriveStraight(-24,100,1000);
ClawPiston.set(true);
DriveStraight(20,100,1000);
TurnToHeading(55,100,500);
DriveStraight(-5,100,100);
DriveStraight(40,100,750);
DriveStraight(-20,100,500);
DriveStraight(50,100,1000);
DriveStraight(-20,100,1000);
}
void AutonomousBlueRight(){
Lift.resetPosition();
Lift.spinToPosition(360, vex::degrees);
DriveStraight(-24,100,1000);
ClawPiston.set(true);
DriveStraight(20,100,1000);
TurnToHeading(55,100,500);
DriveStraight(-5,100,100);
DriveStraight(40,100,750);
DriveStraight(-20,100,500);
DriveStraight(50,100,1000);
DriveStraight(-20,100,1000);
}

void AutonomousBlueLeft(){
Lift.resetPosition();
Lift.spinToPosition(360, vex::degrees);
DriveStraight(-24,100,1000);
ClawPiston.set(true);
DriveStraight(20,100,1000);
TurnToHeading(55,100,500);
DriveStraight(-5,100,100);
DriveStraight(40,100,750);
DriveStraight(-20,100,500);
DriveStraight(50,100,1000);
DriveStraight(-20,100,1000);
}

//elims
void ElimsRedRight(){
Lift.resetPosition();
Lift.spinToPosition(360, vex::degrees);
DriveStraight(-24,100,1000);
ClawPiston.set(true);
DriveStraight(20,100,1000);
TurnToHeading(55,100,500);
DriveStraight(-5,100,100);
DriveStraight(40,100,750);
DriveStraight(-20,100,500);
DriveStraight(50,100,1000);
DriveStraight(-20,100,1000);
}
void ElimsRedLeft(){
Lift.resetPosition();
Lift.spinToPosition(360, vex::degrees);
DriveStraight(-24,100,1000);
ClawPiston.set(true);
DriveStraight(20,100,1000);
TurnToHeading(55,100,500);
DriveStraight(-5,100,100);
DriveStraight(40,100,750);
DriveStraight(-20,100,500);
DriveStraight(50,100,1000);
DriveStraight(-20,100,1000);
}
void ElimsBlueRight(){
Lift.resetPosition();
Lift.spinToPosition(360, vex::degrees);
DriveStraight(-24,100,1000);
ClawPiston.set(true);
DriveStraight(20,100,1000);
TurnToHeading(55,100,500);
DriveStraight(-5,100,100);
DriveStraight(40,100,750);
DriveStraight(-20,100,500);
DriveStraight(50,100,1000);
DriveStraight(-20,100,1000);
}
void ElimsBlueLeft(){
Lift.resetPosition();
Lift.spinToPosition(360, vex::degrees);
DriveStraight(-24,100,1000);
ClawPiston.set(true);
DriveStraight(20,100,1000);
TurnToHeading(55,100,500);
DriveStraight(-5,100,100);
DriveStraight(40,100,750);
DriveStraight(-20,100,500);
DriveStraight(50,100,1000);
DriveStraight(-20,100,1000);
}