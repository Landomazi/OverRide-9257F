/*----------------------------------------------------------------------------*/
/*    Module:       autonSelector.h                                           */
/*    Author:       Landon.kiely                                              */
/*----------------------------------------------------------------------------*/
#pragma once

enum AutonMode { Skills, NoSkills };
enum MatchType { Match, Elims };
enum Color {Red, Blue};
enum Side { LeftSide, RightSide, AWPoint };
enum ElimsSide { ELeft, ERight };

// Global variables to store selected autonomous options
extern AutonMode SelectedAutonMode;
extern MatchType SelectedMatchType;
extern Color SelectedColorSide;
extern Side SelectedAutoSide;
extern ElimsSide SelectedElimsSide;

// Function declarations
int WaitForPress();
int DisplayMenu(const char* options[], vex::color colors[], int numOptions);
void AutonSelector();