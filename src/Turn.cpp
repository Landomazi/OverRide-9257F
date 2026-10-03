#include "vex.h"
#include "Configure.h"
#include "Heading.h"
#include "angle.h"
#include <cmath>

void TurnToHeading(double TargetTheta, double MaxSpeed, int Timeout) {
    double kP = 0.8;
    double kI = 0;
    double kD = 3;

    double error = 0;
    double prevError = angleWrap(TargetTheta - BotFacing());
    double integral = 0;
    double derivative = 0;

    vex::timer t;
    t.reset();

    while (t.time(vex::msec) < Timeout) {

        double currentHeading = BotFacing();

        error = angleWrap(TargetTheta - currentHeading);

        if (fabs(error) < 1.0) break;

        integral += error;
        derivative = error - prevError;
        prevError = error;

        double motorPower = kP * error + kI * integral + kD * derivative;

        if (motorPower > MaxSpeed) motorPower = MaxSpeed;
        if (motorPower < -MaxSpeed) motorPower = -MaxSpeed;

        LeftMotors.spin(vex::forward, motorPower, vex::pct);
        RightMotors.spin(vex::forward, -motorPower, vex::pct);

        vex::task::sleep(10);
    }

    LeftMotors.stop(vex::brake);
    RightMotors.stop(vex::brake);
}