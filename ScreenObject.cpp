#include "ScreenObject.h"


glm::vec2 ScreenObject::getPosition() {
	return position;
}

SDL_Rect ScreenObject::getSourceRect() {
	SDL_Rect rect;

	//TODO
	
	return rect;
}

SDL_Rect ScreenObject::getDestRect() {
	SDL_Rect rect;

	rect.x = static_cast<int>(position.x);
	rect.y = static_cast<int>(position.y);
	rect.w = static_cast<int>(size.x);
	rect.h = static_cast<int>(size.y);

	return rect;
}