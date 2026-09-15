/*----------------------------------------------------------------------------*/
/*    Module:       configure.h                                               */
/*    Author:       Landon.kiely                                              */
/*----------------------------------------------------------------------------*/
#pragma once

//compettition
extern vex::competition Competition;
//brain and controllers
extern vex::brain BigBrain;
extern vex::controller Controller;
//Right Motors
extern vex::motor FrRight;
extern vex::motor BaRight;
extern vex::motor_group RightMotors;

//Left Motors
extern vex::motor FrLeft;
extern vex::motor BaLeft;
extern vex::motor_group LeftMotors;
//Sensors
extern vex::inertial IMU1;
extern vex::inertial IMU2;