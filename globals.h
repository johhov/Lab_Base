#pragma	once

#include <vector>

#include "ScreenObject.h"
#include "Level.h"

extern const char gWINDOW_CONFIGURATION_FILE[];
extern const char gLEVELS_FILE[];

extern bool gRunning;

extern Level* gCurrentLevel;
extern std::vector<Level> gLevels;

Uint32 color32(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 alpha);