#include "vex.h" 
#include "Configure.h" 
#include "Heading.h" 
#include "angle.h"


void DriveStraight(double TargetMovement, double maxSpeed, double timeout) { 
    double kP = 3.25; 
    double kI = 0.08; 
    double kD = 2.0; 
 
    double error = 0; 
    double prevError = TargetMovement; 
    double integral = 0; 
    double derivative = 0; 
 
    double wheelDiameter = 2; 
    double wheelCircumference = wheelDiameter * M_PI; 
 
    LeftMotors.resetPosition(); 
    RightMotors.resetPosition(); 
    Ypod.resetPosition();
    vex::timer t; 
    t.reset(); 
 
    while (true) { 
        double Degrees = Ypod.position(vex::degrees); 
        double CurrentPosition = (Degrees / 360.0) * wheelCircumference; 
         
        error = TargetMovement - CurrentPosition; 
 
        if (fabs(error) < 3.0) {  
            integral += error; 
        } else { 
            integral = 0; 
        } 
         
        derivative = error - prevError; 
 
        double moveSpeed = (kP * error) + (kI * integral) + (kD * derivative); 
 
        if (moveSpeed > maxSpeed) moveSpeed = maxSpeed; 
        if (moveSpeed < -maxSpeed) moveSpeed = -maxSpeed; 
 
        //if (fabs(moveSpeed) < 7.0 && fabs(error) > 0.25) { 
        //    moveSpeed = (moveSpeed > 0) ? 7.0 : -7.0; 
        //} 
 
        double leftSpeed = clamp(moveSpeed, -maxSpeed, maxSpeed); 
        double rightSpeed = clamp(moveSpeed, -maxSpeed, maxSpeed); 
 
        LeftMotors.spin(vex::forward, leftSpeed, vex::percent); 
        RightMotors.spin(vex::forward, rightSpeed, vex::percent);

        prevError = error; 
 
        if (fabs(error) < 0.25 || t.time(vex::msec) > timeout) { 
            break; 
        } 
 
        vex::wait(20, vex::msec); 
    } 
 
    LeftMotors.stop(vex::brake); 
    RightMotors.stop(vex::brake); 
}