/*----------------------------------------------------------------------------*/
/*    Module:       configure.cpp                                             */
/*    Author:       Landon.kiely                                              */
/*----------------------------------------------------------------------------*/

#include "vex.h"

//competetion
vex::competition Competition;

//brain & controller
vex::brain BigBrain;
vex::controller Controller = vex::controller(vex::primary);
 
//right motors
vex::motor FrRight = vex::motor( vex::PORT11, vex::ratio6_1, true);
vex::motor BaRight = vex::motor( vex::PORT12, vex::ratio6_1, true);
vex::motor_group RightMotors = vex::motor_group(FrRight, BaRight);

//Left motors
vex::motor FrLeft = vex::motor( vex::PORT20, vex::ratio6_1, false);
vex::motor BaLeft = vex::motor( vex::PORT19, vex::ratio6_1, false);
vex::motor_group LeftMotors= vex::motor_group(FrLeft, BaLeft);

//intake motors
vex::motor Intake = vex::motor(vex::PORT8, vex::ratio6_1, false);

//Lift
vex::motor LiftLeft = vex::motor(vex::PORT6, vex::ratio18_1, false);
vex::motor LiftRight = vex::motor(vex::PORT7, vex::ratio18_1, true );
vex::motor_group Lift = vex::motor_group(LiftLeft, LiftRight);

//Sensors
vex::inertial IMU1(vex::PORT14);
vex::inertial IMU2(vex::PORT21);
vex::rotation Ypod = vex::rotation(vex::PORT7, false);
vex::rotation LiftReader = vex::rotation(vex::PORT1,true);