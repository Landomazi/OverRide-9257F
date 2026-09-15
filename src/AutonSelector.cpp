/*----------------------------------------------------------------------------*/
/*    Module:       autonSelector.cpp                                         */
/*    Author:       Landon.kiely                                              */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "autonSelector.h"

AutonMode SelectedAutonMode;
MatchType SelectedMatchType;
Color SelectedColorSide;
Side SelectedAutoSide;
ElimsSide SelectedElimsSide;

// Wait for screen press and return encoded x and y
int WaitForPress() {
    while (!BigBrain.Screen.pressing()) {
       vex::task::sleep(20);
    }
    int x = BigBrain.Screen.xPosition();
    int y = BigBrain.Screen.yPosition();
    while (BigBrain.Screen.pressing()) {
        vex::task::sleep(20);
    }
    return (x << 16) | y;
}

int DisplayMenu(const char* options[], vex::color colors[], int numOptions) {
    BigBrain.Screen.clearScreen();
    BigBrain.Screen.setFont(vex::fontType::mono30);
    BigBrain.Screen.setPenColor(vex::black);

    int startX[numOptions];
    int startY[numOptions];
    int width[numOptions];
    int height[numOptions];

    // full screen split layout
    if (numOptions == 2 || numOptions == 3) {
        int buttonWidth = 480 / numOptions;

        for (int i = 0; i < numOptions; i++) {
            startX[i] = i * buttonWidth;
            startY[i] = 0;
            width[i]  = buttonWidth;
            height[i] = 240;

            BigBrain.Screen.setFillColor(colors[i]);
            BigBrain.Screen.drawRectangle(startX[i], startY[i], width[i], height[i]);

            BigBrain.Screen.printAt(
                startX[i] + (width[i] / 2) - 60,
                startY[i] + (height[i] / 2),
                options[i]
            );
        }
    }
    // fallback layout for anything else
    else {
        int x = 40;
        int y = 80;

        for (int i = 0; i < numOptions; i++) {
            startX[i] = x;
            startY[i] = y;
            width[i]  = 150;
            height[i] = 150;

            BigBrain.Screen.setFillColor(colors[i]);
            BigBrain.Screen.drawRectangle(x, y, width[i], height[i]);
            BigBrain.Screen.printAt(x + 15, y + 80, options[i]);

            x += 160;
        }
    }

    while (true) {
        int xy = WaitForPress();
        int px = xy >> 16;
        int py = xy & 0xFFFF;

        for (int i = 0; i < numOptions; i++) {
            if (px >= startX[i] && px <= startX[i] + width[i] &&
                py >= startY[i] && py <= startY[i] + height[i]) {
                return i;
            }
        }
    }
}

void AutonSelector() {
    // Step 1: Skills or No Skills
    const char* firstMenu[] = { "Skills", "No Skills" };
    vex::color firstColors[] = { vex::white, vex::blue };
    int choice = DisplayMenu(firstMenu, firstColors, 2);

    SelectedAutonMode = (choice == 0) ? Skills : NoSkills;

    if (SelectedAutonMode == NoSkills) {
        //step 1: color menu
        const char* ColorMenu[] = { "Red", "Blue" };
        vex::color Colors[] = { vex::red, vex::blue };
        choice = DisplayMenu(ColorMenu, Colors, 2);

        // Step 2: Match or Elims
        const char* secondMenu[] = { "Match", "Elims" };
        vex::color secondColors[] = { vex::white, vex::blue };
        choice = DisplayMenu(secondMenu, secondColors, 2);

        SelectedMatchType = (choice == 0) ? Match : Elims;

        if (SelectedMatchType == Match) {
            // Step 3a: Left / Right / AWP
            const char* matchMenu[] = { "Left", "AWP", "Right" };
            vex::color matchColors[] = { vex::blue, vex::white, vex::blue };
            choice = DisplayMenu(matchMenu, matchColors, 3);

            if (choice == 0) SelectedAutoSide = LeftSide;
            else if (choice == 1) SelectedAutoSide = AWPoint;
            else SelectedAutoSide = RightSide;

        } 
        else {
            // Step 3b: Elims Left / Right
            const char* elimsMenu[] = { "Left", "Right" };
            vex::color elimsColors[] = { vex::white, vex::blue };
            choice = DisplayMenu(elimsMenu, elimsColors, 2);

            SelectedElimsSide = (choice == 0) ? ELeft : ERight;
        }
    }

    // Final display
    BigBrain.Screen.clearScreen();
    BigBrain.Screen.setFont(vex::fontType::mono30);
    BigBrain.Screen.setPenColor(vex::white);
    BigBrain.Screen.setFillColor(vex::black);

    if (SelectedAutonMode == Skills) {
        BigBrain.Screen.printAt(40, 100, "Running Skills Autonomous");
    }
    if (SelectedColorSide == Red){
        BigBrain.Screen.printAt(20, 100, "red side");
    } else BigBrain.Screen.printAt(20,100, "blue");

    if (SelectedMatchType == Match) {
        BigBrain.Screen.printAt(60, 100, " Match: ");
        if (SelectedAutoSide == LeftSide)
            BigBrain.Screen.printAt(260, 100, "Left");
        else if (SelectedAutoSide == RightSide)
            BigBrain.Screen.printAt(260, 100, "Right");
        else
            BigBrain.Screen.printAt(260, 100, "AWP");
        } 
    else {
        BigBrain.Screen.printAt(60, 100, " Elims: ");
    if (SelectedElimsSide == ELeft)
        BigBrain.Screen.printAt(260, 100, "Left");
    else
        BigBrain.Screen.printAt(260, 100, "Right");
    }
}