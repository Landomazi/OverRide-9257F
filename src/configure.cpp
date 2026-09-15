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
vex::motor FrRight = vex::motor( vex::PORT2, vex::gearSetting::ratio6_1, true );
vex::motor BaRight = vex::motor( vex::PORT10, vex::gearSetting::ratio6_1, true );
vex::motor_group RightMotors = vex::motor_group(FrRight, FrLeft);

//Left motors
vex::motor FrLeft = vex::motor( vex::PORT1, vex::gearSetting::ratio6_1, false );
vex::motor BaLeft = vex::motor( vex::PORT9, vex::gearSetting::ratio6_1, false );
vex::motor_group LeftMotors= vex::motor_group(FrLeft, BaLeft);

//Sensors
vex::inertial IMU1(vex::PORT3);
vex::inertial IMU2(vex::PORT8);