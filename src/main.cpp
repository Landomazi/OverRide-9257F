/*----------------------------------------------------------------------------*/
/*    Module:       main.cpp                                                  */
/*    Author:       Landon.kiely                                              */
/*    Created:      8/28/2026, 11:48:27 AM                                    */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "autonSelector.h"
#include "autonomousRoutes.h"
#include "Heading.h"

void pre_auton(void) {
  AutonSelector();
}

void autonomous(void) {
  if (SelectedAutonMode == Skills) {
    AutonomousSkills();
  } else if (SelectedMatchType == Match && SelectedColorSide == Red) {
    if (SelectedAutoSide == LeftSide) {
      AutonomousRedLeft();
    } else if (SelectedAutoSide == RightSide) {
      AutonomousRedRight();
    } else if (SelectedAutoSide == AWPoint) {
      AWP();
    }
  } else if (SelectedMatchType == Elims && SelectedColorSide == Red) {
    if (SelectedElimsSide == ELeft) {
      ElimsRedLeft();
    } else if (SelectedElimsSide == ERight) {
      ElimsRedRight();
    }
  } else if (SelectedMatchType == Match && SelectedColorSide == Blue) {
    if (SelectedAutoSide == LeftSide) {
      AutonomousBlueLeft();
    } else if (SelectedAutoSide == RightSide) {
      AutonomousBlueRight();
    } else if (SelectedAutoSide == AWPoint) {
      AWP();
    }
  } else if (SelectedMatchType == Elims && SelectedColorSide == Blue) {
    if (SelectedElimsSide == ELeft) {
      ElimsBlueLeft();
    } else if (SelectedElimsSide == ERight) {
      ElimsBlueRight();
    }
  }
}

void usercontrol(void) {
  while (1) {
    vex::wait(20, vex::msec);
    double L3 = Controller.Axis3.position(); // left stick vertical
    double R3 = Controller.Axis2.position(); // right stick vertical
    double L4 = Controller.Axis4.position(); // left stick horizontal
    double R4 = Controller.Axis1.position(); // right stick horizontal
    bool R1 = Controller.ButtonR1.pressing();
    bool R2 = Controller.ButtonR2.pressing();
    bool L1 = Controller.ButtonL1.pressing();
    bool L2 = Controller.ButtonL2.pressing();
    // Drive motors
    LeftMotors.spin(vex::forward, L3, vex::percent);
    RightMotors.spin(vex::forward, R2, vex::percent);
    //intake
    if (R1) Intake.spin(vex::forward);
    if (R2) Intake.spin(vex::reverse);

    //screen Debug
    BigBrain.Screen.clearScreen();
    BigBrain.Screen.setCursor(1,1);
    BigBrain.Screen.print("Drive L: %.1f  R: %.1f", L3, R2);
    BigBrain.Screen.newLine();
    BigBrain.Screen.print("headings position1:%d  position2:%d", IMU1.heading(), IMU2.heading());
    BigBrain.Screen.newLine();
    BigBrain.Screen.print("Averaged Heading:%d",BotFacing());
  }
}


int main() {
  pre_auton();
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  while (true) {
    vex::wait(100, vex::msec);
  }
}
