#include "SpriteHandler.h"

#include <SDL2/SDL_image.h>

#include "WindowHandler.h"

SDL_Surface* SpriteHandler::loadSurface(std::string filepath) {
	SDL_Surface* surface = NULL;
	SDL_Surface* loadedSurface = IMG_Load(filepath.c_str());
	
	if(loadedSurface == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", filepath.c_str(), SDL_GetError());
	} else {
		surface = SDL_ConvertSurface(loadedSurface, WindowHandler::getInstance().getSurface()->format, NULL); 
		if(surface == NULL) {
			printf("Unable to optimize image %s! SDL Error: %s\n", filepath.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	return surface;
}