#include <SDL2/SDL.h>
#include "InputHandler.h"
#include "globals.h"

void InputHandler::init () {
	//Add new events here and in GameEvent.h
	eventRepeatRate[ActionEnum::QUIT] = 0;
	eventRepeat[ActionEnum::QUIT] = INACTIVE;

	eventRepeatRate[ActionEnum::MOUSEMOTION] = 0;
	eventRepeat[ActionEnum::MOUSEMOTION] = INACTIVE;
}

void InputHandler::readInput(std::queue<GameEvent>& events) {
	//Handle new events on queue
	while (SDL_PollEvent(&event) != 0) {
		//User requests quit
		if (event.type == SDL_QUIT) {
			gRunning = false;
		}

		if (event.type == SDL_KEYDOWN ||
			event.type == SDL_KEYUP)
		{
			handleKeys(events);
		}

		if (event.type == SDL_MOUSEBUTTONDOWN ||
			event.type == SDL_MOUSEBUTTONUP ||
			event.type == SDL_MOUSEMOTION ||
			event.type == SDL_MOUSEWHEEL)
		{
			handleMouse(events);
		}
	}
	
	//This will trigger all events that have reached cool down
	for (auto it = eventRepeat.begin(); it != eventRepeat.end(); ++it) {
		if (it->second != INACTIVE) {
			if (it->second == 0) {
				events.push(GameEvent{ 0, it->first }); // raise the event
				it->second = eventRepeatRate[it->first];  // set to cool down
			} else {
				--it->second;  // cool down toward triggering
			}
		}
	}
}

void InputHandler::handleKeys(std::queue<GameEvent>& events) {
	ActionEnum action;
	switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
					gRunning = false;
					break;

				default:
					break;
			}

			//This checks if the event is active and on cool down
			if (eventRepeat[action] < 0) {
				events.push(GameEvent{ 0, action }); //trigger event
				eventRepeat[action] = eventRepeatRate[action]; // set the repeat cool down
			}
			break;

		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
				default:
					break;
			}

			eventRepeat[action] = INACTIVE;
			break;

		default:
			break;
	}
}
void InputHandler::handleMouse(std::queue<GameEvent>& events) {
    ActionEnum action = ActionEnum::NOACTION;
    
    switch (event.type)
    {
        case SDL_MOUSEBUTTONDOWN:
            break;
        case SDL_MOUSEBUTTONUP:
            break;
        case SDL_MOUSEWHEEL:
            break;
        case SDL_MOUSEMOTION:
            mousePosition.x = event.motion.x;
            mousePosition.y = event.motion.y;
            action = ActionEnum::MOUSEMOTION;
            break;
    }

    if (eventRepeat[action] < 0) {
        events.push(GameEvent{ 0, action }); //trigger event
        eventRepeat[action] = eventRepeatRate[action]; // set the repeat cool down
    }
}