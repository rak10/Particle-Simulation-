//============================================================================
// Name        : SDL_Basic2.cpp
// Author      : Asad
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <SDL.h>
#include <cstring>
#include "Screen.h"
#include <math.h>
using namespace std;
using namespace cop;

int main(int argc, char* argv[])
{



	Screen screen;

	if(screen.init() == false) {
		cout << "Error initialising SDL." << endl;
	}



	while(true) {
		//Update the position/states of particles

		//check for messages and events such as if user clicks the window, button etc
		//it raises an event and some data structure should be filled with some data

		//smooth changing of colours
		int elapsed = SDL_GetTicks();
		unsigned char green = 128 * (1+ sin(elapsed*0.0001));
		unsigned char red = 128 * (1+ sin(elapsed*0.0002));
		unsigned char blue = 128 * (1+ sin(elapsed*0.0003));
		//cout << "Red: " << red << " Green: " << green << " Blue :" << blue << endl;
		//draw particles
		for(int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for(int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x ,y, red, green, blue);

			}
		}


		//Draw the screen
		screen.update();

		//Check for messages/updates
		if(screen.processEvents() == false) {
			break;

		}
	}

	screen.close();
	return 0;
}



