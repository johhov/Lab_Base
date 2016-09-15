#pragma	once

#include <SDL2/SDL.h>
#include <string>
#include <vector>

class SpriteHandler {
public:
	SpriteHandler() {};
	~SpriteHandler() {};

	SDL_Surface* loadSurface(std::string filepath);
private:
	std::vector<SDL_Surface*> sprites;
};