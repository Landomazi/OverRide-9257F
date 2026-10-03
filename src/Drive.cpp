#include "vex.h"
#include "Configure.h"
#include "Heading.h"
#include "angle.h"

void DriveStraight(double TargetMovement, double maxSpeed, double timeoutSec) {
    double kP = 0;
    double kI = 0;
    double kD = 0;

    double error = 0;
    double prevError = 0;
    double integral = 0;
    double derivative = 0;

    double wheelDiameter = 2;
    double wheelCircumference = wheelDiameter * M_PI;

    LeftMotors.resetPosition();
    RightMotors.resetPosition();

    vex::timer t;
    t.reset();

    while (true) {
        // Calculate current distance traveled in inches
        double Degrees = Ypod.angle(vex::degrees);
        double CurrentPosition = (Degrees / 360.0) * wheelCircumference;
        
        error = TargetMovement - CurrentPosition;

        // Integral calculation
        if (fabs(error) < 3.0) { 
            integral += error;
        } else {
            integral = 0;
        }
        
        derivative = error - prevError;

        // Calculate total movement speed based purely on distance PID
        double moveSpeed = (kP * error) + (kI * integral) + (kD * derivative);

        // Cap speed at maxSpeed limits
        if (moveSpeed > maxSpeed) moveSpeed = maxSpeed;
        if (moveSpeed < -maxSpeed) moveSpeed = -maxSpeed;

        // Minimum power to overcome drivetrain friction
        if (fabs(moveSpeed) < 7.0 && fabs(error) > 0.25) {
            moveSpeed = (moveSpeed > 0) ? 7.0 : -7.0;
        }

        // Clip motor speeds to maxSpeed safety limits
        double leftSpeed = clamp(moveSpeed, -maxSpeed, maxSpeed);
        double rightSpeed = clamp(moveSpeed, -maxSpeed, maxSpeed);

        LeftMotors.spin(vex::forward, leftSpeed, vex::percent);
        RightMotors.spin(vex::forward, rightSpeed, vex::percent);

        prevError = error;

        // Exit conditions: Within 0.3 inches of target OR user-defined timeout reached
        if (fabs(error) < 0.25 || t.time(vex::sec) > timeoutSec) {
            break;
        }
        vex::wait(20, vex::msec);
    }

    LeftMotors.stop(vex::brake);
    RightMotors.stop(vex::brake);
}