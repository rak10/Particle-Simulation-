/*
 * Screen.h
 *
 *  Created on: 7 May 2017
 *      Author: Raja
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>
#include <cstring>

namespace cop {

class Screen {
private:
	SDL_Window* m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;


public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

	Screen();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	bool init();
	bool processEvents();
	void close();
	virtual ~Screen();
	void clear();
};

} /* namespace cop */

#endif /* SCREEN_H_ */
