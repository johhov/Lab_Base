#include "globals.h"

const char gWINDOW_CONFIGURATION_FILE[] = "windowConfig";
bool gRunning = true;
std::vector<ScreenObject> gWalls;

Uint32 color32(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 alpha)
{
    return (Uint32(alpha) << 24) + (Uint32(r) << 16) + (Uint32(g) << 8) + Uint32(b);
}