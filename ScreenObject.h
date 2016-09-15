#pragma	once

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class ScreenObject {
public:
	ScreenObject() {};
	ScreenObject(glm::vec2 pos, glm::vec2 sz) : position(pos), size(sz) {};
	~ScreenObject() {};

	glm::vec2 getPosition();
	SDL_Rect getSourceRect();
	SDL_Rect getDestRect();
private:
	glm::vec2 position;
	glm::vec2 size;
};