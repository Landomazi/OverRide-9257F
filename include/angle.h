#pragma once

inline double angleWrap(double angle) {
    while (angle > 180) angle -= 360;
    while (angle < -180) angle += 360;
    return angle;
}

inline double clamp(double val, double minVal, double maxVal) {
    if (val < minVal) return minVal;
    if (val > maxVal) return maxVal;
    return val;
}

inline double max(double a, double b) {
    return (a > b) ? a : b;
}