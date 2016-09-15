#include "WindowHandler.h"

#include <stdio.h>
#include <SDL2/SDL_image.h>

#include "globals.h"

bool WindowHandler::init () {

	loadConfig();

	if(!initSDL()) {
		return false;
	}

	return true;
}

void WindowHandler::loadConfig () {
	FILE* conf = fopen(gWINDOW_CONFIGURATION_FILE, "r");

	fscanf(conf, "Window name: %[^\n]%*c", windowName);
	fscanf(conf, "Window size: %dx%d", &windowXSize, &windowYSize);

	fclose(conf);
}

bool WindowHandler::initSDL () {
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Failed to init SDL\n");
		success = false;
	} else {
		//Set texture filtering to linear
		if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}
		
		window = SDL_CreateWindow(
			windowName, 
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			windowXSize,
			windowYSize,
			SDL_WINDOW_SHOWN //replace with SDL_WINDOW_OPENGL when using OpenGL
		);
		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		} else {
			//Create renderer for window
			//Used for textures
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if(renderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			} else {
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG; 
				if(!(IMG_Init(imgFlags) & imgFlags)) { 
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError()); 
					success = false;
				}
			}

			screenSurface = SDL_GetWindowSurface(window);
		}
	}
	return success;
}

void WindowHandler::clear() {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
}

void WindowHandler::drawList(std::vector<ScreenObject>* objects) {
	for(auto o : *objects) {
		draw(&o);
	}
}

void WindowHandler::draw(ScreenObject* object) {
	SDL_Rect source = object->getSourceRect();
	SDL_Rect destination = object->getDestRect();

	SDL_Rect fillRect = { windowXSize / 4, windowYSize / 4, windowXSize / 2, windowYSize / 2 };

	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);
	//SDL_RenderCopy(renderer, m_spriteSheets[spriteSheetName].get(), &source, &destination);
}

void WindowHandler::update() {
	SDL_RenderPresent(renderer);
}

void WindowHandler::close () {
	SDL_FreeSurface(screenSurface);
	screenSurface = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;

	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* WindowHandler::getSurface() {
	return screenSurface;
}

glm::vec2 WindowHandler::getScreenSize() {
	glm::vec2 size;
	size.x = windowXSize;
	size.y = windowYSize;
	return size;
}