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
using namespace std;

int main(int argc, char* argv[])
{

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL init failed!" << endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow(
			"Particle fire explosion",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

	if (window == NULL) {
		cout << "Error is: " << SDL_GetError() << endl;
		SDL_Quit();
		return 2;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture *texture = SDL_CreateTexture(
			renderer,
			SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC,
			SCREEN_WIDTH,
			SCREEN_HEIGHT
			);

	if (renderer == NULL) {
		cout << "Could not create Renderer" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	if (texture == NULL) {
		cout << "Could not create Texture" << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
		}

	Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; //each pixel has 4 bytes, RGB and Alpha

	memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32)); //set the buffer to black for the entire screen

	for (int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++) //using a for loop ensures we can change individual pixels (4 bytes per pixel)
	{
		buffer[i] = 0x00FF80FF;
	}

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

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

	delete [] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}



