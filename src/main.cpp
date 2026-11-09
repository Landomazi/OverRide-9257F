/*----------------------------------------------------------------------------*/
/*    Module:       main.cpp                                                  */
/*    Author:       Landon.kiely                                              */
/*    Created:      8/28/2026, 11:48:27 AM                                    */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "autonSelector.h"
#include "autonomousRoutes.h"
#include "LiftControls.h"

void PreAuton(void) {
  IMU1.resetHeading();
  IMU1.calibrate();
  IMU2.resetHeading();
  IMU2.calibrate();
  Intake.resetPosition();
  Intake.setVelocity(100, vex::percent);
  Lift.setVelocity(100, vex::percent);
  Ypod.resetPosition();
  LiftReader.resetPosition();
  Lift.resetPosition();
  LeftMotors.resetPosition();
  RightMotors.resetPosition();
  LeftMotors.setVelocity(100, vex::percent);
  RightMotors.setVelocity(100, vex::percent);
  AutonSelector();
}// end PreAuton

void Autonomous(void) {
  if (SelectedAutonMode == Skills) {
    AutonomousSkills();
  }//end if loop
  else if (SelectedMatchType == Match) {
    if (SelectedAutoSide == LeftSide) {
      AutonomousLeft();
    }//end if loop 
    else if (SelectedAutoSide == RightSide) {
      AutonomousRight();
    }//end else if
    else if (SelectedAutoSide == AWPoint) {
      AWP();
    }//end else if
  }//end else if
  else if (SelectedMatchType == Elims) {
    if (SelectedElimsSide == ELeft) {
      ElimsLeft();
    }//end if
    else if (SelectedElimsSide == ERight) {
      ElimsRight();
    }//end else if
  }//end else if
}//end autonomous

void UserControl(void) {
  bool ClawEngaged = false;
  bool ClawPosition = false;
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
    bool Up = Controller.ButtonUp.pressing();
    bool Down = Controller.ButtonDown.pressing();
    bool Left = Controller.ButtonLeft.pressing();
    bool Right = Controller.ButtonRight.pressing();
    bool Y = Controller.ButtonY.pressing();
    bool X = Controller.ButtonX.pressing();
    bool A = Controller.ButtonA.pressing();
    bool B = Controller.ButtonB.pressing();

    LiftControls();

    // Drive motors
    LeftMotors.spin(vex::forward, L3, vex::percent);
    RightMotors.spin(vex::forward, R3, vex::percent);

    //intake
    if (R1) Intake.spin(vex::forward,100,vex::percent);
    else if (R2) Intake.spin(vex::reverse,100,vex::percent);
    else Intake.stop();


    // descore  mechanism
    if (Y && !ClawEngaged) {
      ClawPosition = !ClawPosition;
      ClawPiston.set(ClawPosition);
    }//end if statement
    ClawEngaged = Y;

    // screen Debug
    BigBrain.Screen.clearScreen();
    BigBrain.Screen.setCursor(1, 1);
    BigBrain.Screen.print("Drive L: %.1f  R: %.1f", L3, R3);
    BigBrain.Screen.newLine();
    BigBrain.Screen.print("Headings position1:%d  position2:%d", (double)IMU1.heading(vex::degrees), (double)IMU2.heading(vex::degrees));
    BigBrain.Screen.newLine();
    BigBrain.Screen.print("Averaged Heading:%d", (double)BotFacing());
    BigBrain.Screen.newLine();
    BigBrain.Screen.print("Lift Degrees:%d", (double)LiftReader.position(vex::degrees));
    // PrintOdom();
  }//end while loop
}//end usercontrol

int main() {
  PreAuton();
  Competition.autonomous(Autonomous);
  Competition.drivercontrol(UserControl);
  while (true) {
    vex::wait(100, vex::msec);
  }//end while loop
}//end main