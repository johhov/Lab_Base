#pragma	once

#include <string>
#include <vector>
#include <glm/glm.hpp>

#include "ScreenObject.h"

class Level {
public:
	Level(std::string filepath);

	std::vector<ScreenObject>* getWalls();
private:
	std::vector<std::vector<int>> map;
	std::vector<ScreenObject> walls;

	void loadMap(std::string filepath);
	void createWalls();	
};