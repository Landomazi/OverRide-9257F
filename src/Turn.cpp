#include "vex.h"
#include "Configure.h"
#include "Heading.h"
#include "angle.h"
#include <cmath>

void TurnToHeading( double TargetTheta, double MaxSpeed, int Timeout) {
    double kP = 0;
    double kI = 0;
    double kD = 0;

    double error = 0;
    double prevError = 0;
    double integral = 0;
    double derivative = 0;

    vex::timer t;
    t.reset();

    while (t.time(vex::msec) < Timeout) {

        error = angleWrap(TargetTheta - BotFacing());

        if (fabs(error) < 1.0) break;  // exit if close enough

        integral += error;
        derivative = error - prevError;
        prevError = error;

        double motorPower = kP * error + kI * integral + kD * derivative;

        // clamp speed
        if (motorPower > MaxSpeed) motorPower = MaxSpeed;
        if (motorPower < -MaxSpeed) motorPower = -MaxSpeed;

        LeftMotors.spin(vex::forward, motorPower, vex::pct);
        RightMotors.spin(vex::forward, -motorPower, vex::pct);

        vex::task::sleep(10);
    }

    // stop drivetrain
    LeftMotors.stop(vex::brake);
    RightMotors.stop(vex::brake);
}
