#pragma	once

#include <SDL2/SDL.h>
#include <map>
#include <queue>
#include <glm/glm.hpp>
#include <chrono>

#include "GameEvent.h"

#define INACTIVE -1

class InputHandler {
public:
	// This ensures that there is only ever one instance of the InputHandler.
	static InputHandler& getInstance() {
		static InputHandler instance;
		return instance;
	}
	
	void init();
	void readInput(std::queue<GameEvent>& events);

	InputHandler(InputHandler const& copy) = delete;
	void operator=(InputHandler const& copy) = delete;
private:
	SDL_Event event;
	glm::vec2 mousePosition;

	std::map<ActionEnum, int> eventRepeat;
	std::map<ActionEnum, int> eventRepeatRate;

	InputHandler() {};

	void handleKeys(std::queue<GameEvent>& events);
	void handleMouse(std::queue<GameEvent>& events);
};