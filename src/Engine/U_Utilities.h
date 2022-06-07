#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "../include/SDL2/SDL.h"

#define CLAMP(v, min, max)  (v < min) ? min : (v > max) ? max : v

// ----------------------------------------------------
// Sets an SDL Rect
// ----------------------------------------------------
void SDL_Rect_Set(SDL_Rect* r, int x, int y, int w, int h);

#endif