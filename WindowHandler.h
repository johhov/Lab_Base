#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <glm/glm.hpp>

#include "ScreenObject.h"

class WindowHandler {
public:
	static WindowHandler& getInstance() {
		static WindowHandler instance;
		return instance;
	}

	bool init();
	void clear();
	void drawList(std::vector<ScreenObject>* objects);
	void draw(ScreenObject* object);
	void update();
	void close();

	SDL_Surface* getSurface();
	glm::vec2 getScreenSize();

	WindowHandler(WindowHandler const& copy) = delete;
	void operator=(WindowHandler const& copy) = delete;
private:
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Renderer* renderer = nullptr;
	char windowName[100];
	int windowXSize;
	int windowYSize;

	WindowHandler() {};
	bool initSDL();
	void loadConfig();
};