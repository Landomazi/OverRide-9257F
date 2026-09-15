#include "vex.h"
#include <cmath>

namespace {
double wrap180(double angleDeg) {
  while (angleDeg > 180.0) angleDeg -= 360.0;
  while (angleDeg < -180.0) angleDeg += 360.0;
  return angleDeg;
}
}

double BotFacing() {
  const bool has1 = IMU1.installed();
  const bool has2 = IMU2.installed();

  if (!has1 && !has2) return 0.0;
  if (has1 && !has2) return IMU1.heading(vex::degrees);
  if (!has1 && has2) return IMU2.heading(vex::degrees);

  // If IMUs disagree strongly (mounting mismatch or bad reading), prefer sensor 1.
  if (fabs(wrap180(IMU1.heading(vex::degrees) - IMU2.heading(vex::degrees))) > 25.0) {
    return IMU1.heading(vex::degrees);
  }

  // Circular mean for normal case across the 0/360 seam.
  double IMU1Rad = IMU1.heading(vex::degrees) * M_PI / 180.0;
  double IMU2Rad = IMU2.heading(vex::degrees) * M_PI / 180.0;
  double sumSin = sin(IMU1Rad) + sin(IMU1Rad);
  double sumCos = cos(IMU1Rad) + cos(IMU1Rad);
  double averageHeadingDeg = atan2(sumSin, sumCos) * 180.0 / M_PI;
  if (averageHeadingDeg < 0.0) averageHeadingDeg += 360.0;
  return averageHeadingDeg;

} 