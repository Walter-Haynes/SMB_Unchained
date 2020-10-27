// add your external includes to this file instead of to individual .cpp files

#include <GameSettings.h>

//#define SCRWIDTH		 Game::SCREEN_HEIGHT_PIXELS;
//#define SCRHEIGHT		 Game::SCREEN_WIDTH_PIXELS;

constexpr int SCRWIDTH  = Game::SCREEN_WIDTH_PIXELS;
constexpr int SCRHEIGHT = Game::SCREEN_HEIGHT_PIXELS;

// #define FULLSCREEN
#define ADVANCEDGL	// faster if your system supports it

#include <cinttypes>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <cstdio>

extern "C"
{
#include "glew.h" 
}
#include "gl.h"
#include "wglext.h"

#include "SDL.h"
#include "FreeImage.h"


#include "template.h"
#include "surface.h"