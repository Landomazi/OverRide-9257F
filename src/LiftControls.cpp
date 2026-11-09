
#include "vex.h"
#include <cmath>

// Lift limits
double MaxHeight = 100000000000;
double MinHeight = 0;

// PID constants
double kP = 0.8;
double kD = 0.15;

// Slowdown settings
double SlowZone = 80;
double MinPower = 25;

// Controller variables
double LiftTarget = 0;
double LiftPreviousError = 0;

bool LiftHolding = false;

// Lift PID
void LiftPID(double target)
{
    double currentPosition = Lift.position(vex::degrees);

    double error = target - currentPosition;

    double derivative = error - LiftPreviousError;

    double power = (kP * error) + (kD * derivative);

    LiftPreviousError = error;

    // Stop at target
    if (fabs(error) < 3)
    {
        Lift.stop(vex::hold);
        return;
    }

    // Slow down near target
    if (fabs(error) < SlowZone)
    {
        if (power > 0 && power < MinPower)
            power = MinPower;

        if (power < 0 && power > -MinPower)
            power = -MinPower;
    }

    // Limit power
    if (power > 100) power = 100;
    if (power < -100) power = -100;

    // Correct motor directions
    if (power > 0)
        Lift.spin(vex::forward, power, vex::percent);
    else
        Lift.spin(vex::reverse, -power, vex::percent);
}

// Main lift controls

void LiftControls()
{
    bool L1 = Controller.ButtonL1.pressing();
    bool L2 = Controller.ButtonL2.pressing();

    double currentPosition = Lift.position(vex::degrees);

    // L1 = UP
    if (L1 && !L2 && currentPosition < MaxHeight)
    {
        Lift.spin(vex::forward, 100, vex::percent);
    }

    // L2 = DOWN
    else if (L2 && !L1 && currentPosition > MinHeight)
    {
        Lift.spin(vex::reverse, 100, vex::percent);
    }
    // Stop when released or at a limit
    else
    {
        Lift.stop(vex::hold);
    }
}
