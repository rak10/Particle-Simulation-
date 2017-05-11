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
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
using namespace std;
using namespace cop;

int main(int argc, char* argv[])
{

	srand(time(NULL));

	Screen screen;

	if(screen.init() == false) {
		cout << "Error initialising SDL." << endl;
	}

	Swarm swarm;



	while(true) {
		//Update the position/states of particles

		//check for messages and events such as if user clicks the window, button etc
		//it raises an event and some data structure should be filled with some data
		int elapsed = SDL_GetTicks();
		screen.clear();
		swarm.update();

		unsigned char green = 128 * (1 + sin(elapsed * 0.0001));
		unsigned char red = 128 * (1 + sin(elapsed * 0.0002));
		unsigned char blue = 128 * (1 + sin(elapsed * 0.0003));
		//cout << "Red: " << red << " Green: " << green << " Blue :" << blue << endl;
		//draw particles

		const Particle * const pParticles = swarm.getParticles();
		for (int i = 0; i< Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = particle.m_y  * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel (x, y, red, green, blue);

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



