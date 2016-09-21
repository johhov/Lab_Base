#include "Level.h"
#include "WindowHandler.h"

Level::Level(std::string filepath) {
	loadMap(filepath);
	createWalls();
}

/* 
Reads a text file containing map data in the following format:
5x5
1 1 1 1 1
1 0 0 0 1
0 0 1 0 0
1 0 0 0 1
1 1 1 1 1
*/
void Level::loadMap(std::string filepath) {
	int x, y, temp;
	FILE* file = fopen(filepath.c_str(), "r");
	
	fscanf(file, "%dx%d", &x, &y);

	for(int i = 0; i<y; i++) {
		std::vector<int> row;
		for(int j = 0; j<x; j++) {
			fscanf(file, " %d", &temp);
			row.push_back(temp);
		}
		map.push_back(row);
	}
	
	/*
	// Print data
	for(int i = 0; i<y; i++) {
		for(int j = 0; j<x; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	*/

	fclose(file);
}

void Level::createWalls() {
	glm::vec2 pos, size;
	int rows = map.size();
	int cells = 0;

	for(int i = 0; i<rows; i++) {
		cells = map[i].size();

		for(int j = 0; j<cells; j++) {
			if(map[i][j]) {
				// TODO: Fill in pos and size data 
				ScreenObject wall(pos, size);
				walls.push_back(wall);
			}
		}
	}
}

std::vector<ScreenObject>* Level::getWalls() {
	return &walls;
}