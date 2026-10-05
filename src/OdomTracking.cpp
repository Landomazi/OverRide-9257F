/*----------------------------------------------------------------------------*/
/*    Module:       OdomTracking.cpp                                          */
/*    Author:       Landon.kiely                                              */
/*----------------------------------------------------------------------------*/

#include "vex.h"

// Global position
double globalX = 0.0;
double globalY = 0.0;
double globalHeading = 0.0;

// Last sensor values
double lastYPodDeg = 0.0;
double lastHeading = 0.0;
double headingOffset = 0.0;

// Tracking wheel constants
const double TrackingWheelDiameter = 2.0;
const double TrackingWheelCircumference = TrackingWheelDiameter * M_PI;

// Forward pod lateral offset from robot center (inches).
// Right side positive, left side negative.
double yPodOffset = 0;

static double wrapDeg(double angle) {
  while (angle > 180.0) angle -= 360.0;
  while (angle < -180.0) angle += 360.0;
  return angle;
}

// Reset odom
void ResetOdom(double startX, double startY, double startHeading) {
  globalX = startX;
  globalY = startY;

  Ypod.resetPosition();

  // Align field heading to whichever inertial reading mode BotFacing() returns.
  headingOffset = startHeading - BotFacing();
  globalHeading = startHeading;

  lastYPodDeg = Ypod.position(vex::rotationUnits::deg);
  lastHeading = startHeading;
}

void UpdateOdom() {
  
  double yPodDeg = Ypod.position(vex::rotationUnits::deg);
  double yDeltaDeg = yPodDeg - lastYPodDeg;
  lastYPodDeg = yPodDeg;

  double forwardInches = (yDeltaDeg / 360.0) * TrackingWheelCircumference;

  double newHeading = BotFacing() + headingOffset;
  double deltaHeadingDeg = newHeading - lastHeading;
  deltaHeadingDeg = wrapDeg(deltaHeadingDeg);
  double deltaHeadingRad = deltaHeadingDeg * M_PI / 180.0;

  //Rotation Compensation
  double yRotationComp = deltaHeadingRad * yPodOffset;
  forwardInches -= yRotationComp;

  //Average Heading
  double avgHeadingRad = (lastHeading + deltaHeadingDeg / 2.0) * M_PI / 180.0;

  //Global Position Update
  globalX += forwardInches * sin(avgHeadingRad);
  globalY += forwardInches * cos(avgHeadingRad);


  lastHeading = newHeading;
  globalHeading = newHeading;
}

// Accessors
double GetX() { return globalX; }
double GetY() { return globalY; }
double GetHeading() { return globalHeading; }

// Debug
void PrintOdom() {
  BigBrain.Screen.clearScreen();
  BigBrain.Screen.setCursor(1, 1);
  BigBrain.Screen.print("X: %.2f", globalX);
  BigBrain.Screen.newLine();
  BigBrain.Screen.print("Y: %.2f", globalY);
  BigBrain.Screen.newLine();
  BigBrain.Screen.print("H: %.2f", globalHeading);
}