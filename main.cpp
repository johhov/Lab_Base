#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>

#include "InputHandler.h"
#include "WindowHandler.h"
#include "globals.h"
#include "GameEvent.h"
#include "ScreenObject.h"
#include "Level.h"

//using namespace tinyxml2;

Level* loadLevels() {
	FILE* file = fopen(gLEVELS_FILE, "r");

	int f;
	std::string tempString;

	fscanf(file, "Number of files: %d", &f);

	for(int i = 1; i<=f; i++) {
		char tempCString[51];
		fscanf(file, "%50s", &tempCString);
		tempString = tempCString;
		Level level(tempString);
		gLevels.push_back(level);
	}

	fclose(file);
	
	return &gLevels.front();
}

Level* init() {
	InputHandler::getInstance().init();
	if(!WindowHandler::getInstance().init()) {
		gRunning = false;
	}

	return loadLevels();
}

void update(float deltaTime) {
	//Do game logic here.
}

void draw(Level* currentLevel, ScreenObject* player) {
	WindowHandler::getInstance().clear();
	WindowHandler::getInstance().drawList(currentLevel->getWalls());
	WindowHandler::getInstance().draw(player);
	WindowHandler::getInstance().update();
}

void close() {
	WindowHandler::getInstance().close();
}

int main(int argc, char *argv[]) {
	std::queue<GameEvent> eventQueue;
	ScreenObject* player = nullptr;
	Level* currentLevel = nullptr;

	currentLevel = init();

	float deltaTime = 0.0f;

	while(gRunning) {
		auto clockStart = std::chrono::high_resolution_clock::now();

		InputHandler::getInstance().readInput(eventQueue);
		update(deltaTime);
		draw(currentLevel, player);

		auto clockStop = std::chrono::high_resolution_clock::now();
		deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(clockStop - clockStart).count();
	}

	close();
	return 0;
}