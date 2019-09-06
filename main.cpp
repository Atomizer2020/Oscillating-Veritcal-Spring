/* CSCI 261 Final Project: Vertically Oscillating Spring
 *
 * Author: Anand Zorig
 *
 * Section: C
 */

#include <iostream>                             // for standard input/output
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <vector>
#include "DiffEq.h"

using namespace std;                            // using the standard namespace

#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library

using namespace sf;                             // using the sf namespace

int main() {
    double m, b, k;
    int c1, c2;
    int time;
    double arrayPosition[100]; //Y Position for spring in cartesian form
    int yPosition[100];        //Y Position for spring in SFML
    double max, min, absolute;
    int y;
    cout << "Enter mass:" << endl;
    cin >> m;
    cout << "Enter damping coeffecient:" << endl;
    cin >> b;
    cout << "Enter spring constant: " << endl;
    cin >> k;

    DiffEq user;
    user.force(m, b, k);
    user.formula();
    user.generalEquation();
    user.overview();
    cout << "Enter constant1: " << endl;
    cin >> c1;

    cout << "Enter constant2: " << endl;
    cin >> c2;

    user.constants(c1, c2);

    user.particularSolution();

    for (time = 0; time < 100; time++) { //Testing maximum and minimum positions of spring
        arrayPosition[time] = user.solution(time);
        if (time == 0) {
            max = arrayPosition[0];
            min = arrayPosition[0];

        }
        if (arrayPosition[time] >= max) {
            max = arrayPosition[time];
        }
        if (arrayPosition[time] <= min) {
            min = arrayPosition[time];
        }
    }

    if (max >= (-min)) { //Setting Y bounds of the spring in SFML XY plane
        absolute = max;
    } else if (max < (-min)) {
        absolute = (-min);
    }

    for (time = 0; time < 100; time++) { //Converting from Cartesian to SFML XY Plane
        if (arrayPosition[time] > 0) {
            yPosition[time] = (int) (arrayPosition[time] * 640 / absolute);
        }
        if (arrayPosition[time] < 0) {
            yPosition[time] = (int) (640 + (arrayPosition[time] * 640 / absolute));
        }
        if (arrayPosition[time] == 0 || yPosition[time] == 0) {
            yPosition[time] = 320;
        }
    }
    cout << "max: " << max << endl << "min: " << min << endl << "absolute: " << absolute << endl;

    for (int i = 0; i < 100; i++) {
        cout << arrayPosition[i] << " ---> " << yPosition[i] << endl;
    }


    // create a RenderWindow object
    // specify the size to be 640x640
    // set the title to be "SFML Example Window"
    RenderWindow window(VideoMode(640, 640), "SFML Example Window");

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING BELOW HERE
    //********************************************

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING ABOVE HERE
    //********************************************

    // while our window is open, keep it open
    // this is our draw loop

    int i = 0;
    while (window.isOpen()) {
        window.clear(Color::Black);           // clear the contents of the old frame
        // by setting the window to black

        //****************************************
        //  ADD ALL OF OUR DRAWING BELOW HERE
        //****************************************

        y = (yPosition[i]);
        user.setShape(y);
        window.draw(user.getShape()); //Drawing the object
        i++;


        //****************************************
        //  ADD ALL OF OUR DRAWING ABOVE HERE
        //****************************************


        window.display();  // display the window


        //****************************************
        // HANDLE EVENTS BELOW HERE
        //****************************************
        Event event;
        while (window.pollEvent(event)) {      // ask the window if any events occurred
            if (event.type == Event::Closed) { // if event type is a closed event
                // i.e. they clicked the X on the window
                window.close();                 // then close our window
            }
        }
    }

    return EXIT_SUCCESS;                        // report our program exited successfully
}