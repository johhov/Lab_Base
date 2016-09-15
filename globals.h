#pragma	once

#include <vector>

#include "ScreenObject.h"

extern const char gWINDOW_CONFIGURATION_FILE[];
extern bool gRunning;
extern std::vector<ScreenObject> gWalls;

Uint32 color32(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 alpha);