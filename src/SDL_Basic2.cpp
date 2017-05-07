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
using namespace std;
using namespace cop;

int main(int argc, char* argv[])
{



	Screen screen;

	if(screen.init() == false) {
		cout << "Error initialising SDL." << endl;
	}


	bool quit = false;

	SDL_Event event;

	while(!quit) {
		//Update the position/states of particles
		//draw particles
		//check for messages and events such as if user clicks the window, button etc
		//it raises an event and some data structure should be filled with some data

		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				SDL_Log("Program quit after %i ticks", event.quit.timestamp);
				cout << "quit after : " << event.quit.timestamp << endl;
				quit = true;
			}
		}
	}

	screen.close();
	return 0;
}



