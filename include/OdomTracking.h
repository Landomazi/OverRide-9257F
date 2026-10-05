/*----------------------------------------------------------------------------*/
/*    Module:       OdomTracking.h                                            */
/*    Author:       Landon.kiely                                              */
/*----------------------------------------------------------------------------*/
#pragma once

extern double globalX;
extern double globalY;
extern double globalHeading;

void UpdateOdom();
void ResetOdom(double startX = 0, double startY = 0, double startHeading = 0);
void PrintOdom();