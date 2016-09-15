#include <stdio.h>
#include <SDL2/SDL.h>

#include "InputHandler.h"
#include "WindowHandler.h"
#include "globals.h"
#include "GameEvent.h"
#include "ScreenObject.h"

//using namespace tinyxml2;

void init() {
	InputHandler::getInstance().init();
	if(!WindowHandler::getInstance().init()) {
		gRunning = false;
	}
}
/*
int readSVGrects(const char * filename)
{
	XMLDocument doc; //from the tinyxml2 namespace
	doc.LoadFile(filename);  // the actual file parsing
	
	int x=0, y=0;
	int width=0, height=0;
	int i=0;

	XMLElement *levelElement = doc.FirstChildElement("svg")->FirstChildElement("g");

	for (XMLElement* child = levelElement->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
	{
		// Currently this data is not saved anywhere. Use it as you wish.
		//There should be a check to see if the child is a rect. Child->Value()
		const char* name = child->Attribute("id");
		x = child->IntAttribute("x");
		y = child->IntAttribute("y");
		width = child->IntAttribute("width");
		height = child->IntAttribute("height");

		wall[i] = new BaseObject(x, y, width, height);
		i++;
	}
	return i;
}
*/

void update(float deltaTime) {
	//Do game logic here.
}

void draw() {
	//Do rendering here.
	WindowHandler::getInstance().clear();
	WindowHandler::getInstance().drawList(&gWalls);
	WindowHandler::getInstance().update();
}

void close() {
	WindowHandler::getInstance().close();
}

int main(int argc, char *argv[]) {
	std::queue<GameEvent> eventQueue;


	init();

	float deltaTime = 0.0f;

	while(gRunning) {
		auto clockStart = std::chrono::high_resolution_clock::now();

		InputHandler::getInstance().readInput(eventQueue);
		update(deltaTime);
		draw();

		auto clockStop = std::chrono::high_resolution_clock::now();
		deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(clockStop - clockStart).count();
	}

	close();
	return 0;
}